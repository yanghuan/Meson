using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Meson.Compiler.CppAst {
  class CompilationUnitSyntax : SyntaxNode {
    public readonly SyntaxList<StatementSyntax> HeadStatements = new SyntaxList<StatementSyntax>();
    public readonly SyntaxList<StatementSyntax> SrcStatements = new SyntaxList<StatementSyntax>();
    public readonly SyntaxList<StatementSyntax> ReferencesIncludes = new SyntaxList<StatementSyntax>();
    private readonly StatementListSyntax srcIncludes_ = new StatementListSyntax();
    private NamespaceSyntax headNamespaceSyntax_;
    private NamespaceSyntax srcNamespaceSyntax_;

    public bool IsSrcEmpty => srcNamespaceSyntax_.IsEmpty;

    public CompilationUnitSyntax() {
      HeadStatements.Add(PragmaPretreatmentSyntax.Once);
      HeadStatements.Add(BlankLinesStatement.One);
      SrcStatements.Add(srcIncludes_);
    }

    internal override void Render(CppRenderer renderer) {
      HeadStatements.Add(headNamespaceSyntax_);
      renderer.Render(this);
    }

    internal (NamespaceSyntax, NamespaceSyntax) AddNamespace(string name, string typeName) {
      string classNamespaceName = typeName.WithNamespace();
      headNamespaceSyntax_ = new NamespaceSyntax(name);
      srcNamespaceSyntax_ = new NamespaceSyntax($"{name}{Tokens.TwoColon}{classNamespaceName}");
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

    public void AddReferencesIncludes(string typeName, IEnumerable<string> references) {
      ReferencesIncludes.Add(PragmaPretreatmentSyntax.Once);
      ReferencesIncludes.Add(BlankLinesStatement.One);
      ReferencesIncludes.Add(new IncludePretreatmentSyntax($"{typeName}.h", false));
      if (references.Any()) {
        ReferencesIncludes.Add(BlankLinesStatement.One);
        ReferencesIncludes.AddRange(references.Select(i => new IncludePretreatmentSyntax(i)));
      }

      srcIncludes_.Add(new IncludePretreatmentSyntax($"{typeName}{Utils.kDependExtra}.h", false));
      srcIncludes_.Add(BlankLinesStatement.One);
    }

    public void AddSrcReferencesIncludes(IEnumerable<string> references) {
      if (references.Any()) {
        srcIncludes_.AddRange(references.Select(i => new IncludePretreatmentSyntax(i)));
        srcIncludes_.Add(BlankLinesStatement.One);
      }
    }

    public void AddSrcStatement(StatementSyntax statement) {
      srcNamespaceSyntax_.Add(statement);
    }
  }
}
