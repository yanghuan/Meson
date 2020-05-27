using ICSharpCode.Decompiler.CSharp.Syntax;
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

  sealed class ExpressionStatementSyntax : StatementSyntax {
    public ExpressionSyntax Expression { get; }
    public bool HasSemicolon { get; set; } = true;

    public ExpressionStatementSyntax(ExpressionSyntax expression) {
      Expression = expression ?? throw new ArgumentNullException(nameof(expression));
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class StatementListSyntax : StatementSyntax {
    public readonly SyntaxList<StatementSyntax> Statements = new SyntaxList<StatementSyntax>();
    public bool IsEmpty => Statements.Count == 0;

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public void Add(StatementSyntax statement) {
      Statements.Add(statement);
    }
  }

  sealed class BlankLinesStatement : StatementSyntax {
    public int Count { get; }

    public BlankLinesStatement(int count) {
      Count = count;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly BlankLinesStatement One = new BlankLinesStatement(1);
  }

  internal abstract class PretreatmentSyntax : StatementSyntax {
    public string Prefix => Tokens.PretreatmentPrefix;
  }

  sealed class PragmaPretreatmentSyntax : PretreatmentSyntax {
    public string PragmaToken => Tokens.Pragma;
    public string Symbol { get; }

    public PragmaPretreatmentSyntax(string symbol) {
      Symbol = symbol;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static PragmaPretreatmentSyntax Once = new PragmaPretreatmentSyntax("once");
  }

  sealed class IncludePretreatmentSyntax : PretreatmentSyntax {
    public string IncludeToken => Tokens.Include;
    public string Path { get; }
    public bool IsSystemPath { get; }
    public string OpenToken => IsSystemPath ? Tokens.Less : Tokens.Quote;
    public string CloseToken => IsSystemPath ? Tokens.Greater : Tokens.Quote;

    public IncludePretreatmentSyntax(string path, bool isSystem = true) {
      Path = path;
      IsSystemPath = isSystem;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class DefinePretreatmentSyntax : PretreatmentSyntax {
    public string DefineToken => Tokens.Define;
    public IdentifierSyntax Name { get; }
    public ExpressionSyntax Expression { get; }

    public DefinePretreatmentSyntax(IdentifierSyntax name, ExpressionSyntax expression) {
      Name = name;
      Expression = expression;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class UndefPretreatmentSyntax : PretreatmentSyntax {
    public string UnDefToken => Tokens.Undef;
    public IdentifierSyntax Name { get; }

    public UndefPretreatmentSyntax(IdentifierSyntax name) {
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  class BlockSyntax : StatementSyntax {
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

    public void AddRange(IEnumerable<StatementSyntax> nodes) {
      Statements.AddRange(nodes);
    }
  }

  sealed class NamespaceSyntax : BlockSyntax {
    public string NamespaceToken => Tokens.Namespace;
    public string Name { get; }
    public bool IsEmpty => Statements.Count == 0;

    public NamespaceSyntax(string name) {
      Name = name.Replace(".", "::");
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class EnumSyntax : BlockSyntax {
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

  sealed class EnumFieldSyntax : StatementSyntax {
    public string EqualsToken => Tokens.Equals;
    public IdentifierSyntax Name { get; }
    public string Value { get; }

    public EnumFieldSyntax(IdentifierSyntax name, string value) {
      Name = name;
      Value = value;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class TemplateTypenameSyntax : SyntaxNode {
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

  sealed class TemplateSyntax : SyntaxNode {
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

  sealed class BaseSyntax : SyntaxNode {
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

  sealed class ClassSyntax : BlockSyntax {
    public string AccessibilityToken { get; set; }
    public TemplateSyntax Template { get; set; }
    public string ClassToken => IsStruct ? Tokens.Struct : Tokens.Class;
    public IdentifierSyntax Name { set; get; }
    public readonly List<BaseSyntax> Bases = new List<BaseSyntax>();
    public bool IsStruct { get; }
    public ClassKind Kind { get; set; }

    public ClassSyntax(IdentifierSyntax name, bool isStruct = false) {
      Name = name;
      IsStruct = isStruct;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class FieldDefinitionSyntax : StatementSyntax {
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

  class ClassForwardDeclarationSyntax : StatementSyntax {
    public TemplateSyntax Template { get; set; }
    public string ClassToken => IsStruct ? Tokens.Struct : Tokens.Class;
    public IdentifierSyntax Name { get; }
    public bool IsStruct { get; }
    public bool IsFriend { get; }

    public ClassForwardDeclarationSyntax(IdentifierSyntax name, bool isStruct = false) {
      Name = name;
      IsStruct = isStruct;
    }

    protected ClassForwardDeclarationSyntax(IdentifierSyntax name, bool isStruct, int _) : this(name, isStruct) {
      IsFriend = true;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class UsingDeclarationSyntax : StatementSyntax {
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

  sealed class UsingNamespaceSyntax : StatementSyntax {
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

  sealed class FriendClassDeclarationSyntax : ClassForwardDeclarationSyntax {
    public FriendClassDeclarationSyntax(IdentifierSyntax name, bool isStruct = false) : base(name, isStruct, -1) {
    }
  }

  sealed class ForwardMacroSyntax : StatementSyntax {
    public bool IsMulti { get; }
    public IdentifierSyntax Macro => !IsMulti ? "FORWARD" : "FORWARD_";
    public string AccessibilityToken { get; set; }
    public InvationExpressionSyntax Invation { get; }

    public ForwardMacroSyntax(IdentifierSyntax name, IEnumerable<IdentifierSyntax> typeArguments, bool isMulti = false) {
      IsMulti = isMulti;
      Invation = new InvationExpressionSyntax(Macro);
      Invation.Arguments.Add(name);
      Invation.Arguments.AddRange(typeArguments);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
}
