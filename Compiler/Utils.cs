using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.TypeSystem;
using ICSharpCode.Decompiler.TypeSystem.Implementation;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class NotImplementedException : Exception {
    public NotImplementedException() {
    }
  }

  public sealed class CompilationErrorException : Exception {
    public CompilationErrorException(string message) : base(message) {
    }
  }

  public sealed class TypeDefinitionEqualityComparer : IEqualityComparer<ITypeDefinition> {
    public bool Equals(ITypeDefinition x, ITypeDefinition y) {
      return x.EQ(y);
    }

    public int GetHashCode(ITypeDefinition obj) {
      return $"{obj.ParentModule.Name}.{obj.FullName}".GetHashCode();
    }

    public static readonly TypeDefinitionEqualityComparer Default = new TypeDefinitionEqualityComparer();
  }

  internal static class Utils {
    public const string kDependExtra = "-dep";
    private const string kBackingFieldSuffix = ">k__BackingField";

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

    public static bool TryAdd<K, V>(this Dictionary<K, HashSet<V>> dict, K key, V value, IEqualityComparer<V> comparer = null) {
      var set = dict.GetOrDefault(key);
      if (set == null) {
        set = new HashSet<V>(comparer);
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

    public static T[] ArrayOf<T>(this T t) {
      return new T[] { t };
    }

    public static T[] ArrayOf<T>(this T t, T a) {
      return new T[] { t, a };
    }

    public static T[] ArrayOf<T>(this T t, T a, T b) {
      return new T[] { t, a, b };
    }

    public static T[] ArrayOf<T>(this T t, T a, T b, T c) {
      return new T[] { t, a, b, c };
    }

    public static T[] ArrayOf<T>(this T t, params T[] args) {
      T[] array = new T[args.Length + 1];
      array[0] = t;
      Array.Copy(args, 0, array, 1, args.Length);
      return array;
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

    public static IEnumerable<string> GetAllNamespaces(this string ns, string separator) {
      if (ns.Length > 0) {
        yield return ns;
        int index = ns.Length - 1;
        while (true) {
          int pos = ns.LastIndexOf(separator, index);
          if (pos == -1) {
            break;
          }
          yield return ns.Substring(0, pos);
          index = pos - 1;
        }
      }
    }

    public static string GetFullNamespace(this ITypeDefinition reference, bool hasGlobal = false, ITypeDefinition definition = null, bool isForUsing= false) {
      if (definition != null && definition.ParentModule.AssemblyName == reference.ParentModule.AssemblyName) {
        if (isForUsing) {
          return reference.Namespace.ReplaceDot();
        } else {
          foreach (string item in definition.Namespace.GetAllNamespaces(".")) {
            if (reference.Namespace.StartsWith(item)) {
              string name;
              if (reference.Namespace == item) {
                int pos = reference.Namespace.LastIndexOf('.');
                name = pos != -1 ? reference.Namespace.Substring(pos + 1).ReplaceDot() : reference.Namespace.ReplaceDot();
              } else {
                name = reference.Namespace.Substring(item.Length + 1).ReplaceDot();
              }
              return name;
            }
          }
        }
      }

      string ns;
      if (string.IsNullOrEmpty(reference.Namespace)) {
        ns = reference.ParentModule.Name;
      } else {
        ns = $"{reference.ParentModule.Name}.{reference.Namespace}";
      }
      return !hasGlobal ? ns.ReplaceDot() : Tokens.TwoColon + ns.ReplaceDot();
    }

    public static string GetFullName(this ITypeDefinition reference, ITypeDefinition definition = null) {
      string ns = reference.GetFullNamespace(true, definition);
      return $"{ns}{Tokens.TwoColon}{reference.Name}";
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
      static IEnumerable<IType> GetBaseTypes(ITypeDefinition type) {
        return type.DirectBaseTypes.Where(i => i.IsKnownType(KnownTypeCode.None));
      }

      switch (kind) {
        case ReferenceTypeKind.FieldStore: {
            return type.Fields.Where(i => !i.IsStatic).Select(i => i.Type).Distinct();
          }
        case ReferenceTypeKind.NestedReference: {
            return GetBaseTypes(type).Concat(type.Fields.Select(i => i.Type)).Concat(type.Methods.SelectMany(i => i.Parameters).Select(i => i.Type)).Distinct();
          }
        case ReferenceTypeKind.FieldReference: {
            return GetBaseTypes(type).Concat( type.Fields.Where(i => !i.IsStatic).Select(i => i.Type.GetReferenceType() ?? i.Type)).Distinct();
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

    public static bool EQ(this ITypeDefinition a, ITypeDefinition b) {
      return a.FullName == b.FullName && a.ParentModule.Name == b.ParentModule.Name;
    }

    public static bool IsRefType(this ITypeDefinition type) {
      return (type.Kind != TypeKind.Struct && type.Kind != TypeKind.Enum) && !type.IsStatic;
    }

    public static bool IsRefType(this IType type) {
      return type.Kind != TypeKind.Struct && type.Kind != TypeKind.Enum;
    }

    public static ITypeDefinition GetReferenceTypeDefinition(this IType type) {
      var definition = type.GetDefinition();
      if (definition == null && type is TypeWithElementType t) {
        definition = t.ElementType.GetReferenceTypeDefinition();
      }
      return definition;
    }

    public static bool IsInt32(this IType type) {
      return type.GetDefinition()?.IsInt32() ?? false;
    }

    public static bool IsInt32(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.Int32;
    }

    public static bool IsString(this IType type) {
      return type.GetDefinition()?.IsString() ?? false;
    }

    public static bool IsDecimal(this IType type) {
      return type.GetDefinition()?.IsDecimal() ?? false;
    }

    public static bool IsString(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.String;
    }

    public static bool IsDecimal(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.Decimal;
    }

    public static bool IsObject(this IType type) {
      return type.GetDefinition()?.IsObject() ?? false;
    }

    public static bool IsObject(this ITypeDefinition type) {
      return type.KnownTypeCode == KnownTypeCode.Object;
    }

    public static IType Original(this IType type) {
      if (type is NullabilityAnnotatedType t) {
        type = t.TypeWithoutAnnotation;
      }
      return type;
    }

    public static IEnumerable<IType> GetTypeArguments(this IType type) {
      if (type.TypeArguments.Count > 0) {
        IType genericType;
        if (type is ParameterizedType parameterizedType) {
          genericType = parameterizedType.GenericType.Original();
        } else {
          genericType = type;
        }
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
      return a switch
      {
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

    public static TemplateSyntax GetTemplateSyntax(this IMethod method) {
      if (method.TypeParameters.Count > 0) {
        var typeParameters = method.TypeParameters.Select(i => (IdentifierSyntax)i.Name);
        return new TemplateSyntax(typeParameters);
      }
      return null;
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

    public static LiteralExpressionSyntax GetPrimitiveTypeDefaultValue(this ITypeDefinition type) {
      switch (type.KnownTypeCode) {
        case KnownTypeCode.Boolean: 
          return BooleanLiteralExpressionSyntax.False;
        default:
          return NumberLiteralExpressionSyntax.Zero;
      }
    }

    internal static LiteralExpressionSyntax GetPrimitiveExpression(object value, bool isInPrimitiveType = false) {
      var type = value.GetType();
      var code = Type.GetTypeCode(type);
      switch (code) {
        case TypeCode.Char:{
          char v = (char)value;
          return new NumberLiteralExpressionSyntax(((int)v).ToString());
        }
        case TypeCode.String: {
          return new StringLiteralExpressionSyntax((string)value);
        }
        case TypeCode.Int32: {
          return new NumberLiteralExpressionSyntax(value.ToString());
        }
        case TypeCode.UInt32: {
          return new NumberLiteralExpressionSyntax($"{value}u");
        }
        case TypeCode.Boolean:{
          return value is false ? BooleanLiteralExpressionSyntax.False : BooleanLiteralExpressionSyntax.True;
        }
        case TypeCode.Single:{
          string s;
          if (value is float.NaN) {
            s = isInPrimitiveType ? "rt::NaN<float>" : "Single::NaN";
          } else if (value is float.NegativeInfinity) {
            s = isInPrimitiveType ? "rt::NegativeInfinity<float>" : "Single::NegativeInfinity";
          } else if (value is float.PositiveInfinity) {
            s = isInPrimitiveType ? "rt::PositiveInfinity<float>" : "Single::PositiveInfinity";
          } else {
            s = value.ToString();
          }
          return new NumberLiteralExpressionSyntax(s);
        }
        case TypeCode.Double:{
          string s;
          if (value is double.NaN) {
            s = isInPrimitiveType ? "rt::NaN<double>" : "Double::NaN";
          } else if (value is double.NegativeInfinity) {
            s = isInPrimitiveType ? "rt::NegativeInfinity<double>" : "Double::NegativeInfinity";
          } else if (value is double.PositiveInfinity) {
            s = isInPrimitiveType ? "rt::PositiveInfinity<double>" : "Double::PositiveInfinity";
          } else {
            s = value.ToString();
          }
          return new NumberLiteralExpressionSyntax(s);
        }
        case TypeCode.Decimal:{
          return new NumberLiteralExpressionSyntax(value.ToString());
        }
        default: {
          return new NumberLiteralExpressionSyntax(value.ToString());
        }
      }
    }

    public static IdentifierSyntax GetEnumUnderlyingTypeName(this ITypeDefinition type) {
      return innerValueTypeNames_[type.EnumUnderlyingType.FullName];
    }

    private static EnumForwardSyntax GetEnumForwardSyntax(this ITypeDefinition type) {
      return new EnumForwardSyntax(type.Name) { UnderlyingType = type.GetEnumUnderlyingTypeName() };
    }

    public static ForwardMacroSyntax GetNestedForwardStatement(this ITypeDefinition type) {
      return new ForwardMacroSyntax(type.Name, type.GetTypeParameters().Select(i => (IdentifierSyntax)i.Name), ForwardMacroKind.NestedClass);
    }

    public static ForwardMacroSyntax GetNestedFriendStatement(this ITypeDefinition type) {
      ForwardMacroKind kind = type.Kind == TypeKind.Struct ? ForwardMacroKind.FriendNestedStruct : ForwardMacroKind.FriendNestedClass;
      return new ForwardMacroSyntax(type.Name, type.GetTypeParameters().Select(i => (IdentifierSyntax)i.Name), kind) { 
        AccessibilityToken = type.Accessibility.ToTokenString(),
      };
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
      return type.ParentModule.AssemblyName == reference.ParentModule.AssemblyName && type.Namespace.StartsWith(reference.Namespace);
    }

    public static bool IsSameNamespace(this ITypeDefinition type, ITypeDefinition other) {
      return type.ParentModule == other.ParentModule && type.Namespace == other.Namespace;
    }

    public static IEnumerable<ITypeDefinition> GetAllBaseTypes(this ITypeDefinition type) {
      return type.GetAllBaseTypeDefinitions().Where(i => i.Kind != TypeKind.Interface);
    }

    public static IEnumerable<IMember> GetAllMembers(this ITypeDefinition type) {
      return type.GetAllBaseTypes().SelectMany(i => {
        List<IMember> members = new List<IMember>();
        foreach (var p in i.Properties) {
          if (p.CanGet) {
            members.Add(p.Getter);
          }
          if (p.CanSet) {
            members.Add(p.Setter);
          }
        }
        members.AddRange(i.Methods);
        members.AddRange(i.Fields);
        return members;
      });
    }

    public static string GetMemberName(this IMember member) {
      if (member.SymbolKind == SymbolKind.Field) {
        return ((IField)member).GetFieldName();
      }
      return member.Name;
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

    public static bool IsCtor(this IMethod method) {
      return !method.IsStatic && method.SymbolKind == SymbolKind.Constructor && method.DeclaringType.Kind == TypeKind.Struct;
    }

    public static bool IsMainEntryPoint(this IMethod symbol) {
      if (symbol.Name == "Main" && symbol.IsStatic && symbol.TypeArguments.Count == 0 && symbol.DeclaringType.TypeArguments.Count == 0) {
        if (symbol.ReturnType.Kind == TypeKind.Void || symbol.ReturnType.IsInt32()) {
          if (symbol.Parameters.Count == 0) {
            return true;
          } else if (symbol.Parameters.Count == 1) {
            var parameterType = symbol.Parameters[0].Type;
            if (parameterType.Kind == TypeKind.Array) {
              var arrayType = (ArrayType)parameterType;
              if (arrayType.ElementType.IsString()) {
                return true;
              }
            }
          }
        }
      }
      return false;
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

    public static string Wrap(this string name) {
      return name + "___";
    }

    public static string FirstCharLow(this string name) {
      return char.ToLower(name[0]) + name.Substring(1);
    }

    public static string LastNamespace(this string ns) {
      int pos = ns.LastIndexOf('.');
      return pos != -1 ? ns.Substring(pos + 1) : ns;
    }

    public static string GetNewIdentifierName(this string name, int index) {
      return index switch
      {
        0 => name,
        1 => name + "_",
        2 => "_" + name,
        _ => name + (index - 2),
      };
    }

    public static IdentifierSyntax Identifier(this string name) {
      return name;
    }

    public static ExpressionSyntax WithFullName(this ExpressionSyntax typeName, IType type, ITypeDefinition definition = null) {
      var typeDefinition = type.GetDefinition();
      string ns = typeDefinition.GetFullNamespace(true, definition);
      return ((IdentifierSyntax)ns).TwoColon(typeName);
    }

    public static T Accept<T>(this AstNode node, MethodTransform transform) where T : SyntaxNode {
      return (T)node.AcceptVisitor(transform);
    }

    public static ExpressionSyntax AcceptExpression(this AstNode node, MethodTransform transform) {
      return (ExpressionSyntax)node.AcceptVisitor(transform);
    }

    public static StatementSyntax AcceptStatement(this AstNode node, MethodTransform transform) {
      return (StatementSyntax)node.AcceptVisitor(transform);
    }

    public static Expression UnParenthesized(this Expression node) {
      if (node is ParenthesizedExpression parenthesizedExpression) {
        return parenthesizedExpression.Expression.UnParenthesized();
      }
      return node;
    }

    public static IType GetBaseType(this IType type) {
      var first = type.DirectBaseTypes.FirstOrDefault();
      return first != null && first.Kind != TypeKind.Interface ? first : null;
    }

    public static IEnumerable<IType> GetInterfaceTypes(this IType type) {
      return type.DirectBaseTypes.Where(i => i.Kind == TypeKind.Interface);
    }

    public static bool IsSubclassOf(this IType child, IType parent) {
      if (parent.IsObject()) {
        return true;
      }

      var p = child;
      if (p.Equals(parent)) {
        return false;
      }

      while (p != null) {
        if (p.Equals(parent)) {
          return true;
        }
        p = p.GetBaseType();
      }
      return false;
    }

    private static bool IsImplementInterface(this IType implementType, IType interfaceType) {
      Contract.Assert(interfaceType.Kind == TypeKind.Interface);

      var t = implementType;
      while (t != null) {
        var interfaces = implementType.GetInterfaceTypes();
        foreach (var i in interfaces) {
          if (i.Equals(interfaceType) || i.IsImplementInterface(interfaceType)) {
            return true;
          }
        }
        t = t.GetBaseType();
      }
      return false;
    }

    public static bool Is(this IType left, IType right) {
      if (left.Equals(right)) {
        return true;
      }

      if (left.IsSubclassOf(right)) {
        return true;
      }

      if (right.Kind == TypeKind.Interface) {
        return left.IsImplementInterface(right);
      }

      return false;
    }

    public static bool IsOverridable(this IProperty symbol) {
      return !symbol.IsStatic && (symbol.IsAbstract || symbol.IsVirtual || symbol.IsOverride);
    }

    public static bool IsPropertyField(this IProperty property) {
      if (property.IsOverridable()) {
        return false;
      }
      return property.Getter?.GetAttribute(KnownAttribute.CompilerGenerated) != null;
    }

    public static bool IsBackingField(this IField field) {
      return field.Name.StartsWith('<') && field.Name.EndsWith(kBackingFieldSuffix);
    }

    public static bool TryGetBackingFieldName(this IField field, out string name) {
      if (field.IsBackingField()) {
        name = field.Name[1..^kBackingFieldSuffix.Length];
        return true;
      }
      name = null;
      return false;
    }

    public static string GetBackingFieldName(this IProperty property) {
      return $"<{property.Name}{kBackingFieldSuffix}";
    }

    public static string GetFieldName(this IField field) {
      if (field.TryGetBackingFieldName(out string name)) {
        return name;
      }
      return field.Name;
    }

    public static string RemoveSpeacialChars(this string name) {
      return name.Replace(".", "").Replace("<", "").Replace(">", "").Replace(",", "");
    }
    
    public static bool IsNull(this Expression expression) {
      return expression == null || expression == Expression.Null;
    }
  }
}
