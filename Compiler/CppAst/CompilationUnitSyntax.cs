using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Meson.Compiler.CppAst {
  class CompilationUnitSyntax : SyntaxNode {
    public readonly SyntaxList<StatementSyntax> HeadStatements = new SyntaxList<StatementSyntax>();
    public readonly SyntaxList<StatementSyntax> SrcStatements = new SyntaxList<StatementSyntax>();

    private NamespaceSyntax headNamespaceSyntax_;
    private NamespaceSyntax srcNamespaceSyntax_;
    private readonly StatementListSyntax srcIncludes_ = new StatementListSyntax();

    public CompilationUnitSyntax() {
      HeadStatements.Add(PragmaPretreatmentSyntax.Once);
      HeadStatements.Add(BlankLinesStatement.One);
    }

    internal override void Render(CppRenderer renderer) {
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
      includes.Statements.Add(new IncludePretreatmentSyntax(path, isSystem));
    }

    public void AddHeadIncludes(IEnumerable<string> files) {
      HeadStatements.Add(new IncludePretreatmentSyntax("rt/GCObject.h"));
      HeadStatements.AddRange(files.Select(i => new IncludePretreatmentSyntax(i)));
      HeadStatements.Add(BlankLinesStatement.One);
    }

    public void AddSrcInclude(string path, bool isSystem = true) {
      AddIncludeTo(srcIncludes_, path, isSystem);
    }

    public void AddSrcStatement(StatementSyntax statement) {
      srcNamespaceSyntax_.Add(statement);
    }
  }
}
