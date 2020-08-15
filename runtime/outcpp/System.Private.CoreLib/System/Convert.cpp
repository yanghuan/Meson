#include "Convert-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/IConvertible.h>
#include <System.Private.CoreLib/System/IFormattable.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/ParseNumbers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::ConvertNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;

ReadOnlySpan<SByte> Convert::get_DecodingMap() {
  return rt::newarr<Array<SByte>>(256);
}

Boolean Convert::TryDecodeFromUtf16(ReadOnlySpan<Char> utf16, Span<Byte> bytes, Int32& consumed, Int32& written) {
  Char& reference = MemoryMarshal::GetReference(utf16);
  Byte& reference2 = MemoryMarshal::GetReference(bytes);
  Int32 num = utf16.get_Length() & -4;
  Int32 length = bytes.get_Length();
  Int32 num2 = 0;
  Int32 num3 = 0;
  if (utf16.get_Length() != 0) {
    SByte& reference3 = MemoryMarshal::GetReference(get_DecodingMap());
    Int32 num4 = (length < (num >> 2) * 3) ? (length / 3 * 4) : (num - 4);
    while (true) {
      if (num2 < num4) {
        Int32 num5 = Decode(Unsafe::Add(reference, num2), reference3);
        if (num5 >= 0) {
          WriteThreeLowOrderBytes(Unsafe::Add(reference2, num3), num5);
          num3 += 3;
          num2 += 4;
          continue;
        }
      } else if (num4 == num - 4 && num2 != num) {
        Int32 num6 = Unsafe::Add(reference, num - 4);
        Int32 num7 = Unsafe::Add(reference, num - 3);
        Int32 num8 = Unsafe::Add(reference, num - 2);
        Int32 num9 = Unsafe::Add(reference, num - 1);
        if (((num6 | num7 | num8 | num9) & 4294967040u) == 0) {
          num6 = Unsafe::Add(reference3, num6);
          num7 = Unsafe::Add(reference3, num7);
          num6 <<= 18;
          num7 <<= 12;
          num6 |= num7;
          if (num9 != 61) {
            num8 = Unsafe::Add(reference3, num8);
            num9 = Unsafe::Add(reference3, num9);
            num8 <<= 6;
            num6 |= num9;
            num6 |= num8;
            if (num6 >= 0 && num3 <= length - 3) {
              WriteThreeLowOrderBytes(Unsafe::Add(reference2, num3), num6);
              num3 += 3;
              goto IL_01e6;
            }
          } else if (num8 != 61) {
            num8 = Unsafe::Add(reference3, num8);
            num8 <<= 6;
            num6 |= num8;
            if (num6 >= 0 && num3 <= length - 2) {
              Unsafe::Add(reference2, num3) = (Byte)(num6 >> 16);
              Unsafe::Add(reference2, num3 + 1) = (Byte)(num6 >> 8);
              num3 += 2;
              goto IL_01e6;
            }
          } else if (num6 >= 0 && num3 <= length - 1) {
            Unsafe::Add(reference2, num3) = (Byte)(num6 >> 16);
            num3++;
            goto IL_01e6;
          }


        }
      }

      goto IL_0200;

    IL_0200:
      consumed = num2;
      written = num3;
      return false;

    IL_01e6:
      num2 += 4;
      if (num == utf16.get_Length()) {
        break;
      }
      goto IL_0200;
    }
  }
  consumed = num2;
  written = num3;
  return true;
}

Int32 Convert::Decode(Char& encodedChars, SByte& decodingMap) {
  Int32 num = encodedChars;
  Int32 num2 = Unsafe::Add(encodedChars, 1);
  Int32 num3 = Unsafe::Add(encodedChars, 2);
  Int32 num4 = Unsafe::Add(encodedChars, 3);
  if (((num | num2 | num3 | num4) & 4294967040u) != 0) {
    return -1;
  }
  num = Unsafe::Add(decodingMap, num);
  num2 = Unsafe::Add(decodingMap, num2);
  num3 = Unsafe::Add(decodingMap, num3);
  num4 = Unsafe::Add(decodingMap, num4);
  num <<= 18;
  num2 <<= 12;
  num3 <<= 6;
  num |= num4;
  num2 |= num3;
  return num | num2;
}

void Convert::WriteThreeLowOrderBytes(Byte& destination, Int32 value) {
  destination = (Byte)(value >> 16);
  Unsafe::Add(destination, 1) = (Byte)(value >> 8);
  Unsafe::Add(destination, 2) = (Byte)value;
}

TypeCode Convert::GetTypeCode(Object value) {
  if (value == nullptr) {
    return TypeCode::Empty;
  }
  auto& default = (rt::as<IConvertible>(value));
  auto& extern = default == nullptr ? nullptr : default->GetTypeCode();
  return extern != nullptr ? extern : TypeCode::Object;
}

Boolean Convert::IsDBNull(Object value) {
  if (value == DBNull::in::Value) {
    return true;
  }
  IConvertible convertible = rt::as<IConvertible>(value);
  if (convertible == nullptr) {
    return false;
  }
  return convertible->GetTypeCode() == TypeCode::DBNull;
}

Object Convert::ChangeType(Object value, TypeCode typeCode) {
  return ChangeType(value, typeCode, CultureInfo::in::get_CurrentCulture());
}

Object Convert::ChangeType(Object value, TypeCode typeCode, IFormatProvider provider) {
  if (value == nullptr && (typeCode == TypeCode::Empty || typeCode == TypeCode::String || typeCode == TypeCode::Object)) {
    return nullptr;
  }
  IConvertible convertible = rt::as<IConvertible>(value);
  if (convertible == nullptr) {
    rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_IConvertible());
  }
  switch (typeCode) {
    case TypeCode::Boolean:
      return convertible->ToBoolean(provider);
    case TypeCode::Char:
      return convertible->ToChar(provider);
    case TypeCode::SByte:
      return convertible->ToSByte(provider);
    case TypeCode::Byte:
      return convertible->ToByte(provider);
    case TypeCode::Int16:
      return convertible->ToInt16(provider);
    case TypeCode::UInt16:
      return convertible->ToUInt16(provider);
    case TypeCode::Int32:
      return convertible->ToInt32(provider);
    case TypeCode::UInt32:
      return convertible->ToUInt32(provider);
    case TypeCode::Int64:
      return convertible->ToInt64(provider);
    case TypeCode::UInt64:
      return convertible->ToUInt64(provider);
    case TypeCode::Single:
      return convertible->ToSingle(provider);
    case TypeCode::Double:
      return convertible->ToDouble(provider);
    case TypeCode::Decimal:
      return convertible->ToDecimal(provider);
    case TypeCode::DateTime:
      return convertible->ToDateTime(provider);
    case TypeCode::String:
      return convertible->ToString(provider);
    case TypeCode::Object:
      return value;
    case TypeCode::DBNull:
      rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_DBNull());
    case TypeCode::Empty:
      rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_Empty());
    default:
      rt::throw_exception<ArgumentException>(SR::get_Arg_UnknownTypeCode());
  }
}

