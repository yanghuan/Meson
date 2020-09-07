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
    private readonly Dictionary<ITypeDefinition, RefMultiGenericTypeInfo> multiGenericTypes_ = new Dictionary<ITypeDefinition, RefMultiGenericTypeInfo>(TypeDefinitionEqualityComparer.Default);
    private readonly Dictionary<ISymbol, SymbolNameSyntax> memberNames_ = new Dictionary<ISymbol, SymbolNameSyntax>();
    private Dictionary<string, HashSet<ITypeDefinition>> namespaceTypes_;
    private static readonly DecompilerSettings decompilerSettings_ = new DecompilerSettings(LanguageVersion.Latest) {
      ThrowExpressions = false,
      StringInterpolation = false,
      NullPropagation = false,
      Discards = false,
      OutVariables = false,
      NamedArguments = false,
      UseLambdaSyntax = false,
      AnonymousMethods = false,
      QueryExpressions = false,
      ExtensionMethods = false,
      SwitchStatementOnString = false,
      NativeIntegers = false,
    };
    private readonly List<ITypeDefinition> knownTypes_ = new List<ITypeDefinition>();

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

    public EntityDeclaration GetMethodDeclaration(IMethod method) {
      var decompiler = GetDecompiler(method.ParentModule);
      var node = decompiler.Decompile(method.MetadataToken);
      return node.Members.OfType<EntityDeclaration>().First();
    }

    private IEnumerable<CompilationUnitTransform> GetCompilationUnits() {
      var modules = Options.Assemnlys.SelectMany(GetModules).Distinct();
      CheckSameNameTypes(modules);
      var assemblyTransforms = modules.Select(i => new AssemblyTransform(this, i)).ToList();
      return assemblyTransforms.SelectMany(i => i.GetCompilationUnits());
    }

    public ITypeDefinition IntPtrTypeDefinition => GetKnownType(KnownTypeCode.IntPtr);
    public ITypeDefinition UIntPtrTypeDefinition => GetKnownType(KnownTypeCode.UIntPtr);
    public ITypeDefinition StringTypeDefinition => GetKnownType(KnownTypeCode.String);
    public ITypeDefinition TypeTypeDefinition => GetKnownType(KnownTypeCode.Type);

    internal ITypeDefinition GetKnownType(KnownTypeCode code) {
      int index = code - KnownTypeCode.Object;
      return knownTypes_[index];
    }

    private bool TopLevelTypeFilter(ITypeDefinition type) {
      if (type.Name.StartsWith('<')) {
        return false;
      }
      if (type.KnownTypeCode != KnownTypeCode.None) {
        int index = type.KnownTypeCode - KnownTypeCode.Object;
        knownTypes_.AddAt(index, type);
      }
      return true;
    }

    private void CheckSameNameTypes(IEnumerable<IModule> modules) {
      var types = modules.SelectMany(i => i.TopLevelTypeDefinitions.Where(TopLevelTypeFilter));
      namespaceTypes_ = types.GroupBy(i => i.GetFullNamespace()).ToDictionary(i => i.Key, i => new HashSet<ITypeDefinition>(i, TypeDefinitionEqualityComparer.Default));
    }

    internal bool TryGetReferenceUsing(ITypeDefinition reference, ITypeDefinition definition, ReferencePackage info, out string usingNamespace) {
      if (!definition.IsNamespaceContain(reference)) {
        usingNamespace = reference.GetFullNamespace(true, definition, true);
        AddImportTypes(definition, usingNamespace, info.ImportTypes);
        return true;
      }
      usingNamespace = null;
      return false;
    }

    internal IEnumerable<ITypeDefinition> GetTypesInNamespace(string ns) {
      return namespaceTypes_.GetOrDefault(ns);
    }

    private void AddImportTypes(ITypeDefinition definition, string usingNamespace, HashSet<ITypeDefinition> importTypes) {
      if (usingNamespace.StartsWith(Tokens.TwoColon)) {
        string ns = usingNamespace.Substring(Tokens.TwoColon.Length);
        var types = GetTypesInNamespace(ns);
        if (types != null) {
          importTypes.UnionWith(types);
        }
      } else {
        foreach (string i in definition.GetFullNamespace().GetAllNamespaces(Tokens.TwoColon)) {
          string ns = i + Tokens.TwoColon + usingNamespace;
          var types = GetTypesInNamespace(ns);
          if (types != null) {
            importTypes.UnionWith(types);
          }
        }
      }
    }

    public void AddMultiGenericType(List<ITypeDefinition> types) {
      multiGenericTypes_.Add(types.First(), new RefMultiGenericTypeInfo() { Types = types });
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
      Contract.Assert(symbol != null);
      var name = memberNames_.GetOrDefault(symbol);
      if (name == null) {
        string symbolName = symbol.Name;
        switch (symbol.SymbolKind) {
          case SymbolKind.Accessor:
          case SymbolKind.Method: {
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
              symbolName = symbol.Name.TrimStart('.');
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

    private static void CheckMemberBadName(ISymbol symbol, string originalString, SymbolNameSyntax name) {
      switch (symbol.SymbolKind) {
        case SymbolKind.Field:
        case SymbolKind.Method:
        case SymbolKind.Parameter: {
            if (Utils.CheckBadName(ref originalString)) {
              name.Update(originalString);
            }
            break;
          }
      }
    }
  }
}
