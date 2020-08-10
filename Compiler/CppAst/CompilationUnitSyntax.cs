using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Meson.Compiler.CppAst {
  class CompilationUnitSyntax : SyntaxNode {
    public readonly List<StatementSyntax> HeadStatements = new List<StatementSyntax>();
    public readonly List<StatementSyntax> SrcStatements = new List<StatementSyntax>();
    private readonly List<StatementSyntax> referencesIncludes_ = new List<StatementSyntax>();
    private readonly List<StatementSyntax> inlineStatements_ = new List<StatementSyntax>();
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
      renderer.Render(this);
    }

    internal (NamespaceSyntax, NamespaceSyntax) AddNamespace(string name, string typeName) {
      string classNamespaceName = typeName.WithNamespace();
      headNamespaceSyntax_ = new NamespaceSyntax(name);
      srcNamespaceSyntax_ = new NamespaceSyntax($"{name}{Tokens.TwoColon}{classNamespaceName}");
      SrcStatements.Add(srcNamespaceSyntax_);
      return (headNamespaceSyntax_, new NamespaceSyntax(classNamespaceName));
    }

    internal void AddNamespaceClose() {
      HeadStatements.Add(headNamespaceSyntax_);
    }

    private void AddGCObjectHeadInclude() {
      HeadStatements.Add(new IncludePretreatmentSyntax("rt/GCObject.h"));
    }

    internal void AddHeadIncludes(IEnumerable<string> references) {
      if (references.Any()) {
        HeadStatements.AddRange(references.Select(i => new IncludePretreatmentSyntax(i)));
      } else {
        AddGCObjectHeadInclude();
      }
      HeadStatements.Add(BlankLinesStatement.One);
    }

    public void AddEnumHeadInclude() {
      HeadStatements.Add(new IncludePretreatmentSyntax("cstdint"));
      HeadStatements.Add(BlankLinesStatement.One);
    }

    public void AddReferencesIncludes(string typeName, IEnumerable<string> references) {
      referencesIncludes_.Add(PragmaPretreatmentSyntax.Once);
      referencesIncludes_.Add(BlankLinesStatement.One);
      referencesIncludes_.Add(new IncludePretreatmentSyntax($"{typeName}.h", false));
      if (references.Any()) {
        referencesIncludes_.Add(BlankLinesStatement.One);
        referencesIncludes_.AddRange(references.Select(i => new IncludePretreatmentSyntax(i)));
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

    internal void AddInlineMethodDefinition(MethodDefinitionSyntax node) {
      inlineStatements_.Add(node);
      inlineStatements_.Add(BlankLinesStatement.One);
    }

    internal List<StatementSyntax> ReferencesIncludes {
      get {
        if (inlineStatements_.Count == 0) {
          return referencesIncludes_;
        }

        var statements = referencesIncludes_.ToList();
        statements.Add(BlankLinesStatement.One);
        var ns = new NamespaceSyntax(srcNamespaceSyntax_.Name);
        ns.AddRange(inlineStatements_);
        statements.Add(ns);
        return statements;
      }
    }
  }
}
