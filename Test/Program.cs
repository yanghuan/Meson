using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Test {
  class Program {
    private int A { get; set; }

    private static void Main(string[] args) {
      Console.WriteLine(args);
    }

    private void f() {
      A = 20;

      Action a = f;
      var p = new Program();
      Action b = p.f;
    }
  }
}
