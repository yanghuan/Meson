using System;
using System.Runtime.InteropServices;

namespace Test {
  public class A {
    public void F(double a) {
    }

    private void F(int a) {
    }

    public static int operator == (A a, A b) {
      return 2;
    }

    public static int operator !=(A a, A b) {
      return 2;
    }
  }

  class Program {
    static void f() {

    }

    private static void Main(string[] args) {
      f();
      Console.WriteLine(args);
      int a = 10;
      A aa = new A();
      aa.F(a);
    }
  }
}
