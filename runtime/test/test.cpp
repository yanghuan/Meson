#include "test.h"
#include "runtime.h"

#include <System.Private.CoreLib/System/Array.h>
#include <System.Private.CoreLib/System/String.h>

using namespace System::Private::CoreLib::System;

void f(Array<Object> arr) {
}

/*
void f(Object o) {
}*/

int main() {
  Array<String> arr = nullptr;
  Array<Object> tt = arr;
  f(arr);
  return 0;
}


