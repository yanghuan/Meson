using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Reflection;

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
    private bool isPrimitiveType_;

    public TypeDefinitionTransform(CompilationUnitTransform compilationUnit, BlockSyntax parent, IEnumerable<ITypeDefinition> types, TypeDefinitionTransform parentTransform = null) {
      CompilationUnit = compilationUnit;
      types_ = types.ToList();
      parent_ = parent;
      parentTransform_ = parentTransform;
      Visit();
    }

    public bool IsMulti => types_.Count > 1;
    public bool HasRef => types_.Exists(i => i.IsRefType());
    private ITypeDefinition Root => types_.First();
    public IdentifierSyntax GetMemberName(ISymbol symbol) => Generator.GetMemberName(symbol);

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
          var fieldName = GetMemberName(field);
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
        node.Bases.Add(new BaseSyntax(IdentifierSyntax.Meson.TwoColon(type.Name.ToLower())));
      }
      VisitMembers(type, node);
      parent_.Add(node);
    }

    private bool IsExportMethod(IMethod method) {
      if (IsMulti || method.IsConstructor) {
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

    private IdentifierSyntax GetPropertyFieldName(ITypeDefinition typeDefinition, IProperty property) {
      string fieldName = property.GetBackingFieldName();
      var field = typeDefinition.Fields.First(i => i.Name == fieldName);
      Contract.Assert(field != null);
      return Generator.GetMemberName(field);
    }

    private void VisitMethod(IMethod method, ITypeDefinition typeDefinition, ClassSyntax node) {
      var parameters = method.Parameters.Select(i => GetParameterSyntax(i, method, typeDefinition)).ToList();
      var methodName = GetMemberName(method);
      var returnType = GetRetuenTypeSyntax(method, typeDefinition);
      var methodDefinition = new MethodDefinitionSyntax(returnType, methodName, parameters, method.IsStatic, !method.IsMainEntryPoint() ? method.Accessibility.ToTokenString() : Tokens.Public);
      node.Statements.Add(methodDefinition);
      if (method.HasBody) {
        if (method.AccessorOwner is IProperty property && property.IsPropertyField()) {
          var fieldName = GetPropertyFieldName(typeDefinition, property);
          if (method.AccessorKind == MethodSemanticsAttributes.Getter) {
            methodDefinition.Body = new BlockSyntax(new ReturnStatementSyntax(fieldName)) { IsSingleLine = true };
          } else {
            methodDefinition.Body = new BlockSyntax(new BinaryExpressionSyntax(fieldName, Tokens.Equals, IdentifierSyntax.Value)) { IsSingleLine = true };
          }
          if (property.IsStatic) {
            CompilationUnit.AddPropertyFieldTypeReference(property);
          }
        } else {
          if (typeDefinition.TypeParameterCount == 0) {
            new MethodTransform(this, method, node);
          }
        }
      }
    }

    private void VisitMethods(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var method in typeDefinition.Methods.Where(IsExportMethod)) {
        VisitMethod(method, typeDefinition, node);
      }
    }

    private ExpressionSyntax GetRetuenTypeSyntax(IMethod method, ITypeDefinition typeDefinition) {
      var returnType = CompilationUnit.GetTypeName(new TypeNameArgs {
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
            type = type.WithFullName(returnType, typeDefinition);
          }
        }
      }
    }

    private ParameterSyntax GetParameterSyntax(IParameter parameter, IMethod method, ITypeDefinition typeDefinition) {
      var type = CompilationUnit.GetTypeName(new TypeNameArgs {
        Type = parameter.Type,
        Definition = typeDefinition,
        IsForward = true,
        IsInHead = true,
        Original = parameter.Type,
        Symbol = parameter,
      });
      CheckParameterTypeConflict(ref type, parameter, method, typeDefinition);
      var name = GetMemberName(parameter);
      return new ParameterSyntax(type, name);
    }

    public static void CheckParameterTypeConflict(ref ExpressionSyntax type, IParameter parameter, IMethod method, ITypeDefinition typeDefinition) {
      foreach (var m in typeDefinition.Methods) {
        if (m == method) {
          break;
        }
        if (m.Name == parameter.Type.Name) {
          type = type.WithFullName(parameter.Type, typeDefinition);
          break;
        }
      }
    }

    private static bool IsValueTypeInnerField(IField field, ITypeDefinition typeDefinition, out ExpressionSyntax typeName) {
      if (typeDefinition.Kind == TypeKind.Struct && !field.IsStatic && field.Type == typeDefinition) {
        string name = field.Type.GetValueTypeInnerName();
        if (name != null) {
          typeName = (IdentifierSyntax)name;
          return true;
        }
      }
      typeName = null;
      return false;
    }

    private static bool IsArrayInnerSpecialField(IField field, ITypeDefinition typeDefinition, out ExpressionSyntax typeName) {
      if (typeDefinition.DeclaringTypeDefinition?.IsArrayType() == true && !field.IsStatic && field.Type.Kind == TypeKind.Array) {
        ArrayType arrayType = (ArrayType)field.Type;
        Contract.Assert(arrayType.ElementType.GetDefinition().IsObjectType());
        typeName = new GenericIdentifierSyntax(arrayType.DirectBaseTypes.First().Name);
        return true;
      }
      typeName = null;
      return false;
    }

    private void VisitFields(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var field in typeDefinition.Fields) {
        var fieldName = GetMemberName(field);
        if (IsValueTypeInnerField(field, typeDefinition, out ExpressionSyntax typeName)) {
          node.Bases.Add(new BaseSyntax(IdentifierSyntax.PrimitiveType.Generic(node.Name)));

          var statements = new StatementListSyntax(); 
          string accessibilityToken = Accessibility.Public.ToTokenString();
          var defaultConstructor = new ConstructorDefinitionSyntax(node.Name, Array.Empty<ParameterSyntax>(), accessibilityToken) { 
            Body = BlockSyntax.EmptyBlock,
            IsConstexpr = true,
            IsNoexcept = true,
          };
          defaultConstructor.AddInitializationList(fieldName, field.Type.GetDefinition().GetPrimitiveTypeDefaultValue());
          statements.Add(defaultConstructor);

          var underlyingTypeConstructor = new ConstructorDefinitionSyntax(node.Name, new ParameterSyntax(typeName, IdentifierSyntax.Value).ArrayOf(), accessibilityToken) { 
            Body = BlockSyntax.EmptyBlock,
            IsConstexpr = true,
            IsNoexcept = true,
          };
          underlyingTypeConstructor.AddInitializationList(fieldName, IdentifierSyntax.Value);
          statements.Add(underlyingTypeConstructor);

          node.Statements.Insert(0, statements);
          isPrimitiveType_ = true;
        } else if (IsArrayInnerSpecialField(field, typeDefinition, out typeName)) {
        } else {
          typeName = GetFieldTypeName(field, typeDefinition);
        }
        Contract.Assert(typeName != null);
        var constantValue = field.GetConstantValue();
        node.Statements.Add(new FieldDefinitionSyntax(typeName, fieldName, field.IsStatic, field.Accessibility.ToTokenString()) {
          IsConstexpr = field.IsConst,
          ConstantValue = field.IsConst ? Utils.GetPrimitiveExpression(constantValue) : null,
        });
      }
    }

    private bool CheckFixedBufferField(IField field, ITypeDefinition typeDefinition, out ExpressionSyntax result) {
      if (field.Type.Name.StartsWith('<')) {
        var attr = field.GetAttribute(KnownAttribute.FixedBuffer);
        if (attr != null) {
          var type = (IType)attr.FixedArguments[0].Value;
          int size = (int)attr.FixedArguments[1].Value;
          var name = CompilationUnit.GetTypeName(new TypeNameArgs {
            Type = type,
            Definition = typeDefinition,
            IsForward = field.IsStatic,
            IsInHead = true,
            Original = type,
            Symbol = field,
          });
          result = new GenericIdentifierSyntax(IdentifierSyntax.FixedBuffer, name, (IdentifierSyntax)size.ToString());
          return true;
        }
      }
      result = null;
      return false;
    }

    private ExpressionSyntax GetFieldTypeName(IField field, ITypeDefinition typeDefinition) {
      if (CheckFixedBufferField(field, typeDefinition, out var buffField)) {
        return buffField;
      }

      var typeName = CompilationUnit.GetTypeName(new TypeNameArgs {
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
          type = type.WithFullName(field.Type, typeDefinition);
          return;
        }
      }

      foreach (var f in typeDefinition.Fields) {
        if (f == field) {
          break;
        }
        if (f.GetFieldName() == field.Type.Name) {
          type = type.WithFullName(field.Type, typeDefinition);
          break;
        }
      }
    }

    public ExpressionSyntax GetTypeName(IType type, ITypeDefinition typeDefinition, ISymbol symbol) {
      return CompilationUnit.GetTypeName(new TypeNameArgs {
        Type = type,
        Definition = typeDefinition,
        IsForward = false,
        IsInHead = false,
        Original = type,
        Symbol = symbol,
      });
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
              name = IdentifierSyntax.NAME.Invation(name);
            }
            var friend = new FriendClassDeclarationSyntax(name, !isRef) { Template = nestedType.GetTemplateSyntax() };
            node.Add(friend);
          }
        }
        var block = brotherType != null ? GetBrotherTypeParnetBlock(brotherType) : node;
        new TypeDefinitionTransform(CompilationUnit, block, types, this);
      }
    }

    private void VisitPropertys(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var property in typeDefinition.Properties) {
        if (property.CanGet) {
          VisitMethod(property.Getter, typeDefinition, node);
        }
        if (property.CanSet) {
          VisitMethod(property.Setter, typeDefinition, node);
        }
      }
    }

    private void VisitMembers(ITypeDefinition type, ClassSyntax node) {
      VisitTypes(type, node);
      VisitPropertys(type, node);
      VisitMethods(type, node);
      VisitFields(type, node);
      if (isPrimitiveType_) {
        node.Add(new FriendClassDeclarationSyntax(IdentifierSyntax.PrimitiveType, true) { Template = TemplateSyntax.T  });
      }
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
      return CompilationUnit.GetNestedCycleRefTypeName(symbol);
    }
  }
}
