using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  class SyntaxNode {
    internal virtual void Render(CppRenderer renderer) {
      throw new NotSupportedException($"{this.GetType().Name} is not override");
    }

    public static readonly string[] TempIdentifiers = {
      "default", "extern", "ref", "out", "byte", "uint", "lock", "fixed",  "internal",
    };
  }

  class Keyword {
    public const string Alignas = "alignas";
    public const string Alignof = "alignof";
    public const string And = "and";
    public const string And_eq = "and_eq";
    public const string Asm = "asm";
    public const string Auto = "auto";
    public const string Bitand = "bitand";
    public const string Bitor = "bitor";
    public const string Bool = "bool";
    public const string Break = "break";
    public const string Case = "case";
    public const string Catch = "catch";
    public const string Char = "char";
    public const string Char8_t = "char8_t";
    public const string char16_t = "char16_t";
    public const string char32_t = "char32_t";
    public const string Class = "class";
    public const string Compl = "compl";
    public const string concept = "concept";
    public const string Const = "const";
    public const string Consteval = "consteval";
    public const string Constexpr = "constexpr";
    public const string Constinit = "constinit";
    public const string Const_cast = "const_cast";
    public const string Continue = "continue";
    public const string Co_await = "co_await";
    public const string Co_return = "co_return";
    public const string Co_yield = "co_yield";
    public const string Decltype = "decltype";
    public const string Default = "default";
    public const string Delete = "delete";
    public const string Do = "do";
    public const string Double = "double";
    public const string Dynamic_cast = "dynamic_cast";
    public const string Else = "else";
    public const string Enum = "enum";
    public const string Explicit = "explicit";
    public const string Export = "export";
    public const string Extern = "extern";
    public const string False = "false";
    public const string Float = "float";
    public const string For = "for";
    public const string Friend = "friend";
    public const string Goto = "goto";
    public const string If = "if";
    public const string Inline = "inline";
    public const string Int = "int";
    public const string Long = "long";
    public const string Mutable = "mutable";
    public const string Namespace = "namespace";
    public const string New = "new";
    public const string Noexcept = "noexcept";
    public const string Not = "not";
    public const string Not_eq = "not_eq";
    public const string Nullptr = "nullptr";
    public const string Operator = "operator";
    public const string Or = "or";
    public const string Or_eq = "or_eq";
    public const string Private = "private";
    public const string Protected = "protected";
    public const string Public = "public";
    public const string Reflexpr = "reflexpr";
    public const string Register = "register";
    public const string Reinterpret_cast = "reinterpret_cast";
    public const string Requires = "requires";
    public const string Return = "return";
    public const string Short = "short";
    public const string Signed = "signed";
    public const string Sizeof = "sizeof";
    public const string Static = "static";
    public const string Static_assert = "static_assert";
    public const string Static_cast = "static_cast";
    public const string Struct = "struct";
    public const string Switch = "switch";
    public const string Template = "template";
    public const string This = "this";
    public const string Thread_local = "thread_local";
    public const string Throw = "throw";
    public const string True = "true";
    public const string Try = "try";
    public const string Typedef = "typedef";
    public const string Typeid = "typeid";
    public const string Typename = "typename";
    public const string Union = "union";
    public const string Unsigned = "unsigned";
    public const string Using = "using";
    public const string Virtual = "virtual";
    public const string Void = "void";
    public const string Volatile = "volatile";
    public const string Wchar_t = "wchar_t";
    public const string While = "while";
    public const string Xor = "xor";
    public const string Xor_eq = "xor_eq";
  }

  sealed class Tokens : Keyword {
    public const string PretreatmentPrefix = "#";
    public const string Pragma = "pragma";
    public const string Include = "include";
    public const string Define = "define";
    public const string Undef = "undef";
    public const string Finally = "finally";
    public const string OpenParentheses = "(";
    public const string CloseParentheses = ")";
    public const string OpenBrace = "{";
    public const string CloseBrace = "}";
    public const string OpenBracket = "[";
    public const string CloseBracket = "]";
    public const string Semicolon = ";";
    public const string Colon = ":";
    public new const string Equals = "=";
    public const string PlusEquals = "+=";
    public const string SubEquals = "-=";
    public const string EqualsEquals = "==";
    public const string NotEquals = "!=";
    public const string Plus = "+";
    public const string PlusPlus = "++";
    public const string Sub = "-";
    public const string SubSub = "--";
    public const string Multiply = "*";
    public const string Div = "/";
    public const string Mod = "%";
    public const string Dot = ".";
    public const string Asterisk = "*";
    public const string Ampersand = "&";
    public const string LogicAnd = "&&";
    public const string LogicOr = "||";
    public const string Exclamation = "!";
    public const string Quote = "\"";
    public const string Arrow = "->";
    public const string TwoColon = "::";
    public const string Less = "<";
    public const string LessLess = "<<";
    public const string LessEquals = "<=";
    public const string Greater = ">";
    public const string GreaterEquals = ">=";
    public const string GreaterGreater = ">>";
    public const string LineComment = "//";
    public const string OpneComment = "/*";
    public const string CloseComment = "*/";
    public const string Tilde = "~";

    private static readonly HashSet<string> ReservedWords = new HashSet<string>() {            
      // compiler reserved words
      "rt",
    };

    static Tokens() {
      // lua reserved words
      foreach (var field in typeof(Keyword).GetFields()) {
        ReservedWords.Add(field.GetRawConstantValue().ToString());
      }
    }

    public static bool IsReservedWord(string identifier) {
      return ReservedWords.Contains(identifier);
    }
  }
}
