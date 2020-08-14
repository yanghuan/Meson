using System;
using System.Runtime.InteropServices;

namespace Test {
  class Program {
    private static void Main(string[] args) {
      Console.WriteLine(args);
      int a = args.Length;
      Console.WriteLine($"dddd{a:x}ddd");
      lock (args) a = 2;
    }
  }
}
