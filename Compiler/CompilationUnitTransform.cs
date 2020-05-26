using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class CompilationUnitTransform {
    public AssemblyTransform AssemblyTransform { get; }
    public SyntaxGenerator Generator => AssemblyTransform.Generator;
    private CompilationUnitSyntax compilationUnit_ = new CompilationUnitSyntax();
    public readonly HashSet<ITypeDefinition> References = new HashSet<ITypeDefinition>();
    private readonly Dictionary<ITypeDefinition, ForwardMacroSyntax> forwards_ = new Dictionary<ITypeDefinition, ForwardMacroSyntax>();
    private ITypeDefinition root_;

    public CompilationUnitTransform(AssemblyTransform assemblyTransform, List<ITypeDefinition> types) {
      AssemblyTransform = assemblyTransform;
      root_ = types.First();
      VisitCompilationUnit(types);
    }

    private void VisitCompilationUnit(IEnumerable<ITypeDefinition> types) {
      var ns = compilationUnit_.AddNamespace(root_.Namespace);
      var usingsSyntax = new StatementListSyntax();
      ns.Add(usingsSyntax);

      new TypeDefinitionTransform(this, ns, types);
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
        AddForwards(usingsSyntax);
        if (root_.Kind != TypeKind.Interface) {
          compilationUnit_.AddSrcInclude(root_.GetIncludeString(), false);
          compilationUnit_.AddSrcStatement(BlankLinesStatement.One);
        }

        if (usings.Count > 0) {

        }
      }
    }

    private void AddForwards(StatementListSyntax statements) {
      var outs = new List<(ITypeDefinition Type, ForwardMacroSyntax Forward)>();
      foreach (var (type, forward) in forwards_) {
        if (root_.Namespace == type.Namespace) {
          statements.Add(forward);
        } else {
          outs.Add((type, forward));
        }
      }
      if (outs.Count > 0) {
       var group = outs.GroupBy(i => i.Type.Namespace);
        foreach (var g in group) {
          var ns = new NamespaceSyntax(g.Key);
          ns.AddRange(g.Select(i => i.Forward));
          compilationUnit_.HeadStatements.Add(ns);
        }
      }
    }

    internal void Write(string outDir) {
      CppRenderer rener = new CppRenderer(root_, outDir);
      compilationUnit_.Render(rener);
    }

    private static UsingNamespaceSyntax GetUsingNamespaceSyntax(string name) {
      return new UsingNamespaceSyntax(name.Replace(Tokens.Dot, Tokens.TwoColon));
    }

    public void AddForward(ITypeDefinition type) {
      var firstType = Generator.GetRefMultiGenericFirstType(type, out int genericCount);
      var value = firstType ?? type;
      forwards_[value] = value.GetForwardStatement(genericCount);
    }
  }
}