Object Convert::DefaultToType(IConvertible value, Type targetType, IFormatProvider provider) {
  if (targetType == nullptr) {
    rt::throw_exception<ArgumentNullException>("targetType");
  }
  if ((Object)value->GetType() == targetType) {
    return value;
  }
  if ((Object)targetType == ConvertTypes[3]) {
    return value->ToBoolean(provider);
  }
  if ((Object)targetType == ConvertTypes[4]) {
    return value->ToChar(provider);
  }
  if ((Object)targetType == ConvertTypes[5]) {
    return value->ToSByte(provider);
  }
  if ((Object)targetType == ConvertTypes[6]) {
    return value->ToByte(provider);
  }
  if ((Object)targetType == ConvertTypes[7]) {
    return value->ToInt16(provider);
  }
  if ((Object)targetType == ConvertTypes[8]) {
    return value->ToUInt16(provider);
  }
  if ((Object)targetType == ConvertTypes[9]) {
    return value->ToInt32(provider);
  }
  if ((Object)targetType == ConvertTypes[10]) {
    return value->ToUInt32(provider);
  }
  if ((Object)targetType == ConvertTypes[11]) {
    return value->ToInt64(provider);
  }
  if ((Object)targetType == ConvertTypes[12]) {
    return value->ToUInt64(provider);
  }
  if ((Object)targetType == ConvertTypes[13]) {
    return value->ToSingle(provider);
  }
  if ((Object)targetType == ConvertTypes[14]) {
    return value->ToDouble(provider);
  }
  if ((Object)targetType == ConvertTypes[15]) {
    return value->ToDecimal(provider);
  }
  if ((Object)targetType == ConvertTypes[16]) {
    return value->ToDateTime(provider);
  }
  if ((Object)targetType == ConvertTypes[18]) {
    return value->ToString(provider);
  }
  if ((Object)targetType == ConvertTypes[1]) {
    return value;
  }
  if ((Object)targetType == EnumType) {
    return (Enum)value;
  }
  if ((Object)targetType == ConvertTypes[2]) {
    rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_DBNull());
  }
  if ((Object)targetType == ConvertTypes[0]) {
    rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_Empty());
  }
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), value->GetType()->get_FullName(), targetType->get_FullName()));
}

Object Convert::ChangeType(Object value, Type conversionType) {
  return ChangeType(value, conversionType, CultureInfo::in::get_CurrentCulture());
}

Object Convert::ChangeType(Object value, Type conversionType, IFormatProvider provider) {
  if ((Object)conversionType == nullptr) {
    rt::throw_exception<ArgumentNullException>("conversionType");
  }
  if (value == nullptr) {
    if (conversionType->get_IsValueType()) {
      rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_CannotCastNullToValueType());
    }
    return nullptr;
  }
  IConvertible convertible = rt::as<IConvertible>(value);
  if (convertible == nullptr) {
    if (value->GetType() == conversionType) {
      return value;
    }
    rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_IConvertible());
  }
  if ((Object)conversionType == ConvertTypes[3]) {
    return convertible->ToBoolean(provider);
  }
  if ((Object)conversionType == ConvertTypes[4]) {
    return convertible->ToChar(provider);
  }
  if ((Object)conversionType == ConvertTypes[5]) {
    return convertible->ToSByte(provider);
  }
  if ((Object)conversionType == ConvertTypes[6]) {
    return convertible->ToByte(provider);
  }
  if ((Object)conversionType == ConvertTypes[7]) {
    return convertible->ToInt16(provider);
  }
  if ((Object)conversionType == ConvertTypes[8]) {
    return convertible->ToUInt16(provider);
  }
  if ((Object)conversionType == ConvertTypes[9]) {
    return convertible->ToInt32(provider);
  }
  if ((Object)conversionType == ConvertTypes[10]) {
    return convertible->ToUInt32(provider);
  }
  if ((Object)conversionType == ConvertTypes[11]) {
    return convertible->ToInt64(provider);
  }
  if ((Object)conversionType == ConvertTypes[12]) {
    return convertible->ToUInt64(provider);
  }
  if ((Object)conversionType == ConvertTypes[13]) {
    return convertible->ToSingle(provider);
  }
  if ((Object)conversionType == ConvertTypes[14]) {
    return convertible->ToDouble(provider);
  }
  if ((Object)conversionType == ConvertTypes[15]) {
    return convertible->ToDecimal(provider);
  }
  if ((Object)conversionType == ConvertTypes[16]) {
    return convertible->ToDateTime(provider);
  }
  if ((Object)conversionType == ConvertTypes[18]) {
    return convertible->ToString(provider);
  }
  if ((Object)conversionType == ConvertTypes[1]) {
    return value;
  }
  return convertible->ToType(conversionType, provider);
}

void Convert::ThrowCharOverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_Char());
}

void Convert::ThrowByteOverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_Byte());
}

void Convert::ThrowSByteOverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_SByte());
}

void Convert::ThrowInt16OverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_Int16());
}

void Convert::ThrowUInt16OverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_UInt16());
}

void Convert::ThrowInt32OverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_Int32());
}

void Convert::ThrowUInt32OverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_UInt32());
}

void Convert::ThrowInt64OverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_Int64());
}

void Convert::ThrowUInt64OverflowException() {
  rt::throw_exception<OverflowException>(SR::get_Overflow_UInt64());
}

Boolean Convert::ToBoolean(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToBoolean(nullptr);
  }
  return false;
}

Boolean Convert::ToBoolean(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToBoolean(provider);
  }
  return false;
}

Boolean Convert::ToBoolean(Boolean value) {
  return value;
}

Boolean Convert::ToBoolean(SByte value) {
  return value != 0;
}

Boolean Convert::ToBoolean(Char value) {
  return ((IConvertible)value)->ToBoolean((IFormatProvider)nullptr);
}

Boolean Convert::ToBoolean(Byte value) {
  return value != 0;
}

Boolean Convert::ToBoolean(Int16 value) {
  return value != 0;
}

Boolean Convert::ToBoolean(UInt16 value) {
  return value != 0;
}

Boolean Convert::ToBoolean(Int32 value) {
  return value != 0;
}

Boolean Convert::ToBoolean(UInt32 value) {
  return value != 0;
}

Boolean Convert::ToBoolean(Int64 value) {
  return value != 0;
}

Boolean Convert::ToBoolean(UInt64 value) {
  return value != 0;
}

Boolean Convert::ToBoolean(String value) {
  if (value == nullptr) {
    return false;
  }
  return Boolean::Parse(value);
}

Boolean Convert::ToBoolean(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return false;
  }
  return Boolean::Parse(value);
}

Boolean Convert::ToBoolean(Single value) {
  return value != 0;
}

Boolean Convert::ToBoolean(Double value) {
  return value != 0;
}

Boolean Convert::ToBoolean(Decimal value) {
  return value != 0;
}

Boolean Convert::ToBoolean(DateTime value) {
  return ((IConvertible)value)->ToBoolean((IFormatProvider)nullptr);
}

Char Convert::ToChar(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToChar(nullptr);
  }
  return 0;
}

Char Convert::ToChar(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToChar(provider);
  }
  return 0;
}

Char Convert::ToChar(Boolean value) {
  return ((IConvertible)value)->ToChar((IFormatProvider)nullptr);
}

Char Convert::ToChar(Char value) {
  return value;
}

