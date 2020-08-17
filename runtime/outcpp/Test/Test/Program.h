#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <Test/Test/TestEnum.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ProgramNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(Program) : public Object::in {
  public: static void f(TestEnum E = (TestEnum)21);
  private: template <class T>
  static void Write(T& a, T b);
  public: static void Main(Array<String> args);
  public: void ctor();
};
} // namespace ProgramNamespace
using Program = ProgramNamespace::Program;
} // namespace Test::Test
