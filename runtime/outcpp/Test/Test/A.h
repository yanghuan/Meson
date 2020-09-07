#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace Test::Test {
namespace ANamespace {
using namespace ::System::Private::CoreLib::System;
template <class T>
struct A : public valueType<A<T>> {
  public: CLASS(B) : public object {
    public: void ctor();
  };
};
} // namespace ANamespace
template <class T>
using A = ANamespace::A<T>;
} // namespace Test::Test