Char Convert::ToChar(SByte value) {
  if (value < 0) {
    ThrowCharOverflowException();
  }
  return (Char)value;
}

Char Convert::ToChar(Byte value) {
  return (Char)value;
}

Char Convert::ToChar(Int16 value) {
  if (value < 0) {
    ThrowCharOverflowException();
  }
  return (Char)value;
}

Char Convert::ToChar(UInt16 value) {
  return (Char)value;
}

Char Convert::ToChar(Int32 value) {
  return ToChar((UInt32)value);
}

Char Convert::ToChar(UInt32 value) {
  if (value > 65535) {
    ThrowCharOverflowException();
  }
  return (Char)value;
}

Char Convert::ToChar(Int64 value) {
  return ToChar((UInt64)value);
}

Char Convert::ToChar(UInt64 value) {
  if (value > 65535) {
    ThrowCharOverflowException();
  }
  return (Char)value;
}

Char Convert::ToChar(String value) {
  return ToChar(value, nullptr);
}

Char Convert::ToChar(String value, IFormatProvider provider) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() != 1) {
    rt::throw_exception<FormatException>(SR::get_Format_NeedSingleChar());
  }
  return value[0];
}

Char Convert::ToChar(Single value) {
  return ((IConvertible)value)->ToChar((IFormatProvider)nullptr);
}

Char Convert::ToChar(Double value) {
  return ((IConvertible)value)->ToChar((IFormatProvider)nullptr);
}

Char Convert::ToChar(Decimal value) {
  return ((IConvertible)value)->ToChar((IFormatProvider)nullptr);
}

Char Convert::ToChar(DateTime value) {
  return ((IConvertible)value)->ToChar((IFormatProvider)nullptr);
}

SByte Convert::ToSByte(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToSByte(nullptr);
  }
  return 0;
}

SByte Convert::ToSByte(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToSByte(provider);
  }
  return 0;
}

SByte Convert::ToSByte(Boolean value) {
  if (!value) {
    return 0;
  }
  return 1;
}

SByte Convert::ToSByte(SByte value) {
  return value;
}

SByte Convert::ToSByte(Char value) {
  if (value > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)value;
}

SByte Convert::ToSByte(Byte value) {
  if (value > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)value;
}

SByte Convert::ToSByte(Int16 value) {
  if (value < -128 || value > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)value;
}

SByte Convert::ToSByte(UInt16 value) {
  if (value > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)value;
}

SByte Convert::ToSByte(Int32 value) {
  if (value < -128 || value > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)value;
}

SByte Convert::ToSByte(UInt32 value) {
  if (value > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)value;
}

SByte Convert::ToSByte(Int64 value) {
  if (value < -128 || value > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)value;
}

SByte Convert::ToSByte(UInt64 value) {
  if (value > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)value;
}

SByte Convert::ToSByte(Single value) {
  return ToSByte((Double)value);
}

SByte Convert::ToSByte(Double value) {
  return ToSByte(ToInt32(value));
}

SByte Convert::ToSByte(Decimal value) {
  return Decimal::ToSByte(Decimal::Round(value, 0));
}

SByte Convert::ToSByte(String value) {
  if (value == nullptr) {
    return 0;
  }
  return SByte::Parse(value);
}

SByte Convert::ToSByte(String value, IFormatProvider provider) {
  return SByte::Parse(value, provider);
}

SByte Convert::ToSByte(DateTime value) {
  return ((IConvertible)value)->ToSByte((IFormatProvider)nullptr);
}

Byte Convert::ToByte(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToByte(nullptr);
  }
  return 0;
}

Byte Convert::ToByte(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToByte(provider);
  }
  return 0;
}

Byte Convert::ToByte(Boolean value) {
  if (!value) {
    return 0;
  }
  return 1;
}

Byte Convert::ToByte(Byte value) {
  return value;
}

Byte Convert::ToByte(Char value) {
  if (value > 255) {
    ThrowByteOverflowException();
  }
  return (Byte)value;
}

Byte Convert::ToByte(SByte value) {
  if (value < 0) {
    ThrowByteOverflowException();
  }
  return (Byte)value;
}

Byte Convert::ToByte(Int16 value) {
  if ((UInt32)value > 255u) {
    ThrowByteOverflowException();
  }
  return (Byte)value;
}

Byte Convert::ToByte(UInt16 value) {
  if (value > 255) {
    ThrowByteOverflowException();
  }
  return (Byte)value;
}

Byte Convert::ToByte(Int32 value) {
  return ToByte((UInt32)value);
}

Byte Convert::ToByte(UInt32 value) {
  if (value > 255) {
    ThrowByteOverflowException();
  }
  return (Byte)value;
}

Byte Convert::ToByte(Int64 value) {
  return ToByte((UInt64)value);
}

Byte Convert::ToByte(UInt64 value) {
  if (value > 255) {
    ThrowByteOverflowException();
  }
  return (Byte)value;
}

Byte Convert::ToByte(Single value) {
  return ToByte((Double)value);
}

Byte Convert::ToByte(Double value) {
  return ToByte(ToInt32(value));
}

Byte Convert::ToByte(Decimal value) {
  return Decimal::ToByte(Decimal::Round(value, 0));
}

Byte Convert::ToByte(String value) {
  if (value == nullptr) {
    return 0;
  }
  return Byte::Parse(value);
}

Byte Convert::ToByte(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return Byte::Parse(value, provider);
}

Byte Convert::ToByte(DateTime value) {
  return ((IConvertible)value)->ToByte((IFormatProvider)nullptr);
}

Int16 Convert::ToInt16(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToInt16(nullptr);
  }
  return 0;
}

Int16 Convert::ToInt16(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToInt16(provider);
  }
  return 0;
}

Int16 Convert::ToInt16(Boolean value) {
  if (!value) {
    return 0;
  }
  return 1;
}

Int16 Convert::ToInt16(Char value) {
  if (value > 32767) {
    ThrowInt16OverflowException();
  }
  return (Int16)value;
}

Int16 Convert::ToInt16(SByte value) {
  return value;
}

Int16 Convert::ToInt16(Byte value) {
  return value;
}

Int16 Convert::ToInt16(UInt16 value) {
  if (value > 32767) {
    ThrowInt16OverflowException();
  }
  return (Int16)value;
}

Int16 Convert::ToInt16(Int32 value) {
  if (value < -32768 || value > 32767) {
    ThrowInt16OverflowException();
  }
  return (Int16)value;
}

Int16 Convert::ToInt16(UInt32 value) {
  if (value > 32767) {
    ThrowInt16OverflowException();
  }
  return (Int16)value;
}

Int16 Convert::ToInt16(Int16 value) {
  return value;
}

Int16 Convert::ToInt16(Int64 value) {
  if (value < -32768 || value > 32767) {
    ThrowInt16OverflowException();
  }
  return (Int16)value;
}

Int16 Convert::ToInt16(UInt64 value) {
  if (value > 32767) {
    ThrowInt16OverflowException();
  }
  return (Int16)value;
}

Int16 Convert::ToInt16(Single value) {
  return ToInt16((Double)value);
}

Int16 Convert::ToInt16(Double value) {
  return ToInt16(ToInt32(value));
}

