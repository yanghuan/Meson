using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  class CompilationUnitSyntax : SyntaxNode {
    public string RootTypeName { get; }
    public readonly SyntaxList<StatementSyntax> HeadStatements = new SyntaxList<StatementSyntax>();
    public readonly SyntaxList<StatementSyntax> SrcStatements = new SyntaxList<StatementSyntax>();

    private NamespaceSyntax headNamespaceSyntax_;
    private NamespaceSyntax srcNamespaceSyntax_;
    private StatementListSyntax includes_ = new StatementListSyntax();

    public CompilationUnitSyntax(string name) {
      RootTypeName = name;
      HeadStatements.Add(PragmaPretreatmentStatementSyntax.Once);
      HeadStatements.Add(BlankLinesStatement.One);
      HeadStatements.Add(includes_);
      includes_.Statements.Add(new IncludePretreatmentStatementSyntax("rt/GCObject.h", true));
    }

    internal override void Render(CppRenderer renderer) {
      if (includes_.Statements.Count > 0) {
        HeadStatements.Add(BlankLinesStatement.One);
      }
      HeadStatements.Add(headNamespaceSyntax_);
      if (!srcNamespaceSyntax_.IsEmpty) {
        SrcStatements.Add(new IncludePretreatmentStatementSyntax($"{RootTypeName}.h"));
        SrcStatements.Add(srcNamespaceSyntax_);
      }
      renderer.Render(this);
    }

    internal NamespaceSyntax AddNamespace(string name) {
      headNamespaceSyntax_ = new NamespaceSyntax(name);
      srcNamespaceSyntax_ = new NamespaceSyntax(name);
      return headNamespaceSyntax_;
    }

    public void AddIncludes(List<string> filePaths) {
      foreach (string path in filePaths) {
        includes_.Statements.Add(new IncludePretreatmentStatementSyntax(path, true));
      }
    }

    public void AddTypeMetadataVar(string typeName) {
      string code = $"meson::TypeMetadata {typeName}::typeMetadata_{{}}";
      srcNamespaceSyntax_.Add((IdentifierSyntax)code);
    }
  }
}
