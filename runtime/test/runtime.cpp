// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"
#include <System.Private.CoreLib/System/ValueTuple.h>

#include <iostream>

template <class T0 = void, class T1 = void, class T2 = void>
struct Action {
  Action() {
    std::cout << "-1" << std::endl;
  }
};

template <class T0 = void, class T1 = void, class T2 = void>
using Act = Action<T0, T1, T2>;

template <>
struct Action<> {
  Action() {
    std::cout << "0" << std::endl;
  }
};
template <class T>
struct Action<T> {
  Action() {
    std::cout << "1" << std::endl;
  }
};
template <class T1, class T2>
struct Action<T1, T2> {
  Action() {
    std::cout << "2" << std::endl;
  }
};

void f() {
  Act<> a;
  Act<int> aa;
  Act<int, int> aaaa;

}

int main()
{
  f();
  return 0;
}
