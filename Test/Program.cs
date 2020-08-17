using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  class Program {
    private static void Write<T>(ref T a, T b) {

    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      Write(ref args, null);
      Task.FromResult(2);
    }
  }
}
