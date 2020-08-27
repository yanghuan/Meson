using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  unsafe struct A {
    public fixed char a[10];
  }

  class Program {
    private unsafe static void Test() {
      long aa = 0;
      A* a = (A*)aa;
    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      string s = "\nsssss\a";
    }
  }
}
