using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Test {
  interface IA {
  }

  interface IB {
  }

   unsafe class Program {
    static void Main(string[] args) {
      IDisposable a = args;
    }
  }
}
