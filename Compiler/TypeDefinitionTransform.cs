using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.IO;
using System.Text;
using System.Linq;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal class TypeDefinitionTransform {
    public CompilationUnitTransform CompilationUnit { get; }
    public AssemblyTransform AssemblyTransform => CompilationUnit.AssemblyTransform;
    public SyntaxGenerator Generator => AssemblyTransform.Generator;
    private readonly BlockSyntax parent_;
    private readonly List<ITypeDefinition> types_;
    private readonly TypeDefinitionTransform parentTransform_;
    private readonly Dictionary<ITypeDefinition, ITypeDefinition> nestedCycleTypes_ = new Dictionary<ITypeDefinition, ITypeDefinition>();
    private readonly Dictionary<ISymbol, NestedCycleRefTypeNameSyntax> nestedCycleRefNames_ = new Dictionary<ISymbol, NestedCycleRefTypeNameSyntax>();

    public bool IsMulti => types_.Count > 1;
    public bool HasRef => types_.Exists(i => i.IsRefType());
    private ITypeDefinition Root => types_.First();

    public TypeDefinitionTransform(CompilationUnitTransform compilationUnit, BlockSyntax parent, IEnumerable<ITypeDefinition> types, TypeDefinitionTransform parentTransform = null) {
      CompilationUnit = compilationUnit;
      types_ = types.ToList();
      parent_ = parent;
      parentTransform_ = parentTransform;
      Visit();
    }

    private void Visit() {
      if (IsMulti) {
        int typeParameterCount = types_.Last().TypeParameterCount + 1;
        ClassSyntax node = new ClassSyntax(Root.Name, Root.Kind == TypeKind.Struct) { 
          Template = typeParameterCount.GetVoidTemplate(),
          Kind = HasRef ? ClassKind.MultiRefForward : ClassKind.None,
        };
        parent_.Add(node);
      }

      foreach (var type in types_) {
        var referenceType = parentTransform_?.nestedCycleTypes_.GetOrDefault(type);
        if (referenceType != null) {
          var forward = referenceType.GetNestedForwardStatement();
          forward.AccessibilityToken = GetAccessibilityString(referenceType);
          parent_.Add(forward);
        }
        VisitTypeDefinition(type);
      }
    }

    private void VisitTypeDefinition(ITypeDefinition type) {
      switch (type.Kind) {
        case TypeKind.Enum: {
          VistEnum(type);
          break;
        }
        case TypeKind.Struct: {
          VisitStruct(type);
          break;
        }
        default: {
          VistClass(type);
          break;
        }
      }
    }

    private void VistEnum(ITypeDefinition type) {
      EnumSyntax node = new EnumSyntax(type.Name) { 
        AccessibilityToken = GetAccessibilityString(type),
        UnderlyingType = type.GetEnumUnderlyingTypeName(),
      };
      VisitEnumFields(type, node);
      parent_.Add(node);
    }

    private void VisitEnumFields(ITypeDefinition typeDefinition, EnumSyntax node) {
      foreach (var field in typeDefinition.Fields) {
        if (field.Name != "value__") {
          object v = field.GetConstantValue();
          // https://stackoverflow.com/questions/14695118/2147483648-0-returns-true-in-c
          if (v.Equals(int.MinValue)) {
            v = $"{int.MinValue + 1} - 1";
          }
          var fieldName = Generator.GetMemberName(field);
          node.Add(new EnumFieldSyntax(fieldName, v.ToString()));
        }
      }
    }

    private void VisitStruct(ITypeDefinition type) {
      var template = type.GetTemplateSyntax();
      ClassSyntax node = new ClassSyntax(type.Name, true) {
        Template = template,
        Kind = GetClassKind(type),
        AccessibilityToken = GetAccessibilityString(type),
      };
      parent_.Add(node);
      VisitMembers(type, node);
    }

    private ClassKind GetClassKind(ITypeDefinition type) {
      if (IsMulti) {
        return types_.Exists(i => i.IsRefType()) ? ClassKind.MultiRef : ClassKind.Multi;
      }

      if (type.IsArrayType()) {
        return ClassKind.Array;
      }

      return type.IsRefType() ? ClassKind.Ref : ClassKind.None;
    }

    private void VistClass(ITypeDefinition type) {
      var template = type.GetTemplateSyntax();
      ClassSyntax node = new ClassSyntax(type.Name) {
        Template = template,
        Kind = GetClassKind(type),
        AccessibilityToken = GetAccessibilityString(type),
      };
      if (type.IsStringType() || type.IsObjectType()) {
        node.Bases.Add(new BaseSyntax(new MemberAccessExpressionSyntax(IdentifierSyntax.Meson, (IdentifierSyntax)type.Name.ToLower(), MemberAccessOperator.TwoColon)));
      }
      VisitMembers(type, node);
      parent_.Add(node);
    }

    private bool IsExportMethod(IMethod method) {
      if (IsMulti || method.IsConstructor || method.IsOperator) {
        return false;
      }

      if (method.TypeParameters.Count > 0 || method.TypeArguments.Count > 0) {
        return false;
      }

      if (method.Name.Contains('<')) {
        return false;
      }

      if (method.Name.Contains('.')) {
        return false;
      }

      if (method.ReturnType.Kind == TypeKind.ByReference) {
        return false;
      }

      return true;
    }

    private void VisitMethods(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var method in typeDefinition.Methods.Where(IsExportMethod)) {
        var parameters = method.Parameters.Select(i => GetParameterSyntax(i, method, typeDefinition)).ToList();  
        var methodName = Generator.GetMemberName(method);
        var returnType = GetRetuenTypeSyntax(method, typeDefinition);
        node.Statements.Add(new MethodDefinitionSyntax(returnType, methodName, parameters, method.IsStatic, method.Accessibility.ToTokenString()));
        if (typeDefinition.TypeParameterCount == 0) {
          new MethodTransform(this, method);
        }
      }
    }

    private ExpressionSyntax GetRetuenTypeSyntax(IMethod method, ITypeDefinition typeDefinition) {
      var returnType = GetTypeName(new TypeNameArgs { 
        Type = method.ReturnType,
        Definition = typeDefinition,
        IsForward = true,
        IsInHead = true,
        Original = method.ReturnType,
        Symbol = method,
      });
      CheckReturnTypeConflict(ref returnType, method.ReturnType.GetDefinition(), typeDefinition);
      return returnType;
    }

    private static void CheckReturnTypeConflict(ref ExpressionSyntax type, ITypeDefinition returnType, ITypeDefinition typeDefinition) {
      if (returnType != null) {
        foreach (var nestedType in typeDefinition.NestedTypes) {
          if (nestedType != returnType && nestedType.Name == returnType.Name) {
            type = type.WithFullName(returnType);
          }
        }
      }
    }

    private ParameterSyntax GetParameterSyntax(IParameter parameter, IMethod method, ITypeDefinition typeDefinition) {
      var type = GetTypeName(new TypeNameArgs { 
        Type = parameter.Type,
        Definition = typeDefinition,
        IsForward = true,
        IsInHead = true,
        Original = parameter.Type,
        Symbol = parameter,
      });
      CheckParameterTypeConflict(ref type, parameter, method, typeDefinition);
      var name = Generator.GetMemberName(parameter);
      return new ParameterSyntax(type, name);
    }

    public static void CheckParameterTypeConflict(ref ExpressionSyntax type, IParameter parameter, IMethod method, ITypeDefinition typeDefinition) {
      foreach (var m in typeDefinition.Methods) {
        if (m == method) {
          break;
        }
        if (m.Name == parameter.Type.Name) {
          type = type.WithFullName(parameter.Type);
          break;
        }
      }
    }

    private void VisitFields(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var field in typeDefinition.Fields) {
        if (!field.Name.StartsWith('<')) {
          ExpressionSyntax typeName = null;
          if (typeDefinition.Kind == TypeKind.Struct && !field.IsStatic && field.Type == typeDefinition) {
            string name = field.Type.GetInnerTypeName();
            if (name != null) {
              typeName = (IdentifierSyntax)name;
            }
          }
          if (typeName == null) {
            typeName = GetFieldTypeName(field, typeDefinition);
          }
          var fieldName = Generator.GetMemberName(field);
          node.Statements.Add(new FieldDefinitionSyntax(typeName, fieldName, field.IsStatic, field.Accessibility.ToTokenString()));
        }
      }
    }

    private ExpressionSyntax GetFieldTypeName(IField field, ITypeDefinition typeDefinition) {
      if (field.Type.Name.StartsWith('<')) {
        var attr = field.GetAttribute(KnownAttribute.FixedBuffer);
        if (attr != null) {
          var type = (IType)attr.FixedArguments[0].Value;
          int size = (int)attr.FixedArguments[1].Value;
          var name = GetTypeName(new TypeNameArgs { 
            Type = type,
            Definition = typeDefinition,
            IsForward = field.IsStatic,
            IsInHead = true,
            Original = type,
            Symbol = field,
          });
          return new GenericIdentifierSyntax(IdentifierSyntax.FixedBuffer, name, (IdentifierSyntax)size.ToString());
        }
      }

      var typeName = GetTypeName(new TypeNameArgs { 
        Type = field.Type,
        Definition = typeDefinition,
        IsForward = field.Type.IsRefType() || field.IsStatic,
        IsInHead = true,
        Original = field.Type,
        Symbol = field,
      });
      CheckFieldTypeConflict(ref typeName, field, typeDefinition);
      return typeName;
    }

    private void CheckFieldTypeConflict(ref ExpressionSyntax type, IField field, ITypeDefinition typeDefinition) {
      foreach (var m in typeDefinition.Methods) {
        if (m.Name == field.Type.Name) {
          type = type.WithFullName(field.Type);
          return;
        }
      }

      foreach (var f in typeDefinition.Fields) {
        if (f == field) {
          break;
        }
        if (f.Name == field.Type.Name) {
          type = type.WithFullName(field.Type);
          break;
        }
      }
    }

    public ExpressionSyntax GetTypeName(IType type, ITypeDefinition typeDefinition, ISymbol symbol) {
      return GetTypeName(new TypeNameArgs {
        Type = type,
        Definition = typeDefinition,
        IsForward = false,
        IsInHead = false,
        Original = type,
        Symbol = symbol,
      });
    }

    private struct TypeNameArgs {
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

    private ExpressionSyntax AddHeadReference(in TypeNameArgs args) {
      var referenceType = args.Type.GetReferenceType();
      if (referenceType != null) {
        var rootType = args.Definition.GetReferenceType();
        if (!Generator.IsCompilationUnitIn(rootType, referenceType)) {
          var referenceTypeDefinition = referenceType.GetDefinition();
          if (referenceTypeDefinition.Kind == TypeKind.Enum) {
            CompilationUnit.AddHeadReference(referenceTypeDefinition, true);
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
                    CompilationUnit.AddHeadReference(rootObject, true);
                    nestedCycleName = new NestedCycleRefTypeNameSyntax(shortName);
                  }
                  nestedCycleRefNames_[args.Symbol] = nestedCycleName;
                  return nestedCycleName;
                }
              }
            }
            CompilationUnit.AddHeadReference(referenceTypeDefinition, args.IsForward);
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
          CompilationUnit.AddSrcReference(referenceTypeDefinition);
        }
      }
    }

    private ExpressionSyntax GetTypeName(TypeNameArgs args) {
      switch (args.Type.Kind) {
        case TypeKind.Void: {
          return IdentifierSyntax.Void;
        }
        case TypeKind.Array: {
          ArrayType arrayType = (ArrayType)args.Type;
          if (args.IsInHead) {
            var arrayDefinition = arrayType.DirectBaseTypes.First().GetDefinition();
            if (arrayDefinition != args.Definition) {
              CompilationUnit.AddHeadReference(arrayDefinition, args.IsForward);
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

      ExpressionSyntax typeName = (IdentifierSyntax)args.Type.Name;
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
            typeName = new GenericIdentifierSyntax(typeName, IdentifierSyntax.Void);
          }
        }
      }

      return typeName;
    }

    private List<ITypeDefinition> SortNestedTypes(List<ITypeDefinition> types) {
      List<List<ITypeDefinition>> typesList = new List<List<ITypeDefinition>>() { types.ToList() };
      while (true) {
        var parentTypes = new HashSet<ITypeDefinition>();
        var lastTypes = typesList.Last();
        foreach (var x in lastTypes) {
          foreach (var y in lastTypes) {
            if (x != y && y != nestedCycleTypes_.GetOrDefault(x)) {
              bool yInX = x.IsMemberTypeExists(y);
              bool xInY = y.IsMemberTypeExists(x);
              if (yInX) {
                var y1 = y;
                if (xInY) {
                  var x1 = x;
                  if (x1.Kind == TypeKind.Struct) {
                    (y1, x1) = (x1, y1);
                  }
                  nestedCycleTypes_[y1] = x1;
                }
                parentTypes.Add(y1);
              }
            }
          }
        }
        if (parentTypes.Count == 0) {
          break;
        }
        typesList.Add(parentTypes.ToList());
      }
      typesList.Reverse();
      return typesList.SelectMany(i => i).Distinct().ToList();
    }

    private IEnumerable<ITypeDefinition> GetNestedTypes(ITypeDefinition type) {
      IEnumerable<ITypeDefinition> types;
      if (type.NestedTypes.Count > 1) {
        var nestedTypes = type.NestedTypes.ToList();
        var enums = new List<ITypeDefinition>();
        nestedTypes.RemoveAll(i => {
          bool isEnum = i.Kind == TypeKind.Enum;
          if (isEnum) {
            enums.Add(i);
          }
          return isEnum;
        });
        nestedTypes = SortNestedTypes(nestedTypes);
        nestedTypes.InsertRange(0, enums);
        types = nestedTypes;
      } else {
        types = type.NestedTypes;
      }
      return types.Where(i => !i.Name.StartsWith('<'));
    }

    private void VisitTypes(ITypeDefinition type, ClassSyntax node) {
      var nestedTypes = GetNestedTypes(type);
      var sameNameTypes = nestedTypes.GroupBy(i => i.Name);
      foreach (var types in sameNameTypes) {
        var brotherType = AssemblyTransform.GetNestedBrotherType(types);
        if (brotherType != null) {
          foreach (var nestedType in types) {
            bool isRef = nestedType.IsRefType();
            ExpressionSyntax name = (IdentifierSyntax)nestedType.Name;
            if (isRef) {
              name = new InvationExpressionSyntax(IdentifierSyntax.NAME, name);
            }
            var friend = new FriendClassDeclarationSyntax(name, !isRef) { Template = nestedType.GetTemplateSyntax() };
            node.Add(friend);
          }
        }
        var block = brotherType != null ? GetBrotherTypeParnetBlock(brotherType) : node;
        new TypeDefinitionTransform(CompilationUnit, block, types, this);
      }
    }

    private void VisitMembers(ITypeDefinition type, ClassSyntax node) {
      VisitTypes(type, node);
      VisitMethods(type, node);
      VisitFields(type, node);
    }

    private BlockSyntax GetBrotherTypeParnetBlock(ITypeDefinition brotherType) {
      if (types_.Contains(brotherType)) {
        return parent_;
      }
      Contract.Assert(parentTransform_ != null);
      return parentTransform_.GetBrotherTypeParnetBlock(brotherType);
    }

    private string GetAccessibilityString(ITypeDefinition type) {
      return AssemblyTransform.GetDeclaringType(type) != null ? type.Accessibility.ToTokenString() : null;
    }

    internal NestedCycleRefTypeNameSyntax GetNestedCycleRefTypeName(ISymbol symbol) {
      return nestedCycleRefNames_.GetOrDefault(symbol);
    }
  }
}
