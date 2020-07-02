#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
namespace Vector128Namespace {
template <class T1 = void, class T2 = void>
class Vector128 {
};
template <>
class Vector128<> {
};
template <class T>
struct Vector128<T> {
  public: static Int32 get_Count();
  public: static Vector128<T> get_Zero();
  public: String get_DisplayString();
  public: static Boolean get_IsSupported();
  private: UInt64 _00;
  private: UInt64 _01;
};
} // namespace Vector128Namespace
template <class T1 = void, class T2 = void>
using Vector128 = Vector128Namespace::Vector128<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
