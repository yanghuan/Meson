#include <System.Private.CoreLib/System/Array.h>
#include <System.Private.CoreLib/System/String.h>
#include <System.Private.CoreLib/System/Object.h>

CLASS(AAA) {

};

CLASS(AA, T1, T2) {

};

using namespace System;


int main()
{
  String a = String("ddddd");
  array<String> arr = newarr<array<String>>(10);
  arr[0] = "ddd";
  return 0;
}
