using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class IdentifierSyntax : ExpressionSyntax {
    public static implicit operator IdentifierSyntax(string valueText) {
      return (ValueTextIdentifierSyntax)valueText;
    }
  }

  internal class ValueTextIdentifierSyntax : IdentifierSyntax {
    public string ValueText { get; }

    public ValueTextIdentifierSyntax(string valueText) {
      ValueText = valueText;
    }

    public static implicit operator ValueTextIdentifierSyntax(string valueText) {
      return new ValueTextIdentifierSyntax(valueText);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly ValueTextIdentifierSyntax Array = "Array";
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
