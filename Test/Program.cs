using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  struct A {

  }

  class Program {
    private unsafe static void Test() {
      long aa = 0;
      A* a = (A*)aa;
    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      int b = 10;
    }
  }
}
