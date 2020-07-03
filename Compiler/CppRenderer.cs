using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
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
    private bool IsSingleLine => singleLineCounter_ > 0;

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

    private void WriteSeparatedSyntaxList(IEnumerable<SyntaxNode> list) {
      bool isFirst = true;
      foreach (var node in list) {
        if (isFirst) {
          isFirst = false;
        } else {
          WriteCommaWithSpace();
        }
        node.Render(this);
      }
    }

    internal void Render(CompilationUnitSyntax compilationUnit) {
      WriteCompilationUnitStatements(compilationUnit.HeadStatements, HeadFileName);
      if (!compilationUnit.IsSrcEmpty) {
        WriteCompilationUnitStatements(compilationUnit.ReferencesIncludes, DependFileName);
        WriteCompilationUnitStatements(compilationUnit.SrcStatements, SrcFileName);
      }
    }

    private void WriteCompilationUnitStatements(List<StatementSyntax> statements, string file) {
      if (statements.Count > 0) {
        Directory.CreateDirectory(OutDir);
        using var writer = new StreamWriter(file, false, Encoding);
        writer_ = writer;
        WriteNodes(statements);
        writer_ = null;
      }
    }

    private void WriteNodes(IEnumerable<SyntaxNode> nodes) {
      foreach (var node in nodes) {
        node.Render(this);
      }
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
      Write(node.OpenToken);
      WriteNewLine();
      if (!node.IsPreventIdnet) {
        AddIndent();
      }
      WriteNodes(node.Statements);
      if (!node.IsPreventIdnet) {
        Outdent();
      }
      Write(node.CloseToken);
    }

    internal void Render(NamespaceSyntax node) {
      if (!node.IsEmpty) {
        Write(node.NamespaceToken);
        WriteSpace();
        Write(node.Name);
        WriteSpace();
        Render((BlockSyntax)node);
        WriteSpace();
        Write(Tokens.LineComment);
        WriteSpace();
        Write(node.NamespaceToken);
        WriteSpace();
        Write(node.Name);
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
      Render((BlockSyntax)node);
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
      Write(node.TemplateToken);
      WriteSpace();
      Write(node.OpenBrace);
      WriteSeparatedSyntaxList(node.Arguments);
      Write(node.CloseBrace);
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
            WriteSeparatedSyntaxList(new IdentifierSyntax[] { node.Name }.Concat(node.Template.TypeNames));
          } else {
            node.Name.Render(this);
          }
          Write(Tokens.CloseParentheses);
          break;
        }
        case ClassKind.Array: {
          Write("ARRAY");
          Write(Tokens.OpenParentheses);
          Write(Tokens.OpenParentheses);
          Render((BlockSyntax)node);
          Write(Tokens.CloseParentheses);
          Write(Tokens.CloseParentheses);
          WriteNewLine();
          return;
        }
        case ClassKind.Multi: {
          node.Template ??= new TemplateSyntax();
          node.Name = new GenericIdentifierSyntax(node.Name, node.Template.TypeNames);
          goto case ClassKind.None;
        }
        case ClassKind.MultiRefForward: {
          Write("CLASS_FORWARD");
          Write(Tokens.OpenParentheses);
          WriteSeparatedSyntaxList(new IdentifierSyntax[] { node.Name }.Concat(node.Template.TypeNames));
          Write(Tokens.CloseParentheses);
          WriteNewLine();
          return;
        }
      }

      WriteSpace();
      if (node.Bases.Count > 0) {
        WriteColon();
        WriteSpace();
        WriteSeparatedSyntaxList(node.Bases);
        WriteSpace();
      }
      Render((BlockSyntax)node);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(FieldDefinitionSyntax node) {
      WriteAccessibility(node.AccessibilityToken);
      if (node.IsStatic) {
        Write(Tokens.Static);
        WriteSpace();
      }
      node.Type.Render(this);
      WriteSpace();
      node.Nmae.Render(this);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(ParameterSyntax node) {
      node.Type.Render(this);
      WriteSpace();
      node.Name.Render(this);
    }

    internal void Render(MethodDefinitionSyntax node) {
      WriteAccessibility(node.AccessibilityToken);
      if (node.IsStatic) {
        Write(Tokens.Static);
        WriteSpace();
      }
      node.RetuenType.Render(this);
      WriteSpace();
      node.Nmae.Render(this);
      Write(node.OpenParentheses);
      WriteSeparatedSyntaxList(node.Parameters);
      Write(node.CloseParentheses);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(MethodImplementationSyntax node) {
      node.RetuenType.Render(this);
      WriteSpace();
      if (node.DeclaringType != null) {
        node.DeclaringType.Render(this);
        Write(Tokens.TwoColon);
      }
      node.Name.Render(this);
      Write(node.OpenParentheses);
      WriteSeparatedSyntaxList(node.Parameters);
      Write(node.CloseParentheses);
      WriteSpace();
      Render((BlockSyntax)node);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(ValueTextIdentifierSyntax node) {
      Write(node.ValueText);
    }

    internal void Render(GenericIdentifierSyntax node) {
      node.Name.Render(this);
      Write(node.OpenBrace);
      WriteSeparatedSyntaxList(node.GenericArguments);
      Write(node.CloseBrace);
    }

    internal void Render(PointerIdentifierSyntax node) {
      node.Name.Render(this);
      Write(node.Asterisk);
    }

    internal void Render(RefIdentifierSyntax node) {
      node.Name.Render(this);
      Write(node.Ampersand);
    }

    internal void Render(AddressIdentifierSyntax node) {
      Write(node.Ampersand);
      node.Name.Render(this);
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
        Write(node.OpenBrace);
        WriteSeparatedSyntaxList(node.TypeArguments);
        Write(node.CloseBrace);
      }
      Write(node.OpenParentheses);
      WriteSeparatedSyntaxList(node.Arguments);
      Write(node.CloseParentheses);
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

    internal void Render(CastExpressionSyntax node) {
      Write(Tokens.OpenParentheses);
      node.Target.Render(this);
      Write(Tokens.CloseParentheses);
      node.Expression.Render(this);
    }

    internal void Render(IfElseStatementSyntax node) {
      Write(node.IfToken);
      WriteSpace();
      Write(node.OpenParentheses);
      node.Condition.Render(this);
      Write(node.CloseParentheses);
      WriteSpace();
      node.TrueStatement.Render(this);
      if (node.FalseStatement != null) {
        WriteSpace();
        node.FalseStatement.Render(this);
      }
      WriteNewLine();
    }

    internal void Render(BinaryExpressionSyntax node) {
      node.Left.Render(this);
      WriteSpace();
      Write(node.OperatorToken);
      WriteSpace();
      node.Right.Render(this);
    }
  }
}
