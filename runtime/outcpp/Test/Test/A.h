#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace Test::Test {
namespace ANamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(A) : public Object::in {
  private: FRIENDN(B)
  public: void Ctor();
};
CLASS(B) : public A::in {
  public: void Ctor();
};
} // namespace ANamespace
using A = ANamespace::A;
} // namespace Test::Test
