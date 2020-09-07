#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <Test/Test/A.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ProgramNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(Program) : public object {
  public: static void Main(Array<String> args);
  public: void ctor();
  private: A<Int32>::B a;
};
} // namespace ProgramNamespace
using Program = ProgramNamespace::Program;
} // namespace Test::Test
