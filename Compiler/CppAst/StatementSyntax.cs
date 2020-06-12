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
      IsPreventIdnet = true;
      Name = name;
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
    public IEnumerable<IdentifierSyntax> TypeNames => Arguments.OfType<TemplateTypenameSyntax>().Select(i => i.Name);
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

  sealed class ParameterSyntax : SyntaxNode {
    public ExpressionSyntax Type { get; }
    public IdentifierSyntax Name { get; }

    public ParameterSyntax(ExpressionSyntax type, IdentifierSyntax name) {
      Type = type;
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class MethodDefinitionSyntax : StatementSyntax {
    public string AccessibilityToken { get; }
    public ExpressionSyntax RetuenType { get; }
    public IdentifierSyntax Nmae { get; }
    public bool IsStatic { get; }
    public string OpenParentheses => Tokens.OpenParentheses;
    public readonly List<ParameterSyntax> Parameters = new List<ParameterSyntax>();
    public string CloseParentheses => Tokens.CloseParentheses;

    public MethodDefinitionSyntax(ExpressionSyntax retuenType, IdentifierSyntax name, IEnumerable<ParameterSyntax> parameters, bool isStatic, string accessibilityToken) {
      RetuenType = retuenType;
      Nmae = name;
      Parameters.AddRange(parameters);
      IsStatic = isStatic;
      AccessibilityToken = accessibilityToken;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class MethodImplementationSyntax : BlockSyntax {
    public ExpressionSyntax DeclaringType { get; }
    public ExpressionSyntax RetuenType { get; }
    public IdentifierSyntax Name { get; }
    public string OpenParentheses => Tokens.OpenParentheses;
    public readonly List<ParameterSyntax> Parameters = new List<ParameterSyntax>();
    public string CloseParentheses => Tokens.CloseParentheses;

    public MethodImplementationSyntax(IdentifierSyntax name, ExpressionSyntax retuenType, IEnumerable<ParameterSyntax> parameters, ExpressionSyntax declaringType = null) {
      Name = name;
      RetuenType = retuenType;
      DeclaringType = declaringType;
      Parameters.AddRange(parameters);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  class ClassForwardDeclarationSyntax : StatementSyntax {
    public TemplateSyntax Template { get; set; }
    public string ClassToken => IsStruct ? Tokens.Struct : Tokens.Class;
    public ExpressionSyntax Name { get; }
    public bool IsStruct { get; }
    public bool IsFriend { get; }

    public ClassForwardDeclarationSyntax(ExpressionSyntax name, bool isStruct = false) {
      Name = name;
      IsStruct = isStruct;
    }

    protected ClassForwardDeclarationSyntax(ExpressionSyntax name, bool isStruct, int _) : this(name, isStruct) {
      IsFriend = true;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class EnumForwardSyntax : StatementSyntax {
    public string EnumToekn => Tokens.Enum;
    public string ClassToekn => Tokens.Class;
    public IdentifierSyntax UnderlyingType { get; set; }

    public string Name { get; }

    public EnumForwardSyntax(string name) {
      Name = name;
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

  sealed class UsingNamespaceOrTypeSyntax : StatementSyntax {
    public string UsingToken => Tokens.Using;
    public string Name { get; }
    public bool IsNamespace { get; }

    public UsingNamespaceOrTypeSyntax(string name, bool isNamespace = true) {
      Name = name;
      IsNamespace = isNamespace;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class FriendClassDeclarationSyntax : ClassForwardDeclarationSyntax {
    public FriendClassDeclarationSyntax(ExpressionSyntax name, bool isStruct = false) : base(name, isStruct, -1) {
    }
  }

  enum ForwardMacroKind {
    Class,
    MultiClass,
    NestedClass,
    MultiNestedClass,
    Struct,
    MultiStruct,
  }

  sealed class ForwardMacroSyntax : StatementSyntax {
    private static readonly string[] macros_ = new string[] {
      "FORWARD",
      "FORWARD_",
      "FORWARDN",
      "FORWARDN_",
      "FORWARDS",
      "FORWARDS_"
    };

    public ForwardMacroKind Kind { get; }
    public IdentifierSyntax Macro => macros_[(int)Kind];
    public string AccessibilityToken { get; set; }
    public InvationExpressionSyntax Invation { get; }

    public ForwardMacroSyntax(IdentifierSyntax name, IEnumerable<IdentifierSyntax> typeArguments, ForwardMacroKind kind) {
      Kind = kind;
      Invation = new InvationExpressionSyntax(Macro);
      Invation.Arguments.Add(name);
      Invation.Arguments.AddRange(typeArguments);
    }

    public ExpressionStatementSyntax ToUsingMacroSyntax(string ns) {
      IdentifierSyntax name = macros_[(int)Kind].Replace(macros_.First(), "USING");
      var invation = new InvationExpressionSyntax(name);
      invation.Arguments.Add(ns.ReplaceDot());
      invation.Arguments.AddRange(Invation.Arguments);
      return new ExpressionStatementSyntax(invation) { HasSemicolon = false };
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class ReturnStatementSyntax : StatementSyntax {
    public string ReturnKeyword => Tokens.Return;

    public ExpressionSyntax Expression { get; }

    public ReturnStatementSyntax() {
    }

    public ReturnStatementSyntax(ExpressionSyntax expression) {
      Expression = expression;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
}
