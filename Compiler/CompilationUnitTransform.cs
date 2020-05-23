using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class CompilationUnitTransform {
    public AssemblyTransform AssemblyTransform { get; }
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
        usingsSyntax.Statements.AddRange(forwards_.Values);
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

    private static UsingNamespaceSyntax GetUsingNamespaceSyntax(string name) {
      return new UsingNamespaceSyntax(name.Replace(Tokens.Dot, Tokens.TwoColon));
    }

    public void AddForward(ITypeDefinition type) {
      var firstType = AssemblyTransform.GetRefMultiGenericFirstType(type, out int genericCount);
      var value = firstType ?? type;
      forwards_[value] = value.GetForwardStatement(genericCount);
    }
  }
}
