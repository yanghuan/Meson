#include <System.Private.CoreLib/System/Array.h>
#include <System.Private.CoreLib/System/String.h>

using namespace System;

int main()
{
  array<String> arr = *(array<String>*)&newarr<String>(10);
  arr[0] = "dddd";
  return 0;
}
