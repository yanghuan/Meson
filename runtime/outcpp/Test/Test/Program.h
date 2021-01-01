#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
FORWARDS(TestAAA)
namespace ProgramNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(Program) : public object {
  private: static String f(TestAAA& aa);
  private: static void f(TestAAA* ctx);
  private: static void f(IntPtr a);
  public: static void Main(Array<String> args);
  public: void ctor();
};
} // namespace ProgramNamespace
using Program = ProgramNamespace::Program;
} // namespace Test::Test
