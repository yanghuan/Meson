using System;

namespace Meson.Compiler {
  class Program {
    static void Main(string[] args) {
      Console.WriteLine("Hello World!");
      lock (args) {

      }

      {
        lock(args);

      }
    }
  }
}
