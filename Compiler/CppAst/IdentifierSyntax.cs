using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class IdentifierSyntax : ExpressionSyntax {
    public static implicit operator IdentifierSyntax(string valueText) {
      return new ValueTextIdentifierSyntax(valueText);
    }

    public static readonly IdentifierSyntax Meson = "rt";
    public static readonly IdentifierSyntax array = "array";
    public static readonly IdentifierSyntax FixedBuffer = "rt::FixedBuffer";
    public static readonly IdentifierSyntax Void = "void";
    public static readonly IdentifierSyntax T = "T";

    public GenericIdentifierSyntax WithGeneric(TemplateSyntax template) {
      return new GenericIdentifierSyntax(this, template.Arguments.OfType<TemplateTypenameSyntax>().Select(i => i.Name));
    }
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
    public ExpressionSyntax Name { get; }
    public string OpenBrace => Tokens.Less;
    public readonly SyntaxList<ExpressionSyntax> GenericArguments = new SyntaxList<ExpressionSyntax>();
    public string CloseBrace => Tokens.Greater;

    public GenericIdentifierSyntax(ExpressionSyntax name) {
      Name = name;
    }

    public GenericIdentifierSyntax(ExpressionSyntax name, IEnumerable<ExpressionSyntax> args) {
      Name = name;
      GenericArguments.AddRange(args);
    }

    public GenericIdentifierSyntax(ExpressionSyntax name, params ExpressionSyntax[] args) {
      Name = name;
      GenericArguments.AddRange(args);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class PointerIdentifierSyntax : IdentifierSyntax {
    public ExpressionSyntax Name { get; }
    public string Asterisk => Tokens.Asterisk;

    public PointerIdentifierSyntax(ExpressionSyntax name) {
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
}
