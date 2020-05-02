using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.Ast;

namespace Meson.Compiler {
  class TypeDefinitionTransform {
    public AssemblyTransform AssemblyTransform { get; }
    public ITypeDefinition TypeDefinition { get; }
    private CppCompilationUnitSyntax cppCompilationUnit_ = new CppCompilationUnitSyntax();

    public TypeDefinitionTransform(AssemblyTransform assemblyTransform, ITypeDefinition typeDefinition) {
      AssemblyTransform = assemblyTransform;
      TypeDefinition = typeDefinition;
      Accept();
    }

    internal void Write(string outDir) {
      CppRenderer rener = new CppRenderer(this, outDir, TypeDefinition);
      cppCompilationUnit_.Render(rener);
    }

    private void Accept() {

    }
  }
}
