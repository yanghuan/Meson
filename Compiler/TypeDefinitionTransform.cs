using System;
using System.Collections.Generic;
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
      ["System.Char"] = "unsigned char",
      ["System.Int16"] = "int16_t",
      ["System.UInt16"] = "uint16_t",
      ["System.Int32"] = "int32_t",
      ["System.UInt32"] = "uint32_t",
      ["System.Int64"] = "int64_t",
      ["System.UInt64"] = "uint64_t",
      ["System.Single"] = "float",
      ["System.Double"] = "double",
    };

    private List<ITypeDefinition> roots_;
    private CompilationUnitTransform compilationUnit_;
    public AssemblyTransform AssemblyTransform => compilationUnit_.AssemblyTransform;
    private bool IsMulti => roots_.Count > 1;
    private ITypeDefinition Root => roots_.First();

    public TypeDefinitionTransform(CompilationUnitTransform compilationUnit, BlockSyntax parent, IEnumerable<ITypeDefinition> types) {
      compilationUnit_ = compilationUnit;
      roots_ = types.ToList();
      Visit(parent);
    }

    private void Visit(BlockSyntax parent) {
      if (IsMulti) {
        int typeParameterCount = roots_.Last().TypeParameterCount + 1;
        var parameters = Enumerable.Range(0, typeParameterCount).Select((i, it) => new TemplateTypenameSyntax($"T{i + 1}", IdentifierSyntax.Void));
        ClassSyntax node = new ClassSyntax(Root.Name, Root.Kind != TypeKind.Struct) { 
          Template = new TemplateSyntax(parameters),
          Kind = Root.IsRefType() ? ClassKind.MultiRefForward : ClassKind.None,
        };
        parent.Add(node);
      }

      foreach (var root in roots_) {
        VisitTypeDefinition(parent, root);
      }
    }

    private void VisitTypeDefinition(BlockSyntax parnet, ITypeDefinition type) {
      switch (type.Kind) {
        case TypeKind.Enum: {
          VistEnum(parnet, type);
          break;
        }
        case TypeKind.Struct: {
          VisitStruct(parnet, type);
          break;
        }
        default: {
          VistClass(parnet, type);
          break;
        }
      }
    }

    private void VistEnum(BlockSyntax parnet, ITypeDefinition type) {
      EnumSyntax enumNode = new EnumSyntax(type.Name);
      if (!type.EnumUnderlyingType.IsIntType()) {
        enumNode.UnderlyingType = innerValueTypeNames_[type.EnumUnderlyingType.FullName];
      }
      VisitEnumFields(type, enumNode);
      parnet.Add(enumNode);
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

    private void VisitStruct(BlockSyntax parnet, ITypeDefinition type) {
      var template = BuildTemplateSyntax(type);
      ClassSyntax node = new ClassSyntax(type.Name, false) {
        Template = template,
        Kind = GetClassKind(type),
      };
      VisitMembers(parnet, type, node);
      parnet.Add(node);
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

    private void VistClass(BlockSyntax parnet, ITypeDefinition type) {
      var template = BuildTemplateSyntax(type);
      ClassSyntax node = new ClassSyntax(type.Name) {
        Template = template,
        Kind = GetClassKind(type),
      };
      if (type.IsStringType() || type.IsObjectType()) {
        node.Bases.Add(new BaseSyntax(new MemberAccessExpressionSyntax(IdentifierSyntax.Meson, (IdentifierSyntax)type.Name, MemberAccessOperator.TwoColon)));
      }
      VisitMembers(parnet, type, node);
      parnet.Add(node);
    }

    private void VisitFields(ITypeDefinition typeDefinition, ClassSyntax node, HashSet<IType> references) {
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
            typeName = GetFieldTypeName(field, typeDefinition, references);
          }
          node.Statements.Add(new FieldDefinitionSyntax(typeName, field.Name, field.IsStatic, field.Accessibility.ToTokenString()));
        }
      }
    }

    private ExpressionSyntax GetFieldTypeName(IField field, ITypeDefinition typeDefinition, HashSet<IType> references) {
      if (field.Type.Name.StartsWith('<')) {
        var attr = field.GetAttribute(KnownAttribute.FixedBuffer);
        if (attr != null) {
          var type = (IType)attr.FixedArguments[0].Value;
          int size = (int)attr.FixedArguments[1].Value;
          return new GenericIdentifierSyntax(IdentifierSyntax.FixedBuffer, GetTypeName(type, typeDefinition, references), (IdentifierSyntax)size.ToString());
        }
      }
      return GetTypeName(field.Type, typeDefinition, references);
    }

    private ExpressionSyntax GetTypeName(IType type, ITypeDefinition typeDefinition, HashSet<IType> references) {
      if (type.DeclaringType == null) {
        references.Add(type.GetReferenceType());
      }

      switch (type.Kind) {
        case TypeKind.Array: {
          ArrayType arrayType = (ArrayType)type;
          var elementType = GetTypeName(arrayType.ElementType, typeDefinition, references);
          return new GenericIdentifierSyntax(IdentifierSyntax.array, elementType);
        }
      }

      var typeName = new ValueTextIdentifierSyntax(type.Name);
      ExpressionSyntax result = typeName;
      if (type.TypeArguments.Count > 0) {
        var typeArguments = type.GetTypeArguments().Select(i => GetTypeName(i, typeDefinition, references)).ToList();
        if (typeArguments.Count > 0) {
          result = new GenericIdentifierSyntax(typeName, typeArguments);
        }
      }

      if (type.DeclaringType != null) {
        if (!typeDefinition.IsSame(type) && !typeDefinition.IsSame(type.DeclaringType)) {
          var declaringType = GetTypeName(type.DeclaringType, typeDefinition, references);
          return new MemberAccessExpressionSyntax(declaringType, result, MemberAccessOperator.TwoColon);
        }
      }

      if (type.Kind == TypeKind.Class && AssemblyTransform.IsVoidGenericType(type.Original())) {
        result = new GenericIdentifierSyntax(result, IdentifierSyntax.Void);
      }

      return result;
    }

    private void VisitTypes(ITypeDefinition type, ClassSyntax node) {
      var group = type.NestedTypes.Where(i => !i.Name.StartsWith('<')).GroupBy(i => i.Name);
      foreach (var types in group) {
        new TypeDefinitionTransform(compilationUnit_, node, types);
      }
    }

    private void VisitMembers(BlockSyntax parnet, ITypeDefinition type, ClassSyntax node) {
      VisitTypes(type, node);
      HashSet<IType> references = new HashSet<IType>();
      VisitFields(type, node, references);
      AddReferences(type, references);
    }

    private void AddReferences(ITypeDefinition type, HashSet<IType> references) {
      foreach (var reference in references) {
        if (type != reference && reference is IEntity entity) {
          compilationUnit_.AddInclude(entity.GetIncludeString());
          if (!string.IsNullOrEmpty(entity.Namespace) && entity.Namespace != type.Namespace) {
            compilationUnit_.AddUsing(entity.Namespace);
          }
        }
      }
    }

  }
}
