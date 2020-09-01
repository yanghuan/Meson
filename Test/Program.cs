using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  class Program {
    private static void Main(string[] args) {
      Console.WriteLine(args);
    }

    private (int, int) GetDefault() {
      return default;
    }

    private string GetDefaultS() {
      return default;
    }

    private int GetDefaultA() {
      return default;
    }
  }
}
