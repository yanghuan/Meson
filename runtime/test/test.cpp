#include "test.h"
#include "runtime.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

using namespace System::Private::CoreLib::System;

class Complex
{
    double real, imag;
public:
    Complex(double r = 0, double i = 0) :real(r), imag(i) {};
    operator double() { return real; }  //重载强制类型转换运算符 double
};

int main() {
    Complex c(1.2, 3.4);
    double a = c;


  return 0;
}


