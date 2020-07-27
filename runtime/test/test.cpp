#include "test.h"
#include "runtime.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

using namespace System::Private::CoreLib::System;

struct B {
};

struct C {
};

struct A : public B, public C {
    int a;    
};


int main() {
    std::cout << sizeof(A);
    return 0;
}


