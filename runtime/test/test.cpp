#include "test.h"
#include "runtime.h"
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>


#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

using namespace System::Private::CoreLib::System;

class No_Complete;

void testIsArray() {
  using TArray = ArrayNamespace::Array___<String>;
  constexpr auto code = TArray::code;
  constexpr bool ttt = std::is_same<bool, decltype(TArray::code == rt::TypeCode::Array)>::value;
  constexpr bool bbb = rt::IsArray<rt::Array<String, rt::string>>;
  constexpr bool cc = rt::IsArray<TArray>;
  constexpr bool ee = rt::IsArray<Array<int>::in>;
  constexpr bool ff = rt::IsArray<String::in>;
  constexpr bool gg = rt::IsComplete<No_Complete>::value;
  constexpr bool hh = rt::IsComplete<int>::value;
  std::printf("code:%d, tt:%d, bb:%d, cc:%d, ee:%d ff:%d \n", code, ttt, bbb, cc, ee, ff);
}

int main() {
  double d = 10;
  int vv = d;
  return 0;
}


