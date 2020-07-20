#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ANamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(A) {
  public: Int32 get_aaa();
  protected: void Ctor();
};
} // namespace ANamespace
using A = ANamespace::A;
} // namespace Test::Test
