#include "test.h"
#include "runtime.h"
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

using namespace System::Private::CoreLib::System;

int main() {
  using T = rt::IsArrayConvertible<Array<String>::in, Array<Object>::in>;
  constexpr bool tttt = T::value;

  constexpr int aa = (int)rt::TypeKind<Array<String>>::code;
  std::cout <<  "aa:" << aa << std::endl;

  constexpr int bb = (int)rt::TypeKind<Array<int>>::code;
  std::cout <<  "bb:" << bb << std::endl;

  Int32 a = 10;
  std::cout << sizeof(a);

  String s = "ddd";
  s = s + "aaa";

  std::cout << ((char*)s.get() + 4);
  //Array<String> arr = nullptr;
  //Array<Object> bb = arr;



  return 0;
}


