#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace Test::Test {
namespace TestANamespace {
using namespace ::System::Private::CoreLib::System;
struct TestA : public valueType<TestA> {
  public: void Do();
  public: Int32 a;
  public: Int32 b;
};
} // namespace TestANamespace
using TestA = TestANamespace::TestA;
} // namespace Test::Test
