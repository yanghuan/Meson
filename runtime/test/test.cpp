#include "test.h"
#include "runtime.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

using namespace System::Private::CoreLib::System;

void f(Array<Object> arr) {
  //constexpr bool value1 = Array<Obj>::IsArrayConvertible<Array<Obj>::in>::value;
  //static_assert(value1);

  constexpr bool value2 = rt::IsArrayConvertible<Array<Object>::in, Array<Object>::in>::value;
  //constexpr bool value2 = rt::IsDerived<rt::Array_, Array<Object>::in>::value;
  static_assert(value2);

  //arr->GetValue(Int32());
  Array<String> b = nullptr;
  Array<Object> c = b;
}

#if true
void f(Array<> o) {
}
#endif

#if false
void f(Object o) {
}
#endif

int main() {
  Array<String> arr = newarr<Array<String>>(10);
  arr[0] = "ddd";
  arr[1] = "dddd";
  int a = int();
  //Array<Object> tt = arr;
  //f(arr);

  return 0;
}


