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
    public bool IsSrcEmpty => srcNamespaceSyntax_.IsEmpty;

    public CompilationUnitSyntax() {
      HeadStatements.Add(PragmaPretreatmentSyntax.Once);
      HeadStatements.Add(BlankLinesStatement.One);
      SrcStatements.Add(srcIncludes_);
      SrcStatements.Add(BlankLinesStatement.One);
    }

    internal override void Render(CppRenderer renderer) {
      HeadStatements.Add(headNamespaceSyntax_);
      renderer.Render(this);
    }

    internal (NamespaceSyntax, NamespaceSyntax) AddNamespace(string name, string typeName) {
      string classNamespaceName = typeName.WithNamespace();
      headNamespaceSyntax_ = new NamespaceSyntax(name);
      srcNamespaceSyntax_ = new NamespaceSyntax($"{(name.Length > 0 ? name + '.' + classNamespaceName : classNamespaceName)}");
      SrcStatements.Add(srcNamespaceSyntax_);
      return (headNamespaceSyntax_, new NamespaceSyntax(classNamespaceName));
    }

    public void AddHeadIncludes(IEnumerable<string> references) {
      HeadStatements.Add(new IncludePretreatmentSyntax("rt/GCObject.h"));
      HeadStatements.AddRange(references.Select(i => new IncludePretreatmentSyntax(i)));
      HeadStatements.Add(BlankLinesStatement.One);
    }

    public void AddEnumHeadInclude() {
      HeadStatements.Add(new IncludePretreatmentSyntax("cstdint"));
      HeadStatements.Add(BlankLinesStatement.One);
    }

    public void AddSrcIncludes(string head, IEnumerable<string> references) {
      srcIncludes_.Statements.Add(new IncludePretreatmentSyntax(head, false));
      if (references.Any()) {
        srcIncludes_.Add(BlankLinesStatement.One);
        srcIncludes_.Statements.AddRange(references.Select(i => new IncludePretreatmentSyntax(i)));
      }
      srcNamespaceSyntax_.Add(BlankLinesStatement.One);
    }

    public void AddSrcStatement(StatementSyntax statement) {
      srcNamespaceSyntax_.Add(statement);
    }
  }
}
