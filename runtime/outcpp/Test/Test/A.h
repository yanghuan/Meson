#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ANamespace {
using namespace ::System::Private::CoreLib::System;
class A {
  public: template <class T>
  static void Print(T a);
  private: static void Print(Int32 a);
};
} // namespace ANamespace
using A = ANamespace::A;
} // namespace Test::Test
