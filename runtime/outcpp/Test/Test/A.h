#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Double)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ANamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(A) : public Object::in {
  public: void F(Double a);
  private: void F(Int32 a);
  public: static Int32 op_Equality(A a, A b);
  public: static Int32 op_Inequality(A a, A b);
  public: void ctor();
};
} // namespace ANamespace
using A = ANamespace::A;
} // namespace Test::Test