Int16 Convert::ToInt16(Decimal value) {
  return Decimal::ToInt16(Decimal::Round(value, 0));
}

Int16 Convert::ToInt16(String value) {
  if (value == nullptr) {
    return 0;
  }
  return Int16::Parse(value);
}

Int16 Convert::ToInt16(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return Int16::Parse(value, provider);
}

Int16 Convert::ToInt16(DateTime value) {
  return ((IConvertible)value)->ToInt16((IFormatProvider)nullptr);
}

UInt16 Convert::ToUInt16(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToUInt16(nullptr);
  }
  return 0;
}

UInt16 Convert::ToUInt16(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToUInt16(provider);
  }
  return 0;
}

UInt16 Convert::ToUInt16(Boolean value) {
  if (!value) {
    return 0;
  }
  return 1;
}

UInt16 Convert::ToUInt16(Char value) {
  return value;
}

UInt16 Convert::ToUInt16(SByte value) {
  if (value < 0) {
    ThrowUInt16OverflowException();
  }
  return (UInt16)value;
}

UInt16 Convert::ToUInt16(Byte value) {
  return value;
}

UInt16 Convert::ToUInt16(Int16 value) {
  if (value < 0) {
    ThrowUInt16OverflowException();
  }
  return (UInt16)value;
}

UInt16 Convert::ToUInt16(Int32 value) {
  return ToUInt16((UInt32)value);
}

UInt16 Convert::ToUInt16(UInt16 value) {
  return value;
}

UInt16 Convert::ToUInt16(UInt32 value) {
  if (value > 65535) {
    ThrowUInt16OverflowException();
  }
  return (UInt16)value;
}

UInt16 Convert::ToUInt16(Int64 value) {
  return ToUInt16((UInt64)value);
}

UInt16 Convert::ToUInt16(UInt64 value) {
  if (value > 65535) {
    ThrowUInt16OverflowException();
  }
  return (UInt16)value;
}

UInt16 Convert::ToUInt16(Single value) {
  return ToUInt16((Double)value);
}

UInt16 Convert::ToUInt16(Double value) {
  return ToUInt16(ToInt32(value));
}

UInt16 Convert::ToUInt16(Decimal value) {
  return Decimal::ToUInt16(Decimal::Round(value, 0));
}

UInt16 Convert::ToUInt16(String value) {
  if (value == nullptr) {
    return 0;
  }
  return UInt16::Parse(value);
}

UInt16 Convert::ToUInt16(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return UInt16::Parse(value, provider);
}

UInt16 Convert::ToUInt16(DateTime value) {
  return ((IConvertible)value)->ToUInt16((IFormatProvider)nullptr);
}

Int32 Convert::ToInt32(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToInt32(nullptr);
  }
  return 0;
}

Int32 Convert::ToInt32(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToInt32(provider);
  }
  return 0;
}

Int32 Convert::ToInt32(Boolean value) {
  if (!value) {
    return 0;
  }
  return 1;
}

Int32 Convert::ToInt32(Char value) {
  return value;
}

Int32 Convert::ToInt32(SByte value) {
  return value;
}

Int32 Convert::ToInt32(Byte value) {
  return value;
}

Int32 Convert::ToInt32(Int16 value) {
  return value;
}

Int32 Convert::ToInt32(UInt16 value) {
  return value;
}

Int32 Convert::ToInt32(UInt32 value) {
  if ((Int32)value < 0) {
    ThrowInt32OverflowException();
  }
  return (Int32)value;
}

Int32 Convert::ToInt32(Int32 value) {
  return value;
}

Int32 Convert::ToInt32(Int64 value) {
  if (value < Int32::MinValue || value > Int32::MaxValue) {
    ThrowInt32OverflowException();
  }
  return (Int32)value;
}

Int32 Convert::ToInt32(UInt64 value) {
  if (value > Int32::MaxValue) {
    ThrowInt32OverflowException();
  }
  return (Int32)value;
}

Int32 Convert::ToInt32(Single value) {
  return ToInt32((Double)value);
}

Int32 Convert::ToInt32(Double value) {
  if (value >= 0) {
    if (value < 2147483647.5) {
      Int32 num = (Int32)value;
      Double num2 = value - (Double)num;
      if (num2 > 0.5 || (num2 == 0.5 && (num & 1) != 0)) {
        num++;
      }
      return num;
    }
  } else if (value >= -2147483648.5) {
    Int32 num3 = (Int32)value;
    Double num4 = value - (Double)num3;
    if (num4 < -0.5 || (num4 == -0.5 && (num3 & 1) != 0)) {
      num3--;
    }
    return num3;
  }

  rt::throw_exception<OverflowException>(SR::get_Overflow_Int32());
}

Int32 Convert::ToInt32(Decimal value) {
  return Decimal::ToInt32(Decimal::Round(value, 0));
}

Int32 Convert::ToInt32(String value) {
  if (value == nullptr) {
    return 0;
  }
  return Int32::Parse(value);
}

Int32 Convert::ToInt32(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return Int32::Parse(value, provider);
}

Int32 Convert::ToInt32(DateTime value) {
  return ((IConvertible)value)->ToInt32((IFormatProvider)nullptr);
}

UInt32 Convert::ToUInt32(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToUInt32(nullptr);
  }
  return 0u;
}

UInt32 Convert::ToUInt32(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToUInt32(provider);
  }
  return 0u;
}

UInt32 Convert::ToUInt32(Boolean value) {
  if (!value) {
    return 0u;
  }
  return 1u;
}

UInt32 Convert::ToUInt32(Char value) {
  return value;
}

UInt32 Convert::ToUInt32(SByte value) {
  if (value < 0) {
    ThrowUInt32OverflowException();
  }
  return (UInt32)value;
}

UInt32 Convert::ToUInt32(Byte value) {
  return value;
}

UInt32 Convert::ToUInt32(Int16 value) {
  if (value < 0) {
    ThrowUInt32OverflowException();
  }
  return (UInt32)value;
}

UInt32 Convert::ToUInt32(UInt16 value) {
  return value;
}

UInt32 Convert::ToUInt32(Int32 value) {
  if (value < 0) {
    ThrowUInt32OverflowException();
  }
  return (UInt32)value;
}

UInt32 Convert::ToUInt32(UInt32 value) {
  return value;
}

UInt32 Convert::ToUInt32(Int64 value) {
  return ToUInt32((UInt64)value);
}

UInt32 Convert::ToUInt32(UInt64 value) {
  if (value > UInt32::MaxValue) {
    ThrowUInt32OverflowException();
  }
  return (UInt32)value;
}

UInt32 Convert::ToUInt32(Single value) {
  return ToUInt32((Double)value);
}

UInt32 Convert::ToUInt32(Double value) {
  if (value >= -0.5 && value < 4294967295.5) {
    UInt32 num = (UInt32)value;
    Double num2 = value - (Double)num;
    if (num2 > 0.5 || (num2 == 0.5 && (num & 1) != 0)) {
      num++;
    }
    return num;
  }
  rt::throw_exception<OverflowException>(SR::get_Overflow_UInt32());
}

UInt32 Convert::ToUInt32(Decimal value) {
  return Decimal::ToUInt32(Decimal::Round(value, 0));
}

