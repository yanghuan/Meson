#include "Byte-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::ByteNamespace {
using namespace System::Globalization;

Int32 Byte::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (!rt::is<Byte>(value)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeByte());
  }
  return *this - (Byte)value;
}

Int32 Byte::CompareTo(Byte value) {
  return *this - value;
}

Boolean Byte::Equals(Object obj) {
  if (!rt::is<Byte>(obj)) {
    return false;
  }
  return *this == (Byte)obj;
}

Boolean Byte::Equals(Byte obj) {
  return *this == obj;
}

Int32 Byte::GetHashCode() {
  return *this;
}

Byte Byte::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo());
}

Byte Byte::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::get_CurrentInfo());
}

Byte Byte::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::GetInstance(provider));
}

Byte Byte::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider));
}

Byte Byte::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Parse(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Byte Byte::Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info) {
  UInt32 result;
  Number::ParsingStatus parsingStatus = Number::TryParseUInt32(s, style, info, result);
  if (parsingStatus != 0) {
    Number::ThrowOverflowOrFormatException(parsingStatus, TypeCode::Byte);
  }
  if (result > 255) {
    Number::ThrowOverflowException(TypeCode::Byte);
  }
  return (Byte)result;
}

Boolean Byte::TryParse(String s, Byte& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean Byte::TryParse(ReadOnlySpan<Char> s, Byte& result) {
  return TryParse(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean Byte::TryParse(String s, NumberStyles style, IFormatProvider provider, Byte& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Byte::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Byte& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return TryParse(s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Byte::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Byte& result) {
  UInt32 result2;
  if (Number::TryParseUInt32(s, style, info, result2) != 0 || result2 > 255) {
    result = 0;
    return false;
  }
  result = (Byte)result2;
  return true;
}

String Byte::ToString() {
  return Number::UInt32ToDecStr(*this);
}

String Byte::ToString(String format) {
  return Number::FormatUInt32(*this, format, nullptr);
}

String Byte::ToString(IFormatProvider provider) {
  return Number::UInt32ToDecStr(*this);
}

String Byte::ToString(String format, IFormatProvider provider) {
  return Number::FormatUInt32(*this, format, provider);
}

template <>
Boolean Byte::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatUInt32(*this, format, provider, destination, charsWritten);
}

TypeCode Byte::GetTypeCode() {
  return TypeCode::Byte;
}

Boolean Byte::ToBooleanOfIConvertible(IFormatProvider provider) {
  return Convert::ToBoolean(*this);
}

Char Byte::ToCharOfIConvertible(IFormatProvider provider) {
  return Convert::ToChar(*this);
}

SByte Byte::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(*this);
}

Byte Byte::ToByteOfIConvertible(IFormatProvider provider) {
  return *this;
}

Int16 Byte::ToInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt16(*this);
}

UInt16 Byte::ToUInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt16(*this);
}

Int32 Byte::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(*this);
}

UInt32 Byte::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(*this);
}

Int64 Byte::ToInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt64(*this);
}

UInt64 Byte::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(*this);
}

Single Byte::ToSingleOfIConvertible(IFormatProvider provider) {
  return Convert::ToSingle(*this);
}

Double Byte::ToDoubleOfIConvertible(IFormatProvider provider) {
  return Convert::ToDouble(*this);
}

Decimal Byte::ToDecimalOfIConvertible(IFormatProvider provider) {
  return Convert::ToDecimal(*this);
}

DateTime Byte::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Byte", "DateTime"));
}

Object Byte::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType(*this, type, provider);
}

} // namespace System::Private::CoreLib::System::ByteNamespace
