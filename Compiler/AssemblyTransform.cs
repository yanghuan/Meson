using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;

namespace Meson.Compiler {
  class AssemblyTransform {
    private CSharpDecompiler decompiler_;
    private HashSet<IType> voidGenericTypes_ = new HashSet<IType>();

    public AssemblyTransform(string path) {
      decompiler_ = new CSharpDecompiler(path, GetDecompilerSettings());
    }

    private static DecompilerSettings GetDecompilerSettings() {
      DecompilerSettings settings = new DecompilerSettings(LanguageVersion.Latest);
      return settings;
    }

    public void Generate(string outDir) {
      var exportTypes = decompiler_.TypeSystem.MainModule.TypeDefinitions.Where(IsExport);
      var group = exportTypes.GroupBy(i => $"{i.Namespace}.{i.Name}");
      DoPretreatment(group);
      foreach (var types in group) {
        Create(types).Write(outDir);
      }
    }

    private void DoPretreatment(IEnumerable<IEnumerable<ITypeDefinition>> group) {
      foreach (var types in group) {
        if (types.Count() > 1) {
          var type = types.SingleOrDefault(i => i.TypeParameterCount == 0 && i.IsRefType());
          if (type != null) {
            voidGenericTypes_.Add(type);
          }
        }
      }
    }

    private bool IsExport(ITypeDefinition type) {
      if (type.Name.Length == 0) {
        return false;
      }
      if (type.Name.StartsWith("<")) {
        return false;
      }
      if (type.DeclaringType != null) {
        return false;
      }
      return true;
    }

    private CompilationUnitTransform Create(IEnumerable<ITypeDefinition> types) {
      return new CompilationUnitTransform(this, types.OrderBy(i => i.TypeParameterCount));
    }

    public bool IsVoidGenericType(IType type) {
      return voidGenericTypes_.Contains(type);
    }
  }
}
