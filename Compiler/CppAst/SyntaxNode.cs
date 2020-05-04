using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.CppAst {
  class SyntaxNode {
    internal virtual void Render(CppRenderer renderer) {
      throw new NotSupportedException($"{this.GetType().Name} is not override");
    }
  }

  static class Tokens {
    public const string PretreatmentPrefix = "#";
    public const string Pragma = "pragma";
    public const string Include = "include";
    public const string OpenBrace = "{";
    public const string CloseBrace = "}";
    public const string Namespace = "namespace";
    public const string Class = "class";
    public const string Struct = "struct";
    public const string Enum = "enum";
    public const string Static = "static";
    public const string Semicolon = ";";
    public new const string Equals = "=";
    public const string Dot = ".";
    public const string Quote = "\"";
    public const string Arrow = "->";
    public const string TwoColon = "::";
    public const string Less = "<";
    public const string Greater = ">";
  }

  sealed class SyntaxList<T> : List<T> where T : SyntaxNode {
    public new void Add(T node) {
      if (node == null) {
        throw new ArgumentNullException(nameof(node));
      }
      base.Add(node);
    }

    public new void AddRange(IEnumerable<T> collection) {
      foreach (var item in collection) {
        if (item == null) {
          throw new ArgumentNullException(nameof(item));
        }
        base.Add(item);
      }
    }
  }
}
