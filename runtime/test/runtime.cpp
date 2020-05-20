// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"
#include <iostream>

namespace System {
  namespace Diagnostics {
    namespace Tracing {
      class D {
        A a;
      };


    } // namespace Tracing
  } // namespace Diagnostics
} // namespace System

void f() {
}

int main()
{
  f();
  return 0;
}
