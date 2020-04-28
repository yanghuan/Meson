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