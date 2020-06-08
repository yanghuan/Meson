#pragma once
#include <rt/GCObject.h>

namespace A {
  template <class T0, class T1>
  class A__;
  template <class T0 = void, class T1 = void>
  using AP = rt::ref<A__<T0, T1>>;
}