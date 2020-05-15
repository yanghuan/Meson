// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"
#include <rt/GCobject.h>

CLASS(String) : public meson::String{

};

#if 1
CLASS(A) {

};

CLASS_(AA, T0, T1) {

};
#endif

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





int main()
{
  C c;
  C<int> d;
  C<int, int> e;
  C<int, int, int> f;

  String a = "Hello CMake.";
  std::cout << a->c_str() << std::endl;


  return 0;
}
