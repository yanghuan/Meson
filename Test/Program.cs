using System;
using System.Runtime.InteropServices;

namespace Test {
  public class A {
    public void F(double a) {
    }

    private void F(int a) {
    }
  }

  class Program {
    private static void Main(string[] args) {
      Console.WriteLine(args);
      int a = 10;
      A aa = new A();
      aa.F(a);
    }
  }
}
