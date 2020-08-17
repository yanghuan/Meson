using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  enum TestEnum {
    A,
    B = 1,
    C = 2,
    D = 4,
  }

  class Program {
    public static void f(TestEnum E = TestEnum.D | TestEnum.B | (TestEnum)20) {

    }

    private static void Write<T>(ref T a, T b) {

    }

    private static void Main(string[] args) {
      Console.WriteLine(args);
      Write(ref args, null);
      Task.FromResult(2);
    }
  }
}
