#include "test.h"
#include "runtime.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

using namespace System::Private::CoreLib::System;

template <class T>
void f() {

}

int main() {
    struct A {
        void f() {

        }
    };

    std::cout << sizeof(A);
    return 0;
}