UInt32 Convert::ToUInt32(String value) {
  if (value == nullptr) {
    return 0u;
  }
  return UInt32::Parse(value);
}

UInt32 Convert::ToUInt32(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0u;
  }
  return UInt32::Parse(value, provider);
}

UInt32 Convert::ToUInt32(DateTime value) {
  return ((IConvertible)value)->ToUInt32((IFormatProvider)nullptr);
}

Int64 Convert::ToInt64(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToInt64(nullptr);
  }
  return 0;
}

Int64 Convert::ToInt64(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToInt64(provider);
  }
  return 0;
}

Int64 Convert::ToInt64(Boolean value) {
  return value ? 1 : 0;
}

Int64 Convert::ToInt64(Char value) {
  return value;
}

Int64 Convert::ToInt64(SByte value) {
  return value;
}

Int64 Convert::ToInt64(Byte value) {
  return value;
}

Int64 Convert::ToInt64(Int16 value) {
  return value;
}

Int64 Convert::ToInt64(UInt16 value) {
  return value;
}

Int64 Convert::ToInt64(Int32 value) {
  return value;
}

Int64 Convert::ToInt64(UInt32 value) {
  return value;
}

Int64 Convert::ToInt64(UInt64 value) {
  if ((Int64)value < 0) {
    ThrowInt64OverflowException();
  }
  return (Int64)value;
}

Int64 Convert::ToInt64(Int64 value) {
  return value;
}

Int64 Convert::ToInt64(Single value) {
  return ToInt64((Double)value);
}

Int64 Convert::ToInt64(Double value) {
  return (Int64)Math::Round(value);
}

Int64 Convert::ToInt64(Decimal value) {
  return Decimal::ToInt64(Decimal::Round(value, 0));
}

Int64 Convert::ToInt64(String value) {
  if (value == nullptr) {
    return 0;
  }
  return Int64::Parse(value);
}

Int64 Convert::ToInt64(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return Int64::Parse(value, provider);
}

Int64 Convert::ToInt64(DateTime value) {
  return ((IConvertible)value)->ToInt64((IFormatProvider)nullptr);
}

UInt64 Convert::ToUInt64(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToUInt64(nullptr);
  }
  return 0;
}

UInt64 Convert::ToUInt64(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToUInt64(provider);
  }
  return 0;
}

UInt64 Convert::ToUInt64(Boolean value) {
  if (!value) {
    return 0;
  }
  return 1;
}

UInt64 Convert::ToUInt64(Char value) {
  return value;
}

UInt64 Convert::ToUInt64(SByte value) {
  if (value < 0) {
    ThrowUInt64OverflowException();
  }
  return (UInt64)value;
}

UInt64 Convert::ToUInt64(Byte value) {
  return value;
}

UInt64 Convert::ToUInt64(Int16 value) {
  if (value < 0) {
    ThrowUInt64OverflowException();
  }
  return (UInt64)value;
}

UInt64 Convert::ToUInt64(UInt16 value) {
  return value;
}

UInt64 Convert::ToUInt64(Int32 value) {
  if (value < 0) {
    ThrowUInt64OverflowException();
  }
  return (UInt64)value;
}

UInt64 Convert::ToUInt64(UInt32 value) {
  return value;
}

UInt64 Convert::ToUInt64(Int64 value) {
  if (value < 0) {
    ThrowUInt64OverflowException();
  }
  return (UInt64)value;
}

UInt64 Convert::ToUInt64(UInt64 value) {
  return value;
}

UInt64 Convert::ToUInt64(Single value) {
  return ToUInt64((Double)value);
}

UInt64 Convert::ToUInt64(Double value) {
  return (UInt64)Math::Round(value);
}

UInt64 Convert::ToUInt64(Decimal value) {
  return Decimal::ToUInt64(Decimal::Round(value, 0));
}

UInt64 Convert::ToUInt64(String value) {
  if (value == nullptr) {
    return 0;
  }
  return UInt64::Parse(value);
}

UInt64 Convert::ToUInt64(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return UInt64::Parse(value, provider);
}

UInt64 Convert::ToUInt64(DateTime value) {
  return ((IConvertible)value)->ToUInt64((IFormatProvider)nullptr);
}

Single Convert::ToSingle(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToSingle(nullptr);
  }
  return 0;
}

Single Convert::ToSingle(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToSingle(provider);
  }
  return 0;
}

Single Convert::ToSingle(SByte value) {
  return value;
}

Single Convert::ToSingle(Byte value) {
  return (Int32)value;
}

Single Convert::ToSingle(Char value) {
  return ((IConvertible)value)->ToSingle((IFormatProvider)nullptr);
}

Single Convert::ToSingle(Int16 value) {
  return value;
}

Single Convert::ToSingle(UInt16 value) {
  return (Int32)value;
}

Single Convert::ToSingle(Int32 value) {
  return value;
}

Single Convert::ToSingle(UInt32 value) {
  return value;
}

Single Convert::ToSingle(Int64 value) {
  return value;
}

Single Convert::ToSingle(UInt64 value) {
  return value;
}

Single Convert::ToSingle(Single value) {
  return value;
}

Single Convert::ToSingle(Double value) {
  return (Single)value;
}

Single Convert::ToSingle(Decimal value) {
  return (Single)value;
}

Single Convert::ToSingle(String value) {
  if (value == nullptr) {
    return 0;
  }
  return Single::Parse(value);
}

Single Convert::ToSingle(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return Single::Parse(value, provider);
}

Single Convert::ToSingle(Boolean value) {
  return value ? 1 : 0;
}

Single Convert::ToSingle(DateTime value) {
  return ((IConvertible)value)->ToSingle((IFormatProvider)nullptr);
}

Double Convert::ToDouble(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToDouble(nullptr);
  }
  return 0;
}

Double Convert::ToDouble(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToDouble(provider);
  }
  return 0;
}

Double Convert::ToDouble(SByte value) {
  return value;
}

Double Convert::ToDouble(Byte value) {
  return (Int32)value;
}

Double Convert::ToDouble(Int16 value) {
  return value;
}

Double Convert::ToDouble(Char value) {
  return ((IConvertible)value)->ToDouble((IFormatProvider)nullptr);
}

Double Convert::ToDouble(UInt16 value) {
  return (Int32)value;
}

Double Convert::ToDouble(Int32 value) {
  return value;
}

Double Convert::ToDouble(UInt32 value) {
  return value;
}

Double Convert::ToDouble(Int64 value) {
  return value;
}

Double Convert::ToDouble(UInt64 value) {
  return value;
}

Double Convert::ToDouble(Single value) {
  return value;
}

Double Convert::ToDouble(Double value) {
  return value;
}

Double Convert::ToDouble(Decimal value) {
  return (Double)value;
}

Double Convert::ToDouble(String value) {
  if (value == nullptr) {
    return 0;
  }
  return Double::Parse(value);
}

Double Convert::ToDouble(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return Double::Parse(value, provider);
}

Double Convert::ToDouble(Boolean value) {
  return value ? 1 : 0;
}

Double Convert::ToDouble(DateTime value) {
  return ((IConvertible)value)->ToDouble((IFormatProvider)nullptr);
}

