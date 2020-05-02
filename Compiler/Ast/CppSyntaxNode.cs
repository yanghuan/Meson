using System;
using System.Collections.Generic;
using System.Text;

namespace Meson.Compiler.Ast {
  class CppSyntaxNode {
    internal virtual void Render(CppRenderer renderer) {
      throw new NotSupportedException($"{this.GetType().Name} is not override");
    }
  }

  static class Tokens {
    public const string PretreatmentPrefix = "#";
    public const string Pragma = "pragma";
  }

  sealed class CppSyntaxList<T> : List<T> where T : CppSyntaxNode {
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
