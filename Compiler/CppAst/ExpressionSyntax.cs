using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class ExpressionSyntax : SyntaxNode {
    private sealed class EmptyExpressionSyntax : ExpressionSyntax {
      internal override void Render(CppRenderer renderer) {
      }
    }

    public static implicit operator ExpressionSyntax(string valueText) {
      return new ValueTextIdentifierSyntax(valueText);
    }

    public static readonly ExpressionSyntax EmptyExpression = new EmptyExpressionSyntax();

    internal MemberAccessExpressionSyntax TwoColon(ExpressionSyntax expression) {
      return new MemberAccessExpressionSyntax(this, expression, MemberAccessOperator.TwoColon);
    }

    internal MemberAccessExpressionSyntax Arrow(ExpressionSyntax expression) {
      return new MemberAccessExpressionSyntax(this, expression, MemberAccessOperator.Arrow);
    }

    internal CastExpressionSyntax CastTo(ExpressionSyntax target, bool isParenthesesCast = false) {
      return new CastExpressionSyntax(this, target, isParenthesesCast);
    }

    internal AddressIdentifierSyntax Address() {
      return new AddressIdentifierSyntax(this);
    }

    internal ReturnStatementSyntax Return() {
      return new ReturnStatementSyntax(this);
    }

    internal InvationExpressionSyntax Invation() {
      return new InvationExpressionSyntax(this);
    }

    internal InvationExpressionSyntax Invation(params ExpressionSyntax[] arguments) {
      return new InvationExpressionSyntax(this, arguments);
    }

    internal InvationExpressionSyntax Invation(IEnumerable<ExpressionSyntax> arguments) {
      return new InvationExpressionSyntax(this, arguments);
    }

    internal GenericIdentifierSyntax Generic(params ExpressionSyntax[] args) {
      return new GenericIdentifierSyntax(this, args);
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

  internal sealed class InvationExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Expression { get; }
    public string OpenBrace => Tokens.Less;
    public readonly List<ExpressionSyntax> TypeArguments = new List<ExpressionSyntax>();
    public string CloseBrace => Tokens.Greater;

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

  internal sealed class BooleanLiteralExpressionSyntax : LiteralExpressionSyntax {
    public bool Value { get; }

    private BooleanLiteralExpressionSyntax(bool value) {
      Value = value;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly BooleanLiteralExpressionSyntax False = new BooleanLiteralExpressionSyntax(false);
    public static readonly BooleanLiteralExpressionSyntax True = new BooleanLiteralExpressionSyntax(true);
  }

  internal sealed class NumberLiteralExpressionSyntax : LiteralExpressionSyntax {
    public string Value { get; }

    public NumberLiteralExpressionSyntax(string value) {
      Value = value;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly NumberLiteralExpressionSyntax Zero = new NumberLiteralExpressionSyntax("0");
  }

  internal sealed class CodeTemplateExpressionSyntax : ExpressionSyntax {
    public readonly List<ExpressionSyntax> Expressions = new List<ExpressionSyntax>();

    public CodeTemplateExpressionSyntax() { }

    public CodeTemplateExpressionSyntax(params ExpressionSyntax[] expressions) {
      Expressions.AddRange(expressions);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class CastExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Expression { get; }
    public ExpressionSyntax Target { get; }
    public bool IsParenthesesCast { get; }

    public CastExpressionSyntax(ExpressionSyntax expression, ExpressionSyntax target, bool isParenthesesCast = false) {
      Expression = expression;
      Target = target;
      IsParenthesesCast = isParenthesesCast;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class BinaryExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Left { get; }
    public string OperatorToken { get; }
    public ExpressionSyntax Right { get; }

    public BinaryExpressionSyntax(ExpressionSyntax left, string operatorToken, ExpressionSyntax right) {
      Left = left;
      OperatorToken = operatorToken;
      Right = right;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

}
