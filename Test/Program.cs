using System;
using System.Runtime.InteropServices;

namespace Test {
  class Program {
    private static int a;
    private static int A {
      get {
        return a;
      }
      set {
        a = value;
      }
    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      A = args.Length;
      int aa = A;
    }
  }
}
