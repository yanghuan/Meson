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
    public static readonly IdentifierSyntax FixedBuffer = "rt::FixedBuffer";
    public static readonly IdentifierSyntax Void = "void";
    public static readonly IdentifierSyntax Object = "Object";
    public static readonly IdentifierSyntax T = "T";
    public static readonly IdentifierSyntax In = "in";
    public static readonly IdentifierSyntax Is = "rt::is";
    public static readonly IdentifierSyntax Cast = "rt::cast";
    public static readonly IdentifierSyntax Out = "out";
    public static readonly IdentifierSyntax Value = "value";
    public static readonly IdentifierSyntax NAME = "NAME";
    public static readonly IdentifierSyntax Nullptr = Tokens.Nullptr;
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
    public readonly List<ExpressionSyntax> GenericArguments = new List<ExpressionSyntax>();
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

  internal sealed class RefIdentifierSyntax : IdentifierSyntax {
    public ExpressionSyntax Name { get; }
    public string Ampersand => Tokens.Ampersand;

    public RefIdentifierSyntax(ExpressionSyntax name) {
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class AddressIdentifierSyntax : IdentifierSyntax {
    public ExpressionSyntax Name { get; }
    public string Ampersand => Tokens.Ampersand;

    public AddressIdentifierSyntax(ExpressionSyntax name) {
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class NestedCycleRefTypeNameSyntax : IdentifierSyntax {
    public IdentifierSyntax Type { get; }
    public string OpenComment => Tokens.OpneComment;
    public string FullName { get; }
    public string CloseComment => Tokens.CloseComment;

    public NestedCycleRefTypeNameSyntax(string fullName) : this(fullName, Object) {
    }

    public NestedCycleRefTypeNameSyntax(string fullName, IdentifierSyntax type) {
      FullName = fullName;
      Type = type;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class SymbolNameSyntax : IdentifierSyntax {
    public IdentifierSyntax NameExpression { get; private set; }

    public SymbolNameSyntax(IdentifierSyntax identifierName) {
      NameExpression = identifierName;
    }

    public void Update(IdentifierSyntax newName) {
      NameExpression = newName;
    }

    internal override void Render(CppRenderer renderer) {
      NameExpression.Render(renderer);
    }
  }
}
