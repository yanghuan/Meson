using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Test {
  public static class Extensions {
    public static unsafe void Test() {
      int* p = stackalloc int[2];
      p[10] = 2;
    }
  }

  class Program {
    private static void Main(string[] args) {
      //IList<int> l = null;
      //IReadOnlyList ll = null;
      //IReadOnlyCollection lll = null;

      Console.WriteLine(args);
      Extensions.Test();
    }
  }
}
