// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"
#include <iostream>

namespace System {

  class A {
    class B {

    };

    friend class C;
  };

  template <class T>
  class C {
    A::B b;
  };

} 

void f() {
}

int main()
{
  f();
  return 0;
}
