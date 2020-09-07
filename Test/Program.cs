using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace Test {
  public static class Extensions {
    public static string To(this string s) {
      return s;
    }
  }
  
  class Program {


    private static void Main(string[] args) {
      Console.WriteLine(args);
      args[0].To();
    }
  }
}
