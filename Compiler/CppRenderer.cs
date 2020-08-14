using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal class CppRenderer {
    private static readonly Encoding Encoding = new UTF8Encoding(false);
    private const string IndentString = "  ";

    private readonly string outDir_;
    private readonly ITypeDefinition rootType_;
    private StreamWriter writer_;

    private bool isNewLine_;
    private int indentLevel_;
    private int singleLineCounter_;
    private int noSemicolonCounter_;
    private bool IsSingleLine => singleLineCounter_ > 0;
    private bool IsNoSemicolon => noSemicolonCounter_ > 0;

    public CppRenderer(ITypeDefinition rootType, string outDir) {
      rootType_ = rootType;
      outDir_ = outDir;
    }

    private string FolderPath {
      get {
        string[] ns = rootType_.Namespace.Split('.');
        string[] paths = new string[] { rootType_.ParentModule.AssemblyName }.Concat(ns).ToArray();
        return Path.Combine(paths);
      }
    }

    private string OutDir {
      get {
        return Path.Combine(outDir_, FolderPath);
      }
    }

    private string GetOutFile(string suffix, string extra = "") {
      return Path.Combine(OutDir, $"{rootType_.Name}{extra}.{suffix}");
    }

    private string HeadFileName => GetOutFile("h");
    private string SrcFileName => GetOutFile("cpp");
    private string DependFileName => GetOutFile("h", Utils.kDependExtra);

    private void AddIndent() {
      if (IsSingleLine) {
        WriteSpace();
      } else {
        ++indentLevel_;
      }
    }

    private void Outdent() {
      if (IsSingleLine) {
        WriteSpace();
      } else {
        if (indentLevel_ == 0) {
          throw new InvalidOperationException();
        }
        --indentLevel_;
      }
    }

    private void WriteNewLine() {
      if (IsSingleLine) {
        return;
      }

      writer_.Write('\n');
      isNewLine_ = true;
    }

    private void WriteSpace() {
      Write(" ");
    }

    private void WriteComma() {
      Write(",");
    }

    private void WriteCommaWithSpace() {
      Write(", ");
    }

    private void WriteColon() {
      Write(Tokens.Colon);
    }

    private void WriteSemicolon() {
      if (IsNoSemicolon) {
        return;
      }
      Write(Tokens.Semicolon);
    }

    private void Write(string value) {
      if (isNewLine_) {
        for (int i = 0; i < indentLevel_; i++) {
          writer_.Write(IndentString);
        }
        isNewLine_ = false;
      }
      writer_.Write(value);
    }

    internal void Render(CompilationUnitSyntax compilationUnit) {
      WriteCompilationUnitStatements(compilationUnit.HeadStatements, HeadFileName);
      if (!compilationUnit.IsSrcEmpty) {
        WriteCompilationUnitStatements(compilationUnit.ReferencesIncludes, DependFileName);
        WriteCompilationUnitStatements(compilationUnit.SrcStatements, SrcFileName);
      }
    }

    private void WriteCompilationUnit(string file, List<StatementSyntax> statements) {
      Directory.CreateDirectory(OutDir);
      using var writer = new StreamWriter(file, false, Encoding);
      writer_ = writer;
      WriteNodes(statements);
      writer_ = null;
    }

    private static string GetFileHash(FileInfo file) {
      using SHA256 sha = SHA256.Create();
      using var s = file.OpenRead();
      byte[] hash = sha.ComputeHash(s);
      return Convert.ToBase64String(hash);
    }

    private static bool IsFileChanged(FileInfo a, FileInfo b) {
      if (a.Length != b.Length) {
        return true;
      }

      if (GetFileHash(a) != GetFileHash(b)) {
        return true;
      }

      return false;
    }

    private void WriteCompilationUnitStatements(List<StatementSyntax> statements, string file) {
      if (statements.Count > 0) {
        if (File.Exists(file)) {
          string tmp = file + ".tmp";
          WriteCompilationUnit(tmp, statements);
          var tmpInfo = new FileInfo(tmp);
          var fileInfo = new FileInfo(file);
          if (IsFileChanged(tmpInfo, fileInfo)) {
            tmpInfo.MoveTo(file, true);
          } else {
            tmpInfo.Delete();
          }
        } else {
          WriteCompilationUnit(file, statements);
        }
      }
    }

    private void WriteNodesWithSeparated(IEnumerable<SyntaxNode> nodes) {
      bool isFirst = true;
      foreach (var node in nodes) {
        if (isFirst) {
          isFirst = false;
        } else {
          WriteCommaWithSpace();
        }
        node.Render(this);
      }
    }

    private void WriteNodes(IEnumerable<SyntaxNode> nodes) {
      foreach (var node in nodes) {
        node.Render(this);
      }
    }

    private void WriteBlock(BlockSyntax block) {
      Render(block);
    }

    internal void Render(CodeTemplateExpressionSyntax node) {
      WriteNodes(node.Expressions);
    }

    internal void Render(ExpressionStatementSyntax node) {
      node.Expression.Render(this);
      if (node.HasSemicolon) {
        WriteSemicolon();
      }
      WriteNewLine();
    }

    internal void Render(StatementListSyntax node) {
      WriteNodes(node.Statements);
    }

    internal void Render(BlankLinesStatement node) {
      for (int i = 0; i < node.Count; ++i) {
        WriteNewLine();
      }
    }

    internal void Render(PragmaPretreatmentSyntax node) {
      Write(node.Prefix);
      Write(node.PragmaToken);
      WriteSpace();
      Write(node.Symbol);
      WriteNewLine();
    }

    internal void Render(IncludePretreatmentSyntax node) {
      Write(node.Prefix);
      Write(node.IncludeToken);
      WriteSpace();
      Write(node.OpenToken);
      Write(node.Path);
      Write(node.CloseToken);
      WriteNewLine();
    }

    internal void Render(DefinePretreatmentSyntax node) {
      Write(node.Prefix);
      Write(node.DefineToken);
      WriteSpace();
      node.Name.Render(this);
      WriteSpace();
      node.Expression.Render(this);
      WriteNewLine();
    }

    internal void Render(UndefPretreatmentSyntax node) {
      Write(node.Prefix);
      Write(node.UnDefToken);
      WriteSpace();
      node.Name.Render(this);
      WriteNewLine();
    }

    internal void Render(BlockSyntax node) {
      if (node.IsSingleLine) {
        if (node.Statements.Count == 0) {
          Write(Tokens.OpenBrace);
          Write(Tokens.CloseBrace);
          return;
        }

        ++singleLineCounter_;
      }

      Write(Tokens.OpenBrace);
      WriteNewLine();
      if (!node.IsPreventIdnet) {
        AddIndent();
      }
      WriteNodes(node.Statements);
      if (!node.IsPreventIdnet) {
        Outdent();
      }
      Write(Tokens.CloseBrace);

      if (node.IsSingleLine) {
        --singleLineCounter_;
      }
    }

    internal void Render(BlockStatementSyntax node) {
      WriteBlock(node);
      WriteNewLine();
    }

    internal void Render(NamespaceSyntax node) {
      if (!node.IsEmpty) {
        Write(node.NamespaceToken);
        WriteSpace();
        node.Name.Render(this);
        WriteSpace();
        WriteBlock(node);
        WriteSpace();
        Write(Tokens.LineComment);
        WriteSpace();
        Write(node.NamespaceToken);
        WriteSpace();
        node.Name.Render(this);
        WriteNewLine();
      }
    }

    private void WriteAccessibility(string token) {
      if (!string.IsNullOrEmpty(token)) {
        Write(token);
        WriteColon();
        WriteSpace();
      }
    }

    internal void Render(EnumSyntax node) {
      WriteAccessibility(node.AccessibilityToken);
      Write(node.EnumToekn);
      WriteSpace();
      Write(node.ClassToekn);
      WriteSpace();
      Write(node.Name);
      if (node.UnderlyingType != null) {
        WriteSpace();
        WriteColon();
        WriteSpace();
        node.UnderlyingType.Render(this);
      }
      WriteSpace();
      WriteBlock(node);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(EnumFieldSyntax node) {
      node.Name.Render(this);
      if (node.Value != null) {
        WriteSpace();
        Write(node.EqualsToken);
        WriteSpace();
        Write(node.Value);
      }
      WriteComma();
      WriteNewLine();
    }

    internal void Render(TemplateTypenameSyntax node) {
      Write(node.ClassToken);
      WriteSpace();
      node.Name.Render(this);
      if (node.Value != null) {
        WriteSpace();
        Write(node.EqualsToken);
        WriteSpace();
        node.Value.Render(this);
      }
    }

    internal void Render(TemplateSyntax node) {
      Write(Tokens.Template);
      WriteSpace();
      Write(Tokens.Less);
      WriteNodesWithSeparated(node.Arguments);
      Write(Tokens.Greater);
      WriteNewLine();
    }

    internal void Render(BaseSyntax node) {
      Write(Tokens.Public);
      WriteSpace();
      node.Type.Render(this);
    }

    internal void Render(ClassSyntax node) {
      WriteAccessibility(node.AccessibilityToken);
      switch (node.Kind) {
        case ClassKind.None: {
            node.Template?.Render(this);
            Write(node.ClassToken);
            WriteSpace();
            node.Name.Render(this);
            break;
          }
        case ClassKind.MultiRef:
        case ClassKind.Ref: {
            Write(node.Kind == ClassKind.Ref ? "CLASS" : "CLASS_");
            Write(Tokens.OpenParentheses);
            if (node.Template != null) {
              WriteNodesWithSeparated(new IdentifierSyntax[] { node.Name }.Concat(node.Template.TypeNames));
            } else {
              node.Name.Render(this);
            }
            Write(Tokens.CloseParentheses);
            break;
          }
        case ClassKind.Array: {
            Write("CLASS_FORWARD");
            Write(Tokens.OpenParentheses);
            WriteNodesWithSeparated(new IdentifierSyntax[] { node.Name }.Concat(2.GetTypeNames()));
            Write(Tokens.CloseParentheses);
            WriteNewLine();

            Write("CLASS_");
            Write(Tokens.OpenParentheses);
            WriteNodesWithSeparated(new IdentifierSyntax[] { node.Name }.Concat(1.GetTypeNames()));
            Write(Tokens.CloseParentheses);
            WriteSemicolon();
            WriteNewLine();

            Write("CLASS_");
            Write(Tokens.OpenParentheses);
            node.Name.Render(this);
            Write(Tokens.CloseParentheses);
            break;
            /*
            Write("ARRAY");
            Write(Tokens.OpenParentheses);
            Write(Tokens.OpenParentheses);
            WriteBlock(node);
            Write(Tokens.CloseParentheses);
            Write(Tokens.CloseParentheses);
            WriteNewLine();
            return;*/
          }
        case ClassKind.Multi: {
            node.Template ??= new TemplateSyntax();
            node.Name = new GenericIdentifierSyntax(node.Name, node.Template.TypeNames);
            goto case ClassKind.None;
          }
        case ClassKind.MultiRefForward: {
            Write("CLASS_FORWARD");
            Write(Tokens.OpenParentheses);
            WriteNodesWithSeparated(new IdentifierSyntax[] { node.Name }.Concat(node.Template.TypeNames));
            Write(Tokens.CloseParentheses);
            WriteNewLine();
            return;
          }
      }

      WriteSpace();
      if (node.Bases.Count > 0) {
        WriteColon();
        WriteSpace();
        WriteNodesWithSeparated(node.Bases);
        WriteSpace();
      }
      WriteBlock(node);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(FieldDefinitionSyntax node) {
      WriteAccessibility(node.AccessibilityToken);
      if (node.IsStatic) {
        Write(Tokens.Static);
        WriteSpace();
      }
      if (node.IsConstexpr) {
        Write(Tokens.Constexpr);
        WriteSpace();
      }
      node.Type.Render(this);
      WriteSpace();
      node.Nmae.Render(this);
      if (node.ConstantValue != null) {
        WriteSpace();
        Write(Tokens.Equals);
        WriteSpace();
        node.ConstantValue.Render(this);
      }
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(ParameterSyntax node) {
      node.Type.Render(this);
      if (node.Name != null) {
        WriteSpace();
        node.Name.Render(this);
      }
    }

    internal void Render(MethodDefinitionSyntax node) {
      WriteAccessibility(node.AccessibilityToken);
      node.Template?.Render(this);
      if (node.IsInline) {
        Write(Tokens.Inline);
        WriteSpace();
      }
      if (node.IsStatic) {
        Write(Tokens.Static);
        WriteSpace();
      }
      if (node.IsConstexpr) {
        Write(Tokens.Constexpr);
        WriteSpace();
      }
      if (node.RetuenType != null) {
        node.RetuenType.Render(this);
        WriteSpace();
      } else if (node.IsExplicit) {
        Write(Tokens.Explicit);
        WriteSpace();
      }
      if (node.DeclaringType != null) {
        node.DeclaringType.Render(this);
        Write(Tokens.TwoColon);
      }
      node.Name.Render(this);
      Write(Tokens.OpenParentheses);
      WriteNodesWithSeparated(node.Parameters);
      Write(Tokens.CloseParentheses);
      if (node.IsConst) {
        WriteSpace();
        Write(Tokens.Const);
      }
      if (node.IsNoexcept) {
        WriteSpace();
        Write(Tokens.Noexcept);
      }
      if (node.InitializationList != null && node.InitializationList.Count > 0) {
        WriteSpace();
        WriteColon();
        WriteSpace();
        WriteNodesWithSeparated(node.InitializationList);
      }
      if (node.Body != null) {
        WriteSpace();
        node.Body.Render(this);
      } else {
        WriteSemicolon();
      }
      WriteNewLine();
    }

    internal void Render(ValueTextIdentifierSyntax node) {
      Write(node.ValueText);
    }

    internal void Render(GenericIdentifierSyntax node) {
      node.Name.Render(this);
      Write(node.OpenBrace);
      WriteNodesWithSeparated(node.GenericArguments);
      Write(node.CloseBrace);
    }

    internal void Render(PostfixUnaryExpression node) {
      node.Expression.Render(this);
      Write(node.OperatorToken);
    }

    internal void Render(PrefixUnaryExpressionSyntax node) {
      Write(node.OperatorToken);
      node.Expression.Render(this);
    }

    internal void Render(MemberAccessExpressionSyntax node) {
      node.Expression.Render(this);
      Write(node.OperatorToken);
      node.Name.Render(this);
    }

    internal void Render(ClassForwardDeclarationSyntax node) {
      node.Template?.Render(this);
      if (node.IsFriend) {
        Write(Tokens.Friend);
        WriteSpace();
      }
      Write(node.ClassToken);
      WriteSpace();
      node.Name.Render(this);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(EnumForwardSyntax node) {
      Write(node.EnumToekn);
      WriteSpace();
      Write(node.ClassToekn);
      WriteSpace();
      Write(node.Name);
      if (node.UnderlyingType != null) {
        WriteSpace();
        WriteColon();
        WriteSpace();
        node.UnderlyingType.Render(this);
      }
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(UsingDeclarationSyntax node) {
      WriteAccessibility(node.AccessibilityToken);
      node.Template?.Render(this);
      Write(node.UsingToken);
      WriteSpace();
      node.Name.Render(this);
      WriteSpace();
      Write(node.EqualsToken);
      WriteSpace();
      node.Type.Render(this);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(UsingNamespaceOrTypeSyntax node) {
      Write(node.UsingToken);
      WriteSpace();
      if (node.IsNamespace) {
        Write(Tokens.Namespace);
        WriteSpace();
      }
      Write(node.Name);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(InvationExpressionSyntax node) {
      node.Expression.Render(this);
      if (node.TypeArguments.Count > 0) {
        Write(Tokens.Less);
        WriteNodesWithSeparated(node.TypeArguments);
        Write(Tokens.Greater);
      }
      Write(Tokens.OpenParentheses);
      WriteNodesWithSeparated(node.Arguments);
      Write(Tokens.CloseParentheses);
    }

    internal void Render(IndexerExpressionSyntax node) {
      node.Expression.Render(this);
      Write(Tokens.OpenBracket);
      WriteNodesWithSeparated(node.Arguments);
      Write(Tokens.CloseBracket);
    }

    internal void Render(ForwardMacroSyntax node) {
      WriteAccessibility(node.AccessibilityToken);
      node.Invation.Render(this);
      WriteNewLine();
    }

    internal void Render(NestedCycleRefTypeNameSyntax node) {
      node.Type.Render(this);
      Write(node.OpenComment);
      Write(node.FullName);
      Write(node.CloseComment);
    }

    internal void Render(ReturnStatementSyntax node) {
      Write(node.ReturnKeyword);
      if (node.Expression != null) {
        WriteSpace();
        node.Expression.Render(this);
      }
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(StringLiteralExpressionSyntax node) {
      Write(node.OpenParenToken);
      Write(node.Value);
      Write(node.CloseParenToken);
    }

    internal void Render(BooleanLiteralExpressionSyntax node) {
      Write(node.Value ? "true" : "false");
    }

    internal void Render(NumberLiteralExpressionSyntax node) {
      Write(node.Value);
    }

    internal void Render(CastExpressionSyntax node) {
      if (node.IsParenthesesCast) {
        Write(Tokens.OpenParentheses);
        node.Target.Render(this);
        Write(Tokens.CloseParentheses);
        node.Expression.Render(this);
      } else {
        IdentifierSyntax.Cast.Generic(node.Target).Invation(node.Expression).Render(this);
      }
    }

    internal void Render(IfElseStatementSyntax node) {
      Write(Tokens.If);
      WriteSpace();
      Write(Tokens.OpenParentheses);
      node.Condition.Render(this);
      Write(Tokens.CloseParentheses);
      WriteSpace();
      node.TrueStatement.Render(this);
      if (node.FalseStatement != null) {
        WriteSpace();
        Write(Tokens.Else);
        WriteSpace();
        node.FalseStatement.Render(this);
      }
      WriteNewLine();
    }

    private void OpenForIteratorStatement() {
      ++noSemicolonCounter_;
      ++singleLineCounter_;
    }

    private void CloseForIteratorStatement() {
      --noSemicolonCounter_;
      --singleLineCounter_;
    }

    internal void Render(ForStatementSyntax node) {
      Write(Tokens.For);
      WriteSpace();
      Write(Tokens.OpenParentheses);
      if (node.Initializers != null) {
        OpenForIteratorStatement();
        WriteNodesWithSeparated(node.Initializers);
        CloseForIteratorStatement();
      }
      WriteSemicolon();
      if (node.Condition != null) {
        WriteSpace();
        node.Condition.Render(this);
      }
      WriteSemicolon();
      if (node.Iterators != null) {
        WriteSpace();
        OpenForIteratorStatement();
        WriteNodesWithSeparated(node.Iterators);
        CloseForIteratorStatement();
      }
      Write(Tokens.CloseParentheses);
      WriteSpace();
      node.EmbeddedStatement.Render(this);
      WriteNewLine();
    }

    internal void Render(WhileStatementSyntax node) {
      Write(Tokens.While);
      WriteSpace();
      Write(Tokens.OpenParentheses);
      node.Condition.Render(this);
      Write(Tokens.CloseParentheses);
      WriteSpace();
      node.EmbeddedStatement.Render(this);
      WriteNewLine();
    }

    internal void Render(DoWhileStatementSyntax node) {
      Write(Tokens.Do);
      WriteSpace();
      node.EmbeddedStatement.Render(this);
      WriteSpace();
      Write(Tokens.While);
      WriteSpace();
      Write(Tokens.OpenParentheses);
      node.Condition.Render(this);
      Write(Tokens.CloseParentheses);
      WriteNewLine();
    }

    internal void Render(BinaryExpressionSyntax node) {
      node.Left.Render(this);
      WriteSpace();
      Write(node.OperatorToken);
      WriteSpace();
      node.Right.Render(this);
    }

    internal void Render(ParenthesizedExpressionSyntax node) {
      Write(Tokens.OpenParentheses);
      node.Expression.Render(this);
      Write(Tokens.CloseParentheses);
    }

    internal void Render(LambdaExpressionSyntax node) {
      Write(Tokens.OpenBracket);
      if (node.Captures != null) {
        Write(string.Join(", ", node.Captures));
      }
      Write(Tokens.CloseBracket);
      if (node.TypeParameters != null) {
        Write(Tokens.Less);
        WriteNodesWithSeparated(node.TypeParameters);
        Write(Tokens.Greater);
      }
      Write(Tokens.OpenParentheses);
      WriteNodesWithSeparated(node.Parameters);
      Write(Tokens.CloseParentheses);
      if (node.RetuenType != null) {
        WriteSpace();
        Write(Tokens.Arrow);
        WriteSpace();
        node.RetuenType.Render(this);
      }
      WriteSpace();
      WriteBlock(node.Body);
    }

    internal void Render(ConditionalExpressionSyntax node) {
      node.Condition.Render(this);
      WriteSpace();
      Write(Tokens.Question);
      WriteSpace();
      node.TrueExpression.Render(this);
      WriteSpace();
      WriteColon();
      WriteSpace();
      node.FalseExpression.Render(this);
    }

    internal void Render(VariableInitializerSyntax node) {
      node.Name.Render(this);
      if (node.Initializer != null) {
        WriteSpace();
        Write(Tokens.Equals);
        WriteSpace();
        node.Initializer.Render(this);
      }
    }

    internal void Render(VariableDeclarationStatementSyntax node) {
      node.Type.Render(this);
      WriteSpace();
      WriteNodesWithSeparated(node.Variables);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(CatchClauseSyntax node) {
      WriteSpace();
      Write(Tokens.Catch);
      WriteSpace();
      Write(Tokens.OpenParentheses);
      node.Type.Render(this);
      if (node.Name != null) {
        WriteSpace();
        node.Name.Render(this);
      }
      Write(Tokens.CloseParentheses);
      WriteSpace();
      WriteBlock(node);
    }

    internal void Render(TryStatementSyntax node) {
      Write(Tokens.Try);
      WriteBlock(node);
      WriteNodes(node.CatchClauses);
      if (node.FinallyBlock != null) {
        WriteSpace();
        Write(Tokens.Finally);
        WriteColon();
        WriteSpace();
        node.FinallyBlock.Render(this);
      }
      WriteNewLine();
    }

    internal void Render(CaseLabelSyntax node) {
      if (node.Expression != null) {
        Write(Tokens.Case);
        WriteSpace();
        node.Expression.Render(this);
        WriteColon();
      } else {
        Write(Tokens.Default);
        WriteColon();
      }
      WriteNewLine();
    }

    internal void Render(SwitchSectionSyntax node) {
      WriteNodes(node.CaseLabels);
      AddIndent();
      WriteNodes(node.Statements);
      Outdent();
    }

    internal void Render(SwitchStatementSyntax node) {
      Write(Tokens.Switch);
      WriteSpace();
      Write(Tokens.OpenParentheses);
      node.Expression.Render(this);
      Write(Tokens.CloseParentheses);
      WriteSpace();
      Write(Tokens.OpenBrace);
      WriteNewLine();
      AddIndent();
      WriteNodes(node.SwitchSections);
      Outdent();
      Write(Tokens.CloseBrace);
      WriteNewLine();
    }

    internal void Render(BreakStatementSyntax node) {
      Write(Tokens.Break);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(ContinueStatementSyntax node) {
      Write(Tokens.Continue);
      WriteSemicolon();
      WriteNewLine();
    }
  }
}
