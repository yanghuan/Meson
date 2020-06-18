using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.TypeSystem.Implementation;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal static class Utils {
    public const string kDependExtra = "-dep";

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
        ByReferenceType byReferenceType => byReferenceType.ElementType.GetReferenceType(),
        ParameterizedType t => t.GenericType.GetReferenceType(),
        _ => type.GetDefinition(),
      };
    }

    public static string GetReferenceIncludeString(this ITypeDefinition reference, bool isReference = false) {
      IEnumerable<string> parts = new string[] { reference.ParentModule.Name };
      if (!string.IsNullOrEmpty(reference.Namespace)) {
        parts = parts.Concat(reference.Namespace.Split('.'));
      }
      string extra = isReference && (reference.Kind != TypeKind.Enum && reference.Kind != TypeKind.Interface) ? kDependExtra : string.Empty;
      return $"{string.Join('/', parts)}/{reference.Name}{extra}.h";
    }

    public static string GetFullNamespace(this ITypeDefinition reference, bool hasGlobal = false) {
      string ns;
      if (string.IsNullOrEmpty(reference.Namespace)) {
        ns = reference.ParentModule.Name;
      } else {
        ns = $"{reference.ParentModule.Name}.{reference.Namespace}";
      }
      return !hasGlobal ? ns.ReplaceDot() : Tokens.TwoColon + ns.ReplaceDot(); 
    }

    private static bool IsTypeArgumentHasType(this IType argument, ITypeDefinition other, HashSet<ITypeDefinition> recursiveTypes) {
      if (argument.HasType(other, recursiveTypes)) {
        return true;
      }

      if (recursiveTypes != null) {
        var argumentTypeDefinition = argument.GetDefinition();
        if (argumentTypeDefinition != null && !recursiveTypes.Contains(argumentTypeDefinition)) {
          if (argumentTypeDefinition.IsMemberTypeExists(other, recursiveTypes)) {
            return true;
          }
        }
      }

      return false;
    }

    private static bool HasType(this IType type, ITypeDefinition other, HashSet<ITypeDefinition> recursiveTypes) {
      if (other.Equals(type.GetDefinition())) {
        return true;
      }

      if (type is TypeWithElementType typeWithElementType) {
        if (IsTypeArgumentHasType(typeWithElementType.ElementType, other, recursiveTypes)) {
          return true;
        }
      } else {
        foreach (var argument in type.TypeArguments) {
          if (IsTypeArgumentHasType(argument, other, recursiveTypes)) {
            return true;
          }
        }
      }

      return false;
    }

    private enum ReferenceTypeKind {
      FieldStore,
      NestedReference,
      FieldReference,
    }

    private static IEnumerable<IType> GetMemberReferenceTypes(this ITypeDefinition type, ReferenceTypeKind kind) {
      switch (kind) {
        case ReferenceTypeKind.FieldStore: {
          return type.Fields.Where(i => !i.IsStatic).Select(i => i.Type);
        }
        case ReferenceTypeKind.NestedReference: {
          return type.Fields.Select(i => i.Type).Concat(type.Methods.SelectMany(i => i.Parameters).Select(i => i.Type));
        }
        case ReferenceTypeKind.FieldReference: {
          return type.Fields.Where(i => !i.IsStatic).Select(i => i.Type.GetReferenceType() ?? i.Type);
        }
      }
      throw new InvalidProgramException();
    }

    private static bool IsMemberTypeExists(this ITypeDefinition type, ITypeDefinition memberType, HashSet<ITypeDefinition> recursiveTypes) {
      recursiveTypes?.Add(type);
      ReferenceTypeKind kind = recursiveTypes == null ? ReferenceTypeKind.NestedReference : ReferenceTypeKind.FieldReference;
      foreach (var referenceType in type.GetMemberReferenceTypes(kind)) {
        if (referenceType.Kind != TypeKind.TypeParameter) {
          if (referenceType.HasType(memberType, recursiveTypes)) {
            return true;
          }

          if (recursiveTypes != null) {
            var typeDefinition = referenceType.GetReferenceTypeDefinition();
            if (typeDefinition != null && !recursiveTypes.Contains(typeDefinition)) {
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

    public static bool IsRefType(this IType type) {
      return type.Kind != TypeKind.Struct && type.Kind != TypeKind.Enum;
    }

    private static ITypeDefinition GetReferenceTypeDefinition(this IType type) {
      var definition = type.GetDefinition();
      if (definition == null && type is TypeWithElementType t) {
        definition = t.ElementType.GetReferenceTypeDefinition();
      }
      return definition;
    }

    public static bool IsInt32(this IType type) {
      return ((ITypeDefinition)type).KnownTypeCode == KnownTypeCode.Int32;
    }

    public static bool IsIEnumeratorOfT(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.IEnumeratorOfT;
    }

    public static bool IsIListOfT(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.IListOfT;
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
      return a switch {
        Accessibility.Private => Tokens.Private,
        Accessibility.Protected => Tokens.Protected,
        _ => Tokens.Public
      };
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
        foreach (var referenceType in type.GetMemberReferenceTypes(ReferenceTypeKind.FieldStore)) {
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

    public static ITypeDefinition GetRootObjectDefinition(this ITypeDefinition type) {
      if (!type.DirectBaseTypes.Any()) {
        return type;
      }
      return type.DirectBaseTypes.First().GetDefinition().GetRootObjectDefinition();
    }

    public static TemplateSyntax GetTemplateSyntax(this ITypeDefinition type) {
      TemplateSyntax template = null;
      if (type.TypeParameterCount > 0) {
        var typeParameters = type.GetTypeParameters().Select(i => new TemplateTypenameSyntax(i.Name));
        if (typeParameters.Any()) {
          template = new TemplateSyntax(typeParameters);
        }
      }
      return template;
    }

    public static ForwardMacroSyntax GetForwardStatement(this ITypeDefinition type, int genericCount) {
      return new ForwardMacroSyntax(type.Name, genericCount.GetTypeNames(), type.Kind == TypeKind.Struct ? ForwardMacroKind.MultiStruct : ForwardMacroKind.MultiClass);
    }

    private static readonly Dictionary<string, string> innerValueTypeNames_ = new Dictionary<string, string>() {
      ["System.Byte"] = "uint8_t",
      ["System.SByte"] = "int8_t",
      ["System.Boolean"] = "bool",
      ["System.Char"] = "char8_t",
      ["System.Int16"] = "int16_t",
      ["System.UInt16"] = "uint16_t",
      ["System.Int32"] = "int32_t",
      ["System.UInt32"] = "uint32_t",
      ["System.Int64"] = "int64_t",
      ["System.UInt64"] = "uint64_t",
      ["System.Single"] = "float",
      ["System.Double"] = "double",
    };

    public static string GetValueTypeInnerName(this IType type) {
      return innerValueTypeNames_.GetOrDefault(type.FullName);
    }

    public static IdentifierSyntax GetEnumUnderlyingTypeName(this ITypeDefinition type) {
      if (!type.EnumUnderlyingType.IsInt32()) {
        return innerValueTypeNames_[type.EnumUnderlyingType.FullName];
      }
      return null;
    }

    private static EnumForwardSyntax GetEnumForwardSyntax(this ITypeDefinition type) {
      return new EnumForwardSyntax(type.Name) { UnderlyingType = type.GetEnumUnderlyingTypeName() };
    }

    public static ForwardMacroSyntax GetNestedForwardStatement(this ITypeDefinition type) {
      return new ForwardMacroSyntax(type.Name, type.GetTypeParameters().Select(i => (IdentifierSyntax)i.Name), ForwardMacroKind.NestedClass);
    }

    public static StatementSyntax GetForwardStatement(this ITypeDefinition type) {
      if (type.IsArrayType()) {
        return type.GetForwardStatement(2);
      }

      if (type.Kind == TypeKind.Enum) {
        return type.GetEnumForwardSyntax();
      }

      ForwardMacroKind kind = type.Kind == TypeKind.Struct ? ForwardMacroKind.Struct : ForwardMacroKind.Class;
      return new ForwardMacroSyntax(type.Name, type.GetTypeParameters().Select(i => (IdentifierSyntax)i.Name), kind);
    }

    public static TemplateSyntax GetVoidTemplate(this int typeParameterCount) {
      var args = Enumerable.Range(0, typeParameterCount).Select((i, it) => new TemplateTypenameSyntax($"T{i + 1}", IdentifierSyntax.Void));
      return new TemplateSyntax(args);
    }

    public static IEnumerable<IdentifierSyntax> GetTypeNames(this int genericCount) {
      return Enumerable.Range(0, genericCount).Select(i => (IdentifierSyntax)$"T{i + 1}");
    }

    public static bool IsNamespaceContain(this ITypeDefinition type, ITypeDefinition reference) {
      return type.GetFullNamespace().StartsWith(reference.GetFullNamespace());
    }

    public static StringBuilder GetShortName(this IType type, StringBuilder sb, bool isFirst) {
      if (type.DeclaringType != null) {
        type.DeclaringType.GetShortName(sb, false);
      }
      sb.Append(type.Name);
      if (!isFirst) {
        sb.Append('.');
      }
      return sb;
    }

    public static string GetShortName(this IType type) {
      return type.GetShortName(new StringBuilder(), true).ToString();
    }

    public static bool IsCanForward(this ISymbol symbol) {
      return !(symbol is IField field && field.IsStatic);
    }

    private static readonly Regex identifierRegex_ = new Regex(@"^[a-zA-Z_][a-zA-Z0-9_]*$", RegexOptions.Compiled);

    public static bool IsIdentifierIllegal(ref string identifierName) {
      if (!identifierRegex_.IsMatch(identifierName)) {
        identifierName = EncodeToIdentifier(identifierName);
        return true;
      }
      return false;
    }

    private static string ToBase63(int number) {
      const string kAlphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
      int basis = kAlphabet.Length;
      int n = number;
      StringBuilder sb = new StringBuilder();
      while (n > 0) {
        char ch = kAlphabet[n % basis];
        sb.Append(ch);
        n /= basis;
      }
      return sb.ToString();
    }

    private static string EncodeToIdentifier(string name) {
      StringBuilder sb = new StringBuilder();
      foreach (char c in name) {
        if (c < 127) {
          sb.Append(c);
        } else {
          string base63 = ToBase63(c);
          sb.Append(base63);
        }
      }
      if (char.IsNumber(sb[0])) {
        sb.Insert(0, '_');
      }
      return sb.ToString();
    }

    public static string GetNewName(string name, int index) {
      return index switch
      {
        0 => name,
        1 => name + "_",
        2 => "_" + name,
        _ => name + (index - 2),
      };
    }

    public static string ReplaceDot(this string name) {
      return name.Replace(Tokens.Dot, Tokens.TwoColon);
    }

    public static string WithNamespace(this string name) {
      return name + "Namespace";
    }

    public static ExpressionSyntax WithFullName(this ExpressionSyntax typeName, IType type) {
      IdentifierSyntax ns = type.GetDefinition().GetFullNamespace(true);
      return ns.TwoColon(typeName);
    }

    public static T Accept<T>(this AstNode node, MethodTransform transform) where T : SyntaxNode {
      return (T)node.AcceptVisitor(transform);
    }

    public static ExpressionSyntax AcceptExpression(this AstNode node, MethodTransform transform) {
      return node.Accept<ExpressionSyntax>(transform); ;
    }
  }
}
