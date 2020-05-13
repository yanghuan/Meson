// runtime.cpp: 定义应用程序的入口点。
//

#include "runtime.h"
#include <rt/GCobject.h>

CLASS(String) : public meson::String {

};

#if 1
CLASS(A){

};

CLASS_(AA, T0, T1){

};
#endif

 meson::TypeMetadata meson::TypeMetadataHolder<A>::data = {};





int main()
{
  //AA<int, int> aa = newobj<AA<int, int>>();
  String a = "Hello CMake.";
  A aa = newobj<A>();
  std::cout << a->c_str() << std::endl;
  return 0;
}
