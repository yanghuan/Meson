using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

using Meson.Compiler.CppAst;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;

namespace Meson.Compiler {
  sealed class SyntaxGenerator {
    private sealed class RefMultiGenericTypeInfo {
      public List<ITypeDefinition> Types;
    }
    
    public Options Options { get; }
    private readonly Dictionary<IModule, CSharpDecompiler> decompilers_ = new Dictionary<IModule, CSharpDecompiler>();
    private readonly Dictionary<ITypeDefinition, RefMultiGenericTypeInfo> multiGenericTypes_ = new Dictionary<ITypeDefinition, RefMultiGenericTypeInfo>();
    private readonly Dictionary<ISymbol, SymbolNameSyntax> memberNames_ = new Dictionary<ISymbol, SymbolNameSyntax>();
    private static readonly DecompilerSettings decompilerSettings_ = new DecompilerSettings(LanguageVersion.Latest); 
    
    public SyntaxGenerator(Options options) {
      Options = options;
      foreach (var compilationUnit in GetCompilationUnits()) {
        compilationUnit.Write(options.OutCppDir);
      }
    }

    private IEnumerable<IModule> GetModules(string path) {
      var decompiler = new CSharpDecompiler(path, decompilerSettings_);
      foreach (var module in decompiler.TypeSystem.Modules) {
        decompilers_[module] = decompiler;
      }
      return decompiler.TypeSystem.Modules;
    }

    public CSharpDecompiler GetDecompiler(IModule module) {
      return decompilers_[module];
    }

     private IEnumerable<CompilationUnitTransform> GetCompilationUnits() {
      var modules = Options.Assemnlys.SelectMany(GetModules).Distinct();
      return modules.SelectMany(GetCompilationUnits);
    }

    private IEnumerable<CompilationUnitTransform> GetCompilationUnits(IModule module) {
      return new AssemblyTransform(this, module).GetCompilationUnits();
    }

    public void AddMultiGenericType(ITypeDefinition type, List<ITypeDefinition> types) {
      multiGenericTypes_.Add(type, new RefMultiGenericTypeInfo() { Types = types });
    }

    public bool IsVoidGenericType(ITypeDefinition type) {
      return multiGenericTypes_.ContainsKey(type);
    }

    public ITypeDefinition GetRefMultiGenericFirstType(ITypeDefinition type, out int genericCount) {
      var info = multiGenericTypes_.GetOrDefault(type);
      if (info != null) {
        genericCount = info.Types.Last().TypeParameterCount + 1;
        return info.Types.First();
      }
      genericCount = -1;
      return null;
    }

    public bool IsCompilationUnitIn(ITypeDefinition root, ITypeDefinition type) {
      if (root.Equals(type)) {
        return true;
      }
      var info = multiGenericTypes_.GetOrDefault(root);
      return info != null && info.Types.Contains(type);
    }

    public IdentifierSyntax GetMemberName(ISymbol symbol) {
      var name = memberNames_.GetOrDefault(symbol);
      if (name == null) {
        name = new SymbolNameSyntax(symbol.Name);
        memberNames_.Add(symbol, name);
        CheckMemberBadName(symbol, name);
      }
      return name;
    }

    private void CheckMemberBadName(ISymbol symbol, SymbolNameSyntax name) {
      string originalString = symbol.Name;
      switch (symbol.SymbolKind) {
        case SymbolKind.Field:
        case SymbolKind.Method: {
          if (Tokens.IsReservedWord(originalString)) {
            RefactorMemberName(originalString, symbol, name);
            break;
          }

          if (Utils.IsIdentifierIllegal(ref originalString)) {
            RefactorMemberName(originalString, symbol, name);
          }
          break;
        }
      }
    }

    private void RefactorMemberName(string originalString, ISymbol symbol, SymbolNameSyntax name) {
      name.Update(Utils.GetNewName(originalString, 1));
    }
  }
}
