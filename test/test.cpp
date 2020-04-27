#include <Array>
#include <atomic>
#include <iostream>
#include <type_traits>
#include <tuple>
#include <initializer_list>

#include "../rt/GCObject.h"

namespace detail {

class String : public meson::String {};

class A {};
}  // namespace detail

using String = meson::ref<detail::String>;
using ARef = meson::ref<detail::A>;

void f() {
  String a = "ttt";
  a = "cccc";
  a = nullptr;
  a = "ttt";
  //ARef t = "dddd";
  //t = t + t;

  if (a == nullptr) {
    std::cout << "is null";
  }

  if (a != nullptr) {
    std::cout << "not null";
  }

  const String& k = "ddd";

  auto t = std::tie(k, k, k);
  using TT = typename std::tuple_element<0, decltype(t)>::type;
  using T = decltype(std::get<0>(t));
  using T1 = typename std::remove_reference<T>::type;
  using T2 = typename std::remove_const<T1>::type;
  static_assert(T2::kIsString);

  String c = a + a + a + "ddd" + a;
  std::cout << c->c_str() << std::endl;
}

int main() {
  f();

  //{

  //}

  std::cout << sizeof(intptr_t) << std::endl;
  std::cout << sizeof(meson::GCObjectHead) << std::endl;
  std::cout << sizeof(meson::GCObject<detail::String>) << std::endl;
  std::cout << sizeof(meson::GCObject<detail::A>) << std::endl;

  auto a = std::make_tuple(10);
  int tt = 10;
  const int& ttt = tt;
  auto aaaa = std::tie(tt);
  auto e = std::tie(ttt);
}