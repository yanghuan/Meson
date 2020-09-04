using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  struct TestAAA {
    public void f() {
    }
  }

  class Program {
    private unsafe static string f(ref TestAAA aa) {
      return string.Empty;
    }

    private unsafe static void f(TestAAA* ctx) {
      ref TestAAA b = ref *ctx;
      string s = f(ref b);
      b = ref *ctx;
    }

    private static void f(IntPtr a) {

    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      f((IntPtr)(-2147483647));
    }
  }
}
