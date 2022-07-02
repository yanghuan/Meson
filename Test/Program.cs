using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;

namespace Test {
  interface IA {
  }

  interface IB {
  }

   unsafe class Program {
    static void Main(string[] args) {
      Console.WriteLine("hello,word");

      int aa = char.MaxValue;
      Console.WriteLine($"\\u{aa:x}");

      if (args.Length == 2) {
        goto AAA;
      }

      int cc;
      cc = 0;
      cc.ToString();

    AAA:

      Console.WriteLine($"\\u{aa:x}");
    }
  }
}