Decimal Convert::ToDecimal(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToDecimal(nullptr);
  }
  return 0;
}

Decimal Convert::ToDecimal(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToDecimal(provider);
  }
  return 0;
}

Decimal Convert::ToDecimal(SByte value) {
  return value;
}

Decimal Convert::ToDecimal(Byte value) {
  return value;
}

Decimal Convert::ToDecimal(Char value) {
  return ((IConvertible)value)->ToDecimal((IFormatProvider)nullptr);
}

Decimal Convert::ToDecimal(Int16 value) {
  return value;
}

Decimal Convert::ToDecimal(UInt16 value) {
  return value;
}

Decimal Convert::ToDecimal(Int32 value) {
  return value;
}

Decimal Convert::ToDecimal(UInt32 value) {
  return value;
}

Decimal Convert::ToDecimal(Int64 value) {
  return value;
}

Decimal Convert::ToDecimal(UInt64 value) {
  return value;
}

Decimal Convert::ToDecimal(Single value) {
  return (Decimal)value;
}

Decimal Convert::ToDecimal(Double value) {
  return (Decimal)value;
}

Decimal Convert::ToDecimal(String value) {
  if (value == nullptr) {
    return 0;
  }
  return Decimal::Parse(value);
}

Decimal Convert::ToDecimal(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return 0;
  }
  return Decimal::Parse(value, provider);
}

Decimal Convert::ToDecimal(Decimal value) {
  return value;
}

Decimal Convert::ToDecimal(Boolean value) {
  return value ? 1 : 0;
}

