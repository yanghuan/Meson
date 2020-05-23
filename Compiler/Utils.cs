using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.TypeSystem.Implementation;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal static class Utils {
    public static T First<T>(this IList<T> list) {
      return list[0];
    }

    public static T Last<T>(this IList<T> list) {
      return list[list.Count - 1];
    }

    public static bool IsNullOrEmpty<T>(this IList<T> list) {
      return list == null || list.Count == 0;
    }

    public static T GetOrDefault<T>(this IList<T> list, int index, T v = default) {
      return index >= 0 && index < list.Count ? list[index] : v;
    }

    public static void RemoveRange<T>(this List<T> list, int index) {
      list.RemoveRange(index, list.Count - index);
    }

    public static T GetOrDefault<K, T>(this IDictionary<K, T> dict, K key, T t = default) {
      if (dict.TryGetValue(key, out T v)) {
        return v;
      }
      return t;
    }

    public static bool TryAdd<K, V>(this Dictionary<K, HashSet<V>> dict, K key, V value) {
      var set = dict.GetOrDefault(key);
      if (set == null) {
        set = new HashSet<V>();
        dict.Add(key, set);
      }
      return set.Add(value);
    }

    public static T GetOrAdd<K, T>(this IDictionary<K, T> dict, K key, Func<K, T> valueFunc) {
      if (!dict.TryGetValue(key, out var v)) {
        v = valueFunc(key);
        dict.Add(key, v);
      }
      return v;
    }

    public static bool Contains<K, V>(this Dictionary<K, HashSet<V>> dict, K key, V value) {
      var set = dict.GetOrDefault(key);
      return set != null && set.Contains(value);
    }

    public static void AddAt<T>(this IList<T> list, int index, T v) {
      if (index < list.Count) {
        list[index] = v;
      } else {
        int count = index - list.Count;
        for (int i = 0; i < count; ++i) {
          list.Add(default);
        }
        list.Add(v);
      }
    }

    public static int IndexOf<T>(this IEnumerable<T> source, T value) {
      var comparer = EqualityComparer<T>.Default;
      return source.IndexOf(i => comparer.Equals(i, value));
    }

    public static int IndexOf<T>(this IEnumerable<T> source, Predicate<T> match) {
      int index = 0;
      foreach (var item in source) {
        if (match(item)) {
          return index;
        }
        ++index;
      }
      return -1;
    }

    public static ITypeDefinition GetReferenceType(this IType type) {
      if (type.DeclaringType != null) {
        return type.DeclaringType.GetReferenceType();
      }
      return type switch
      {
        ArrayType arrayType => arrayType.DirectBaseTypes.First().GetReferenceType(),
        PointerType pointerType => pointerType.ElementType.GetReferenceType(),
        ParameterizedType t => t.GenericType.GetReferenceType(),
        _ => type.GetDefinition(),
      };
    }

    public static string GetReferenceIncludeString(this ITypeDefinition reference) {
      string[] parts = new string[] { reference.ParentModule.Name }.Concat(reference.Namespace.Split('.')).ToArray();
      return $"{string.Join('/', parts)}/{reference.Name}.h";
    }

    public static string GetIncludeString(this ITypeDefinition type) {
      return $"{type.Name}.h";
    }

    private static bool HasType(this IType type, ITypeDefinition other, HashSet<ITypeDefinition> recursiveTypes) {
      if (type.Original().Equals(other)) {
        return true;
      }

      foreach (var argument in type.TypeArguments) {
        if (argument.HasType(other, recursiveTypes)) {
          return true;
        }

        if (recursiveTypes != null) {
          var argumentTypeDefinition = argument.GetDefinition();
          if (argumentTypeDefinition != null && !recursiveTypes.Contains(argumentTypeDefinition)) {
            recursiveTypes.Add(argumentTypeDefinition);
            if (argumentTypeDefinition.IsMemberTypeExists(other, recursiveTypes)) {
              return true;
            }
          }
        }
      }

      return false;
    }
    
    private static IEnumerable<IType> GetMemberReferenceTypes(this ITypeDefinition type) {
      return type.Fields.Select(i => i.Type);
    }

    private static bool IsMemberTypeExists(this ITypeDefinition type, ITypeDefinition memberType, HashSet<ITypeDefinition> recursiveTypes) {
      recursiveTypes?.Add(type);
      foreach (var referenceType in type.GetMemberReferenceTypes()) {
        if (referenceType.Kind != TypeKind.TypeParameter) {
          if (referenceType.HasType(memberType, recursiveTypes)) {
            return true;
          }

          if (recursiveTypes != null) {
            var typeDefinition = referenceType.GetReferenceTypeDefinition();
            if (typeDefinition != null && !recursiveTypes.Contains(typeDefinition)) {
              recursiveTypes.Add(typeDefinition);
              if (typeDefinition.IsMemberTypeExists(memberType, recursiveTypes)) {
                return true;
              }
            }
          }
        }
      }

      foreach (var nestedType in type.NestedTypes) {
        if (nestedType.IsMemberTypeExists(memberType, recursiveTypes)) {
          return true;
        }
      }
      return false;
    }

    public static bool IsMemberTypeExists(this ITypeDefinition typeDefinition, ITypeDefinition memberType, bool isRecursiveTypeDefinition = false) {
      return typeDefinition.IsMemberTypeExists(memberType, isRecursiveTypeDefinition ? new HashSet<ITypeDefinition>() : null);
    }

    public static bool IsSame(this ITypeDefinition type, IType other) {
      if (other != null) {
        if (other is ITypeDefinition) {
          return other == type;
        }

        if (other is ParameterizedType parameterizedType) {
          return type.IsSame(parameterizedType.GenericType);
        }
      }
      return false;
    }

    public static bool IsRefType(this ITypeDefinition type) {
      return type.Kind != TypeKind.Struct && !type.IsStatic;
    }

    private static ITypeDefinition GetReferenceTypeDefinition(this IType type) {
      var definition = type.GetDefinition();
      if (definition == null && type is TypeWithElementType t) {
        definition = t.ElementType.GetReferenceTypeDefinition();
      }
      return definition;
    }

    public static bool IsIntType(this IType type) {
      return ((ITypeDefinition)type).KnownTypeCode == KnownTypeCode.Int32;
    }

    public static IType Original(this IType type) {
      if (type is NullabilityAnnotatedType t) {
        type = t.TypeWithoutAnnotation;
      }
      return type;
    }

    public static IEnumerable<IType> GetTypeArguments(this IType type) {
      if (type.TypeArguments.Count > 0) {
        var parameterizedType = (ParameterizedType)type;
        var genericType = parameterizedType.GenericType.Original();
        int skipCount = genericType.TypeParameters.Count(i => i.Owner != genericType);
        return type.TypeArguments.Skip(skipCount);
      }
      return Array.Empty<IType>();
    }

    public static IEnumerable<IType> GetTypeParameters(this ITypeDefinition type) {
      return type.TypeParameters.Where(i => i.Owner == type);
    }

    public static bool IsStringType(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.String;
    }

    public static bool IsObjectType(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.Object;
    }

    public static bool IsArrayType(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.Array;
    }

    public static string ToTokenString(this Accessibility a) {
      switch (a) {
        case Accessibility.Private:
          return Tokens.Private;
        case Accessibility.Protected:
          return Tokens.Protected;
      }
      return Tokens.Public;
    }

    private static List<ITypeDefinition> GetStructDeclaringTypes(this ITypeDefinition type) {
      List<ITypeDefinition> declaringTypes = new List<ITypeDefinition>();
      while (true) {
        var declaringType = type.DeclaringType?.GetDefinition();
        if (declaringType == null) {
          break;
        }
        if (declaringType.Kind == TypeKind.Struct) {
          declaringTypes.Add(declaringType);
        }
        type = declaringType;
      }
      return declaringTypes;
    }

    public static ITypeDefinition GetStructReferenceDeclaringType(this ITypeDefinition type) {
      var declaringTypes = type.GetStructDeclaringTypes();
      if (declaringTypes.Count > 0) {
        int maxIndex = -1;
        foreach (var referenceType in type.GetMemberReferenceTypes()) {
          if (referenceType.Kind == TypeKind.Struct) {
            int index = declaringTypes.FindIndex(i => i.Equals(referenceType));
            if (index != -1 && index > maxIndex) {
              maxIndex = index;
            }
          }
        }
        if (maxIndex != -1) {
          return declaringTypes[maxIndex];
        }
      }
      return null;
    }

    public static ForwardMacroSyntax GetForwardStatement(this ITypeDefinition type, int genericCount = -1) {
      if (genericCount != -1) {
        return new ForwardMacroSyntax(type.Name, Enumerable.Range(0, genericCount).Select(i => (IdentifierSyntax)$"T{i + 1}"), true);
      }
      return new ForwardMacroSyntax(type.Name, type.GetTypeParameters().Select(i => (IdentifierSyntax)i.Name));
    }
  }
}
