using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http.Headers;
using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class CompilationUnitTransform {
    public AssemblyTransform AssemblyTransform { get; }
    private CompilationUnitSyntax compilationUnit_ = new CompilationUnitSyntax();
    public readonly HashSet<ITypeDefinition> References = new HashSet<ITypeDefinition>();
    public readonly HashSet<ITypeDefinition> Forwards = new HashSet<ITypeDefinition>();
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
        HashSet<string> includes = new HashSet<string>();
        HashSet<string> usings = new HashSet<string>();
        foreach (var reference in References) {
          includes.Add(reference.GetReferenceIncludeString());
          if (!string.IsNullOrEmpty(reference.Namespace) && !root_.Namespace.StartsWith(reference.Namespace)) {
            usings.Add(reference.Namespace);
          }
        }
        compilationUnit_.AddHeadIncludes(includes.OrderBy(i => i));
        usingsSyntax.Statements.AddRange(usings.OrderBy(i => i).Select(GetUsingNamespaceSyntax));
        usingsSyntax.Statements.AddRange(Forwards.Where(i => i.Name != "Task").Select(GetExpressionForward));
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

    private static ExpressionStatementSyntax GetExpressionForward(ITypeDefinition type) {
      var args = new IdentifierSyntax[] { type.Name }.Concat(type.GetTypeParameters().Select(i => (IdentifierSyntax)i.Name));
      var invation = new InvationExpressionSyntax((IdentifierSyntax)"FORWARD", args);
      return new ExpressionStatementSyntax(invation) { HasSemicolon = true };
    }

    private static UsingNamespaceSyntax GetUsingNamespaceSyntax(string name) {
      return new UsingNamespaceSyntax(name.Replace(Tokens.Dot, Tokens.TwoColon));
    }
  }
}
