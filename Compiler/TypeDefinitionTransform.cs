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
    private BlockSyntax parent_;
    private List<ITypeDefinition> types_;
    private TypeDefinitionTransform parentTransform_;

    public AssemblyTransform AssemblyTransform => compilationUnit_.AssemblyTransform;
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
        int typeParameterCount = types_.Last().TypeParameterCount + 1;
        var parameters = Enumerable.Range(0, typeParameterCount).Select((i, it) => new TemplateTypenameSyntax($"T{i + 1}", IdentifierSyntax.Void));
        ClassSyntax node = new ClassSyntax(Root.Name, Root.Kind == TypeKind.Struct) { 
          Template = new TemplateSyntax(parameters),
          Kind = Root.IsRefType() ? ClassKind.MultiRefForward : ClassKind.None,
        };
        parent_.Add(node);
      }

      foreach (var root in types_) {
        VisitTypeDefinition(root);
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
          enumNode.Add(new EnumFieldSyntax(field.Name, v.ToString()));
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
      if (!type.IsRefType()) {
        return IsMulti ? ClassKind.Multi : ClassKind.None;
      }

      if (type.IsArrayType()) {
        return ClassKind.Array;
      }

      if (IsMulti) {
        return ClassKind.MultiRef;
      }

      return ClassKind.Ref;
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
          node.Statements.Add(new FieldDefinitionSyntax(typeName, field.Name, field.IsStatic, field.Accessibility.ToTokenString()));
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
      if (referenceType.Kind != TypeKind.TypeParameter) {
        var rootType = typeDefinition.GetReferenceType();
        if (!referenceType.Equals(rootType)) {
          var referenceTypeDefinition = referenceType.GetDefinition();
          compilationUnit_.References.Add(referenceTypeDefinition);
          if (referenceTypeDefinition.Kind != TypeKind.Enum) {
            bool isExists = referenceTypeDefinition.IsMemberTypeExists(rootType.GetDefinition(), true);
            if (isExists) {
              compilationUnit_.Forwards.Add(referenceTypeDefinition);
            }
          }
        }
      }

      switch (type.Kind) {
        case TypeKind.Array: {
          ArrayType arrayType = (ArrayType)type;
          var elementType = GetTypeName(arrayType.ElementType, typeDefinition);
          return new GenericIdentifierSyntax(IdentifierSyntax.array, elementType);
        }
        case TypeKind.Pointer: {
          PointerType pointerType = (PointerType)type;
          var elementType = GetTypeName(pointerType.ElementType, typeDefinition);
          return new PointerIdentifierSyntax(elementType);
        }
      }

      var typeName = new ValueTextIdentifierSyntax(type.Name);
      ExpressionSyntax result = typeName;
      if (type.TypeArguments.Count > 0) {
        var typeArguments = type.GetTypeArguments().Select(i => GetTypeName(i, typeDefinition)).ToList();
        if (typeArguments.Count > 0) {
          result = new GenericIdentifierSyntax(typeName, typeArguments);
        }
      }

      if (type.DeclaringType != null && !AssemblyTransform.IsInternalMemberType(type, typeDefinition)) {
        var outTypeName = GetTypeName(type.DeclaringType, typeDefinition);
        if (type.DeclaringType.GetDefinition().IsRefType()) {
          outTypeName = outTypeName.TwoColon(IdentifierSyntax.In);
        }
        return outTypeName.TwoColon(result);
      }

      if (type.Kind == TypeKind.Class && AssemblyTransform.IsVoidGenericType(type.Original())) {
        result = new GenericIdentifierSyntax(result, IdentifierSyntax.Void);
      }

      return result;
    }

    private static int CompareNestedType(ITypeDefinition type, ITypeDefinition x, ITypeDefinition y) {
      if (x.IsMemberTypeExists(y)) {
        return 1;
      }

      if (y.IsMemberTypeExists(x)) {
        return -1;
      }

      int indexX = type.NestedTypes.IndexOf(x);
      int indexY = type.NestedTypes.IndexOf(y);
      return indexX.CompareTo(indexY);
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
        nestedTypes.Sort((x, y) => CompareNestedType(type, x, y));
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
            var friend = new FriendClassDeclarationSyntax(nestedType.Name, nestedType.Kind == TypeKind.Struct) { Template = BuildTemplateSyntax(nestedType) };
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
