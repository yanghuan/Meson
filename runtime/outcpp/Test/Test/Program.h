#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ProgramNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(Program) : public object {
  private: CLASS(__c__DisplayClass1_0) : public object {
    public: void ctor();
    public: void _f2_b__0();
    public: void _f2_b__1();
    public: Int32 a;
  };
  private: static void f2();
  private: static void f2(Int32 a);
  public: static void Main(Array<String> args);
  public: void ctor();
};
} // namespace ProgramNamespace
using Program = ProgramNamespace::Program;
} // namespace Test::Test
