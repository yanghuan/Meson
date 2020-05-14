#include <System.Private.CoreLib/System/Array.h>
#include <System.Private.CoreLib/System/String.h>
#include <System.Private.CoreLib/System/Object.h>

CLASS(AAA) {

};


using namespace System;


int main()
{
  String a = String("ddddd");
  array<String> arr = newarr<array<String>>(10);
  arr[0] = "ddd";
  return 0;
}
