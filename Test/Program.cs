using System;
using System.Runtime.InteropServices;

namespace Test {
  class Program {
    public static void F(string s, params object[] args) {

    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      F("aaa", 1, 2, 3, 4);
    }
  }
}
