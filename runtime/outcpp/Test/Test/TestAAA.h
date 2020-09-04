#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace Test::Test {
namespace TestAAANamespace {
using namespace ::System::Private::CoreLib::System;
struct TestAAA : public valueType<TestAAA> {
  public: void f();
};
} // namespace TestAAANamespace
using TestAAA = TestAAANamespace::TestAAA;
} // namespace Test::Test
