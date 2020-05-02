using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.Ast {
  class CppStatementSyntax : CppSyntaxNode {
  }

  class CppPretreatmentStatementSyntax : CppStatementSyntax {
    public string Prefix => Tokens.PretreatmentPrefix;
  }

  class PragmaPretreatmentStatementSyntax : CppPretreatmentStatementSyntax {
    public string Pragma => Tokens.Pragma;
    public string Symbol { get; }

    public PragmaPretreatmentStatementSyntax(string symbol) {
      Symbol = symbol;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static PragmaPretreatmentStatementSyntax Once = new PragmaPretreatmentStatementSyntax("once");
  }
}
