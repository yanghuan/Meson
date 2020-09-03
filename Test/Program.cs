using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  struct TestA {
    public int a;
    public int b;

    public void Do() {
      a = 10;
      b = 20;
    }
  }

  class Program {
    private static void Main(string[] args) {
      Console.WriteLine(args);
      TestA[] arr = new TestA[] { default, default };
      foreach (TestA a in arr) {
        a.Do();
      }
    }
  }
}
