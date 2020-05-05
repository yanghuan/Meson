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
      ["System.Boolean"] = "bool",
      ["System.Char"] = "char",
      ["System.Int32"] = "int32_t",
      ["System.Single"] = "float",
      ["System.Double"] = "double",
    };

    public AssemblyTransform AssemblyTransform { get; }
    private ITypeDefinition rootType_;
    private CompilationUnitSyntax cppCompilationUnit_ = new CompilationUnitSyntax();

    public TypeDefinitionTransform(AssemblyTransform assemblyTransform, ITypeDefinition rootType) {
      AssemblyTransform = assemblyTransform;
      rootType_ = rootType;
      VisitRootType(rootType_);
    }

    internal void Write(string outDir) {
      CppRenderer rener = new CppRenderer(this, outDir, rootType_);
      cppCompilationUnit_.Render(rener);
    }

    private static void RefTypeName(ref string s) {
      s = "__" + s + "__";
    }

    private static string RefTypeName(string s) {
      return "__" + s + "__";
    }

    private void VisitRootType(ITypeDefinition type) {
      var ns = cppCompilationUnit_.AddNamespace(type.Namespace);
      if (type.Kind == TypeKind.Enum) {
        EnumSyntax enumNode = new EnumSyntax(type.Name);
        ns.Add(enumNode);
        VisitEnumFields(type, enumNode);
      } else {
        string name = type.Name;
        if (type.IsRefType()) {
          if (type.IsArrayType()) {
            name = "Abstract" + name;
          } else {
            RefTypeName(ref name);
            ns.Add(new ClassForwardDeclarationSyntax(name));
            ns.Add(new UsingDeclarationSyntax(type.Name, new GenericIdentifierSyntax(IdentifierSyntax.Ref, (IdentifierSyntax)name)));
          }
        }
        ClassSyntax classNode = new ClassSyntax(name);
        ns.Add(classNode);
        VisitMembers(ns, rootType_, classNode);

        if (type.IsRefType()) {
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

    private ExpressionSyntax GetTypeName(IType type, HashSet<IType> references) {
      references.Add(type);

      switch (type.Kind) {
        case TypeKind.Array: {
          ArrayType arrayType = (ArrayType)type;
          var elementType = GetTypeName(arrayType.ElementType, references);
          return new GenericIdentifierSyntax(ValueTextIdentifierSyntax.Array, elementType);
        }
      }

      return new ValueTextIdentifierSyntax(type.Name);
    }

    private void VisitMembers(NamespaceSyntax ns, ITypeDefinition typeDefinition, ClassSyntax node) {
      HashSet<IType> references = new HashSet<IType>();
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
            typeName = GetTypeName(field.Type, references);
          }
          node.Statements.Add(new FieldDefinitionSyntax(typeName, field.Name, field.IsStatic));
        }
      }

      FillIncludeFiels(ns, typeDefinition, node, references);
    }

    private void FillIncludeFiels(NamespaceSyntax ns, ITypeDefinition typeDefinition, ClassSyntax node, HashSet<IType> references) {
      List<string> includes = new List<string>();
      foreach (var reference in references) {
        if (typeDefinition != reference && reference is IEntity entity) {
          string[] parts = new string[] { entity.ParentModule.Name }.Concat(reference.Namespace.Split('.')).ToArray();
          string headFile = $"{string.Join('/', parts)}/{reference.Name}.h";
          includes.Add(headFile);
        }
      }
      includes.Sort();
      cppCompilationUnit_.AddIncludes(includes);
    }
  }
}
