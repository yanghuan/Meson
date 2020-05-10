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
      ["System.Char"] = "char",
      ["System.Int16"] = "int16_t",
      ["System.UInt16"] = "uint16_t",
      ["System.Int32"] = "int32_t",
      ["System.UInt32"] = "uint32_t",
      ["System.Int64"] = "int64_t",
      ["System.UInt64"] = "uint64_t",
      ["System.Single"] = "float",
      ["System.Double"] = "double",
    };

    public AssemblyTransform AssemblyTransform { get; }
    private ITypeDefinition root_;
    private CompilationUnitSyntax compilationUnit_;
    private HashSet<string> includes_ = new HashSet<string>();
    private HashSet<string> usings_ = new HashSet<string>();

    public TypeDefinitionTransform(AssemblyTransform assemblyTransform, ITypeDefinition rootType) {
      AssemblyTransform = assemblyTransform;
      root_ = rootType;
      VisitCompilationUnit();
    }

    internal void Write(string outDir) {
      CppRenderer rener = new CppRenderer(this, outDir, root_);
      compilationUnit_.Render(rener);
    }

    private static void RefTypeName(ref string s) {
      s = RefTypeName(s);
    }

    private static string RefTypeName(string s) {
      return $"__{s}__";
    }

    private void VisitCompilationUnit() {
      compilationUnit_ = new CompilationUnitSyntax();
      var ns = compilationUnit_.AddNamespace(root_.Namespace);
      var usingsSyntax = new StatementListSyntax();
      ns.Add(usingsSyntax);

      VisitTypeDefinition(ns.Current, root_);
      var includes = includes_.ToList();
      includes.Sort();
      compilationUnit_.AddHeadIncludes(includes);
      compilationUnit_.AddSrcInclude(root_.GetIncludeString(), false);

      var usings = usings_.ToList();
      usings.Sort();
      foreach (string i in usings) {
        usingsSyntax.Add(new UsingNamespaceSyntax(i.Replace(Tokens.Dot, Tokens.TwoColon)));
      }
    }

    private void VisitTypeDefinition(BlockSyntax parnet, ITypeDefinition type) {
      switch (type.Kind) {
        case TypeKind.Enum: {
          VistEnum(parnet, type);
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

    private void VistClass(BlockSyntax parnet, ITypeDefinition type) {
      TemplateSyntax template = null;
      if (type.TypeParameterCount > 0) {
        var typeParameters = type.GetTypeParameters().Select(i => new TemplateTypenameSyntax(i.Name));
        if (typeParameters.Any()) {
          template = new TemplateSyntax(typeParameters);
        }
      }

      string name = type.Name;
      bool isRefType = type.IsRefType();
      if (isRefType) {
        RefTypeName(ref name);
        parnet.Add(new ClassForwardDeclarationSyntax(name, isRefType) { Template = template });
        IdentifierSyntax identifierName = name;
        if (template != null) {
          identifierName = identifierName.WithGeneric(template);
        }
        parnet.Add(new UsingDeclarationSyntax(type.Name, new GenericIdentifierSyntax(IdentifierSyntax.Ref, identifierName)) { Template = template });
        CheckArrayForwardDeclaration(parnet, type);
      }

      ClassSyntax node = new ClassSyntax(name, isRefType) { Template = template };
      if (type.IsStringType() || type.IsObjectType()) {
        node.Bases.Add(new BaseSyntax(new MemberAccessExpressionSyntax(IdentifierSyntax.Meson, (IdentifierSyntax)type.Name, MemberAccessOperator.TwoColon)));
      }

      VisitMembers(parnet, type, node);
      parnet.Add(node);
      compilationUnit_.AddTypeMetadataVar(node);
      CheckArrayType(parnet, type, name);
    }

    private void CheckArrayForwardDeclaration(BlockSyntax parnet, ITypeDefinition type) {
      if (type.IsArrayType()) {
        string genericName = type.Name.ToLower();
        string newName = RefTypeName(genericName);
        parnet.Add(new ClassForwardDeclarationSyntax(newName) { Template = TemplateSyntax.T });
        var genericIdentifier = new GenericIdentifierSyntax(IdentifierSyntax.Ref, new GenericIdentifierSyntax(newName, IdentifierSyntax.T));
        var usingDeclaration = new UsingDeclarationSyntax(genericName, genericIdentifier) { Template = TemplateSyntax.T };
        parnet.Add(usingDeclaration);
      }
    }

    private void CheckArrayType(BlockSyntax parnet, ITypeDefinition type, string abstractArrayNme) {
      if (type.IsArrayType()) {
        string genericName = type.Name.ToLower();
        string newName = RefTypeName(genericName);
        ClassSyntax newNode = new ClassSyntax(newName) { Template = TemplateSyntax.T };
        newNode.Bases.Add(new BaseSyntax(new GenericIdentifierSyntax(IdentifierSyntax.BaseArray, IdentifierSyntax.T)));
        newNode.Bases.Add(new BaseSyntax(abstractArrayNme));
        parnet.Add(newNode);
      }
    }

    private void VisitFields(ITypeDefinition typeDefinition, ClassSyntax node, HashSet<IType> references) {
      foreach (var field in typeDefinition.Fields) {
        if (!field.Name.StartsWith('<')) {
          ExpressionSyntax typeName = null;
          if (typeDefinition.IsValueType() && !field.IsStatic && field.Type == typeDefinition) {
            string name = innerValueTypeNames_.GetOrDefault(field.Type.FullName);
            if (name != null) {
              typeName = (IdentifierSyntax)name;
            }
          }
          if (typeName == null) {
            field.GetAttributes();
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
          return new GenericIdentifierSyntax(
            IdentifierSyntax.FixedBuffer,
            GetTypeName(type, typeDefinition, references),
            (IdentifierSyntax)size.ToString());
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

      return result;
    }

    private void VisitTypes(ITypeDefinition type, ClassSyntax node) {
      foreach (var nestedType in type.NestedTypes) {
        if (!nestedType.Name.StartsWith('<')) {
          VisitTypeDefinition(node, nestedType);
        }
      }
    }

    private void VisitMembers(BlockSyntax parnet, ITypeDefinition type, ClassSyntax node) {
      VisitTypes(type, node);
      node.Statements.Add(new ExpressionStatementSyntax(IdentifierSyntax.InsertMetadataObj) { HasSemicolon = false });
      HashSet<IType> references = new HashSet<IType>();
      VisitFields(type, node, references);
      AddReferences(parnet, type, references);
    }

    private void AddReferences(BlockSyntax parnet, ITypeDefinition type, HashSet<IType> references) {
      foreach (var reference in references) {
        if (type != reference && reference is IEntity entity) {
          includes_.Add(entity.GetIncludeString());
          if (!string.IsNullOrEmpty(entity.Namespace) && entity.Namespace != type.Namespace) {
            usings_.Add(entity.Namespace);
          }
        }
      }
    }

  }
}