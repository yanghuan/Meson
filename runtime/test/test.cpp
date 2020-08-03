#include "test.h"
#include "runtime.h"

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

//using namespace System::Private::CoreLib::System;

struct B {

};

template <class T>
struct Op {

};

struct A : public B, public Op<A> {
    int a;
};

int main() {
    std::cout << sizeof(A);
    return 0;
}


