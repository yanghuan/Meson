using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class ExpressionSyntax : SyntaxNode {
    private sealed class EmptyExpressionSyntax : ExpressionSyntax {
      internal override void Render(CppRenderer renderer) {
      }
    }

    internal MemberAccessExpressionSyntax TwoColon(ExpressionSyntax expression) {
      return new MemberAccessExpressionSyntax(this, expression, MemberAccessOperator.TwoColon);
    }

    public static implicit operator ExpressionSyntax(string valueText) {
      return new ValueTextIdentifierSyntax(valueText);
    }

    public static readonly ExpressionSyntax EmptyExpression = new EmptyExpressionSyntax();
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

  internal sealed class InvationExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Expression { get; }
    public string OpenParentheses => Tokens.OpenParentheses;
    public List<ExpressionSyntax> Arguments = new List<ExpressionSyntax>();
    public string CloseParentheses => Tokens.CloseParentheses;

    public InvationExpressionSyntax(ExpressionSyntax expresison) {
      Expression = expresison;
    }

    public InvationExpressionSyntax(ExpressionSyntax expresison, params ExpressionSyntax[] arguments) {
      Expression = expresison;
      Arguments.AddRange(arguments);
    }


    public InvationExpressionSyntax(ExpressionSyntax expresison, IEnumerable<ExpressionSyntax> arguments) {
      Expression = expresison;
      Arguments.AddRange(arguments);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal abstract class LiteralExpressionSyntax : ExpressionSyntax {
  }

  internal sealed class StringLiteralExpressionSyntax : LiteralExpressionSyntax {
    public string OpenParenToken => Tokens.Quote;
    public string Value { get; }
    public string CloseParenToken => Tokens.Quote;

    public StringLiteralExpressionSyntax(string value) {
      Value = value;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly StringLiteralExpressionSyntax Empty = new StringLiteralExpressionSyntax(string.Empty);
  }

}
