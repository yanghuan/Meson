using System;
using System.Runtime.InteropServices;

namespace Test {
  static class A {
    public static void Print<T>(T a) {
    }

    private static void Print(int a) {

    }
  }

  class Program {
    private unsafe static void Main(string[] args) {
      A.Print(2);
    }
  }
}
