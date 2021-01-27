using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Test {
   unsafe class Program {
    static void Main(string[] args) {
      string s = args[0];
      fixed (char* p = s) {

      }
    }
  }
}
