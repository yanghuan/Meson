#include "runtime.h"

template <class T0 = void, class T1 = void, class T3 = void, class T4 = void>
struct C {
  C() {
    std::cout << "C" << std::endl;
  }
};

template <>
struct C<> {
  C() {
    std::cout << "C0" << std::endl;
  }
};

template <class T>
struct C<T> {
  C() {
    std::cout << "C1" << std::endl;
  }
};

template <class T, class T1>
struct C<T, T1> {
  C() {
    std::cout << "C2" << std::endl;
  }
};

template <class T, class T1, class T2>
struct C<T, T1, T2> {
  C() {
    std::cout << "C3" << std::endl;
  }
};

template <class T0 = void, class T1 = void, class T3 = void, class T4 = void>
using CCC = C<T0, T1, T3, T4>;


void f() {
  C c;
  C<int> d;
}