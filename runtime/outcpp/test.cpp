#include <System.Private.CoreLib/System/Array.h>
#include <System.Private.CoreLib/System/String.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueTuple.h>

using namespace System;


int main()
{
  String a = String("ddddd");
  ValueTuple<int, int, int> t;
  t.Item1 = 2;
  t.Item2 = 3;
  t.Item3 = 3;
  return 0;
}
