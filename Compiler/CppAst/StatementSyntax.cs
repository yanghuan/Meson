using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class StatementSyntax : SyntaxNode {
    private sealed class EmptyStatementSyntax : StatementSyntax {
      internal override void Render(CppRenderer renderer) {
      }
    }

    public static implicit operator StatementSyntax(ExpressionSyntax expression) {
      return new ExpressionStatementSyntax(expression);
    }

    public static readonly StatementSyntax Empty = new EmptyStatementSyntax();
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
    public readonly List<StatementSyntax> Statements = new List<StatementSyntax>();
    public bool IsEmpty => Statements.Count == 0;

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public void Add(StatementSyntax statement) {
      Statements.Add(statement);
    }

    public void AddRange(IEnumerable<StatementSyntax> statements) {
      Statements.AddRange(statements);
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
    public bool IsPreventIdnet { get; set; }
    public bool IsSingleLine { get; set; }

    public readonly List<StatementSyntax> Statements = new List<StatementSyntax>();
    internal int TempCount;

    public BlockSyntax() {}

    public BlockSyntax(StatementSyntax statement) {
      Statements.Add(statement);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public void Add(StatementSyntax statement) {
      Statements.Add(statement);
    }

    public void AddRange(IEnumerable<StatementSyntax> nodes) {
      Statements.AddRange(nodes);
    }

    public static readonly BlockSyntax EmptyBlock = new BlockSyntax() { IsSingleLine = true };
  }

  sealed class BlockStatementSyntax : BlockSyntax {
    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class NamespaceSyntax : BlockSyntax {
    public string NamespaceToken => Tokens.Namespace;
    public IdentifierSyntax Name { get; }
    public bool IsEmpty => Statements.Count == 0;

    public NamespaceSyntax(IdentifierSyntax name) {
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
    public List<TemplateTypenameSyntax> Arguments { get; } = new List<TemplateTypenameSyntax>();

    public TemplateSyntax() {}

    public TemplateSyntax(TemplateTypenameSyntax argument) {
      Arguments.Add(argument);
    }

    public TemplateSyntax(params TemplateTypenameSyntax[] args) {
      Arguments.AddRange(args);
    }

    public TemplateSyntax(IEnumerable<TemplateTypenameSyntax> args) {
      Arguments.AddRange(args);
    }

    public TemplateSyntax(IEnumerable<IdentifierSyntax> args) {
      Arguments.AddRange(args.Select(i => new TemplateTypenameSyntax(i)));
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly TemplateSyntax T = new TemplateSyntax(new TemplateTypenameSyntax(IdentifierSyntax.T));
    public static readonly TemplateSyntax Empty = new TemplateSyntax();
    public IEnumerable<IdentifierSyntax> TypeNames => Arguments.Select(i => i.Name);
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
    public bool IsConstexpr { get; set; }
    public ExpressionSyntax ConstantValue { get; set; }
    
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
    public TemplateSyntax Template { get; set; }
    public bool IsConstexpr { get; set; }
    public bool IsExplicit { get; set; }
    public bool IsNoexcept { get; set; }
    public bool IsStatic { get; set; }
    public string AccessibilityToken { get; set; }
    public ExpressionSyntax RetuenType { get; }
    public ExpressionSyntax DeclaringType { get; set; }
    public IdentifierSyntax Name { get; }
    public readonly List<ParameterSyntax> Parameters = new List<ParameterSyntax>();
    public List<InvationExpressionSyntax> InitializationList { get; set; }
    public BlockSyntax Body { get; set; }
    public int TotalTempCount { get; set; }

    public MethodDefinitionSyntax(IdentifierSyntax name, IEnumerable<ParameterSyntax> parameters, ExpressionSyntax retuenType = null) {
      Name = name;
      Parameters.AddRange(parameters);
      RetuenType = retuenType;
    }

    public void AddInitializationList(IdentifierSyntax name, ExpressionSyntax value) {
      InitializationList ??= new List<InvationExpressionSyntax>();
      InitializationList.Add(name.Invation(value));
    }

    public void AddStatement(StatementSyntax statement) {
      Body ??= new BlockSyntax();
      Body.Add(statement);
    }

    public void AddStatements(IEnumerable<StatementSyntax> nodes) {
      Body ??= new BlockSyntax();
      Body.AddRange(nodes);
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
      Invation = Macro.Invation();
      Invation.Arguments.Add(name);
      Invation.Arguments.AddRange(typeArguments);
    }

    public ExpressionStatementSyntax ToUsingMacroSyntax(string ns) {
      IdentifierSyntax name = macros_[(int)Kind].Replace(macros_.First(), "USING");
      var invation = name.Invation();
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

  sealed class IfElseStatementSyntax : StatementSyntax {
    public ExpressionSyntax Condition { get; }
    public StatementSyntax TrueStatement { get; }
    public StatementSyntax FalseStatement { get; set; }

    public IfElseStatementSyntax(ExpressionSyntax condition, StatementSyntax trueStatement) {
      Condition = condition;
      TrueStatement = trueStatement;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class ForStatementSyntax : StatementSyntax {
    public List<StatementSyntax> Initializers { get; } = new List<StatementSyntax>();
    public ExpressionSyntax Condition { get; }
    public List<StatementSyntax> Iterators { get; } = new List<StatementSyntax>();
    public StatementSyntax EmbeddedStatement { get; }

    public ForStatementSyntax(IEnumerable<StatementSyntax> initializers, ExpressionSyntax condition, IEnumerable<StatementSyntax> iterators, StatementSyntax embeddedStatement) {
      if (initializers != null) {
        Initializers.AddRange(initializers);
      }
      Condition = condition;
      if (Iterators != null) {
        Iterators.AddRange(iterators);
      }
      EmbeddedStatement = embeddedStatement;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class WhileStatementSyntax : StatementSyntax {
    public ExpressionSyntax Condition { get; }
    public StatementSyntax EmbeddedStatement { get; }

    public WhileStatementSyntax(ExpressionSyntax condition, StatementSyntax embeddedStatement) {
      Condition = condition;
      EmbeddedStatement = embeddedStatement;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class VariableInitializerSyntax : SyntaxNode {
    public IdentifierSyntax Name { get; }
    public ExpressionSyntax Initializer { get; }

    public VariableInitializerSyntax(IdentifierSyntax name, ExpressionSyntax initializer = null) {
      Name = name;
      Initializer = initializer;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class VariableDeclarationStatementSyntax : StatementSyntax {
    public ExpressionSyntax Type { get; }
    public List<VariableInitializerSyntax> Variables { get; } = new List<VariableInitializerSyntax>();

    public VariableDeclarationStatementSyntax(ExpressionSyntax type, IEnumerable<VariableInitializerSyntax> variables) {
      Type = type;
      Variables.AddRange(variables);
    }

    public VariableDeclarationStatementSyntax(ExpressionSyntax type, IdentifierSyntax name, ExpressionSyntax value) {
      Type = type;
      Variables.Add(new VariableInitializerSyntax(name, value));
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class CatchClauseSyntax : BlockSyntax {
    public ExpressionSyntax Type { get; }
    public IdentifierSyntax Name { get; }

    public CatchClauseSyntax(ExpressionSyntax type, IdentifierSyntax name) {
      Type = type;
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class TryStatementSyntax : BlockSyntax {
    public List<CatchClauseSyntax> CatchClauses { get; } = new List<CatchClauseSyntax>();
    public BlockSyntax FinallyBlock { get; }

    public TryStatementSyntax(BlockSyntax tryBlock, IEnumerable<CatchClauseSyntax> catchClauses, BlockSyntax finallyBlock = null) {
      AddRange(tryBlock.Statements);
      CatchClauses.AddRange(catchClauses);
      FinallyBlock = finallyBlock;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class CaseLabelSyntax : SyntaxNode {
    public ExpressionSyntax Expression { get; }

    public CaseLabelSyntax(ExpressionSyntax expression) {
      Expression = expression;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class SwitchSectionSyntax : SyntaxNode {
    public List<CaseLabelSyntax> CaseLabels { get; } = new List<CaseLabelSyntax>();
    public List<StatementSyntax> Statements { get; } = new List<StatementSyntax>();

    public SwitchSectionSyntax(IEnumerable<CaseLabelSyntax> caseLabels, IEnumerable<StatementSyntax> statements) {
      CaseLabels.AddRange(caseLabels);
      Statements.AddRange(statements);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class SwitchStatementSyntax : StatementSyntax {
    public ExpressionSyntax Expression { get; }
    public List<SwitchSectionSyntax> SwitchSections { get; } = new List<SwitchSectionSyntax>();

    public SwitchStatementSyntax(ExpressionSyntax expression, IEnumerable<SwitchSectionSyntax> switchSections) {
      Expression = expression;
      SwitchSections.AddRange(switchSections);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  sealed class BreakStatementSyntax : StatementSyntax {
    private BreakStatementSyntax() { }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }

    public static readonly BreakStatementSyntax Ins = new BreakStatementSyntax();
  }

}
