using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  struct A<T> {
    public class B {

    }
  }


  class Program {
    private A<int>.B a;

    private static void Main(string[] args) {
      Console.WriteLine(args);
    }
  }
}
