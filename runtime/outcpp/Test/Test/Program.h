#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ProgramNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(Program) {
  public: void Ctor();
  public: void Ctor(Int32 a);
  public: static void Main(Array<String> args);
  private: static void Print(Int32 a);
};
} // namespace ProgramNamespace
using Program = ProgramNamespace::Program;
} // namespace Test::Test
