using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  class CompilationUnitSyntax : SyntaxNode {
    public readonly SyntaxList<StatementSyntax> HeadStatements = new SyntaxList<StatementSyntax>();
    public readonly SyntaxList<StatementSyntax> SrcStatements = new SyntaxList<StatementSyntax>();

    private NamespaceSyntax headNamespaceSyntax_;
    private NamespaceSyntax srcNamespaceSyntax_;
    private StatementListSyntax headIncludes_ = new StatementListSyntax();
    private StatementListSyntax srcIncludes_ = new StatementListSyntax();

    public CompilationUnitSyntax() {
      HeadStatements.Add(PragmaPretreatmentStatementSyntax.Once);
      HeadStatements.Add(BlankLinesStatement.One);
      HeadStatements.Add(headIncludes_);
      headIncludes_.Statements.Add(new IncludePretreatmentStatementSyntax("rt/GCObject.h", true));
    }

    internal override void Render(CppRenderer renderer) {
      if (!headIncludes_.IsEmpty) {
        HeadStatements.Add(BlankLinesStatement.One);
      }
      HeadStatements.Add(headNamespaceSyntax_);
      if (!srcNamespaceSyntax_.IsEmpty) {
        if (!srcIncludes_.IsEmpty) {
          SrcStatements.Add(srcIncludes_);
          SrcStatements.Add(BlankLinesStatement.One);
        }
        SrcStatements.Add(srcNamespaceSyntax_);
      }
      renderer.Render(this);
    }

    internal NamespaceSyntax AddNamespace(string name) {
      headNamespaceSyntax_ = new NamespaceSyntax(name);
      srcNamespaceSyntax_ = new NamespaceSyntax(name);
      return headNamespaceSyntax_;
    }

    private static void AddIncludeTo(StatementListSyntax includes, string path, bool isSystem = true) {
      includes.Statements.Add(new IncludePretreatmentStatementSyntax(path, isSystem));
    }

    public void AddHeadIncludes(IEnumerable<string> files) {
      foreach (string path in files) {
        AddIncludeTo(headIncludes_, path);
      }
    }

    public void AddSrcInclude(string path, bool isSystem = true) {
      AddIncludeTo(srcIncludes_, path, isSystem);
    }

    public void AddSrcStatement(StatementSyntax statement) {
      srcNamespaceSyntax_.Add(statement);
    }
  }
}
