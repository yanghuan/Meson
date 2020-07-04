#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int64)
FORWARD(String)
FORWARD(IFormatProvider)
namespace IntPtrNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct IntPtr {
  public: static Int32 get_Size();
  public: static IntPtr get_MaxValue();
  public: static IntPtr get_MinValue();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Int32 ToInt32();
  public: Int64 ToInt64();
  public: static IntPtr Add(IntPtr pointer, Int32 offset);
  public: static IntPtr Subtract(IntPtr pointer, Int32 offset);
  public: void* ToPointer();
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(IntPtr value);
  public: Boolean Equals(IntPtr other);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: static IntPtr Parse(String s);
  public: static IntPtr Parse(String s, NumberStyles style);
  public: static IntPtr Parse(String s, IFormatProvider provider);
  public: static IntPtr Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Boolean TryParse(String s, IntPtr& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, IntPtr& result);
  private: void* _value;
  public: static IntPtr Zero;
};
} // namespace IntPtrNamespace
using IntPtr = IntPtrNamespace::IntPtr;
} // namespace System::Private::CoreLib::System
