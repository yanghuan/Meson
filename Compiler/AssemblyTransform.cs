using System;
using System.Collections.Generic;
using System.Linq;

using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.TypeSystem;

namespace Meson.Compiler {
  class AssemblyTransform {
    public SyntaxGenerator Generator { get; }
    public IModule Module { get;}
    private readonly Dictionary<ITypeDefinition, ITypeDefinition> nestedBrotherTypes_ = new Dictionary<ITypeDefinition, ITypeDefinition>();
    private IEnumerable<CompilationUnitTransform> compilationUnits_;

    public AssemblyTransform(SyntaxGenerator generator, IModule module) {
      Generator = generator;
      Module = module;
      Init();
    }

    private void Init() {
      var exportTypes = Module.TypeDefinitions.Where(IsExportType);
      var rootTypes = GetTypes(exportTypes.Where(i => i.DeclaringType == null));
      CheckVoidGenericType(rootTypes);
      var nestedTypes = exportTypes.Where(i => i.DeclaringType != null);
      CheckNestedType(nestedTypes);
      compilationUnits_ = rootTypes.Select(Create);
    }

    private IEnumerable<List<ITypeDefinition>> GetTypes(IEnumerable<ITypeDefinition> types) {
      return types.GroupBy(i => i.FullName).Select(i => i.OrderBy(i => i.TypeParameterCount).ToList());
    }

    private static bool IsExportType(ITypeDefinition type) {
      return type.Name.Length > 0 && !type.Name.StartsWith("<");
    }

    public IEnumerable<CompilationUnitTransform> GetCompilationUnits() {
      return compilationUnits_;
    }

    private void CheckVoidGenericType(IEnumerable<List<ITypeDefinition>> sameNameTypes) {
      foreach (var types in sameNameTypes) {
        if (types.Count > 1) {
          foreach (var type in types) {
            Generator.AddMultiGenericType(type, types);
            CheckVoidGenericType(GetTypes(type.NestedTypes));
          }
        } else {
          var type = types.First();
          CheckVoidGenericType(GetTypes(type.NestedTypes));
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
