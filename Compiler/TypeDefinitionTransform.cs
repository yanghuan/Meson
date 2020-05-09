using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Linq;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;
using ICSharpCode.Decompiler.TypeSystem.Implementation;

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
    private ITypeDefinition rootType_;
    private CompilationUnitSyntax compilationUnit_;

    public TypeDefinitionTransform(AssemblyTransform assemblyTransform, ITypeDefinition rootType) {
      AssemblyTransform = assemblyTransform;
      rootType_ = rootType;
      VisitRootType(rootType_);
    }

    internal void Write(string outDir) {
      CppRenderer rener = new CppRenderer(this, outDir, rootType_);
      compilationUnit_.Render(rener);
    }

    private static void RefTypeName(ref string s) {
      s = "__" + s + "__";
    }

    private static string RefTypeName(string s) {
      return "__" + s + "__";
    }

    private void VisitRootType(ITypeDefinition type) {
      compilationUnit_ = new CompilationUnitSyntax();
      var ns = compilationUnit_.AddNamespace(type.Namespace);
      if (type.Kind == TypeKind.Enum) {
        EnumSyntax enumNode = new EnumSyntax(type.Name);
        if (!type.EnumUnderlyingType.IsIntType() ) {
          enumNode.UnderlyingType = innerValueTypeNames_[type.EnumUnderlyingType.FullName];
        }

        ns.Add(enumNode);
        VisitEnumFields(type, enumNode);
      } else {
        string name = type.Name;
        bool isRefType = type.IsRefType();
        if (isRefType) {
          if (type.IsArrayType()) {
            name = name.ToLower();
          } else {
            RefTypeName(ref name);
            ns.Add(new ClassForwardDeclarationSyntax(name, isRefType));
            ns.Add(new UsingDeclarationSyntax(type.Name, new GenericIdentifierSyntax(IdentifierSyntax.Ref, (IdentifierSyntax)name)));
          }
        }

        ClassSyntax classNode = new ClassSyntax(name, isRefType);
        classNode.Statements.Add(new ExpressionStatementSyntax(IdentifierSyntax.InsertMetadataObj) { HasSemicolon = false });
        if (type.TypeParameterCount > 0) {
          var typeParameters = type.TypeParameters.Select(i => new TemplateTypenameSyntax(i.Name));
          classNode.Template = new TemplateSyntax(typeParameters);
        }
        VisitMembers(ns, rootType_, classNode);
        ns.Add(classNode);

        if (isRefType) {
          if (type.IsStringType()) {
            classNode.Bases.Add(new BaseSyntax(IdentifierSyntax.BaseString));
          } else if (type.IsArrayType()) {
            string newName = RefTypeName(type.Name);
            ClassSyntax newNode = new ClassSyntax(newName);
            newNode.Template = new TemplateSyntax(new TemplateTypenameSyntax(IdentifierSyntax.T));
            newNode.Bases.Add(new BaseSyntax(new GenericIdentifierSyntax(IdentifierSyntax.BaseArray, IdentifierSyntax.T)));
            newNode.Bases.Add(new BaseSyntax(name));
            ns.Add(newNode);

            var genericIdentifier = new GenericIdentifierSyntax(IdentifierSyntax.Ref, new GenericIdentifierSyntax(newName, IdentifierSyntax.T));
            var usingDeclaration = new UsingDeclarationSyntax(type.Name, genericIdentifier);
            usingDeclaration.Template = new TemplateSyntax(new TemplateTypenameSyntax(IdentifierSyntax.T));
            ns.Add(usingDeclaration);
          }
        }
      }
    }

    private void VisitEnumFields(ITypeDefinition typeDefinition, EnumSyntax classNode) {
      foreach (var field in typeDefinition.Fields) {
        if (field.Name != "value__") {
          object v = field.GetConstantValue();
          classNode.Statements.Add(new EnumFieldSyntax(field.Name, v.ToString()));
        }
      }
    }

    private ExpressionSyntax GetTypeName(IType type, ITypeDefinition typeDefinition, HashSet<IType> references) {
      if (type.DeclaringType == null) {
        references.Add(type.GetReferenceType());
      }

      switch (type.Kind) {
        case TypeKind.Array: {
          ArrayType arrayType = (ArrayType)type;
          var elementType = GetTypeName(arrayType.ElementType, typeDefinition, references);
          return new GenericIdentifierSyntax(ValueTextIdentifierSyntax.Array, elementType);
        }
      }

      var typeName = new ValueTextIdentifierSyntax(type.Name);
      ExpressionSyntax result = typeName;
      if (type.TypeArguments.Count > 0) {
        List<ExpressionSyntax> typeArguments = new List<ExpressionSyntax>();
        foreach (var typeArgument in type.TypeArguments) {
          bool isSkip = false;
          if (typeArgument is NullabilityAnnotatedTypeParameter parameter) {
            if (typeDefinition == parameter.OriginalTypeParameter.Owner) {
              isSkip = true;
            }
          }
          if (!isSkip) {
            typeArguments.Add(GetTypeName(typeArgument, typeDefinition, references));
          }
        }
        if (typeArguments.Count > 0) {
          result = new GenericIdentifierSyntax(typeName, typeArguments);
        }
      }

      if (type.DeclaringType != null && !typeDefinition.IsSame(type.DeclaringType)) {
        var declaringType = GetTypeName(type.DeclaringType, typeDefinition, references);
        return new MemberAccessExpressionSyntax(declaringType, result, MemberAccessOperator.TwoColon);
      }

      return result;
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
            typeName = GetTypeName(field.Type, typeDefinition, references);
          }
          node.Statements.Add(new FieldDefinitionSyntax(typeName, field.Name, field.IsStatic, field.Accessibility.ToTokenString()));
        }
      }
    }

    private void VisitMembers(NamespaceSyntax ns, ITypeDefinition typeDefinition, ClassSyntax node) {
      HashSet<IType> references = new HashSet<IType>();
      VisitFields(typeDefinition, node, references);
      FillIncludes(ns, typeDefinition, node, references);
      compilationUnit_.AddSrcInclude(typeDefinition.GetIncludeString(), false);
      compilationUnit_.AddTypeMetadataVar(node.Name);
    }

    private void FillIncludes(NamespaceSyntax ns, ITypeDefinition typeDefinition, ClassSyntax node, HashSet<IType> references) {
      List<string> includes = new List<string>();
      List<string> usings = new List<string>();
      foreach (var reference in references) {
        if (typeDefinition != reference && reference is IEntity entity) {
          includes.Add(entity.GetIncludeString());
          if (entity.Namespace != typeDefinition.Namespace && !usings.Contains(entity.Namespace)) {
            usings.Add(entity.Namespace);
          }
        }
      }
      includes.Sort();
      compilationUnit_.AddHeadIncludes(includes);

      usings.Sort();
      foreach (string i in usings) {
        ns.Add(new UsingNamespaceSyntax(i.Replace(Tokens.Dot, Tokens.TwoColon)));
      }
    }
  }
}
