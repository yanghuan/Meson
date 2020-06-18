using System;

namespace Test {
  class Program {
    static void Main(string[] args) {
      Console.WriteLine("Hello World! {0}", args);
      int[] aa = new int[] { 1, 2, 3, 4 };
      object[] bb = aa;
    }
  }
}
