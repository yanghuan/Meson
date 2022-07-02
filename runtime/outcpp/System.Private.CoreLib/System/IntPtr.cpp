#include "IntPtr-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::IntPtrNamespace {
using namespace Internal::Runtime::CompilerServices;

Int32 IntPtr::get_Size() {
  return 8;
}

IntPtr IntPtr::get_MaxValue() {
  return (IntPtr)Int64::MaxValue();
}

IntPtr IntPtr::get_MinValue() {
  return (IntPtr)Int64::MinValue();
}

IntPtr::IntPtr(Int32 value) {
  _value = (void*)value;
}

IntPtr::IntPtr(Int64 value) {
  _value = (void*)value;
}

IntPtr::IntPtr(void* value) {
  _value = value;
}

IntPtr::IntPtr(SerializationInfo info, StreamingContext context) {
  Int64 int一 = info->GetInt64("value");
  if (get_Size() == 4) {
  }
  _value = (void*)int一;
}

void IntPtr::GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  info->AddValue("value", ToInt64());
}

Boolean IntPtr::Equals(Object obj) {
  if (rt::is<IntPtr>(obj)) {
    IntPtr intPtr = (IntPtr)obj;
    return _value == intPtr._value;
  }
  return false;
}

Int32 IntPtr::GetHashCode() {
  Int64 num = (Int64)_value;
  return (Int32)num ^ (Int32)(num >> 32);
}

Int32 IntPtr::ToInt32() {
  Int64 num = (Int64)_value;
  return (Int32)num;
}

Int64 IntPtr::ToInt64() {
  return (Int64)(IntPtr)_value;
}

IntPtr IntPtr::op_Explicit(Int32 value) {
  return IntPtr(value);
}

IntPtr IntPtr::op_Explicit(Int64 value) {
  return IntPtr(value);
}

IntPtr IntPtr::op_Explicit(void* value) {
  return IntPtr(value);
}

void* IntPtr::op_Explicit(IntPtr value, void*) {
  return value._value;
}

Int32 IntPtr::op_Explicit(IntPtr value, Int32) {
  Int64 num = (Int64)value._value;
  return (Int32)num;
}

Int64 IntPtr::op_Explicit(IntPtr value, Int64) {
  return (Int64)(IntPtr)value._value;
}

Boolean IntPtr::op_Equality(IntPtr value1, IntPtr value2) {
  return value1._value == value2._value;
}

Boolean IntPtr::op_Inequality(IntPtr value1, IntPtr value2) {
  return value1._value != value2._value;
}

IntPtr IntPtr::Add(IntPtr pointer, Int32 offset) {
  return pointer + offset;
}

IntPtr IntPtr::op_Addition(IntPtr pointer, Int32 offset) {
  return (IntPtr)((Byte*)pointer._value + offset);
}

IntPtr IntPtr::Subtract(IntPtr pointer, Int32 offset) {
  return pointer - offset;
}

IntPtr IntPtr::op_Subtraction(IntPtr pointer, Int32 offset) {
  return (IntPtr)((Byte*)pointer._value - offset);
}

void* IntPtr::ToPointer() {
  return _value;
}

Int32 IntPtr::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<IntPtr>(value)) {
    IntPtr intPtr = (IntPtr)value;
    if ((Int64)_value < (Int64)intPtr) {
      return -1;
    }
    if ((Int64)_value > (Int64)intPtr) {
      return 1;
    }
    return 0;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeIntPtr());
}

Int32 IntPtr::CompareTo(IntPtr value) {
  return ((Int64)_value).CompareTo((Int64)value);
}

Boolean IntPtr::Equals(IntPtr other) {
  return (Int64)_value == (Int64)other;
}

String IntPtr::ToString() {
  return ((Int64)_value).ToString();
}

String IntPtr::ToString(String format) {
  return ((Int64)_value).ToString(format);
}

String IntPtr::ToString(IFormatProvider provider) {
  return ((Int64)_value).ToString(provider);
}

String IntPtr::ToString(String format, IFormatProvider provider) {
  return ((Int64)_value).ToString(format, provider);
}

IntPtr IntPtr::Parse(String s) {
  return (IntPtr)Int64::Parse(s);
}

IntPtr IntPtr::Parse(String s, NumberStyles style) {
  return (IntPtr)Int64::Parse(s, style);
}

IntPtr IntPtr::Parse(String s, IFormatProvider provider) {
  return (IntPtr)Int64::Parse(s, provider);
}

IntPtr IntPtr::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return (IntPtr)Int64::Parse(s, style, provider);
}

Boolean IntPtr::TryParse(String s, IntPtr& result) {
  Unsafe::SkipInit<IntPtr>(result);
  return Int64::TryParse(s, Unsafe::As<IntPtr, Int64>(result));
}

Boolean IntPtr::TryParse(String s, NumberStyles style, IFormatProvider provider, IntPtr& result) {
  Unsafe::SkipInit<IntPtr>(result);
  return Int64::TryParse(s, style, provider, Unsafe::As<IntPtr, Int64>(result));
}

} // namespace System::Private::CoreLib::System::IntPtrNamespace
