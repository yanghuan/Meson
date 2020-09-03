using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  class Program {
    private static int[] Get(params int[] args) {
      return args;
    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      var a1 = Get();
      var a2 = Get();
      Console.WriteLine(a1 == a2);
      Console.WriteLine(a1 == Array.Empty<int>());
    }
  }
}
