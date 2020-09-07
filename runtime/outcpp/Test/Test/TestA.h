#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace Test::Test {
namespace TestANamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(TestA) : public object {
  public: void f();
  public: static void f1();
  public: void ctor();
};
} // namespace TestANamespace
using TestA = TestANamespace::TestA;
} // namespace Test::Test
