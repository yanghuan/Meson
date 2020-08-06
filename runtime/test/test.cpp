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
  constexpr auto code = Array<String>::in::code;
  constexpr bool ttt = rt::IsArray<Array<String>::in>;
  constexpr bool bbb = rt::IsArray<rt::Array<int, rt::string>>;

  std::cout << "code:" << (int)code << " " << ttt << ":" << bbb << std::endl;

  //Array<String> s = nullptr;
  //auto i = s->aaaa;

  Int32 a = 10;
  std::cout << sizeof(a);

  //String s = "ddd";
  //s = s + "aaa";

  //std::cout << ((char*)s.get() + 4);
  //Array<String> arr = nullptr;
  //Array<Object> bb = arr;
  return 0;
}


