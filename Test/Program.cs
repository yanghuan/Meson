using System;
using System.Runtime.InteropServices;

namespace Test {
  class Program {
    private static void Write<T>(ref T a, T b) {

    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      Write(ref args, null);
    }
  }
}
