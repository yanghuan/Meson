#include <Array>
#include <atomic>
#include <iostream>
#include <type_traits>
#include <tuple>
#include <initializer_list>
#include <memory>
#include <cstdint>
#include <cstdio>

#include "../rt/GCObject.h"

namespace detail {

  class String : public meson::String {
    INSERT_METADATA_OBJ
  };

  meson::TypeMetadata String::typeMetadata_{};

  class Object : public meson::Object {
    INSERT_METADATA_OBJ
  };

  meson::TypeMetadata Object::typeMetadata_{};

  class ArrayOfBase {};

  template <class T>
  class Array : public meson::Array<T>, public ArrayOfBase {
  };

  class A {
    INSERT_METADATA_OBJ
  public:
    A() {};
    A(int a, int b) : a_(a + b) { };

  public:
    int a_;
    int b_;
  };

  meson::TypeMetadata A::typeMetadata_{};

  class AA : public A {};
}  // namespace detail

using String = meson::ref<detail::String>;
using Object = meson::ref<detail::Object>;
using A = meson::ref<detail::A>;
using AA = meson::ref<detail::AA>;

template <class T>
using Array = meson::ref<meson::Array<T>>;

void f() {
  String a = "ttt";
  Object i = a;
  A a1;
  AA a2;

  Object c2 = a1;
  A a3 = a2;
  a3 = a2;

  bool i1 = a3 == a2;
  bool i4 = a2 == a3;
  bool i5 = a == i;
  //bool i6 = a == a3;

  a = "cccc";
  a = nullptr;
  a = "ttt";
  //ARef t = "dddd";
  //t = t + t;

  if (a == nullptr) {
    std::cout << "is null\n";
  }

  if (a != nullptr) {
    std::cout << "not null\n";
  }

  detail::String* x1 = a.get();
  detail::String* x2 = a.get();
  auto t = std::make_tuple(x1, x2);
  const auto& t1 = t;

  using T = decltype(std::get<0>(t1));
  using T1 = typename std::remove_reference<T>::type;
  using T2 = typename std::remove_const<T1>::type;
  using T3 = typename std::remove_pointer<T2>::type;

  const auto& ax1 = x1;
  auto tt = std::tuple_cat(std::make_tuple(x1, x2), std::make_tuple(x1));
  //using T4 = decltype(tt);

  auto c = a + "ddd";
  auto cc = a + a + "ddd";
  String dd = String() + cc + a + a + "dddd";
  std::cout << dd->c_str() << std::endl;
}

int main() {
  f();

  Array<String> a = newarr<String>(10);
  a[0] = "dddd";
  a[1] = "ccccc";
  a[2] = a[0] + a[1];

  std::cout << a[0]->c_str() << " " << a[1]->c_str() << " " << a[2]->c_str() << std::endl;
}