using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Principal;
using System.Text;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal class CppRenderer {
    private static readonly Encoding Encoding = new UTF8Encoding(false);
    private const string IndentString = "  ";

    private TypeDefinitionTransform transform_;
    private string outDir_;
    private ITypeDefinition rootType_;
    private StreamWriter writer_;

    private bool isNewLine_;
    private int indentLevel_;
    private int singleLineCounter_;
    private bool IsSingleLine => singleLineCounter_ > 0;

    public CppRenderer(TypeDefinitionTransform transform, string outDir, ITypeDefinition rootType) {
      transform_ = transform;
      outDir_ = outDir;
      rootType_ = rootType;
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

    private string HeadFileName {
      get {
        return Path.Combine(OutDir, $"{rootType_.Name}.h"); ;
      }
    }

    private string SrcFileName {
      get {
        return Path.Combine(OutDir, $"{rootType_.Name}.cpp"); ;
      }
    }

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
      WriteCompilationUnitStatements(compilationUnit.SrcStatements, SrcFileName);
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

    internal void Render(StatementListSyntax node) {
      WriteNodes(node.Statements);
    }

    internal void Render(BlankLinesStatement node) {
      for (int i = 0; i < node.Count; ++i) {
        WriteNewLine();
      }
    }

    internal void Render(PragmaPretreatmentStatementSyntax node) {
      Write(node.Prefix);
      Write(node.PragmaToken);
      WriteSpace();
      Write(node.Symbol);
      WriteNewLine();
    }

    internal void Render(IncludePretreatmentStatementSyntax node) {
      Write(node.Prefix);
      Write(node.IncludeToken);
      WriteSpace();
      Write(node.IsSystemPath ? Tokens.Less : Tokens.Quote);
      Write(node.Path);
      Write(node.IsSystemPath ? Tokens.Greater : Tokens.Quote);
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
        Write(node.CloseComment);
        WriteNewLine();
      }
    }

    internal void Render(EnumSyntax node) {
      WriteNewLine();
      Write(node.ClassToekn);
      WriteSpace();
      Write(node.EnumToekn);
      WriteSpace();
      Write(node.Name);
      WriteSpace();
      Render((BlockSyntax)node);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(EnumFieldSyntax node) {
      Write(node.Name);
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
      WriteNewLine();
      node.Template?.Render(this);
      Write(node.StructToken);
      WriteSpace();
      Write(node.Name);
      WriteSpace();
      if (node.Bases.Count > 0) {
        Write(Tokens.Colon);
        WriteSpace();
        WriteSeparatedSyntaxList(node.Bases);
        WriteSpace();
      }
      Render((BlockSyntax)node);
      WriteSemicolon();
      WriteNewLine();
    }

    internal void Render(FieldDefinitionSyntax node) {
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

    internal void Render(ValueTextIdentifierSyntax node) {
      Write(node.ValueText);
    }

    internal void Render(GenericIdentifierSyntax node) {
      node.Identifier.Render(this);
      Write(node.OpenBrace);
      WriteSeparatedSyntaxList(node.GenericArguments);
      Write(node.CloseBrace);
    }

    internal void Render(MemberAccessExpressionSyntax node) {
      node.Expression.Render(this);
      Write(node.OperatorToken);
      node.Name.Render(this);
    }

    internal void Render(ClassForwardDeclarationSyntax node) {
      Write(node.ClassToken);
      WriteSpace();
      node.Name.Render(this);
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

  }
}
