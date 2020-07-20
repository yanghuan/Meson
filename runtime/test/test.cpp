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
    std::cout << a.get() << std::endl;
    return 0;
}


