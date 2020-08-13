#include "UIntPtr-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::UIntPtrNamespace {
using namespace Internal::Runtime::CompilerServices;

Int32 UIntPtr::get_Size() {
  return 8;
}

UIntPtr UIntPtr::get_MaxValue() {
  return (UIntPtr)UInt64::MaxValue;
}

UIntPtr UIntPtr::get_MinValue() {
  return (UIntPtr)0;
}

UIntPtr::UIntPtr(UInt32 value) {
  _value = (void*)value;
}

UIntPtr::UIntPtr(UInt64 value) {
  _value = (void*)value;
}

UIntPtr::UIntPtr(void* value) {
  _value = value;
}

UIntPtr::UIntPtr(SerializationInfo info, StreamingContext context) {
  UInt64 uInt = info->GetUInt64("value");
  if (get_Size() == 4) {
  }
  _value = (void*)uInt;
}

Boolean UIntPtr::Equals(Object obj) {
  if (rt::is<UIntPtr>(obj)) {
    return _value == ((UIntPtr)obj)._value;
  }
  return false;
}

Int32 UIntPtr::GetHashCode() {
  UInt64 num = (UInt64)_value;
}

UInt32 UIntPtr::ToUInt32() {
  return (UInt32)_value;
}

UInt64 UIntPtr::ToUInt64() {
  return (UInt64)_value;
}

UIntPtr UIntPtr::op_Explicit(UInt32 value) {
  return UIntPtr(value);
}

UIntPtr UIntPtr::op_Explicit(UInt64 value) {
  return UIntPtr(value);
}

UIntPtr UIntPtr::op_Explicit(void* value) {
  return UIntPtr(value);
}

void* UIntPtr::op_Explicit(UIntPtr value, void*) {
  return value._value;
}

UInt32 UIntPtr::op_Explicit(UIntPtr value, UInt32) {
  return (UInt32)value._value;
}

UInt64 UIntPtr::op_Explicit(UIntPtr value, UInt64) {
  return (UInt64)value._value;
}

Boolean UIntPtr::op_Equality(UIntPtr value1, UIntPtr value2) {
  return value1._value == value2._value;
}

Boolean UIntPtr::op_Inequality(UIntPtr value1, UIntPtr value2) {
  return value1._value != value2._value;
}

UIntPtr UIntPtr::Add(UIntPtr pointer, Int32 offset) {
  return pointer + offset;
}

UIntPtr UIntPtr::op_Addition(UIntPtr pointer, Int32 offset) {
  return UIntPtr((unsigned int)((int)(unsigned int)(UIntPtr)pointer._value + offset));
}

UIntPtr UIntPtr::Subtract(UIntPtr pointer, Int32 offset) {
  return pointer - offset;
}

UIntPtr UIntPtr::op_Subtraction(UIntPtr pointer, Int32 offset) {
  return UIntPtr((unsigned int)((int)(unsigned int)(UIntPtr)pointer._value - offset));
}

void* UIntPtr::ToPointer() {
  return _value;
}

Int32 UIntPtr::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<UIntPtr>(value)) {
    UIntPtr uIntPtr = (UIntPtr)value;
    if ((unsigned int)(UIntPtr)_value < (unsigned int)uIntPtr) {
      return -1;
    }
    if ((unsigned int)(UIntPtr)_value > (unsigned int)uIntPtr) {
      return 1;
    }
    return 0;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeUIntPtr());
}

Int32 UIntPtr::CompareTo(UIntPtr value) {
  return ((UInt64)_value).CompareTo((UInt64)value);
}

Boolean UIntPtr::Equals(UIntPtr other) {
  return (UIntPtr)_value == other;
}

String UIntPtr::ToString() {
  return ((UInt64)_value).ToString();
}

String UIntPtr::ToString(String format) {
  return ((UInt64)_value).ToString(format);
}

String UIntPtr::ToString(IFormatProvider provider) {
  return ((UInt64)_value).ToString(provider);
}

String UIntPtr::ToString(String format, IFormatProvider provider) {
  return ((UInt64)_value).ToString(format, provider);
}

UIntPtr UIntPtr::Parse(String s) {
  return (UIntPtr)UInt64::Parse(s);
}

UIntPtr UIntPtr::Parse(String s, NumberStyles style) {
  return (UIntPtr)UInt64::Parse(s, style);
}

UIntPtr UIntPtr::Parse(String s, IFormatProvider provider) {
  return (UIntPtr)UInt64::Parse(s, provider);
}

UIntPtr UIntPtr::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return (UIntPtr)UInt64::Parse(s, style, provider);
}

Boolean UIntPtr::TryParse(String s, UIntPtr& result) {
  Unsafe::SkipInit(result);
  return UInt64::TryParse(s, Unsafe::As<UIntPtr, UInt64>(result));
}

Boolean UIntPtr::TryParse(String s, NumberStyles style, IFormatProvider provider, UIntPtr& result) {
  Unsafe::SkipInit(result);
  return UInt64::TryParse(s, style, provider, Unsafe::As<UIntPtr, UInt64>(result));
}

} // namespace System::Private::CoreLib::System::UIntPtrNamespace
