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

    public AssemblyTransform(SyntaxGenerator generator, IModule module) {
      Generator = generator;
      Module = module;
    }

    private static bool IsExportType(ITypeDefinition type) {
      return type.Name.Length > 0 && !type.Name.StartsWith("<");
    }

    public IEnumerable<CompilationUnitTransform> GetCompilationUnits() {
      var exportTypes = Module.TypeDefinitions.Where(IsExportType);
      var nestedTypes = exportTypes.Where(i => i.DeclaringType != null);
      var rootTypes = exportTypes.Where(i => i.DeclaringType == null);
      var sameNameTypes = rootTypes.GroupBy(i => i.FullName).ToDictionary(i => i.Key, i => i.OrderBy(i => i.TypeParameterCount).ToList());
      CheckVoidGenericType(sameNameTypes.Values);
      CheckNestedType(nestedTypes);
      var compilationUnits = new List<CompilationUnitTransform>();
      compilationUnits.AddRange(sameNameTypes.Values.Select(Create));
      return compilationUnits;
    }

    private void CheckVoidGenericType(IEnumerable<List<ITypeDefinition>> sameNameTypes) {
      foreach (var types in sameNameTypes) {
        if (types.Count > 1) {
          foreach (var type in types) {
            Generator.AddMultiGenericType(type, types);
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
