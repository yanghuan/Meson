using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Text;
using System.Linq;

using Meson.Compiler.CppAst;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.CSharp.Syntax;

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
      decompilers_.Add(decompiler.TypeSystem.MainModule, decompiler);
      return decompiler.TypeSystem.Modules;
    }

    public CSharpDecompiler GetDecompiler(IModule module) {
      var decompiler = decompilers_.GetOrDefault(module);
      if (decompiler == null) {
        decompiler = new CSharpDecompiler(module.PEFile.FileName, decompilerSettings_);
        decompilers_.Add(module, decompiler);
      }
      return decompiler;
    }

    public MethodDeclaration GetMethodDeclaration(IMethod method) {
      var decompiler = GetDecompiler(method.ParentModule);
      var node = decompiler.Decompile(method.MetadataToken);
      return node.Members.OfType<MethodDeclaration>().FirstOrDefault();
    }

    private IEnumerable<CompilationUnitTransform> GetCompilationUnits() {
      var modules = Options.Assemnlys.SelectMany(GetModules).Distinct();
      var assemblyTransforms = modules.Select(i => new AssemblyTransform(this, i)).ToList();
      return assemblyTransforms.SelectMany(i => i.GetCompilationUnits());
    }

    public void AddMultiGenericType(ITypeDefinition type, List<ITypeDefinition> types) {
      multiGenericTypes_.Add(type, new RefMultiGenericTypeInfo() { Types = types });
    }

    public bool IsVoidGenericType(ITypeDefinition type) {
      if (type.IsArrayType()) {
        return true;
      }
      return multiGenericTypes_.ContainsKey(type);
    }

    public ITypeDefinition GetMultiGenericFirstType(ITypeDefinition type, out int genericCount) {
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
        string symbolName = symbol.Name;
        switch (symbol.SymbolKind) {
          case SymbolKind.Accessor: {
              var method = (IMethod)symbol;
              if (method.IsExplicitInterfaceImplementation) {
                int i = symbolName.LastIndexOf('.');
                Contract.Assert(i != -1);
                string propertyName = symbolName.Substring(i + 1);
                int j = symbolName.LastIndexOf('.', i - 1);
                Contract.Assert(j != -1);
                string prefix = symbolName.Substring(j + 1, i - j - 1);
                symbolName = $"{propertyName}Of{prefix.RemoveSpeacialChars()}";
              }
              break;
            }
          case SymbolKind.Field: {
              var field = (IField)symbol;
              if (field.TryGetBackingFieldName(out string backingFieldName)) {
                symbolName = backingFieldName;
              }
              break;
            }
          case SymbolKind.Constructor: {
              var ctor = (IMethod)symbol;
              symbolName = ctor.IsStatic ? "SCtor" : "Ctor";
              break;
            }
          case SymbolKind.Operator: {
              break;
            }
          case SymbolKind.Parameter: {
              if (string.IsNullOrEmpty(symbolName)) {
                symbolName = "_";
              }
              break;
            }
        }
        name = new SymbolNameSyntax(symbolName);
        memberNames_.Add(symbol, name);
        CheckMemberBadName(symbol, symbolName, name);
      }
      return name;
    }

    private void CheckMemberBadName(ISymbol symbol, string originalString, SymbolNameSyntax name) {
      switch (symbol.SymbolKind) {
        case SymbolKind.Field:
        case SymbolKind.Method:
        case SymbolKind.Parameter: {
            if (Tokens.IsReservedWord(originalString)) {
              string newName = Utils.GetNewName(originalString, 1);
              name.Update(newName);
              break;
            }

            if (Utils.IsIdentifierIllegal(ref originalString)) {
              string newName = Utils.GetNewName(originalString, 0);
              name.Update(newName);
            }
            break;
          }
      }
    }
  }
}
