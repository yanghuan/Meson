#include "runtime.h"

namespace Test {
    class A {
        class B {
        };
        B f(B b);
    };

    A::B A::f(B bb) {
        B b;
        return b;
    }

}

