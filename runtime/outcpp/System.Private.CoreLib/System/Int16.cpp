#include "Int16-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Int16Namespace {
using namespace System::Globalization;

Int32 Int16::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<Int16>(value)) {
    return *this - (Int16)value;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeInt16());
}

Int32 Int16::CompareTo(Int16 value) {
  return *this - value;
}

Boolean Int16::Equals(Object obj) {
  if (!rt::is<Int16>(obj)) {
    return false;
  }
  return *this == (Int16)obj;
}

Boolean Int16::Equals(Int16 obj) {
  return *this == obj;
}

Int32 Int16::GetHashCode() {
  return *this;
}

String Int16::ToString() {
  return Number::Int32ToDecStr(*this);
}

String Int16::ToString(IFormatProvider provider) {
  return Number::FormatInt32(*this, 0, nullptr, provider);
}

String Int16::ToString(String format) {
  return ToString(format, nullptr);
}

String Int16::ToString(String format, IFormatProvider provider) {
  return Number::FormatInt32(*this, 65535, format, provider);
}

template <>
Boolean Int16::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatInt32(*this, 65535, format, provider, destination, charsWritten);
}

Int16 Int16::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo());
}

Int16 Int16::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::get_CurrentInfo());
}

Int16 Int16::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::GetInstance(provider));
}

Int16 Int16::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider));
}

Int16 Int16::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Parse(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Int16 Int16::Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info) {
  Int32 result;
  Number::ParsingStatus parsingStatus = Number::TryParseInt32(s, style, info, result);
  if (parsingStatus != 0) {
    Number::ThrowOverflowOrFormatException(parsingStatus, TypeCode::Int16);
  }
  if ((UInt32)(result - -32768 - ((Int32)(style & NumberStyles::AllowHexSpecifier) << 6)) > 65535u) {
    Number::ThrowOverflowException(TypeCode::Int16);
  }
  return (Int16)result;
}

Boolean Int16::TryParse(String s, Int16& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean Int16::TryParse(ReadOnlySpan<Char> s, Int16& result) {
  return TryParse(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean Int16::TryParse(String s, NumberStyles style, IFormatProvider provider, Int16& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Int16::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int16& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return TryParse(s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean Int16::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Int16& result) {
  Int32 result2;
  if (Number::TryParseInt32(s, style, info, result2) != 0 || (UInt32)(result2 - -32768 - ((Int32)(style & NumberStyles::AllowHexSpecifier) << 6)) > 65535u) {
    result = 0;
    return false;
  }
  result = (Int16)result2;
  return true;
}

TypeCode Int16::GetTypeCode() {
  return TypeCode::Int16;
}

Boolean Int16::ToBooleanOfIConvertible(IFormatProvider provider) {
  return Convert::ToBoolean(*this);
}

Char Int16::ToCharOfIConvertible(IFormatProvider provider) {
  return Convert::ToChar(*this);
}

SByte Int16::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(*this);
}

Byte Int16::ToByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToByte(*this);
}

Int16 Int16::ToInt16OfIConvertible(IFormatProvider provider) {
  return *this;
}

UInt16 Int16::ToUInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt16(*this);
}

Int32 Int16::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(*this);
}

UInt32 Int16::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(*this);
}

Int64 Int16::ToInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt64(*this);
}

UInt64 Int16::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(*this);
}

Single Int16::ToSingleOfIConvertible(IFormatProvider provider) {
  return Convert::ToSingle(*this);
}

Double Int16::ToDoubleOfIConvertible(IFormatProvider provider) {
  return Convert::ToDouble(*this);
}

Decimal Int16::ToDecimalOfIConvertible(IFormatProvider provider) {
  return Convert::ToDecimal(*this);
}

DateTime Int16::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Int16", "DateTime"));
}

Object Int16::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType(*this, type, provider);
}

} // namespace System::Private::CoreLib::System::Int16Namespace
