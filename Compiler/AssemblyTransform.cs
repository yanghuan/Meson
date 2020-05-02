using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.Ast;

namespace Meson.Compiler {
  class AssemblyTransform {
    private CSharpDecompiler decompiler_;

    public AssemblyTransform(string path) {
      decompiler_ = new CSharpDecompiler(path, GetDecompilerSettings());
    }

    private static DecompilerSettings GetDecompilerSettings() {
      DecompilerSettings settings = new DecompilerSettings(LanguageVersion.Latest);
      return settings;
    }

    public void Generate(string outDir) {
      var typeDefinitionTransforms = decompiler_.TypeSystem.GetAllTypeDefinitions().Where(IsExport).Select(Create);
      foreach (var typeDefinitionTransform in typeDefinitionTransforms) {
        typeDefinitionTransform.Write(outDir);
      }
    }

    private bool IsExport(ITypeDefinition type) {
      if (type.Name.Length == 0) {
        return false;
      }

      if (type.Name.StartsWith("<")) {
        return false;
      }

      if (type.DeclaringType != null) {
        return false;
      }

      return true;
    }

    private TypeDefinitionTransform Create(ITypeDefinition typeDefinition) {
      return new TypeDefinitionTransform(this, typeDefinition);
    }
  }
}
