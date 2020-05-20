using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class StatementSyntax : SyntaxNode {
    public static implicit operator StatementSyntax(ExpressionSyntax expression) {
      return new ExpressionStatementSyntax(expression);
    }
  }

  internal sealed class ExpressionStatementSyntax : StatementSyntax {
    public ExpressionSyntax Expression { get; }
    public bool HasSemicolon { get; set; } = true;

    public ExpressionStatementSyntax(ExpressionSyntax expression) {
      Expression = expression ?? throw new ArgumentNullException(nameof(expression));
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class StatementListSyntax : StatementSyntax {
    public readonly SyntaxList<StatementSyntax> Statements = new SyntaxList<StatementSyntax>();
    public bool IsEmpty => Statements.Count == 0;

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public void Add(StatementSyntax statement) {
      Statements.Add(statement);
    }
  }

  internal sealed class BlankLinesStatement : StatementSyntax {
    public int Count { get; }

    public BlankLinesStatement(int count) {
      Count = count;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly BlankLinesStatement One = new BlankLinesStatement(1);
  }

  internal abstract class PretreatmentStatementSyntax : StatementSyntax {
    public string Prefix => Tokens.PretreatmentPrefix;
  }

  internal sealed class PragmaPretreatmentStatementSyntax : PretreatmentStatementSyntax {
    public string PragmaToken => Tokens.Pragma;
    public string Symbol { get; }

    public PragmaPretreatmentStatementSyntax(string symbol) {
      Symbol = symbol;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static PragmaPretreatmentStatementSyntax Once = new PragmaPretreatmentStatementSyntax("once");
  }

  internal sealed class IncludePretreatmentStatementSyntax : PretreatmentStatementSyntax {
    public string IncludeToken => Tokens.Include;

    public string Path { get; }
    public bool IsSystemPath { get; }

    public IncludePretreatmentStatementSyntax(string path, bool isSystem = false) {
      Path = path;
      IsSystemPath = isSystem;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal class BlockSyntax : StatementSyntax {
    public string OpenToken => Tokens.OpenBrace;
    public string CloseToken => Tokens.CloseBrace;
    public bool IsPreventIdnet { get; set; } 

    public readonly SyntaxList<StatementSyntax> Statements = new SyntaxList<StatementSyntax>();

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public void Add(StatementSyntax statement) {
      Statements.Add(statement);
    }
  }

  internal sealed class NamespaceSyntax : BlockSyntax {
    public string NamespaceToken => Tokens.Namespace;
    public string CloseComment => $"// {NamespaceToken} {Name}";
    public string Name { get; }
    public NamespaceSyntax Current { get; private set; }
    public bool IsEmpty => Current.Statements.Count == 0;

    public NamespaceSyntax(string name) {
      if (name.Contains('.')) {
        string[] names = name.Split('.');
        Name = names.First();
        Current = this;
        for (int i = 1; i < names.Length; ++ i) {
          var ns = new NamespaceSyntax(names[i]);
          Current.Statements.Add(ns);
          Current = ns;
        }
      } else {
        Name = name;
        Current = this;
      }
      IsPreventIdnet = true;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public new void Add(StatementSyntax node) {
      Current.Statements.Add(node);
    }
  }

  internal sealed class EnumSyntax : BlockSyntax {
    public string AccessibilityToken { get; set; }
    public string EnumToekn => Tokens.Enum;
    public string ClassToekn => Tokens.Class;
    public IdentifierSyntax UnderlyingType { get; set; }

    public string Name { get; }

    public EnumSyntax(string name) {
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class EnumFieldSyntax : StatementSyntax {
    public string EqualsToken => Tokens.Equals;
    public string Name { get; }
    public string Value { get; }

    public EnumFieldSyntax(string name, string value) {
      Name = name;
      Value = value;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class TemplateTypenameSyntax : SyntaxNode {
    public string ClassToken => Tokens.Class;
    public IdentifierSyntax Name { get; }
    public string EqualsToken => Tokens.Equals;
    public IdentifierSyntax Value { get; set; }

    public TemplateTypenameSyntax(IdentifierSyntax name) {
      Name = name;
    }

    public TemplateTypenameSyntax(IdentifierSyntax name, IdentifierSyntax value) {
      Name = name;
      Value = value;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class TemplateSyntax : SyntaxNode {
    public string TemplateToken => Tokens.Template;
    public string OpenBrace => Tokens.Less;
    public readonly SyntaxList<SyntaxNode> Arguments = new SyntaxList<SyntaxNode>();
    public string CloseBrace => Tokens.Greater;

    public TemplateSyntax(TemplateTypenameSyntax argument) {
      Arguments.Add(argument);
    }

    public TemplateSyntax(params TemplateTypenameSyntax[] args) {
      Arguments.AddRange(args);
    }

    public TemplateSyntax(IEnumerable<TemplateTypenameSyntax> args) {
      Arguments.AddRange(args);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly TemplateSyntax T = new TemplateSyntax(new TemplateTypenameSyntax(IdentifierSyntax.T));
    public static readonly TemplateSyntax Empty = new TemplateSyntax();
  }

  internal sealed class BaseSyntax : SyntaxNode {
    public ExpressionSyntax Type { get; }

    public BaseSyntax(IdentifierSyntax type) {
      Type = type;
    }

    public BaseSyntax(ExpressionSyntax type) {
      Type = type;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal enum ClassKind { 
    None,
    Ref,
    Array,
    Multi,
    MultiRef,
    MultiRefForward,
  }

  internal sealed class ClassSyntax : BlockSyntax {
    public string AccessibilityToken { get; set; }
    public TemplateSyntax Template { get; set; }
    public string ClassOrStructToken => IsClassOrStruct ? Tokens.Class : Tokens.Struct;
    public IdentifierSyntax Name { set; get; }
    public readonly List<BaseSyntax> Bases = new List<BaseSyntax>();
    public bool IsClassOrStruct { get; }
    public ClassKind Kind { get; set; }

    public ClassSyntax(IdentifierSyntax name, bool isClass = true) {
      Name = name;
      IsClassOrStruct = isClass;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class FieldDefinitionSyntax : StatementSyntax {
    public string AccessibilityToken { get; }
    public ExpressionSyntax Type { get; }
    public IdentifierSyntax Nmae { get; }
    public bool IsStatic { get; }

    public FieldDefinitionSyntax(ExpressionSyntax type, IdentifierSyntax name, bool isStatic, string accessibilityToken) {
      Type = type;
      Nmae = name;
      IsStatic = isStatic;
      AccessibilityToken = accessibilityToken;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class ClassStaticFieldInitSyntax : StatementSyntax {
    public TemplateSyntax Template { get; }
    public ExpressionSyntax FieldType { get; }

    public IdentifierSyntax ClassName { get; }
    public string TwoColon => Tokens.TwoColon;
    public IdentifierSyntax FieldName { get; }

    public ClassStaticFieldInitSyntax(ExpressionSyntax fieldType, IdentifierSyntax fieldName, IdentifierSyntax className, TemplateSyntax template = null) {
      FieldType = fieldType;
      FieldName = fieldName;
      ClassName = template != null ? className.WithGeneric(template) : className;
      Template = template;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class ClassForwardDeclarationSyntax : StatementSyntax {
    public TemplateSyntax Template { get; set; }
    public string ClassOrStructToken => IsClassOrStruct ? Tokens.Class : Tokens.Struct;
    public IdentifierSyntax Name { get; }
    public bool IsClassOrStruct { get; }

    public ClassForwardDeclarationSyntax(IdentifierSyntax name, bool isClass = true) {
      Name = name;
      IsClassOrStruct = isClass;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class UsingDeclarationSyntax : StatementSyntax {
    public TemplateSyntax Template { get; set; }
    public string UsingToken => Tokens.Using;
    public IdentifierSyntax Name { get; }
    public string EqualsToken => Tokens.Equals;
    public ExpressionSyntax Type { get; }

    public UsingDeclarationSyntax(IdentifierSyntax name, ExpressionSyntax type) {
      Name = name;
      Type = type;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class UsingNamespaceSyntax : StatementSyntax {
    public string UsingToken => Tokens.Using;
    public string NamespaceToken => Tokens.Namespace;

    public string Name { get; }

    public UsingNamespaceSyntax(string name) {
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

  }
}
