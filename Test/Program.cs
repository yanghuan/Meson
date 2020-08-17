using System;
using System.Runtime.InteropServices;

namespace Test {
  class Program {
    private static void Print(params object[] args) {

    }


    private static void Main(string[] args) {
      Console.WriteLine(args);
      Print(args, args);
    }
  }
}
