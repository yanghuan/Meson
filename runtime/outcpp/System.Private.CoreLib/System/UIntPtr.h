#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles : int32_t;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(IComparable)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARD(Object)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace UIntPtrNamespace {
using namespace System::Globalization;
using namespace System::Runtime::Serialization;
struct UIntPtr : public valueType<UIntPtr, rt::TypeCode::UIntPtr> {
  public: using interface = rt::TypeList<IEquatable<UIntPtr>, IComparable<>, IComparable<UIntPtr>, IFormattable, ISerializable>;
  public: static Int32 get_Size();
  public: static UIntPtr get_MaxValue();
  public: static UIntPtr get_MinValue();
  public: explicit UIntPtr(UInt32 value);
  public: explicit UIntPtr(UInt64 value);
  public: explicit UIntPtr(void* value);
  private: explicit UIntPtr(SerializationInfo info, StreamingContext context);
  private: void GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: UInt32 ToUInt32();
  public: UInt64 ToUInt64();
  public: static UIntPtr op_Explicit(UInt32 value);
  public: static UIntPtr op_Explicit(UInt64 value);
  public: static UIntPtr op_Explicit(void* value);
  public: static void* op_Explicit(UIntPtr value, void*);
  public: static UInt32 op_Explicit(UIntPtr value, UInt32);
  public: static UInt64 op_Explicit(UIntPtr value, UInt64);
  public: static Boolean op_Equality(UIntPtr value1, UIntPtr value2);
  public: static Boolean op_Inequality(UIntPtr value1, UIntPtr value2);
  public: static UIntPtr Add(UIntPtr pointer, Int32 offset);
  public: static UIntPtr op_Addition(UIntPtr pointer, Int32 offset);
  public: static UIntPtr Subtract(UIntPtr pointer, Int32 offset);
  public: static UIntPtr op_Subtraction(UIntPtr pointer, Int32 offset);
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
  public: explicit UIntPtr() {}
  private: void* _value;
  public: static UIntPtr Zero;
  public: explicit UIntPtr(Int32 value) noexcept : _value((void*)value) {}
  public: explicit UIntPtr(uintptr_t value) noexcept : _value((void*)value) {}
  public: uintptr_t& get() noexcept { return *reinterpret_cast<uintptr_t*>(_value); }
  public: uintptr_t get() const noexcept { return *reinterpret_cast<uintptr_t*>(_value); }
};
} // namespace UIntPtrNamespace
using UIntPtr = UIntPtrNamespace::UIntPtr;
} // namespace System::Private::CoreLib::System
