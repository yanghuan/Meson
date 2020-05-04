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

    private void VisitRootType(ITypeDefinition type) {
      var ns = cppCompilationUnit_.AddNamespace(type.Namespace);
      if (type.Kind == TypeKind.Enum) {
        EnumSyntax enumNode = new EnumSyntax(type.Name);
        ns.Add(enumNode);
        VisitEnumFields(type, enumNode);
      } else {
        ClassSyntax classNode = new ClassSyntax(type.Name);
        ns.Add(classNode);
        VisitMembers(ns, rootType_, classNode);
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
          if (typeDefinition.IsReferenceType == false && !field.IsStatic && field.Type == typeDefinition) {
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
