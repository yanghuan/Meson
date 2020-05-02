using CommandLine;
using System;

namespace Meson.Compiler {
  class Options {
    [Option('o', "outcppdir", Required = true, HelpText = "The directory where generated C++ code is written.")]
    public string OutCppDir { get; set; }
  }

  class Program {
    static void Main(string[] args) {
      Parser.Default.ParseArguments<Options>(args).WithParsed(Run);
    }

    private static void Run(Options opts) {
      string path = typeof(String).Assembly.Location;
      new AssemblyTransform(path).Generate(opts.OutCppDir);
    }
  }
}
