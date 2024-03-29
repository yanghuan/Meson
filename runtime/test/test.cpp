#include "test.h"
#include "runtime.h"

#include <cstdio>
#include <limits>
#include <cmath>
#include <iostream>

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/char.h>
#include <System.Private.CoreLib/System/Array-dep.h>

#if 0
#include <System.Private.CoreLib/System/IFormatProvider.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>


using namespace System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;
using namespace Reflection;
using namespace Text;
using namespace Globalization;

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

void TestInterfaces() {
  using To = IConvertible::in;
  using From = String::in;
  using Interfaces = typename rt::InterfaceOf<From>;
  constexpr size_t size = std::tuple_size_v<Interfaces>;
  constexpr bool b = rt::IsInterfacesContains<Interfaces, To>;
  using Interface = typename std::tuple_element_t<6, Interfaces>;
  static constexpr bool value = std::is_same_v<Interface, To>;
  std::printf("N:%d, N1:%d \n", b, b);
}

void TestAction() {
  constexpr bool aa =  rt::IsRef<IConvertible> && rt::IsInterfaceConvertible<typename rt::RefElementType<IConvertible>::type, Boolean>;
  //Object o = nullptr;
  //Action<> a = { o, &Object::in::GetHashCode };
  Boolean a = false;
  IConvertible ic = a;
  double d = a;
}

void Test() {
  //IFormatProvider aa(CultureInfo::in::get_InvariantCulture());
  //constexpr bool cc =  rt::IsInterfacesContains<CultureInfo::in::interface, IFormatProvider::in>;
  //constexpr bool b1 = rt::CodeOf<IFormatProvider::in> == rt::TypeCode::Interface;
  //constexpr auto b2 = IFormatProvider::in::code;
  constexpr auto b3 = rt::GetTypeCode<IFormatProvider::in>::value;
  constexpr auto b4 = rt::GetTypeCode<Object::in>::value;
  constexpr auto b5 = rt::GetTypeCode<String::in>::value;
  constexpr auto b6 = rt::GetTypeCode<IConvertible::in>::value;
  constexpr bool dd =  rt::IsInterfaceConvertible<IFormatProvider::in, CultureInfo::in>;
}
#endif

using namespace System::Private::CoreLib::System;
using namespace System::Private::CoreLib::System::Collections;




void f(Double a) {

}


int main() {
  Array<Int32>::newarr(10);


  Single a = 200;
  f(a);
  return 0;
}

