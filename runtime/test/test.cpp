#include "test.h"
#include "runtime.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

using namespace System::Private::CoreLib::System;

int main() {
    Int32 a = 1;
    ++a;
    ++a;
    Int32 b = 2;
    a = a + b;
    std::cout << a << std::endl;
    return 0;
}


