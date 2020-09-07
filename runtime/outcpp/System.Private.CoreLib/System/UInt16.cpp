#include "UInt16-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::UInt16Namespace {
using namespace System::Globalization;

Int32 UInt16::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<UInt16>(value)) {
    return *this - (UInt16)value;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeUInt16());
}

Int32 UInt16::CompareTo(UInt16 value) {
  return *this - value;
}

Boolean UInt16::Equals(Object obj) {
  if (!rt::is<UInt16>(obj)) {
    return false;
  }
  return *this == (UInt16)obj;
}

Boolean UInt16::Equals(UInt16 obj) {
  return *this == obj;
}

Int32 UInt16::GetHashCode() {
  return *this;
}

String UInt16::ToString() {
  return Number::UInt32ToDecStr(*this);
}

String UInt16::ToString(IFormatProvider provider) {
  return Number::UInt32ToDecStr(*this);
}

String UInt16::ToString(String format) {
  return Number::FormatUInt32(*this, format, nullptr);
}

String UInt16::ToString(String format, IFormatProvider provider) {
  return Number::FormatUInt32(*this, format, provider);
}

template <>
Boolean UInt16::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatUInt32(*this, format, provider, destination, charsWritten);
}

UInt16 UInt16::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo());
}

UInt16 UInt16::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::get_CurrentInfo());
}

UInt16 UInt16::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::GetInstance(provider));
}

UInt16 UInt16::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider));
}

UInt16 UInt16::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Parse(s, style, NumberFormatInfo::in::GetInstance(provider));
}

UInt16 UInt16::Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info) {
  UInt32 result;
  Number::ParsingStatus parsingStatus = Number::TryParseUInt32(s, style, info, result);
  if (parsingStatus != 0) {
    Number::ThrowOverflowOrFormatException(parsingStatus, TypeCode::UInt16);
  }
  if (result > 65535) {
    Number::ThrowOverflowException(TypeCode::UInt16);
  }
  return (UInt16)result;
}

Boolean UInt16::TryParse(String s, UInt16& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean UInt16::TryParse(ReadOnlySpan<Char> s, UInt16& result) {
  return TryParse(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean UInt16::TryParse(String s, NumberStyles style, IFormatProvider provider, UInt16& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean UInt16::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt16& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return TryParse(s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean UInt16::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, UInt16& result) {
  UInt32 result2;
  if (Number::TryParseUInt32(s, style, info, result2) != 0 || result2 > 65535) {
    result = 0;
    return false;
  }
  result = (UInt16)result2;
  return true;
}

TypeCode UInt16::GetTypeCode() {
  return TypeCode::UInt16;
}

Boolean UInt16::ToBooleanOfIConvertible(IFormatProvider provider) {
  return Convert::ToBoolean(*this);
}

Char UInt16::ToCharOfIConvertible(IFormatProvider provider) {
  return Convert::ToChar(*this);
}

SByte UInt16::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(*this);
}

Byte UInt16::ToByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToByte(*this);
}

Int16 UInt16::ToInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt16(*this);
}

UInt16 UInt16::ToUInt16OfIConvertible(IFormatProvider provider) {
  return *this;
}

Int32 UInt16::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(*this);
}

UInt32 UInt16::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(*this);
}

Int64 UInt16::ToInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt64(*this);
}

UInt64 UInt16::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(*this);
}

Single UInt16::ToSingleOfIConvertible(IFormatProvider provider) {
  return Convert::ToSingle(*this);
}

Double UInt16::ToDoubleOfIConvertible(IFormatProvider provider) {
  return Convert::ToDouble(*this);
}

Decimal UInt16::ToDecimalOfIConvertible(IFormatProvider provider) {
  return Convert::ToDecimal(*this);
}

DateTime UInt16::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "UInt16", "DateTime"));
}

Object UInt16::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType(*this, type, provider);
}

} // namespace System::Private::CoreLib::System::UInt16Namespace
