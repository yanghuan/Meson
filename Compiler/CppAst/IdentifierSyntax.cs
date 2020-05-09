using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class IdentifierSyntax : ExpressionSyntax {
    public static implicit operator IdentifierSyntax(string valueText) {
      return new ValueTextIdentifierSyntax(valueText);
    }

    public static readonly IdentifierSyntax array = "array";
    public static readonly IdentifierSyntax Ref = "meson::ref";
    public static readonly IdentifierSyntax BaseString = "meson::String";
    public static readonly IdentifierSyntax BaseArray = "meson::Array";
    public static readonly IdentifierSyntax T = "T";
    public static readonly IdentifierSyntax InsertMetadataObj = "INSERT_METADATA_OBJ";

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
    public IdentifierSyntax Identifier { get; }
    public string OpenBrace => Tokens.Less;
    public readonly SyntaxList<ExpressionSyntax> GenericArguments = new SyntaxList<ExpressionSyntax>();
    public string CloseBrace => Tokens.Greater;

    public GenericIdentifierSyntax(IdentifierSyntax identifier) {
      Identifier = identifier;
    }

    public GenericIdentifierSyntax(IdentifierSyntax identifier, IEnumerable<ExpressionSyntax> args) {
      Identifier = identifier;
      GenericArguments.AddRange(args);
    }

    public GenericIdentifierSyntax(IdentifierSyntax identifier, params ExpressionSyntax[] args) {
      Identifier = identifier;
      GenericArguments.AddRange(args);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
}
