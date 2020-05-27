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
    private static readonly Dictionary<string, string> innerValueTypeNames_ = new Dictionary<string, string>() {
      ["System.Byte"] = "uint8_t",
      ["System.SByte"] = "int8_t",
      ["System.Boolean"] = "bool",
      ["System.Char"] = "char8_t",
      ["System.Int16"] = "int16_t",
      ["System.UInt16"] = "uint16_t",
      ["System.Int32"] = "int32_t",
      ["System.UInt32"] = "uint32_t",
      ["System.Int64"] = "int64_t",
      ["System.UInt64"] = "uint64_t",
      ["System.Single"] = "float",
      ["System.Double"] = "double",
    };

    private CompilationUnitTransform compilationUnit_;
    public AssemblyTransform AssemblyTransform => compilationUnit_.AssemblyTransform;
    public SyntaxGenerator Generator => AssemblyTransform.Generator;
    private BlockSyntax parent_;
    private List<ITypeDefinition> types_;
    private TypeDefinitionTransform parentTransform_;
    private Dictionary<ITypeDefinition, ITypeDefinition> nestedCycleTypes_ = new Dictionary<ITypeDefinition, ITypeDefinition>();

    private bool IsMulti => types_.Count > 1;
    private ITypeDefinition Root => types_.First();

    public TypeDefinitionTransform(CompilationUnitTransform compilationUnit, BlockSyntax parent, IEnumerable<ITypeDefinition> types, TypeDefinitionTransform parentTransform = null) {
      compilationUnit_ = compilationUnit;
      types_ = types.ToList();
      parent_ = parent;
      parentTransform_ = parentTransform;
      Visit();
    }

    private void Visit() {
      if (IsMulti) {
        bool hasRef = types_.Exists(i => i.IsRefType());
        int typeParameterCount = types_.Last().TypeParameterCount + 1;
        var parameters = Enumerable.Range(0, typeParameterCount).Select((i, it) => new TemplateTypenameSyntax($"T{i + 1}", IdentifierSyntax.Void));
        ClassSyntax node = new ClassSyntax(Root.Name, Root.Kind == TypeKind.Struct) { 
          Template = new TemplateSyntax(parameters),
          Kind = hasRef ? ClassKind.MultiRefForward : ClassKind.None,
        };
        parent_.Add(node);
      }

      foreach (var type in types_) {
        var referenceType = parentTransform_?.nestedCycleTypes_.GetOrDefault(type);
        if (referenceType != null) {
          var forward = referenceType.GetForwardStatement();
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
      EnumSyntax node = new EnumSyntax(type.Name) { AccessibilityToken = GetAccessibilityString(type) };
      if (!type.EnumUnderlyingType.IsIntType()) {
        node.UnderlyingType = innerValueTypeNames_[type.EnumUnderlyingType.FullName];
      }
      VisitEnumFields(type, node);
      parent_.Add(node);
    }

    private void VisitEnumFields(ITypeDefinition typeDefinition, EnumSyntax enumNode) {
      foreach (var field in typeDefinition.Fields) {
        if (field.Name != "value__") {
          object v = field.GetConstantValue();
          var fieldName = Generator.GetMemberName(field);
          enumNode.Add(new EnumFieldSyntax(fieldName, v.ToString()));
        }
      }
    }

    private TemplateSyntax BuildTemplateSyntax(ITypeDefinition type) {
      TemplateSyntax template = null;
      if (type.TypeParameterCount > 0) {
        var typeParameters = type.GetTypeParameters().Select(i => new TemplateTypenameSyntax(i.Name));
        if (typeParameters.Any()) {
          template = new TemplateSyntax(typeParameters);
        }
      }
      return template;
    }

    private void VisitStruct(ITypeDefinition type) {
      var template = BuildTemplateSyntax(type);
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
      var template = BuildTemplateSyntax(type);
      ClassSyntax node = new ClassSyntax(type.Name) {
        Template = template,
        Kind = GetClassKind(type),
        AccessibilityToken = GetAccessibilityString(type),
      };
      if (type.IsStringType() || type.IsObjectType()) {
        node.Bases.Add(new BaseSyntax(new MemberAccessExpressionSyntax(IdentifierSyntax.Meson, (IdentifierSyntax)type.Name, MemberAccessOperator.TwoColon)));
      }
      VisitMembers(type, node);
      parent_.Add(node);
    }

    private void VisitFields(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var field in typeDefinition.Fields) {
        if (!field.Name.StartsWith('<')) {
          ExpressionSyntax typeName = null;
          if (typeDefinition.Kind == TypeKind.Struct && !field.IsStatic && field.Type == typeDefinition) {
            string name = innerValueTypeNames_.GetOrDefault(field.Type.FullName);
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
          return new GenericIdentifierSyntax(IdentifierSyntax.FixedBuffer, GetTypeName(type, typeDefinition), (IdentifierSyntax)size.ToString());
        }
      }
      return GetTypeName(field.Type, typeDefinition);
    }

    private ExpressionSyntax GetTypeName(IType type, ITypeDefinition typeDefinition) {
      var referenceType = type.GetReferenceType();
      if (referenceType != null) {
        var rootType = typeDefinition.GetReferenceType();
        if (!Generator.IsCompilationUnitIn(rootType, referenceType)) {
          var referenceTypeDefinition = referenceType.GetDefinition();
          if (referenceTypeDefinition.Kind != TypeKind.Enum && referenceTypeDefinition.Kind != TypeKind.Struct) {
            bool isExists = referenceTypeDefinition.IsMemberTypeExists(rootType.GetDefinition(), true);
            if (isExists) {
              if (type.DeclaringType != null && type.IsReferenceType == true) {
                var rootObject = referenceTypeDefinition.GetRootObjectDefinition();
                compilationUnit_.References.Add(rootObject);
                return new NestedCycleRefTypeNameSyntax(type.GetShortName());
              }
              compilationUnit_.AddForward(referenceTypeDefinition);
            }
          }
          compilationUnit_.References.Add(referenceTypeDefinition);
        }
      }

      switch (type.Kind) {
        case TypeKind.Array: {
          ArrayType arrayType = (ArrayType)type;
          var elementType = GetTypeName(arrayType.ElementType, typeDefinition);
          return new GenericIdentifierSyntax((IdentifierSyntax)type.Kind.ToString(), elementType);
        }
        case TypeKind.Pointer: {
          PointerType pointerType = (PointerType)type;
          var elementType = GetTypeName(pointerType.ElementType, typeDefinition);
          return new PointerIdentifierSyntax(elementType);
        }
      }

      IdentifierSyntax typeName = type.Name;
      ExpressionSyntax result = typeName;
      bool isGeneric = false;
      if (type.TypeArguments.Count > 0) {
        var typeArguments = type.GetTypeArguments().Select(i => GetTypeName(i, typeDefinition)).ToList();
        if (typeArguments.Count > 0) {
          result = new GenericIdentifierSyntax(result, typeArguments);
          isGeneric = true;
        }
      }

      if (type.DeclaringType != null && !AssemblyTransform.IsInternalMemberType(type, typeDefinition)) {
        var outTypeName = GetTypeName(type.DeclaringType, typeDefinition);
        if (type.DeclaringType.GetDefinition().IsRefType()) {
          outTypeName = outTypeName.TwoColon(IdentifierSyntax.In);
        }
        return outTypeName.TwoColon(result);
      }

      if (!isGeneric) {
        var definition = type.GetDefinition();
        if (definition != null) {
          if (definition.IsArrayType() || Generator.IsVoidGenericType(definition)) {
            result = new GenericIdentifierSyntax(result, IdentifierSyntax.Void);
          }
        }
      }

      return result;
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
                if (xInY) {
                  nestedCycleTypes_[y] = x;
                }
                parentTypes.Add(y);
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
        return nestedTypes;
      }
      return type.NestedTypes;
    }

    private void VisitTypes(ITypeDefinition type, ClassSyntax node) {
      var nestedTypes = GetNestedTypes(type);
      var sameNameTypes = nestedTypes.Where(i => !i.Name.StartsWith('<')).GroupBy(i => i.Name);
      foreach (var types in sameNameTypes) {
        var brotherType = AssemblyTransform.GetNestedBrotherType(types);
        if (brotherType != null) {
          foreach (var nestedType in types) {
            bool isRef = nestedType.IsRefType();
            string name = isRef ? $"{nestedType.Name}___" : nestedType.Name;
            var friend = new FriendClassDeclarationSyntax(name, !isRef) { Template = BuildTemplateSyntax(nestedType) };
            node.Add(friend);
          }
        }
        var block = brotherType != null ? GetBrotherTypeParnetBlock(brotherType) : node;
        new TypeDefinitionTransform(compilationUnit_, block, types, this);
      }
    }

    private void VisitMembers(ITypeDefinition type, ClassSyntax node) {
      VisitTypes(type, node);
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
  }
}
