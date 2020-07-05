#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace UIntPtrNamespace {
using namespace Globalization;
struct UIntPtr {
  public: static Int32 get_Size();
  public: static UIntPtr get_MaxValue();
  public: static UIntPtr get_MinValue();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: UInt32 ToUInt32();
  public: UInt64 ToUInt64();
  public: static UIntPtr Add(UIntPtr pointer, Int32 offset);
  public: static UIntPtr Subtract(UIntPtr pointer, Int32 offset);
  public: void* ToPointer();
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(UIntPtr value);
  public: Boolean Equals(UIntPtr other);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: static UIntPtr Parse(String s);
  public: static UIntPtr Parse(String s, NumberStyles style);
  public: static UIntPtr Parse(String s, IFormatProvider provider);
  public: static UIntPtr Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Boolean TryParse(String s, UIntPtr& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, UIntPtr& result);
  private: void* _value;
  public: static UIntPtr Zero;
};
} // namespace UIntPtrNamespace
using UIntPtr = UIntPtrNamespace::UIntPtr;
} // namespace System::Private::CoreLib::System
