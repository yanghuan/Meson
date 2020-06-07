using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class CompilationUnitTransform {
    public AssemblyTransform AssemblyTransform { get; }
    public SyntaxGenerator Generator => AssemblyTransform.Generator;
    private readonly CompilationUnitSyntax compilationUnit_ = new CompilationUnitSyntax();
    private readonly Dictionary<ITypeDefinition, bool> references_ = new Dictionary<ITypeDefinition, bool>();
    private readonly Dictionary<ITypeDefinition, StatementSyntax> forwards_ = new Dictionary<ITypeDefinition, StatementSyntax>();
    private readonly ITypeDefinition root_;

    public CompilationUnitTransform(AssemblyTransform assemblyTransform, List<ITypeDefinition> types) {
      AssemblyTransform = assemblyTransform;
      root_ = types.First();
      VisitCompilationUnit(types);
    }

    private void VisitCompilationUnit(IEnumerable<ITypeDefinition> types) {
      var rootNamespace = compilationUnit_.AddNamespace(root_.Namespace);
      var classNamespace = new NamespaceSyntax($"{root_.Name}Namespace");
      var usingsSyntax = new StatementListSyntax();
      classNamespace.Add(usingsSyntax);

      var typeDefinition = new TypeDefinitionTransform(this, classNamespace, types);
      if (root_.Kind != TypeKind.Enum) {
        HashSet<string> includes = new HashSet<string>();
        HashSet<string> usings = new HashSet<string>();
        foreach (var (reference, isForward) in references_) {
          if (isForward) {
            AddForward(reference);
          } else {
            includes.Add(reference.GetReferenceIncludeString());
          }
          if (!root_.IsNamespaceContain(reference)) {
            usings.Add(reference.Namespace);
          }
        }
        compilationUnit_.AddHeadIncludes(includes.OrderBy(i => i));
        usingsSyntax.Statements.AddRange(usings.OrderBy(i => i).Select(GetUsingNamespaceSyntax));
        AddForwards(rootNamespace);
        rootNamespace.Add(classNamespace);
        AddTypeUsingDeclaration(rootNamespace, classNamespace, typeDefinition, types);
        if (root_.Kind != TypeKind.Interface) {
          compilationUnit_.AddSrcInclude(root_.GetIncludeString(), false);
          compilationUnit_.AddSrcStatement(BlankLinesStatement.One);
        }
      } else {
        rootNamespace.AddRange(classNamespace.Statements);
        if (!root_.EnumUnderlyingType.IsInt32()) {
          compilationUnit_.AddCstdintHeadInclude();
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

    private void AddForwards(NamespaceSyntax rootNamespace) {
      var outs = new List<(ITypeDefinition Type, StatementSyntax Forward)>();
      foreach (var (type, forward) in forwards_) {
        if (root_.Namespace == type.Namespace) {
          rootNamespace.Add(forward);
        } else {
          outs.Add((type, forward));
        }
      }
      if (outs.Count > 0) {
       var group = outs.GroupBy(i => i.Type.Namespace);
        foreach (var g in group) {
          var ns = new NamespaceSyntax(g.Key);
          ns.AddRange(g.Select(i => i.Forward));
          compilationUnit_.HeadStatements.Add(ns);
        }
      }
    }

    internal void Write(string outDir) {
      CppRenderer rener = new CppRenderer(root_, outDir);
      compilationUnit_.Render(rener);
    }

    private static UsingNamespaceSyntax GetUsingNamespaceSyntax(string name) {
      return new UsingNamespaceSyntax(name.Replace(Tokens.Dot, Tokens.TwoColon));
    }

    private void AddForward(ITypeDefinition type) {
      var multiType = Generator.GetMultiGenericFirstType(type, out int genericCount);
      if (multiType != null) {
        forwards_[multiType] = multiType.GetForwardStatement(genericCount);
      } else {
        forwards_[type] = type.GetForwardStatement();
      }
    }

    internal void AddReference(ITypeDefinition type, bool isForward) {
      if (references_.ContainsKey(type)) {
        var prevIsForward = references_[type];
        if (prevIsForward && !isForward) {
          references_[type] = false;
        }
      } else {
        references_.Add(type, isForward);
      }
    }
  }
}
