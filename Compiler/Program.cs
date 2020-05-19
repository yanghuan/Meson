using CommandLine;
using System;
using System.Collections.Generic;

namespace Meson.Compiler {
  class Options {
    [Option('d', "outcppdir", Required = true, HelpText = "The directory where generated C++ code is written.")]
    public string OutCppDir { get; set; }
  }

  class Program {
    static void Main(string[] args) {
      Parser.Default.ParseArguments<Options>(args).WithParsed(Run);
    }

    private static void Run(Options opts) {
      DoSelfDll(opts);
      DoSystemDll(opts);
    }

    private static void DoSelfDll(Options opts) {
      string path = typeof(Program).Assembly.Location;
      new AssemblyTransform(path).Generate(opts.OutCppDir);
    }

    private static void DoSystemDll(Options opts) {
      string path = typeof(string).Assembly.Location;
      new AssemblyTransform(path).Generate(opts.OutCppDir);
    }
  }
}
