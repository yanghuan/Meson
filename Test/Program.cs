using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  class Program {
    private static void Main(string[] args) {
      Console.WriteLine(args);
      uint aa = 20;
      nuint byteOffset = aa;
      Test(aa);
    }

    private static void Test(nuint aa) {

    }
  }
}
