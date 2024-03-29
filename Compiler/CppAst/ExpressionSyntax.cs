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

    internal MemberAccessExpressionSyntax Dot(ExpressionSyntax expression) {
      return new MemberAccessExpressionSyntax(this, expression, MemberAccessOperator.Dot);
    }

    internal MemberAccessExpressionSyntax WithIn() {
      return TwoColon(IdentifierSyntax.In);
    }

    internal CastExpressionSyntax CastTo(ExpressionSyntax target) {
      return new CastExpressionSyntax(this, target);
    }

    internal AddressExpressionSyntax Address() {
      return new AddressExpressionSyntax(this);
    }

    internal RefExpressionSyntax Ref() {
      return new RefExpressionSyntax(this);
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

    internal GenericIdentifierSyntax Generic() => new GenericIdentifierSyntax(this);

    internal GenericIdentifierSyntax Generic(params ExpressionSyntax[] args) {
      return new GenericIdentifierSyntax(this, args);
    }

    internal GenericIdentifierSyntax Generic(IEnumerable<ExpressionSyntax> args) {
      return new GenericIdentifierSyntax(this, args);
    }

    internal ParenthesizedExpressionSyntax Parenthesized() {
      return new ParenthesizedExpressionSyntax(this);
    }

    internal BinaryExpressionSyntax Binary(string operatorToken, ExpressionSyntax right) {
      return new BinaryExpressionSyntax(this, operatorToken, right);
    }
  }

  internal enum MemberAccessOperator {
    Dot,
    Arrow,
    TwoColon
  }

  internal sealed class MemberAccessExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Expression { get; private set; }
    public ExpressionSyntax Name { get; set; }
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
    public readonly List<ExpressionSyntax> TypeArguments = new List<ExpressionSyntax>();
    public readonly List<ExpressionSyntax> Arguments = new List<ExpressionSyntax>();

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

  internal sealed class IndexerExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Expression { get; }
    public List<ExpressionSyntax> Arguments = new List<ExpressionSyntax>();
    
    public IndexerExpressionSyntax(ExpressionSyntax expresison, IEnumerable<ExpressionSyntax> arguments) {
      Expression = expresison;
      Arguments.AddRange(arguments);
    }

    public IndexerExpressionSyntax(ExpressionSyntax expresison, ExpressionSyntax argument) {
      Expression = expresison;
      Arguments.Add(argument);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal abstract class LiteralExpressionSyntax : ExpressionSyntax {
  }

  internal sealed class CharLiteralExpressionSyntax : LiteralExpressionSyntax {
    public char Char { get; set; }
    public string ValueText { get; }

    public CharLiteralExpressionSyntax(char ch, string valueText) {
      Char = ch;
      ValueText = valueText;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class StringLiteralExpressionSyntax : LiteralExpressionSyntax {
    public string Value { get; }

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
    public bool IsZero => Value == Zero.Value;
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

    public CastExpressionSyntax(ExpressionSyntax expression, ExpressionSyntax target) {
      Expression = expression;
      Target = target;
      IsParenthesesCast = true;
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

  internal sealed class ParenthesizedExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Expression { get; }
    public ParenthesizedExpressionSyntax(ExpressionSyntax expression) {
      Expression = expression;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class LambdaExpressionSyntax : ExpressionSyntax {
    public List<string> Captures { get; set; }
    public List<TemplateTypenameSyntax> TypeParameters { get; set; }
    public ExpressionSyntax RetuenType { get; }
    public List<ParameterSyntax> Parameters { get; } = new List<ParameterSyntax>();
    public BlockSyntax Body { get; }

    public LambdaExpressionSyntax(IEnumerable<ParameterSyntax> parameters, ExpressionSyntax retuenType, BlockSyntax body) {
      Parameters.AddRange(parameters);
      RetuenType = retuenType;
      Body = body;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class ConditionalExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax Condition { get; }
    public ExpressionSyntax TrueExpression { get; }
    public ExpressionSyntax FalseExpression { get; }

    public ConditionalExpressionSyntax(ExpressionSyntax condition, ExpressionSyntax trueExpression, ExpressionSyntax falseExpression) {
      Condition = condition;
      TrueExpression = trueExpression;
      FalseExpression = falseExpression;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class InitializationExpressionSyntax : ExpressionSyntax {
    public List<ExpressionSyntax> Expressions = new List<ExpressionSyntax>();

    public InitializationExpressionSyntax(IEnumerable<ExpressionSyntax> expressions) {
      Expressions.AddRange(expressions);
    }

    public InitializationExpressionSyntax(params ExpressionSyntax[] expressions) {
      Expressions.AddRange(expressions);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
}
