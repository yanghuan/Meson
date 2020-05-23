using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;

namespace Meson.Compiler {
  class AssemblyTransform {
    private sealed class RefMultiGenericTypeInfo {
      public List<ITypeDefinition> Types;
    }

    private CSharpDecompiler decompiler_;
    private Dictionary<ITypeDefinition, RefMultiGenericTypeInfo> refMultiGenericTypes_ = new Dictionary<ITypeDefinition, RefMultiGenericTypeInfo>();
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
          bool hasRef = types.Exists(i => i.IsRefType());
          if (hasRef) {
            foreach (var type in types) {
              refMultiGenericTypes_.Add(type, new RefMultiGenericTypeInfo() { Types = types });
            }
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

    public bool IsRefVoidGenericType(ITypeDefinition type) {
      return refMultiGenericTypes_.ContainsKey(type);
    }

    public ITypeDefinition GetRefMultiGenericFirstType(ITypeDefinition type, out int genericCount) {
      var info = refMultiGenericTypes_.GetOrDefault(type);
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
      var info = refMultiGenericTypes_.GetOrDefault(root);
      return info != null && info.Types.Contains(type);
    }

    internal IType GetDeclaringType(ITypeDefinition type) {
      var brotherTypeType = nestedBrotherTypes_.GetOrDefault(type);
      return (brotherTypeType ?? type).DeclaringType;
    }

    public bool IsInternalMemberType(IType memberType, ITypeDefinition typeDefinition) {
      if (typeDefinition.IsSame(memberType)) {
        return true;
      }

      var memberTypeDeclaringType = memberType.DeclaringType.GetDefinition();
      if (typeDefinition.IsSame(memberTypeDeclaringType)) {
        return true;
      }

      IType declaringType = GetDeclaringType(typeDefinition);
      while (declaringType != null) {
        if (declaringType.Equals(memberTypeDeclaringType)) {
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
