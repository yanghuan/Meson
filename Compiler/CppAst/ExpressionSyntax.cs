using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class ExpressionSyntax : SyntaxNode {
    internal MemberAccessExpressionSyntax TwoColon(ExpressionSyntax expression) {
      return new MemberAccessExpressionSyntax(this, expression, MemberAccessOperator.TwoColon);
    }
  }

  internal enum MemberAccessOperator {
    Dot,
    Arrow,
    TwoColon
  }

  internal sealed class MemberAccessExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Expression { get; private set; }
    public ExpressionSyntax Name { get; }
    public string OperatorToken { get; }

    public MemberAccessExpressionSyntax(ExpressionSyntax expression, ExpressionSyntax name, MemberAccessOperator kind) {
      Expression = expression ?? throw new ArgumentNullException(nameof(expression));
      Name = name ?? throw new ArgumentNullException(nameof(name));
      OperatorToken = kind == MemberAccessOperator.Arrow ? Tokens.Arrow : (kind == MemberAccessOperator.TwoColon ? Tokens.TwoColon : Tokens.Dot);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

}
