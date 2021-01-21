using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Test {
  public interface IA {
    object Current { get; }
    void f();
  }

  public interface IB : IA {
    new string Current { get; }
    new void f();
  }

  class Program {
    private static void Main(string[] args) {
      Console.WriteLine(args);
    }
  }
}
