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
    private readonly Dictionary<ISymbol, NestedCycleRefTypeNameSyntax> nestedCycleRefNames_ = new Dictionary<ISymbol, NestedCycleRefTypeNameSyntax>();
    private readonly Dictionary<ITypeDefinition, SymbolNameSyntax> typeBaseNames_ = new Dictionary<ITypeDefinition, SymbolNameSyntax>();
    private readonly Dictionary<string, HashSet<ITypeDefinition>> sameBaseNames_ = new Dictionary<string, HashSet<ITypeDefinition>>();
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
      CheckRefactorNames();
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

    private void AddHeadReference(ITypeDefinition type, bool isForward) {
      if (headReferences_.ContainsKey(type)) {
        var prevIsForward = headReferences_[type];
        if (prevIsForward && !isForward) {
          headReferences_[type] = false;
        }
      } else {
        headReferences_.Add(type, isForward);
      }
    }

    private void AddSrcReference(ITypeDefinition type) {
      if (!headReferences_.ContainsKey(type)) {
        srcReferences_.Add(type);
      }
    }

    private ExpressionSyntax AddHeadReference(in TypeNameArgs args) {
      var referenceType = args.Type.GetReferenceType();
      if (referenceType != null) {
        var rootType = args.Definition.GetReferenceType();
        if (!Generator.IsCompilationUnitIn(rootType, referenceType)) {
          var referenceTypeDefinition = referenceType.GetDefinition();
          if (referenceTypeDefinition.Kind == TypeKind.Enum) {
            AddHeadReference(referenceTypeDefinition, true);
          } else {
            if (args.Type.DeclaringType != null) {
              bool checkCycleReference = args.Type.IsReferenceType == true || args.Original.Kind == TypeKind.Pointer;
              if (checkCycleReference) {
                bool isExists = referenceTypeDefinition.IsMemberTypeExists(rootType.GetDefinition(), true);
                if (isExists) {
                  string shortName = args.Type.GetShortName();
                  NestedCycleRefTypeNameSyntax nestedCycleName;
                  if (args.Original.Kind == TypeKind.Pointer) {
                    nestedCycleName = new NestedCycleRefTypeNameSyntax(shortName, IdentifierSyntax.Void);
                  } else {
                    var rootObject = referenceTypeDefinition.GetRootObjectDefinition();
                    AddHeadReference(rootObject, true);
                    nestedCycleName = new NestedCycleRefTypeNameSyntax(shortName);
                  }
                  nestedCycleRefNames_[args.Symbol] = nestedCycleName;
                  return nestedCycleName;
                }
              }
            }
            AddHeadReference(referenceTypeDefinition, args.IsForward);
          }
        }
      }
      return null;
    }

    private void AddSrcReference(in TypeNameArgs args) {
      var referenceType = args.Type.GetReferenceType();
      if (referenceType != null) {
        var rootType = args.Definition?.GetReferenceType();
        if (rootType == null || !Generator.IsCompilationUnitIn(rootType, referenceType)) {
          var referenceTypeDefinition = referenceType.GetDefinition();
          AddSrcReference(referenceTypeDefinition);
        }
      }
    }

    private ExpressionSyntax GetTypeBaseName(IType type) {
      if (type.DeclaringType != null) {
        return type.Name;
      }

      var typeDefinition = type.GetDefinition();
      if (typeDefinition == null) {
        return type.Name;
      }

      var expression = typeBaseNames_.GetOrDefault(typeDefinition);
      if (expression == null) {
        string name = type.Name;
        expression = new SymbolNameSyntax(name);
        typeBaseNames_.Add(typeDefinition, expression);
        sameBaseNames_.TryAdd(name, typeDefinition);
      }
      return expression;
    }

    internal ExpressionSyntax GetTypeName(TypeNameArgs args) {
      switch (args.Type.Kind) {
        case TypeKind.Void: {
            return IdentifierSyntax.Void;
          }
        case TypeKind.Array: {
            ArrayType arrayType = (ArrayType)args.Type;
            if (args.IsInHead) {
              var arrayDefinition = arrayType.DirectBaseTypes.First().GetDefinition();
              if (arrayDefinition != args.Definition) {
                AddHeadReference(arrayDefinition, args.IsForward);
              }
            }
            var elementType = GetTypeName(args.With(arrayType.ElementType, true));
            return new GenericIdentifierSyntax((IdentifierSyntax)args.Type.Kind.ToString(), elementType);
          }
        case TypeKind.Pointer: {
            PointerType pointerType = (PointerType)args.Type;
            var elementType = GetTypeName(args.With(pointerType.ElementType, true));
            return new PointerIdentifierSyntax(elementType);
          }
        case TypeKind.ByReference: {
            ByReferenceType byReference = (ByReferenceType)args.Type;
            var elementType = GetTypeName(args.With(byReference.ElementType, true));
            return new RefIdentifierSyntax(elementType);
          }
      }

      if (args.IsInHead) {
        var result = AddHeadReference(args);
        if (result != null) {
          return result;
        }
      } else {
        AddSrcReference(args);
      }

      ExpressionSyntax typeName = GetTypeBaseName(args.Type);
      bool isGeneric = false;
      if (args.Type.TypeArguments.Count > 0) {
        var typeArguments = args.Type.GetTypeArguments().Select(i => GetTypeName(args.With(i, args.IsForward || i.IsRefType(), i))).ToList();
        if (typeArguments.Count > 0) {
          typeName = new GenericIdentifierSyntax(typeName, typeArguments);
          isGeneric = true;
        }
      }

      if (args.Type.DeclaringType != null && (args.Definition == null || !AssemblyTransform.IsInternalMemberType(args.Type, args.Definition))) {
        var outTypeName = GetTypeName(args.With(args.Type.DeclaringType, false));
        if (args.Type.DeclaringType.GetDefinition().IsRefType()) {
          outTypeName = outTypeName.TwoColon(IdentifierSyntax.In);
        }
        return outTypeName.TwoColon(typeName);
      }

      if (!isGeneric) {
        var definition = args.Type.GetDefinition();
        if (definition != null) {
          if (Generator.IsVoidGenericType(definition)) {
            typeName = new GenericIdentifierSyntax(typeName);
          }
        }
      }

      return typeName;
    }

    internal NestedCycleRefTypeNameSyntax GetNestedCycleRefTypeName(ISymbol symbol) {
      return nestedCycleRefNames_.GetOrDefault(symbol);
    }

    private void CheckRefactorNames() {
      foreach (var set in sameBaseNames_.Values) {
        if (set.Count > 1) {
          set.RemoveWhere(Generator.IsVoidGenericType);
          if (set.Count > 0) {

          }
        }
      }
    }
  }

  internal struct TypeNameArgs {
    public IType Type;
    public ITypeDefinition Definition;
    public bool IsForward;
    public IType Original;
    public bool IsInHead;
    public ISymbol Symbol;

    public TypeNameArgs With(IType type, bool isForward) {
      return new TypeNameArgs() {
        Type = type,
        Definition = Definition,
        IsForward = isForward,
        Original = Original,
        IsInHead = IsInHead,
        Symbol = Symbol,
      };
    }

    public TypeNameArgs With(IType type, bool isForward, IType original) {
      return new TypeNameArgs() {
        Type = type,
        Definition = Definition,
        IsForward = isForward,
        Original = original,
        IsInHead = IsInHead,
        Symbol = Symbol,
      };
    }
  }
}
