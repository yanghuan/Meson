// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"
#include <rt/GCobject.h>


class __String__ : public meson::String {

};

using String = meson::ref<__String__>;


CLASS(aa) {

};

CLASS_(AA, A, B) {

};


int main()
{
	AA<int, int> aa = nullptr;
	String a = "Hello CMake.";
	std::cout << a->c_str() << BOOST_PP_VARIADIC_SIZE(AA, (K, V)) << std::endl;
	return 0;
}
