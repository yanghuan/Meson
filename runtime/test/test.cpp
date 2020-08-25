#include "test.h"
#include "runtime.h"

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>

using namespace System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;

class No_Complete;

void testIsArray() {
  using TArray = ArrayNamespace::Array___<String>;
  constexpr auto code = TArray::code;
  constexpr bool ttt = std::is_same<bool, decltype(TArray::code == rt::TypeCode::Array)>::value;
  constexpr bool bbb = rt::IsArray<rt::Array<String, rt::string>>;
  constexpr bool cc = rt::IsArray<TArray>;
  constexpr bool ee = rt::IsArray<Array<int>::in>;
  constexpr bool ff = rt::IsArray<String::in>;
  constexpr bool gg = rt::IsComplete<No_Complete>::value;
  constexpr bool hh = rt::IsComplete<int>::value;
  std::printf("code:%d, tt:%d, bb:%d, cc:%d, ee:%d ff:%d \n", code, ttt, bbb, cc, ee, ff);
}

void TestObject() {
  Object o = nullptr;
  Int32 i = (Int32)o;
}

void TestTry() {
  try {
    String a = "dddd";
    throw a.get(); 
  } catch (Object::in* o) {
    Object i(o);
    std::printf("get exception\n");
  }
}

enum class Enum {
  A,
  B,
  C,
};

template <class T>
static void F(T a, T t = rt::default__, Enum r = Enum::A | Enum::B) {
}

struct TestDefault
{
  template <class T = int>
  void f(T a = rt::default__, int b = 0);  
};

template <>
void TestDefault::f(int a, int b) {
}


// https://stackoverflow.com/a/28209546/13460873
template <char...> double operator "" _x() {
  return .42;
}

void TestStrDefault(String s, String ss = nullptr) {
  F(1);
  TestDefault a;
  a.f();
}

enum class EnumA {
  A, B, C
};

int main() {
  TestTry();
  constexpr rt::TypeCode a = rt::CodeOf<String::in>;
  std::printf("aaaa-> %d%\n", a);

  return 0;
}


