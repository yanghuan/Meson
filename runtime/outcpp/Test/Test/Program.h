#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ProgramNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(Program) {
  public: static void Main(Array<String> args);
};
} // namespace ProgramNamespace
using Program = ProgramNamespace::Program;
} // namespace Test::Test