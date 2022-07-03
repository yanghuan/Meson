using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;

namespace Test {
  class A {
    public void p() {
    }
  }

   unsafe class Program {
    static void Main(string[] args) {
      Console.WriteLine(("<hello,word>")[1..^1]);
      A a = null;
      a.p();
    }
  }
}
