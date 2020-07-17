#include "test.h"
#include "runtime.h"

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

//using namespace System::Private::CoreLib::System;

int main() {
    float a = std::numeric_limits<float>::quiet_NaN();
    float a1 = std::numeric_limits<float>::signaling_NaN();
    int b = *(int*)&a;    
    int b1 = *(int*)&b;
    printf("%d %d\n", b, b1);    
    float c = rt::NaN<float>;
    printf("%f", c);   

    int ccc = std::isnan(c);
    int ddd = std::isnan(a);
    printf("\n%d %d", ccc, ddd);   
    std::cout << c << std::endl;

    int $aaa = 10;
    std::cout << $aaa;

    return 0;
}


