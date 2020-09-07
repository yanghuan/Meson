#include "Int64-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Int64Namespace {
using namespace System::Globalization;

Int32 Int64::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<Int64>(value)) {
    Int64 num = (Int64)value;
    if (*this < num) {
      return -1;
    }
    if (*this > num) {
      return 1;
    }
    return 0;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeInt64());
}

Int32 Int64::CompareTo(Int64 value) {
  if (*this < value) {
    return -1;
  }
  if (*this > value) {
    return 1;
  }
  return 0;
}

Boolean Int64::Equals(Object obj) {
  if (!rt::is<Int64>(obj)) {
    return false;
  }
  return *this == (Int64)obj;
}

Boolean Int64::Equals(Int64 obj) {
  return *this == obj;
}

Int32 Int64::GetHashCode() {
  return (Int32)*this ^ (Int32)(*this >> 32);
}

String Int64::ToString() {
  return Number::Int64ToDecStr(*this);
}

String Int64::ToString(IFormatProvider provider) {
  return Number::FormatInt64(*this, nullptr, provider);
}

String Int64::ToString(String format) {
  return Number::FormatInt64(*this, format, nullptr);
}

String Int64::ToString(String format, IFormatProvider provider) {
  return Number::FormatInt64(*this, format, provider);
}

template <>
Boolean Int64::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatInt64(*this, format, provider, destination, charsWritten);
}

Int64 Int64::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseInt64(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo());
}

Int64 Int64::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseInt64(s, style, NumberFormatInfo::in::get_CurrentInfo());
}

Int64 Int64::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseInt64(s, NumberStyles::Integer, NumberFormatInfo::in::GetInstance(provider));
}

Int64 Int64::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseInt64(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Int64 Int64::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Number::ParseInt64(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Boolean Int64::TryParse(String s, Int64& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return Number::TryParseInt64IntegerStyle(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
}

Boolean Int64::TryParse(ReadOnlySpan<Char> s, Int64& result) {
  return Number::TryParseInt64IntegerStyle(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
}

Boolean Int64::TryParse(String s, NumberStyles style, IFormatProvider provider, Int64& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return Number::TryParseInt64(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
}

Boolean Int64::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int64& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Number::TryParseInt64(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
}

TypeCode Int64::GetTypeCode() {
  return TypeCode::Int64;
}

Boolean Int64::ToBooleanOfIConvertible(IFormatProvider provider) {
  return Convert::ToBoolean(*this);
}

Char Int64::ToCharOfIConvertible(IFormatProvider provider) {
  return Convert::ToChar(*this);
}

SByte Int64::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(*this);
}

Byte Int64::ToByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToByte(*this);
}

Int16 Int64::ToInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt16(*this);
}

UInt16 Int64::ToUInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt16(*this);
}

Int32 Int64::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(*this);
}

UInt32 Int64::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(*this);
}

Int64 Int64::ToInt64OfIConvertible(IFormatProvider provider) {
  return *this;
}

UInt64 Int64::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(*this);
}

Single Int64::ToSingleOfIConvertible(IFormatProvider provider) {
  return Convert::ToSingle(*this);
}

Double Int64::ToDoubleOfIConvertible(IFormatProvider provider) {
  return Convert::ToDouble(*this);
}

Decimal Int64::ToDecimalOfIConvertible(IFormatProvider provider) {
  return Convert::ToDecimal(*this);
}

DateTime Int64::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Int64", "DateTime"));
}

Object Int64::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType(*this, type, provider);
}

} // namespace System::Private::CoreLib::System::Int64Namespace
