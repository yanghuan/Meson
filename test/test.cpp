#include <Array>
#include <atomic>
#include <iostream>
#include <type_traits>

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

  auto c = a + a;
  c = c + "ddd";
  //c += "dddd";
  std::cout << a->c_str() << std::endl;
}

int main() {
  f();

  //{

  //}

  std::cout << sizeof(intptr_t) << std::endl;
  std::cout << sizeof(meson::GCObjectHead) << std::endl;
  std::cout << sizeof(meson::GCObject<detail::String>) << std::endl;
  std::cout << sizeof(meson::GCObject<detail::A>) << std::endl;
}