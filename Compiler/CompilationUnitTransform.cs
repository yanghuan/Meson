using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class ReferencePackage {
    public HashSet<string> HeadIncludes = new HashSet<string>();
    public HashSet<string> HeadUsings = new HashSet<string>();
    public HashSet<string> SrcIncludes = new HashSet<string>();
    public Dictionary<ITypeDefinition, StatementSyntax> Forwards = new Dictionary<ITypeDefinition, StatementSyntax>();
    public HashSet<ITypeDefinition> ImportTypes = new HashSet<ITypeDefinition>(TypeDefinitionEqualityComparer.Default);
  }

  internal sealed class CompilationUnitTransform {
    public AssemblyTransform AssemblyTransform { get; }
    public SyntaxGenerator Generator => AssemblyTransform.Generator;
    public CompilationUnitSyntax CompilationUnit { get; } = new CompilationUnitSyntax();
    private readonly Dictionary<ITypeDefinition, bool> headReferences_ = new Dictionary<ITypeDefinition, bool>(TypeDefinitionEqualityComparer.Default);
    private readonly HashSet<ITypeDefinition> srcReferences_ = new HashSet<ITypeDefinition>(TypeDefinitionEqualityComparer.Default);
    private readonly ITypeDefinition root_;
    private readonly Dictionary<ISymbol, NestedCycleRefTypeNameSyntax> nestedCycleRefNames_ = new Dictionary<ISymbol, NestedCycleRefTypeNameSyntax>();
    private readonly Dictionary<ITypeDefinition, SymbolNameSyntax> typeBaseNames_ = new Dictionary<ITypeDefinition, SymbolNameSyntax>(TypeDefinitionEqualityComparer.Default);

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
      if (IsSrcExists) {
        CompilationUnit.AddSrcStatement(srcUsingsSyntax);
      }

      var typeDefinition = new TypeDefinitionTransform(this, classNamespace, types);
      if (root_.Kind == TypeKind.Enum) {
        rootNamespace.AddRange(classNamespace.Statements);
        CompilationUnit.AddEnumHeadInclude();
      } else {
        var info = FillHeadReferences();
        CompilationUnit.AddHeadIncludes(info.HeadIncludes.OrderBy(i => i));
        headUsingsSyntax.AddRange(info.HeadUsings.OrderBy(i => i).Select(i => new UsingNamespaceOrTypeSyntax(i)));
        AddForwards(rootNamespace, info.Forwards);
        rootNamespace.Add(classNamespace);
        AddTypeUsingDeclaration(rootNamespace, classNamespace, typeDefinition, types);
        if (IsSrcExists) {
          CompilationUnit.AddReferencesIncludes(root_.Name, info.SrcIncludes.OrderBy(i => i));
          CompilationUnit.AddSrcReferencesIncludes(srcReferences_.Select(i => i.GetReferenceIncludeString(true)).OrderBy(i => i));
          srcUsingsSyntax.AddRange(srcReferences_.Where(i => !root_.IsNamespaceContain(i)).Select(i => i.GetFullNamespace(true, root_, true)).Distinct().OrderBy(i => i).Select(i => new UsingNamespaceOrTypeSyntax(i)));
          if (!srcUsingsSyntax.IsEmpty) {
            srcUsingsSyntax.Add(BlankLinesStatement.One);
          }
        }
        CheckRefactorNames(headUsingsSyntax, info.ImportTypes);
      }
      CompilationUnit.AddNamespaceClose();
    }

    private bool IsSrcExists {
      get {
        if (root_.Kind == TypeKind.Enum) {
          return false;
        }

        if (root_.Kind == TypeKind.Interface) {
          bool hasBody = root_.Methods.Any(i => i.HasBody);
          return hasBody;
        }

        return true;
      }
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

    private ReferencePackage FillHeadReferences() {
      var info = new ReferencePackage();
      FillCurrentImportTypes(info.ImportTypes);
      foreach (var (reference, isForward) in headReferences_) {
        if (isForward) {
          var forward = GetForwardMacroSyntax(reference, out var forwardType);
          info.Forwards[forwardType] = forward;
          info.SrcIncludes.Add(reference.GetReferenceIncludeString(true));
        } else {
          info.HeadIncludes.Add(reference.GetReferenceIncludeString());
          info.SrcIncludes.Add(reference.GetReferenceIncludeString(true));
        }
        if (Generator.TryGetReferenceUsing(reference, root_, info, out string usingNamespace)) {
          info.HeadUsings.Add(usingNamespace);
        }
      }
      return info;
    }

    private void AddTypeUsingDeclaration(NamespaceSyntax rootNamespace, NamespaceSyntax classNamespace, TypeDefinitionTransform typeDefinition, IEnumerable<ITypeDefinition> types) {
      IdentifierSyntax name = root_.Name;
      ExpressionSyntax type = classNamespace.Name.TwoColon(name);
      TemplateSyntax template;
      if (root_.IsArrayType() || typeDefinition.IsMulti) {
        type = new GenericIdentifierSyntax(type, IdentifierSyntax.TVariadic);
        template = new TemplateSyntax(IdentifierSyntax.VariadicT);
      } else {
        template = root_.GetTemplateSyntax();
        if (template != null) {
          type = new GenericIdentifierSyntax(type, template.TypeNames);
        }
      }

      var usingDeclaration = new UsingDeclarationSyntax(name, type) { Template = template };
      rootNamespace.Add(usingDeclaration);
      switch (root_.KnownTypeCode) {
        case KnownTypeCode.Object: {
          var objectType = new ClassSyntax(root_.Name.FirstCharLow(), true);
          objectType.Bases.Add(new BaseSyntax(root_.Name.AsIdentifier().WithIn()));
          objectType.Add(new FieldDefinitionSyntax(IdentifierSyntax.TypeCode, IdentifierSyntax.code, true, Accessibility.Public.ToTokenString()) {
            IsConstexpr = true,
            ConstantValue = IdentifierSyntax.TypeCode.TwoColon(root_.Kind.ToString()),
          });
          rootNamespace.Add(objectType);
          break;
        }
        case KnownTypeCode.ValueType: {
          var valueType = new ClassSyntax(root_.Name.FirstCharLow(), true) {
            Template = new TemplateSyntax(
            TemplateTypenameSyntax.T,
            new TemplateTypenameSyntax(IdentifierSyntax.N, IdentifierSyntax.TypeCode.TwoColon(TypeKind.Struct.ToString())) { ClassToken = IdentifierSyntax.TypeCode })
          };
          var baseType = IdentifierSyntax.Meson.TwoColon(valueType.Name).Generic(IdentifierSyntax.T, name.WithIn(), IdentifierSyntax.N);
          valueType.Bases.Add(new BaseSyntax(baseType));
          valueType.Add(new FieldDefinitionSyntax(IdentifierSyntax.TypeCode, IdentifierSyntax.code, true, Accessibility.Public.ToTokenString()) {
            IsConstexpr = true,
            ConstantValue = IdentifierSyntax.N,
          });
          rootNamespace.Add(valueType);
          break;
        }
        case KnownTypeCode.Type: {
          var method = new MethodDefinitionSyntax(IdentifierSyntax.Typeof, null, root_.Name) {
            Template = TemplateSyntax.T,
            Body = new BlockSyntax(),
          };
          method.Body.Add(IdentifierSyntax.Nullptr.Return());
          rootNamespace.Add(method);
          break;
        }
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

    private void AddForwards(NamespaceSyntax rootNamespace, Dictionary<ITypeDefinition, StatementSyntax> forwards) {
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
            bool hasConstDefaultValue = args.Symbol is IParameter parameter && parameter.HasConstantValueInSignature;
            AddHeadReference(referenceTypeDefinition, !hasConstDefaultValue);
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
        string name = type.Name;
        Utils.CheckBadName(ref name);
        return name;
      }

      var typeDefinition = type.GetDefinition();
      if (typeDefinition == null) {
        return type.Name;
      }

      var expression = typeBaseNames_.GetOrDefault(typeDefinition);
      if (expression == null) {
        expression = new SymbolNameSyntax(type.Name);
        typeBaseNames_.Add(typeDefinition, expression);
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
              if (arrayDefinition != args.Definition.GetReferenceType()) {
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
        case TypeKind.NInt: {
            args.Type = Generator.IntPtrTypeDefinition;
            break;
          }
        case TypeKind.NUInt: {
            args.Type = Generator.UIntPtrTypeDefinition;
            break;
          }
        case TypeKind.FunctionPointer: {
            var functionPointerType = (FunctionPointerType)args.Type;
            var returnType = GetTypeName(args.With(functionPointerType.ReturnType, true));
            var parameterTypes = functionPointerType.ParameterTypes.Select(i => GetTypeName(args.With(i, true)));
            var pointer = new FunctionPointerExpressionSyntax(returnType, parameterTypes);
            return IdentifierSyntax.FunctionPointer.Generic(pointer);
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
      if (args.Type.TypeArguments.Count > 0 || args.Type.Kind == TypeKind.Tuple) {
        var typeArguments = args.Type.GetTypeArguments().Select(i => GetTypeName(args.With(i, args.IsForward || i.IsRefType(), i))).ToList();
        if (typeArguments.Count > 0) {
          CheckTupleTypeArgumentCount(args.Type, typeName, ref typeArguments);
          typeName = new GenericIdentifierSyntax(typeName, typeArguments);
          isGeneric = true;
        }
      }

      var typeDefinition = args.Type.GetDefinition();
      if (typeDefinition != null) {
        var declaringType = typeDefinition.DeclaringTypeDefinition;
        if (declaringType != null && (args.Definition == null || !AssemblyTransform.IsInternalMemberType(typeDefinition, args.Definition))) {
          var outTypeName = GetTypeName(args.With(args.Type.DeclaringType, false));
          if (declaringType.GetDefinition().IsRefType()) {
            outTypeName = outTypeName.WithIn();
          }
          return outTypeName.TwoColon(typeName);
        }
      }

      if (!isGeneric && typeDefinition != null) {
        if (Generator.IsVoidGenericType(typeDefinition)) {
          typeName = typeName.Generic();
        } else if (args.Definition != null && typeDefinition.DeclaringTypeDefinition == null) {
          var nestedTypes = args.Definition.NestedTypes.Concat(args.Definition.GetAllBaseTypes().SelectMany(i => i.NestedTypes.Where(i => i.Accessibility != Accessibility.Private)));
          var nestedType = nestedTypes.FirstOrDefault(i => i.Name == typeDefinition.Name);
          if (nestedType != null && !nestedType.EQ(typeDefinition)) {
            if (args.IsInHead && typeDefinition.EQ(args.Definition)) {
              typeName = typeDefinition.Name.WithNamespace().AsIdentifier().TwoColon(typeName);
            } else {
              typeName = typeName.WithFullName(typeDefinition, args.Definition);
            }
          }
        }
      }
      return typeName;
    }

    private void CheckTupleTypeArgumentCount(IType type, ExpressionSyntax typeName, ref List<ExpressionSyntax> typeArguments) {
      const int kMaxTypeArgumentCount = 8;
      if (type.Kind == TypeKind.Tuple && typeArguments.Count > kMaxTypeArgumentCount) {
        var newTypeArguments = new List<ExpressionSyntax>(kMaxTypeArgumentCount);
        newTypeArguments.AddRange(typeArguments.Take(kMaxTypeArgumentCount - 1));
        var remians = typeArguments.Skip(kMaxTypeArgumentCount - 1).ToList();
        CheckTupleTypeArgumentCount(type, typeName, ref remians);
        newTypeArguments.Add(typeName.Generic(remians));
        typeArguments = newTypeArguments;
      }
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

    private void CheckRefactorNames(StatementListSyntax headUsingsSyntax, HashSet<ITypeDefinition> importTypes) {
      HashSet<string> usedNames = new HashSet<string>() { root_.Name };
      var nameGroups = importTypes.GroupBy(i => i.Name).ToDictionary(i => i.Key, i => i.ToList());
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
        Contract.Assert(value != null);
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
