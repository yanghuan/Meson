#include "test.h"
#include "runtime.h"
#include <System.Private.CoreLib/System/Int32-dep.h>

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

using namespace System::Private::CoreLib::System;

int main() {
  Int32 a = 10;
  float b = 20.03232;
  int32_t c = b;
  if (a < b) {

  }
  double d = b;
  int32_t e = d;
  Int32 f = d;
  std::cout << sizeof(a);
  return 0;
}


