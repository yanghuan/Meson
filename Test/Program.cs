using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace Test {
  class Program {
    private static void Main(string[] args) {
      Console.WriteLine(args);
      int[] arr = new int[10];
      IList<int> list = arr;
      var en = list.GetEnumerator();
    }
  }
}
