using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Test {
  class Program {
    private static void Main(string[] args) {
      Console.WriteLine(args);
    }

    private void f() {
      Action a = f;
      var p = new Program();
      Action b = p.f;
    }
  }
}
