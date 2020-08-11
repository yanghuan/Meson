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
    private readonly Dictionary<ITypeDefinition, bool> headReferences_ = new Dictionary<ITypeDefinition, bool>(TypeDefinitionEqualityComparer.Default);
    private readonly HashSet<ITypeDefinition> srcReferences_ = new HashSet<ITypeDefinition>(TypeDefinitionEqualityComparer.Default);
    private readonly ITypeDefinition root_;
    private readonly Dictionary<ISymbol, NestedCycleRefTypeNameSyntax> nestedCycleRefNames_ = new Dictionary<ISymbol, NestedCycleRefTypeNameSyntax>();
    private readonly Dictionary<ITypeDefinition, SymbolNameSyntax> typeBaseNames_ = new Dictionary<ITypeDefinition, SymbolNameSyntax>(TypeDefinitionEqualityComparer.Default);
    //private readonly Dictionary<string, HashSet<ITypeDefinition>> sameBaseNames_ = new Dictionary<string, HashSet<ITypeDefinition>>();
    //private readonly HashSet<ITypeDefinition> importTypes_ = new HashSet<ITypeDefinition>(TypeDefinitionEqualityComparer.Default);

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
      if (root_.Kind == TypeKind.Enum) {
        rootNamespace.AddRange(classNamespace.Statements);
        CompilationUnit.AddEnumHeadInclude();
      } else {
        var (headIncludes, headUsings, srcIncludes, forwards, importTypes) = FillHeadReferences();
        CompilationUnit.AddHeadIncludes(headIncludes.OrderBy(i => i));
        headUsingsSyntax.AddRange(headUsings.OrderBy(i => i).Select(i => new UsingNamespaceOrTypeSyntax(i)));
        AddForwards(rootNamespace, forwards, headUsingsSyntax);
        rootNamespace.Add(classNamespace);
        AddTypeUsingDeclaration(rootNamespace, classNamespace, typeDefinition, types);
        if (root_.Kind != TypeKind.Interface) {
          CompilationUnit.AddReferencesIncludes(root_.Name, srcIncludes.OrderBy(i => i));
          CompilationUnit.AddSrcReferencesIncludes(srcReferences_.Select(i => i.GetReferenceIncludeString(true)).OrderBy(i => i));
          srcUsingsSyntax.AddRange(srcReferences_.Where(i => !root_.IsNamespaceContain(i)).Select(i => i.GetFullNamespace(true, root_)).Distinct().OrderBy(i => i).Select(i => new UsingNamespaceOrTypeSyntax(i)));
        }
        CheckRefactorNames(headUsingsSyntax, srcUsingsSyntax, importTypes);
      }
      CompilationUnit.AddNamespaceClose();
    }

    private void FillCurrentImportTypes(HashSet<ITypeDefinition> importTypes) {
      var ns = root_.GetFullNamespace();
      foreach (string i in ns.GetAllNamespaces(Tokens.TwoColon)) {
        var types = Generator.GetTypesInNamespace(i);
        if (types != null) {
          importTypes.UnionWith(types);
        }
      }
    }

    private (HashSet<string>, HashSet<string>, HashSet<string>, Dictionary<ITypeDefinition, StatementSyntax>, HashSet<ITypeDefinition>) FillHeadReferences() {
      HashSet<ITypeDefinition> importTypes = new HashSet<ITypeDefinition>(TypeDefinitionEqualityComparer.Default);
      FillCurrentImportTypes(importTypes);
      var headIncludes = new HashSet<string>();
      var headUsings = new HashSet<string>();
      var srcIncludes = new HashSet<string>();
      var forwards = new Dictionary<ITypeDefinition, StatementSyntax>();
      foreach (var (reference, isForward) in headReferences_) {
        if (isForward) {
          var forward = GetForwardMacroSyntax(reference, out var forwardType);
          forwards[forwardType] = forward;
          srcIncludes.Add(reference.GetReferenceIncludeString(true));
        } else {
          headIncludes.Add(reference.GetReferenceIncludeString());
          srcIncludes.Add(reference.GetReferenceIncludeString(true));
        }
        if(Generator.TryGetReferenceUsing(reference, root_, out string usingNamespace, importTypes)) {
          headUsings.Add(usingNamespace);
        }
      }
      return (headIncludes, headUsings, srcIncludes, forwards, importTypes);
    }

    private void AddTypeUsingDeclaration(NamespaceSyntax rootNamespace, NamespaceSyntax classNamespace, TypeDefinitionTransform typeDefinition, IEnumerable<ITypeDefinition> types) {
      IdentifierSyntax name = root_.Name;
      ExpressionSyntax type = classNamespace.Name.TwoColon(name);
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
      if (root_.KnownTypeCode == KnownTypeCode.ValueType) {
        ClassSyntax valueType = new ClassSyntax(root_.Name.FirstCharLow(), true) { Template = TemplateSyntax.T };
        var baseType = IdentifierSyntax.Meson.TwoColon(root_.Name).Generic(IdentifierSyntax.T, name.WithIn());
        valueType.Bases.Add(new BaseSyntax(baseType));
        rootNamespace.Add(valueType);
      }
    }

    private static void SortForwards(List<(ITypeDefinition Type, StatementSyntax Forward)> list) {
      list.Sort((x, y) => {
        bool isEnumOfX = x.Type.Kind == TypeKind.Enum;
        bool isEnumOfY = y.Type.Kind == TypeKind.Enum;
        if (isEnumOfX) {
          if (!isEnumOfY) {
            return -1;
          } else {
            goto Out;
          }
        } else if (isEnumOfY) {
          return 1;
        }

      Out:
        return x.Type.Name.CompareTo(y.Type.Name);
      });
    }

    private void AddForwards(NamespaceSyntax rootNamespace, Dictionary<ITypeDefinition, StatementSyntax> forwards, StatementListSyntax usingsSyntax) {
      var curs = new List<(ITypeDefinition Type, StatementSyntax Forward)>();
      var outs = new List<(ITypeDefinition Type, StatementSyntax Forward)>();
      foreach (var (type, forward) in forwards) {
        if (root_.IsSameNamespace(type)) {
          curs.Add((type, forward));
        } else {
          outs.Add((type, forward));
        }
      }
      if (curs.Count > 0) {
        SortForwards(curs);
        rootNamespace.AddRange(curs.Select(i => i.Forward));
      }
      if (outs.Count > 0) {
        var group = outs.GroupBy(i => i.Type.GetFullNamespace());
        foreach (var g in group) {
          var list = g.ToList();
          SortForwards(list);
          var ns = new NamespaceSyntax(g.Key);
          ns.AddRange(list.Select(i => i.Forward));
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

    private void AddSrcReference(IType type, ITypeDefinition definition) {
      var referenceType = type.GetReferenceType();
      if (referenceType != null) {
        var rootType = definition?.GetReferenceType();
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
        //sameBaseNames_.TryAdd(name, typeDefinition, TypeDefinitionEqualityComparer.Default);
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
            return new RefExpressionSyntax(elementType);
          }
      }

      if (args.IsInHead) {
        var result = AddHeadReference(args);
        if (result != null) {
          return result;
        }
      } else {
        AddSrcReference(args.Type, args.Definition);
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

      var typeDefinition = args.Type.GetDefinition();
      if (typeDefinition != null) {
        var declaringType = typeDefinition.DeclaringTypeDefinition;
        if (declaringType != null && (args.Definition == null || !AssemblyTransform.IsInternalMemberType(typeDefinition, args.Definition))) {
          var outTypeName = GetTypeName(args.With(declaringType, false));
          if (declaringType.GetDefinition().IsRefType()) {
            outTypeName = outTypeName.WithIn();
          }
          return outTypeName.TwoColon(typeName);
        }
      }

      if (!isGeneric && typeDefinition != null) {
        if (Generator.IsVoidGenericType(typeDefinition)) {
          typeName = typeName.Generic();
        } else if (args.IsInHead) {
          var definitionBaseType = args.Definition.DirectBaseTypes.FirstOrDefault()?.GetDefinition();
          if (definitionBaseType != null && definitionBaseType.KnownTypeCode == KnownTypeCode.None) {
            var sameNameBaseType = definitionBaseType.NestedTypes.FirstOrDefault(i => i.Name == typeDefinition.Name);
            if (sameNameBaseType != null && sameNameBaseType != typeDefinition) {
              typeName = typeDefinition.Name.WithNamespace().Identifier().TwoColon(typeName);
            }
          }
        }
      }
      return typeName;
    }

    internal NestedCycleRefTypeNameSyntax GetNestedCycleRefTypeName(ISymbol symbol) {
      return nestedCycleRefNames_.GetOrDefault(symbol);
    }

    private static UsingDeclarationSyntax GetUsingDeclarationSyntax(IdentifierSyntax name, ITypeDefinition type, ITypeDefinition definition) {
      var template = type.GetTemplateSyntax();
      ExpressionSyntax typeFullName = type.GetFullName(definition);
      if (template != null) {
        typeFullName = new GenericIdentifierSyntax(typeFullName, template.TypeNames);
      }
      return new UsingDeclarationSyntax(name, typeFullName) { Template = template };
    }

    private void CheckRefactorNames(StatementListSyntax headUsingsSyntax, StatementListSyntax srcUsingsSyntax, HashSet<ITypeDefinition> importTypes) {
      var nameGroups = importTypes.GroupBy(i => i.Name).ToDictionary(i => i.Key, i => i.ToList());
      HashSet<string> usedNames = new HashSet<string>();
      foreach (var referenceType in headReferences_.Keys) {
        var sameNameTypes = nameGroups.GetOrDefault(referenceType.Name);
        if (sameNameTypes != null && sameNameTypes.Count > 1) {
          int count = 0;
          while (true) {
            string name = referenceType.Name.GetNewIdentifierName(count);
            if (usedNames.Add(name)) {
              headUsingsSyntax.Add(GetUsingDeclarationSyntax(name, referenceType, root_));
              if (count != 0) {
                typeBaseNames_[referenceType].Update(name);
              }
              break;
            }
            ++count;
          }
        }
      }

#if false
      foreach (var set in sameBaseNames_.Values) {
        if (set.Count > 1) {
          set.RemoveWhere(Generator.IsVoidGenericType);
          if (set.Count > 0) {
            var types = set.ToList();
            types.Sort((x, y) => {
              if (x.TypeParameterCount > 0 && y.TypeParameterCount == 0) {
                return -1;
              }
              return x.FullName.CompareTo(y.FullName);
            });
            int index = 0;
            foreach (var type in types) {
              var name = typeBaseNames_[type];
              if (index == 0) {
                headUsingsSyntax.Add(GetUsingDeclarationSyntax(name.NameExpression, type, root_));
              } else {
                IdentifierSyntax newName = type.Name + index;
                headUsingsSyntax.Add(GetUsingDeclarationSyntax(newName, type, root_));
                name.Update(newName);
              }
              ++index;
            }
          }
        } else {
          var type = set.First();
          var types = groups.GetOrDefault(type.Name);
        }
      }
#endif
    }
   
  }

  internal struct TypeNameArgs {
    private IType type_;
    public ITypeDefinition Definition;
    public bool IsForward;
    public IType Original;
    public bool IsInHead;
    public ISymbol Symbol;

    public IType Type {
      get {
        return type_;
      }
      set {
        type_ = value.Original();
      }
    }

    public TypeNameArgs With(IType type, bool isForward) {
      var result = this;
      result.Type = type;
      result.IsForward = isForward;
      return result;
    }

    public TypeNameArgs With(IType type, bool isForward, IType original) {
      var result = this;
      result.Type = type;
      result.IsForward = isForward;
      result.Original = original;
      return result;
    }
  }
}
