using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class CompilationUnitTransform {
    public AssemblyTransform AssemblyTransform { get; }
    public SyntaxGenerator Generator => AssemblyTransform.Generator;
    public CompilationUnitSyntax CompilationUnit { get; } = new CompilationUnitSyntax();
    private readonly Dictionary<ITypeDefinition, bool> headReferences_ = new Dictionary<ITypeDefinition, bool>();
    private readonly HashSet<ITypeDefinition> srcReferences_ = new HashSet<ITypeDefinition>();
    private readonly ITypeDefinition root_;

    public CompilationUnitTransform(AssemblyTransform assemblyTransform, List<ITypeDefinition> types) {
      AssemblyTransform = assemblyTransform;
      root_ = types.First();
      VisitCompilationUnit(types);
    }

    private void VisitCompilationUnit(IEnumerable<ITypeDefinition> types) {
      var (rootNamespace, classNamespace) = CompilationUnit.AddNamespace(root_.GetFullNamespace(), root_.Name);
      var headUsingsSyntax = new StatementListSyntax();
      classNamespace.Add(headUsingsSyntax);

      var srcUsingsSyntax = new StatementListSyntax();
      if (root_.Kind != TypeKind.Enum && root_.Kind != TypeKind.Interface) {
        CompilationUnit.AddSrcStatement(srcUsingsSyntax);
      }

      var typeDefinition = new TypeDefinitionTransform(this, classNamespace, types);
      if (root_.Kind != TypeKind.Enum) {
        var headIncludes = new HashSet<string>();
        var headUsings = new HashSet<string>();
        var forwards = new Dictionary<ITypeDefinition, StatementSyntax>();
        var srcIncludes = new HashSet<string>();
        foreach (var (reference, isForward) in headReferences_) {
          if (isForward) {
            var forward = GetForwardMacroSyntax(reference, out var forwardType);
            forwards[forwardType] = forward;
            srcIncludes.Add(reference.GetReferenceIncludeString(true));
          } else {
            headIncludes.Add(reference.GetReferenceIncludeString());
            srcIncludes.Add(reference.GetReferenceIncludeString(true));
          }
          if (!root_.IsNamespaceContain(reference)) {
            headUsings.Add(reference.GetFullNamespace(true));
          }
        }
        CompilationUnit.AddHeadIncludes(headIncludes.OrderBy(i => i));
        headUsingsSyntax.AddRange(headUsings.OrderBy(i => i).Select(i => new UsingNamespaceOrTypeSyntax(i)));
        AddForwards(rootNamespace, forwards, headUsingsSyntax);
        rootNamespace.Add(classNamespace);
        AddTypeUsingDeclaration(rootNamespace, classNamespace, typeDefinition, types);
        if (root_.Kind != TypeKind.Interface) {
          CompilationUnit.AddReferencesIncludes(root_.Name, srcIncludes.OrderBy(i => i));
          CompilationUnit.AddSrcReferencesIncludes(srcReferences_.Select(i => i.GetReferenceIncludeString(true)).OrderBy(i => i));
          srcUsingsSyntax.AddRange(srcReferences_.Where(i => !root_.IsNamespaceContain(i)).Select(i => i.GetFullNamespace(true)).OrderBy(i => i).Select(i => new UsingNamespaceOrTypeSyntax(i)));
        }
      } else {
        rootNamespace.AddRange(classNamespace.Statements);
        if (!root_.EnumUnderlyingType.IsInt32()) {
          CompilationUnit.AddEnumHeadInclude();
        }
      }
    }

    private void AddTypeUsingDeclaration(NamespaceSyntax rootNamespace, NamespaceSyntax classNamespace, TypeDefinitionTransform typeDefinition, IEnumerable<ITypeDefinition> types) {
      IdentifierSyntax name = root_.Name;
      ExpressionSyntax type = ((IdentifierSyntax)classNamespace.Name).TwoColon(name);
      TemplateSyntax template;
      if (root_.IsArrayType()) {
        const int kGenericCount = 2;
        type = new GenericIdentifierSyntax(type, kGenericCount.GetTypeNames());
        template = kGenericCount.GetVoidTemplate();
      } else if (typeDefinition.IsMulti) {
        int typeParameterCount = types.Last().TypeParameterCount + 1;
        type = new GenericIdentifierSyntax(type, typeParameterCount.GetTypeNames());
        template = typeParameterCount.GetVoidTemplate();
      } else {
        template = root_.GetTemplateSyntax();
        if (template != null) {
          type = new GenericIdentifierSyntax(type, template.TypeNames);
        }
      }
      var usingDeclaration = new UsingDeclarationSyntax(name, type) { Template = template };
      rootNamespace.Add(usingDeclaration);
    }

    private void AddForwards(NamespaceSyntax rootNamespace, Dictionary<ITypeDefinition, StatementSyntax> forwards, StatementListSyntax usingsSyntax) {
      var outs = new List<(ITypeDefinition Type, StatementSyntax Forward)>();
      foreach (var (type, forward) in forwards) {
        if (root_.GetFullNamespace() == type.GetFullNamespace()) {
          rootNamespace.Add(forward);
        } else {
          outs.Add((type, forward));
        }
        if (type.IsIEnumeratorOfT() || type.IsIListOfT()) {
          usingsSyntax.Add(new UsingNamespaceOrTypeSyntax(type.FullName.ReplaceDot(), false));
        }
      }
      if (outs.Count > 0) {
       var group = outs.GroupBy(i => i.Type.GetFullNamespace());
        foreach (var g in group) {
          var ns = new NamespaceSyntax(g.Key);
          ns.AddRange(g.Select(i => i.Forward));
          CompilationUnit.HeadStatements.Add(ns);
        }
      }
    }

    internal void Write(string outDir) {
      CppRenderer rener = new CppRenderer(root_, outDir);
      CompilationUnit.Render(rener);
    }

    private StatementSyntax GetForwardMacroSyntax(ITypeDefinition type, out ITypeDefinition forwardType) {
      var multiType = Generator.GetMultiGenericFirstType(type, out int genericCount);
      if (multiType != null) {
        forwardType = multiType;
        return type.GetForwardStatement(genericCount);
      }
      forwardType = type;
      return type.GetForwardStatement();
    }

    internal void AddHeadReference(ITypeDefinition type, bool isForward) {
      if (headReferences_.ContainsKey(type)) {
        var prevIsForward = headReferences_[type];
        if (prevIsForward && !isForward) {
          headReferences_[type] = false;
        }
      } else {
        headReferences_.Add(type, isForward);
      }
    }

    internal void AddSrcReference(ITypeDefinition type) {
      if (!headReferences_.ContainsKey(type)) {
        srcReferences_.Add(type);
      }
    }
  }
}
