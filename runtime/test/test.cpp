#include "test.h"
#include "runtime.h"
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

using namespace System::Private::CoreLib::System;

int main() {
  Int32 a = 10;
  std::cout << sizeof(a);

  UIntPtr i(nullptr);
  UInt64 ii = (UInt64)i;
  
  a.ToString();
  return 0;
}


