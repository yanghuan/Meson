#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARD(String)
namespace IntPtrNamespace {
using namespace Globalization;
using namespace Runtime::Serialization;
struct IntPtr : public rt::ValueType<IntPtr> {
  public: static Int32 get_Size();
  public: static IntPtr get_MaxValue();
  public: static IntPtr get_MinValue();
  public: void Ctor(Int32 value);
  public: void Ctor(Int64 value);
  public: void Ctor(void* value);
  private: void Ctor(SerializationInfo info, StreamingContext context);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Int32 ToInt32();
  public: Int64 ToInt64();
  public: static IntPtr op_Explicit(Int32 value);
  public: static IntPtr op_Explicit(Int64 value);
  public: static IntPtr op_Explicit(void* value);
  public: static void* op_Explicit(IntPtr value, void*);
  public: static Int32 op_Explicit(IntPtr value, Int32);
  public: static Int64 op_Explicit(IntPtr value, Int64);
  public: static Boolean op_Equality(IntPtr value1, IntPtr value2);
  public: static Boolean op_Inequality(IntPtr value1, IntPtr value2);
  public: static IntPtr Add(IntPtr pointer, Int32 offset);
  public: static IntPtr op_Addition(IntPtr pointer, Int32 offset);
  public: static IntPtr Subtract(IntPtr pointer, Int32 offset);
  public: static IntPtr op_Subtraction(IntPtr pointer, Int32 offset);
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
  public: void Ctor();
  private: void* _value;
  public: static IntPtr Zero;
};
} // namespace IntPtrNamespace
using IntPtr = IntPtrNamespace::IntPtr;
} // namespace System::Private::CoreLib::System
