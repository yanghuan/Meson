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
      return type switch {
        NullabilityAnnotatedType nullableType => nullableType.TypeWithoutAnnotation,
        ArrayType arrayType => arrayType.DirectBaseTypes.First(),
        PointerType pointerType => pointerType.ElementType,
        ParameterizedType t => GetReferenceType(t.GenericType),
        _ => type,
      };
    }

    public static string GetIncludeString(this IEntity entity) {
      string[] parts = new string[] { entity.ParentModule.Name }.Concat(entity.Namespace.Split('.')).ToArray();
      return $"{string.Join('/', parts)}/{entity.Name}.h";
    }

    public static string GetIncludeString(this ITypeDefinition type) {
      return $"{type.Name}.h";
    }

    public static bool IsSame(this ITypeDefinition definition, IType type) {
      if (type != null) {
        if (type is ITypeDefinition) {
          return type == definition;
        }

        if (type is ParameterizedType parameterizedType) {
          return definition.IsSame(parameterizedType.GenericType);
        }
      }

      return false;
    }

    public static bool IsValueType(this IType type) {
      return type.IsReferenceType == false;
    }

    public static bool IsIntType(this IType type) {
      return ((ITypeDefinition)type).KnownTypeCode == KnownTypeCode.Int32;
    }

    public static string GetArrayName(this IType type) {
      return type.Name + "__";
    }

    public static IEnumerable<IType> GetTypeArguments(this IType type) {
      if (type.TypeArguments.Count > 0) {
        ParameterizedType parameterizedType = (ParameterizedType)type;
        foreach (var typeArgument in type.TypeArguments) {
          bool isSkip = false;
          if (typeArgument is NullabilityAnnotatedTypeParameter parameter) {
            if (parameter.OriginalTypeParameter.Owner != parameterizedType.GenericType) {
              isSkip = true;
            }
          }
          if (!isSkip) {
            yield return typeArgument;
          }
        }
      }
    }

    public static IEnumerable<IType> GetTypeParameters(this ITypeDefinition type) {
      return type.TypeParameters.Where(i => i.Owner == type);
    }

    public static bool IsRefType(this ITypeDefinition type) {
      return type.IsReferenceType == true && !type.IsStatic;
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
  }
}
