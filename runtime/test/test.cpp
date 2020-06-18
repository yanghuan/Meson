#include "test.h"
#include "runtime.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

using namespace System::Private::CoreLib::System;

void f(Array<Object> arr) {
  //constexpr bool value1 = Array<Obj>::IsArrayConvertible<Array<Obj>::in>::value;
  //static_assert(value1);

  constexpr bool value2 = Array<Object>::IsArrayConvertible<Array<Object>::in>::value;
  //constexpr bool value2 = rt::IsDerived<rt::Array_, Array<Object>::in>::value;
  static_assert(value2);

  //arr->GetValue(Int32());
}

/*
void f(Object o) {
}*/


int main() {
  Array<String> arr = nullptr;
  Array<Object> tt = arr;
  //f(arr);
  using T = rt::ArrayElementType<Array<Object>::in>::type;
  using T1 = rt::ArrayElementType<Array<String>::in>::type;
  using T2 = rt::ArrayElementType<Array<int>::in>::type;
  constexpr bool value1 = rt::IsConvertible<T, T1>::value;
  constexpr bool value = Array<Object>::IsArrayConvertible<Array<String>>::value;
  constexpr bool value2 = rt::IsDerived<rt::Array_, Array<Object>::in>::value;
  constexpr bool value3 = Array<Object>::IsArrayConvertible<int>::value;
  return 0;
}


