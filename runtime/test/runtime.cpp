// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"
#include <iostream>

using namespace System;

void f() {
	Array<int> arr = newarr<Array<int>>(10);
	arr[0] = 20;
	arr[1] = 21;

	String a = "dddd";
	std::cout << a->c_str() << std::endl;
}

int main()
{
  f();
  return 0;
}
