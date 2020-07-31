#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
namespace Vector256Namespace {
template <class T1 = void, class T2 = void>
class Vector256 {
};
template <>
class Vector256<> : public Object::in {
};
template <class T>
struct Vector256<T> {
  public: static Int32 get_Count();
  public: static Vector256<T> get_Zero();
  public: static Vector256<T> get_AllBitsSet();
  public: String get_DisplayString();
  public: static Boolean get_IsSupported();
  private: UInt64 _00;
  private: UInt64 _01;
  private: UInt64 _02;
  private: UInt64 _03;
};
} // namespace Vector256Namespace
template <class T1 = void, class T2 = void>
using Vector256 = Vector256Namespace::Vector256<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
