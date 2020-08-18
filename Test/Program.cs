using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  enum E {
    A,
    B,
    C
  }  

  static class Extension {
    public static void F(this E e, int a = 10, bool c = false) {

    }
  }


  class Program {
    private int A { get; set; }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      E.A.F(c: true);
    }
  }
}
