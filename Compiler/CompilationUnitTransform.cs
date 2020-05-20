using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class CompilationUnitTransform {
    public AssemblyTransform AssemblyTransform { get; }
    private CompilationUnitSyntax compilationUnit_ = new CompilationUnitSyntax();
    private HashSet<string> includes_ = new HashSet<string>();
    private HashSet<string> usings_ = new HashSet<string>();
    private List<StatementSyntax> forwards_ = new List<StatementSyntax>();
    private ITypeDefinition root_;

    public CompilationUnitTransform(AssemblyTransform assemblyTransform, IEnumerable<ITypeDefinition> types) {
      AssemblyTransform = assemblyTransform;
      root_ = types.First();
      VisitCompilationUnit(types);
    }

    private void VisitCompilationUnit(IEnumerable<ITypeDefinition> types) {
      var ns = compilationUnit_.AddNamespace(root_.Namespace);
      var usingsSyntax = new StatementListSyntax();
      ns.Add(usingsSyntax);

      new TypeDefinitionTransform(this, ns.Current, types);
      if (root_.Kind != TypeKind.Enum) {
        var includes = includes_.ToList();
        includes.Sort();
        compilationUnit_.AddHeadIncludes(includes);
        var usings = usings_.ToList();
        usings.Sort();
        foreach (string i in usings) {
          usingsSyntax.Add(new UsingNamespaceSyntax(i.Replace(Tokens.Dot, Tokens.TwoColon)));
        }
        usingsSyntax.Statements.AddRange(forwards_);
        if (root_.Kind != TypeKind.Interface) {
          compilationUnit_.AddSrcInclude(root_.GetIncludeString(), false);
          compilationUnit_.AddSrcStatement(BlankLinesStatement.One);
        }
      }
    }

    internal void Write(string outDir) {
      CppRenderer rener = new CppRenderer(root_, outDir);
      compilationUnit_.Render(rener);
    }

    internal void AddInclude(string includeString) {
      includes_.Add(includeString);
    }

    internal void AddUsing(string usingString) {
      usings_.Add(usingString);
    }

    internal void AddForward(InvationExpressionSyntax expression) {
      forwards_.Add(new ExpressionStatementSyntax(expression) { HasSemicolon = false });
    }
  }
}
