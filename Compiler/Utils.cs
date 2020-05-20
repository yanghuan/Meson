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

    public static IType GetReferenceType(this IType type) {
      if (type.DeclaringType != null) {
        return type.DeclaringType.GetReferenceType();
      }
      return type switch
      {
        NullabilityAnnotatedType nullableType => nullableType.TypeWithoutAnnotation,
        ArrayType arrayType => arrayType.DirectBaseTypes.First(),
        PointerType pointerType => pointerType.ElementType.GetReferenceType(),
        ParameterizedType t => t.GenericType.GetReferenceType(),
        _ => type,
      };
    }

    public static string GetReferenceIncludeString(this ITypeDefinition reference) {
      string[] parts = new string[] { reference.ParentModule.Name }.Concat(reference.Namespace.Split('.')).ToArray();
      return $"{string.Join('/', parts)}/{reference.Name}.h";
    }

    public static string GetIncludeString(this ITypeDefinition type) {
      return $"{type.Name}.h";
    }

    public static bool IsMemberTypeExists(this ITypeDefinition typeDefinition, ITypeDefinition memberType) {
      foreach (var field in typeDefinition.Fields) {
        if (memberType.Equals(field.Type)) {
          return true;
        }
      }

      foreach (var nestedType in typeDefinition.NestedTypes) {
        if (nestedType.IsMemberTypeExists(memberType)) {
          return true;
        }
      }
      return false;
    }

    public static bool IsInternal(this ITypeDefinition typeDefinition, IType type) {
      if (typeDefinition.IsSame(type)) {
        return true;
      }

      if (typeDefinition.IsSame(type.DeclaringType)) {
        return true;
      }

      IType declaringType = typeDefinition.DeclaringType;
      while (declaringType != null) {
        if (declaringType.Equals(type.DeclaringType)) {
          return true;
        }
        declaringType = declaringType.DeclaringType;
      }

      return false;
    }

    private static bool IsSame(this ITypeDefinition typeDefinition, IType type) {
      if (type != null) {
        if (type is ITypeDefinition) {
          return type == typeDefinition;
        }

        if (type is ParameterizedType parameterizedType) {
          return typeDefinition.IsSame(parameterizedType.GenericType);
        }
      }

      return false;
    }

    public static bool IsRefType(this ITypeDefinition type) {
      return type.Kind != TypeKind.Struct && !type.IsStatic;
    }

    public static ITypeDefinition ToTypeDefinition(this IType type) {
      if (type is ITypeDefinition typeDefinition) {
        return typeDefinition;
      }

      if (type is ParameterizedType parameterizedType) {
        return parameterizedType.GenericType.ToTypeDefinition();
      }

      throw new InvalidCastException();
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

    public static string GetAccessibilityString(this ITypeDefinition type) {
      return type.DeclaringType != null ? type.Accessibility.ToTokenString() : null;
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
  }
}