Decimal Convert::ToDecimal(DateTime value) {
  return ((IConvertible)value)->ToDecimal((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(DateTime value) {
  return value;
}

DateTime Convert::ToDateTime(Object value) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToDateTime(nullptr);
  }
  return DateTime::MinValue;
}

DateTime Convert::ToDateTime(Object value, IFormatProvider provider) {
  if (value != nullptr) {
    return ((IConvertible)value)->ToDateTime(provider);
  }
  return DateTime::MinValue;
}

DateTime Convert::ToDateTime(String value) {
  if (value == nullptr) {
    return DateTime(0);
  }
  return DateTime::Parse(value);
}

DateTime Convert::ToDateTime(String value, IFormatProvider provider) {
  if (value == nullptr) {
    return DateTime(0);
  }
  return DateTime::Parse(value, provider);
}

DateTime Convert::ToDateTime(SByte value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Byte value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Int16 value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(UInt16 value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Int32 value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(UInt32 value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Int64 value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(UInt64 value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Boolean value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Char value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Single value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Double value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

DateTime Convert::ToDateTime(Decimal value) {
  return ((IConvertible)value)->ToDateTime((IFormatProvider)nullptr);
}

String Convert::ToString(Object value) {
  return ToString(value, nullptr);
}

String Convert::ToString(Object value, IFormatProvider provider) {
  IConvertible convertible = rt::as<IConvertible>(value);
  if (convertible != nullptr) {
    return convertible->ToString(provider);
  }
  IFormattable formattable = rt::as<IFormattable>(value);
  if (formattable != nullptr) {
    return formattable->ToString(nullptr, provider);
  }
  if (value != nullptr) {
    return value->ToString();
  }
  return String::in::Empty;
}

String Convert::ToString(Boolean value) {
  return value.ToString();
}

String Convert::ToString(Boolean value, IFormatProvider provider) {
  return value.ToString();
}

String Convert::ToString(Char value) {
  return Char::ToString(value);
}

String Convert::ToString(Char value, IFormatProvider provider) {
  return value.ToString();
}

String Convert::ToString(SByte value) {
  return value.ToString();
}

String Convert::ToString(SByte value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(Byte value) {
  return value.ToString();
}

String Convert::ToString(Byte value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(Int16 value) {
  return value.ToString();
}

String Convert::ToString(Int16 value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(UInt16 value) {
  return value.ToString();
}

String Convert::ToString(UInt16 value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(Int32 value) {
  return value.ToString();
}

String Convert::ToString(Int32 value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(UInt32 value) {
  return value.ToString();
}

String Convert::ToString(UInt32 value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(Int64 value) {
  return value.ToString();
}

String Convert::ToString(Int64 value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(UInt64 value) {
  return value.ToString();
}

String Convert::ToString(UInt64 value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(Single value) {
  return value.ToString();
}

String Convert::ToString(Single value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(Double value) {
  return value.ToString();
}

String Convert::ToString(Double value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(Decimal value) {
  return value.ToString();
}

String Convert::ToString(Decimal value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(DateTime value) {
  return value.ToString();
}

String Convert::ToString(DateTime value, IFormatProvider provider) {
  return value.ToString(provider);
}

String Convert::ToString(String value) {
  return value;
}

String Convert::ToString(String value, IFormatProvider provider) {
  return value;
}

Byte Convert::ToByte(String value, Int32 fromBase) {
  if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  if (value == nullptr) {
    return 0;
  }
  Int32 num = ParseNumbers::StringToInt(MemoryExtensions::AsSpan(value), fromBase, 4608);
  if ((UInt32)num > 255u) {
    ThrowByteOverflowException();
  }
  return (Byte)num;
}

SByte Convert::ToSByte(String value, Int32 fromBase) {
  if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  if (value == nullptr) {
    return 0;
  }
  Int32 num = ParseNumbers::StringToInt(MemoryExtensions::AsSpan(value), fromBase, 5120);
  if (fromBase != 10 && num <= 255) {
    return (SByte)num;
  }
  if (num < -128 || num > 127) {
    ThrowSByteOverflowException();
  }
  return (SByte)num;
}

Int16 Convert::ToInt16(String value, Int32 fromBase) {
  if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  if (value == nullptr) {
    return 0;
  }
  Int32 num = ParseNumbers::StringToInt(MemoryExtensions::AsSpan(value), fromBase, 6144);
  if (fromBase != 10 && num <= 65535) {
    return (Int16)num;
  }
  if (num < -32768 || num > 32767) {
    ThrowInt16OverflowException();
  }
  return (Int16)num;
}

UInt16 Convert::ToUInt16(String value, Int32 fromBase) {
  if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  if (value == nullptr) {
    return 0;
  }
  Int32 num = ParseNumbers::StringToInt(MemoryExtensions::AsSpan(value), fromBase, 4608);
  if ((UInt32)num > 65535u) {
    ThrowUInt16OverflowException();
  }
  return (UInt16)num;
}

Int32 Convert::ToInt32(String value, Int32 fromBase) {
  if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  if (value == nullptr) {
    return 0;
  }
  return ParseNumbers::StringToInt(MemoryExtensions::AsSpan(value), fromBase, 4096);
}

UInt32 Convert::ToUInt32(String value, Int32 fromBase) {
  if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  if (value == nullptr) {
    return 0u;
  }
  return (UInt32)ParseNumbers::StringToInt(MemoryExtensions::AsSpan(value), fromBase, 4608);
}

Int64 Convert::ToInt64(String value, Int32 fromBase) {
  if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  if (value == nullptr) {
    return 0;
  }
  return ParseNumbers::StringToLong(MemoryExtensions::AsSpan(value), fromBase, 4096);
}

UInt64 Convert::ToUInt64(String value, Int32 fromBase) {
  if (fromBase != 2 && fromBase != 8 && fromBase != 10 && fromBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  if (value == nullptr) {
    return 0;
  }
  return (UInt64)ParseNumbers::StringToLong(MemoryExtensions::AsSpan(value), fromBase, 4608);
}

String Convert::ToString(Byte value, Int32 toBase) {
  if (toBase != 2 && toBase != 8 && toBase != 10 && toBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  return ParseNumbers::IntToString(value, toBase, -1, 32, 64);
}

String Convert::ToString(Int16 value, Int32 toBase) {
  if (toBase != 2 && toBase != 8 && toBase != 10 && toBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  return ParseNumbers::IntToString(value, toBase, -1, 32, 128);
}

String Convert::ToString(Int32 value, Int32 toBase) {
  if (toBase != 2 && toBase != 8 && toBase != 10 && toBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  return ParseNumbers::IntToString(value, toBase, -1, 32, 0);
}

String Convert::ToString(Int64 value, Int32 toBase) {
  if (toBase != 2 && toBase != 8 && toBase != 10 && toBase != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase());
  }
  return ParseNumbers::LongToString(value, toBase, -1, 32, 0);
}

String Convert::ToBase64String(Array<Byte> inArray) {
  if (inArray == nullptr) {
    rt::throw_exception<ArgumentNullException>("inArray");
  }
  return ToBase64String(ReadOnlySpan<Byte>(inArray));
}

String Convert::ToBase64String(Array<Byte> inArray, Base64FormattingOptions options) {
  if (inArray == nullptr) {
    rt::throw_exception<ArgumentNullException>("inArray");
  }
  return ToBase64String(ReadOnlySpan<Byte>(inArray), options);
}

String Convert::ToBase64String(Array<Byte> inArray, Int32 offset, Int32 length) {
  return ToBase64String(inArray, offset, length, Base64FormattingOptions::None);
}

String Convert::ToBase64String(Array<Byte> inArray, Int32 offset, Int32 length, Base64FormattingOptions options) {
  if (inArray == nullptr) {
    rt::throw_exception<ArgumentNullException>("inArray");
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_Index());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (offset > inArray->get_Length() - length) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_OffsetLength());
  }
  return ToBase64String(ReadOnlySpan<Byte>(inArray, offset, length), options);
}

String Convert::ToBase64String(ReadOnlySpan<Byte> bytes, Base64FormattingOptions options) {
  if (options < Base64FormattingOptions::None || options > Base64FormattingOptions::InsertLineBreaks) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), (Int32)options), "options");
  }
  if (bytes.get_Length() == 0) {
    return String::in::Empty;
  }
  Boolean insertLineBreaks = options == Base64FormattingOptions::InsertLineBreaks;
  String text = String::in::FastAllocateString(ToBase64_CalculateAndValidateOutputLength(bytes.get_Length(), insertLineBreaks));
  {
    Byte* inData = &MemoryMarshal::GetReference(bytes);
    {
      Char* ptr = text;
      Char* outChars = ptr;
      Int32 num = ConvertToBase64Array(outChars, inData, 0, bytes.get_Length(), insertLineBreaks);
    }
  }
  return text;
}

Int32 Convert::ToBase64CharArray(Array<Byte> inArray, Int32 offsetIn, Int32 length, Array<Char> outArray, Int32 offsetOut) {
  return ToBase64CharArray(inArray, offsetIn, length, outArray, offsetOut, Base64FormattingOptions::None);
}

Int32 Convert::ToBase64CharArray(Array<Byte> inArray, Int32 offsetIn, Int32 length, Array<Char> outArray, Int32 offsetOut, Base64FormattingOptions options) {
  if (inArray == nullptr) {
    rt::throw_exception<ArgumentNullException>("inArray");
  }
  if (outArray == nullptr) {
    rt::throw_exception<ArgumentNullException>("outArray");
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_Index());
  }
  if (offsetIn < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offsetIn", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (offsetOut < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offsetOut", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (options < Base64FormattingOptions::None || options > Base64FormattingOptions::InsertLineBreaks) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), (Int32)options), "options");
  }
  Int32 num = inArray->get_Length();
  if (offsetIn > num - length) {
    rt::throw_exception<ArgumentOutOfRangeException>("offsetIn", SR::get_ArgumentOutOfRange_OffsetLength());
  }
  if (num == 0) {
    return 0;
  }
  Boolean insertLineBreaks = options == Base64FormattingOptions::InsertLineBreaks;
  Int32 num2 = outArray->get_Length();
  Int32 num3 = ToBase64_CalculateAndValidateOutputLength(length, insertLineBreaks);
  if (offsetOut > num2 - num3) {
    rt::throw_exception<ArgumentOutOfRangeException>("offsetOut", SR::get_ArgumentOutOfRange_OffsetOut());
  }
  Int32 result;
  {
    Char* outChars = &outArray[offsetOut];
    {
      Byte* inData = &inArray[0];
      result = ConvertToBase64Array(outChars, inData, offsetIn, length, insertLineBreaks);
    }
  }
  return result;
}

Boolean Convert::TryToBase64Chars(ReadOnlySpan<Byte> bytes, Span<Char> chars, Int32& charsWritten, Base64FormattingOptions options) {
  if (options < Base64FormattingOptions::None || options > Base64FormattingOptions::InsertLineBreaks) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), (Int32)options), "options");
  }
  if (bytes.get_Length() == 0) {
    charsWritten = 0;
    return true;
  }
  Boolean insertLineBreaks = options == Base64FormattingOptions::InsertLineBreaks;
  Int32 num = ToBase64_CalculateAndValidateOutputLength(bytes.get_Length(), insertLineBreaks);
  if (num > chars.get_Length()) {
    charsWritten = 0;
    return false;
  }
  {
    Char* outChars = &MemoryMarshal::GetReference(chars);
    {
      Byte* inData = &MemoryMarshal::GetReference(bytes);
      charsWritten = ConvertToBase64Array(outChars, inData, 0, bytes.get_Length(), insertLineBreaks);
      return true;
    }
  }
}

Int32 Convert::ConvertToBase64Array(Char* outChars, Byte* inData, Int32 offset, Int32 length, Boolean insertLineBreaks) {
  Int32 num = length % 3;
  Int32 num2 = offset + (length - num);
  Int32 num3 = 0;
  Int32 num4 = 0;
  {
    Char* ptr = &base64Table[0];
    Int32 i;
    for (i = offset; i < num2; i += 3) {
      if (insertLineBreaks) {
        if (num4 == 76) {
          outChars[num3++] = 13;
          outChars[num3++] = 10;
          num4 = 0;
        }
        num4 += 4;
      }
      outChars[num3] = ptr[(inData[i] & 252) >> 2];
      outChars[num3 + 1] = ptr[((inData[i] & 3) << 4) | ((inData[i + 1] & 240) >> 4)];
      outChars[num3 + 2] = ptr[((inData[i + 1] & 15) << 2) | ((inData[i + 2] & 192) >> 6)];
      outChars[num3 + 3] = ptr[inData[i + 2] & 63];
      num3 += 4;
    }
    i = num2;
    if (insertLineBreaks && num != 0 && num4 == 76) {
      outChars[num3++] = 13;
      outChars[num3++] = 10;
    }
    switch (num.get()) {
      case 2:
        outChars[num3] = ptr[(inData[i] & 252) >> 2];
        outChars[num3 + 1] = ptr[((inData[i] & 3) << 4) | ((inData[i + 1] & 240) >> 4)];
        outChars[num3 + 2] = ptr[(inData[i + 1] & 15) << 2];
        outChars[num3 + 3] = ptr[64];
        num3 += 4;
        break;
      case 1:
        outChars[num3] = ptr[(inData[i] & 252) >> 2];
        outChars[num3 + 1] = ptr[(inData[i] & 3) << 4];
        outChars[num3 + 2] = ptr[64];
        outChars[num3 + 3] = ptr[64];
        num3 += 4;
        break;
    }
  }
  return num3;
}

Int32 Convert::ToBase64_CalculateAndValidateOutputLength(Int32 inputLength, Boolean insertLineBreaks) {
  Int64 num = (Int64)inputLength / 3 * 4;
  num += ((inputLength % 3 != 0) ? 4 : 0);
  if (num == 0) {
    return 0;
  }
  if (insertLineBreaks) {
    Int64 num2 = num / 76;
    if (num % 76 == 0) {
      num2--;
    }
    num += num2 * 2;
  }
  if (num > Int32::MaxValue) {
    rt::throw_exception<OutOfMemoryException>();
  }
  return (Int32)num;
}

Array<Byte> Convert::FromBase64String(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  {
    Char* ptr = s;
    Char* inputPtr = ptr;
    return FromBase64CharPtr(inputPtr, s->get_Length());
  }
}

Boolean Convert::TryFromBase64String(String s, Span<Byte> bytes, Int32& bytesWritten) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  return TryFromBase64Chars(MemoryExtensions::AsSpan(s), bytes, bytesWritten);
}

Boolean Convert::TryFromBase64Chars(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& bytesWritten) {
  Char default[4] = {};
  Span<Char> span = default;
  bytesWritten = 0;
  while (chars.get_Length() != 0) {
    Int32 consumed;
    Int32 written;
    Boolean flag = TryDecodeFromUtf16(chars, bytes, consumed, written);
    bytesWritten += written;
    if (flag) {
      return true;
    }
    chars = chars.Slice(consumed);
    bytes = bytes.Slice(written);
    if (Convert::IsSpace(chars[0])) {
      Int32 i;
      for (i = 1; i != chars.get_Length() && Convert::IsSpace(chars[i]); i++) {
      }
      chars = chars.Slice(i);
      if (written % 3 != 0 && chars.get_Length() != 0) {
        bytesWritten = 0;
        return false;
      }
      continue;
    }
    Int32 consumed2;
    Int32 charsWritten;
    CopyToTempBufferWithoutWhiteSpace(chars, span, consumed2, charsWritten);
    if ((charsWritten & 3) != 0) {
      bytesWritten = 0;
      return false;
    }
    span = span.Slice(0, charsWritten);
    Int32 _;
    Int32 written2;
    if (!TryDecodeFromUtf16(span, bytes, _, written2)) {
      bytesWritten = 0;
      return false;
    }
    bytesWritten += written2;
    chars = chars.Slice(consumed2);
    bytes = bytes.Slice(written2);
    if (written2 % 3 == 0) {
      continue;
    }
    for (Int32 j = 0; j < chars.get_Length(); j++) {
      if (!Convert::IsSpace(chars[j])) {
        bytesWritten = 0;
        return false;
      }
    }
    return true;
  }
  return true;
}

void Convert::CopyToTempBufferWithoutWhiteSpace(ReadOnlySpan<Char> chars, Span<Char> tempBuffer, Int32& consumed, Int32& charsWritten) {
  charsWritten = 0;
  for (Int32 i = 0; i < chars.get_Length(); i++) {
    Char c = chars[i];
    if (!Convert::IsSpace(c)) {
      tempBuffer[charsWritten++] = c;
      if (charsWritten == tempBuffer.get_Length()) {
        consumed = i + 1;
        return;
      }
    }
  }
  consumed = chars.get_Length();
}

Boolean Convert::IsSpace(Char c) {
  if (c != 32 && c != 9 && c != 13) {
    return c == 10;
  }
  return true;
}

Array<Byte> Convert::FromBase64CharArray(Array<Char> inArray, Int32 offset, Int32 length) {
  if (inArray == nullptr) {
    rt::throw_exception<ArgumentNullException>("inArray");
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_Index());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (offset > inArray->get_Length() - length) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_OffsetLength());
  }
  if (inArray->get_Length() == 0) {
    return Array<>::in::Empty<Byte>();
  }
  {
    Char* ptr = &inArray[0];
    return FromBase64CharPtr(ptr + offset, length);
  }
}

Array<Byte> Convert::FromBase64CharPtr(Char* inputPtr, Int32 inputLength) {
  while (inputLength > 0) {
    Int32 num = inputPtr[inputLength - 1];
    if (num != 32 && num != 10 && num != 13 && num != 9) {
      break;
    }
    inputLength--;
  }
  Int32 num2 = FromBase64_ComputeResultLength(inputPtr, inputLength);
  Array<Byte> array = rt::newarr<Array<Byte>>(num2);
  Int32 _;
  if (!TryFromBase64Chars(ReadOnlySpan<Char>(inputPtr, inputLength), array, _)) {
    rt::throw_exception<FormatException>(SR::get_Format_BadBase64Char());
  }
  return array;
}

Int32 Convert::FromBase64_ComputeResultLength(Char* inputPtr, Int32 inputLength) {
  Char* ptr = inputPtr + inputLength;
  Int32 num = inputLength;
  Int32 num2 = 0;
  while (inputPtr < ptr) {
    UInt32 num3 = *inputPtr;
    inputPtr++;
    switch (num3.get()) {
      case 0u:
      case 1u:
      case 2u:
      case 3u:
      case 4u:
      case 5u:
      case 6u:
      case 7u:
      case 8u:
      case 9u:
      case 10u:
      case 11u:
      case 12u:
      case 13u:
      case 14u:
      case 15u:
      case 16u:
      case 17u:
      case 18u:
      case 19u:
      case 20u:
      case 21u:
      case 22u:
      case 23u:
      case 24u:
      case 25u:
      case 26u:
      case 27u:
      case 28u:
      case 29u:
      case 30u:
      case 31u:
      case 32u:
        num--;
        break;
      case 61u:
        num--;
        num2++;
        break;
    }
  }
  switch (num2.get()) {
    case 1:
      num2 = 2;
      break;
    case 2:
      num2 = 1;
      break;
    default:
      rt::throw_exception<FormatException>(SR::get_Format_BadBase64Char());
    case 0:
      break;
  }
  return num / 4 * 3 + num2;
}

void Convert::cctor() {
  ConvertTypes = rt::newarr<Array<Type>>(19);
  EnumType = rt::typeof<Enum>();
  base64Table = rt::newarr<Array<Char>>(65);
  DBNull = DBNull::in::Value;
}

} // namespace System::Private::CoreLib::System::ConvertNamespace
