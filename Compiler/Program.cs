using CommandLine;
using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace Meson.Compiler {
  class Options {
    [Option('d', "outcppdir", Required = true, HelpText = "The directory where generated C++ code is written.")]
    public string OutCppDir { get; set; }
    [Option('a', "assembly", Required = true, Separator = ',', HelpText = "One or more paths to assemblies to convert.")]
    public IEnumerable<string> Assemnlys { get; set; }
  }

  class Program {
    static void Main(string[] args) {
      Parser.Default.ParseArguments<Options>(args).WithParsed(Run);
    }

    private static void Run(Options opts) {
      Stopwatch sw = new Stopwatch();
      sw.Start();
      new SyntaxGenerator(opts);
      double seconds = sw.Elapsed.TotalSeconds;
      Console.WriteLine("successful, cost {0}s", seconds);
    }
  }
}
