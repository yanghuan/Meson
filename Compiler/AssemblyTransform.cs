using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;

namespace Meson.Compiler {
  class AssemblyTransform {
    private CSharpDecompiler decompiler_;
    private HashSet<ITypeDefinition> voidGenericTypes_ = new HashSet<ITypeDefinition>();
    private Dictionary<ITypeDefinition, ITypeDefinition> nestedBrotherTypes_ = new Dictionary<ITypeDefinition, ITypeDefinition>();

    public AssemblyTransform(string path) {
      decompiler_ = new CSharpDecompiler(path, GetDecompilerSettings());
    }

    private static DecompilerSettings GetDecompilerSettings() {
      DecompilerSettings settings = new DecompilerSettings(LanguageVersion.Latest);
      return settings;
    }

    private static bool IsExportType(ITypeDefinition type) {
      return type.Name.Length > 0 && !type.Name.StartsWith("<");
    }

    public void Generate(string outDir) {
      var exportTypes = decompiler_.TypeSystem.MainModule.TypeDefinitions.Where(IsExportType);
      var nestedTypes = exportTypes.Where(i => i.DeclaringType != null);
      var rootTypes = exportTypes.Where(i => i.DeclaringType == null);
      var sameNameTypes = rootTypes.GroupBy(i => $"{i.Namespace}.{i.Name}").ToDictionary(i => i.Key, i => i.OrderBy(i => i.TypeParameterCount).ToList());
      CheckVoidGenericType(sameNameTypes.Values);
      CheckNestedType(nestedTypes);
      foreach (var types in sameNameTypes.Values) {
        Create(types).Write(outDir);
      }
    }

    private void CheckVoidGenericType(IEnumerable<List<ITypeDefinition>> sameNameTypes) {
      foreach (var types in sameNameTypes) {
        if (types.Count > 1) {
          var type = types.First();
          if (type.TypeParameterCount == 0 && type.IsRefType()) {
            voidGenericTypes_.Add(type);
          }
        }
      }
    }

    private void CheckNestedType(IEnumerable<ITypeDefinition> types) {
      foreach (var type in types) {
        var declaringType = type.GetStructReferenceDeclaringType();
        if (declaringType != null) {
          nestedBrotherTypes_.Add(type, declaringType);
        }
      }
    }

    private CompilationUnitTransform Create(List<ITypeDefinition> types) {
      return new CompilationUnitTransform(this, types);
    }

    public bool IsVoidGenericType(IType type) {
      return voidGenericTypes_.Contains(type);
    }

    internal IType GetDeclaringType(ITypeDefinition type) {
      var brotherTypeType = nestedBrotherTypes_.GetOrDefault(type);
      return (brotherTypeType ?? type).DeclaringType;
    }

    public bool IsInternalMemberType(IType memberType, ITypeDefinition typeDefinition) {
      if (typeDefinition.IsSame(memberType)) {
        return true;
      }
      if (typeDefinition.IsSame(memberType.DeclaringType)) {
        return true;
      }
      IType declaringType = GetDeclaringType(typeDefinition);
      while (declaringType != null) {
        if (declaringType.Equals(memberType.DeclaringType)) {
          return true;
        }
        declaringType = declaringType.DeclaringType;
      }
      return false;
    }

    public ITypeDefinition GetNestedBrotherType(IEnumerable<ITypeDefinition> types) {
      foreach (var type in types) {
        var brotherType = nestedBrotherTypes_.GetOrDefault(type);
        if (brotherType != null) {
          return brotherType;
        }
      }
      return null;
    }
  }
}
