using System;
using System.Runtime.InteropServices;

namespace Test {
  abstract class A {
    public abstract int aaa { get; }
  }

  class Program {
    public Program() {
    }

    public Program(int a) {
    }

    private unsafe static void Main(string[] args) {
      float a = float.NaN;
      float b = float.PositiveInfinity;
      float c = float.NegativeInfinity;

      int a1 = *(int*)&a;
      int b1 = *(int*)&b;
      int c1 = *(int*)&c;

      Print(a1);
      Print(b1);
      Print(c1);
      DateTime t = default;
      t.AddDays(2).ToString();
    }

    private static void Print(int a) {
      Console.WriteLine("{0} {1}", a, Convert.ToString(a, 2));
    }
  }
}
