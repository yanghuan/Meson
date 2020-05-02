using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.Ast;

namespace Meson.Compiler {
  internal class CppRenderer {
    private static readonly Encoding Encoding = new UTF8Encoding(false);
    private const string IndentString = "  ";

    private TypeDefinitionTransform transform_;
    private string outDir_;
    private ITypeDefinition typeDefinition_;
    private StreamWriter writer_;
    private bool isNewLine_;
    private int indentLevel_;
    private int singleLineCounter_;
    private bool IsSingleLine => singleLineCounter_ > 0;

    public CppRenderer(TypeDefinitionTransform transform, string outDir, ITypeDefinition typeDefinition) {
      transform_ = transform;
      outDir_ = outDir;
      typeDefinition_ = typeDefinition;
    }

    private string FolderPath {
      get {
        string[] ns = typeDefinition_.Namespace.Split('.');
        string[] paths = new string[] { typeDefinition_.ParentModule.AssemblyName }.Concat(ns).ToArray();
        return Path.Combine(paths);
      }
    }

    private string OutDir {
      get {
        return Path.Combine(outDir_, FolderPath);
      }
    }

    private string HeadFileName {
      get {
        return Path.Combine(OutDir, $"{typeDefinition_.Name}.h"); ;
      }
    }

    private string SrcFileName {
      get {
        return Path.Combine(OutDir, $"{typeDefinition_.Name}.cpp"); ;
      }
    }

    private void WriteNewLine() {
      if (IsSingleLine) {
        return;
      }

      writer_.Write('\n');
      isNewLine_ = true;
    }

    private void WriteSpace() {
      Write(" ");
    }

    private void Write(string value) {
      if (isNewLine_) {
        for (int i = 0; i < indentLevel_; i++) {
          writer_.Write(IndentString);
        }
        isNewLine_ = false;
      }
      writer_.Write(value);
    }

    internal void Render(CppCompilationUnitSyntax compilationUnit) {
      WriteCompilationUnitStatements(compilationUnit.HeadStatements, HeadFileName);
      WriteCompilationUnitStatements(compilationUnit.SrcStatements, SrcFileName);
    }

    private void WriteCompilationUnitStatements(List<CppStatementSyntax> statements, string file) {
      if (statements.Count > 0) {
        Directory.CreateDirectory(OutDir);
        using var writer = new StreamWriter(file, false, Encoding);
        writer_ = writer;
        WriteNodes(statements);
        writer_ = null;
      }
    }

    private void WriteNodes(IEnumerable<CppSyntaxNode> nodes) {
      foreach (var node in nodes) {
        node.Render(this);
      }
    }

    internal void Render(PragmaPretreatmentStatementSyntax statement) {
      Write(statement.Prefix);
      Write(statement.Pragma);
      WriteSpace();
      Write(statement.Symbol);
      WriteNewLine();
    }
  }
}
