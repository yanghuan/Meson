using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class IdentifierSyntax : ExpressionSyntax {
    public static implicit operator IdentifierSyntax(string valueText) {
      return new ValueTextIdentifierSyntax(valueText);
    }

    public static readonly IdentifierSyntax Array = "Array";
    public static readonly IdentifierSyntax Ref = "meson::ref";
    public static readonly IdentifierSyntax BaseString = "meson::String";
    public static readonly IdentifierSyntax BaseArray = "meson::Array";
    public static readonly IdentifierSyntax T = "T";
  }

  internal class ValueTextIdentifierSyntax : IdentifierSyntax {
    public string ValueText { get; }

    public ValueTextIdentifierSyntax(string valueText) {
      ValueText = valueText;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal class GenericIdentifierSyntax : IdentifierSyntax {
    public IdentifierSyntax Identifier { get; }
    public string OpenBrace => Tokens.Less;
    public readonly SyntaxList<ExpressionSyntax> GenericArguments = new SyntaxList<ExpressionSyntax>();
    public string CloseBrace => Tokens.Greater;

    public GenericIdentifierSyntax(IdentifierSyntax identifier) {
      Identifier = identifier;
    }

    public GenericIdentifierSyntax(IdentifierSyntax identifier, params ExpressionSyntax[] args) : this(identifier) {
      GenericArguments.AddRange(args);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
}
