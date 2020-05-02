using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.Ast {
  class CppCompilationUnitSyntax : CppSyntaxNode {
    public readonly CppSyntaxList<CppStatementSyntax> HeadStatements = new CppSyntaxList<CppStatementSyntax>();
    public readonly CppSyntaxList<CppStatementSyntax> SrcStatements = new CppSyntaxList<CppStatementSyntax>();

    public CppCompilationUnitSyntax() {
      HeadStatements.Add(PragmaPretreatmentStatementSyntax.Once);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
}
