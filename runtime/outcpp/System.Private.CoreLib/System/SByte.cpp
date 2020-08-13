#include "SByte-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::SByteNamespace {
using namespace System::Globalization;

Int32 SByte::CompareTo(Object obj) {
  if (obj == nullptr) {
    return 1;
  }
  if (!rt::is<SByte>(obj)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeSByte());
  }
  return *this - (SByte)obj;
}

Int32 SByte::CompareTo(SByte value) {
  return *this - value;
}

Boolean SByte::Equals(Object obj) {
  if (!rt::is<SByte>(obj)) {
    return false;
  }
  return *this == (SByte)obj;
}

Boolean SByte::Equals(SByte obj) {
  return *this == obj;
}

Int32 SByte::GetHashCode() {
  return *this;
}

String SByte::ToString() {
  return Number::Int32ToDecStr(*this);
}

String SByte::ToString(String format) {
  return ToString(format, nullptr);
}

String SByte::ToString(IFormatProvider provider) {
  return Number::FormatInt32(*this, 0, nullptr, provider);
}

String SByte::ToString(String format, IFormatProvider provider) {
  return Number::FormatInt32(*this, 255, format, provider);
}

Boolean SByte::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatInt32(*this, 255, format, provider, destination, charsWritten);
}

SByte SByte::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo());
}

SByte SByte::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::get_CurrentInfo());
}

SByte SByte::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::GetInstance(provider));
}

SByte SByte::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Parse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider));
}

SByte SByte::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Parse(s, style, NumberFormatInfo::in::GetInstance(provider));
}

SByte SByte::Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info) {
  Int32 result;
  Number::ParsingStatus parsingStatus = Number::TryParseInt32(s, style, info, result);
  if (parsingStatus != 0) {
    Number::ThrowOverflowOrFormatException(parsingStatus, TypeCode::SByte);
  }
}

Boolean SByte::TryParse(String s, SByte& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean SByte::TryParse(ReadOnlySpan<Char> s, SByte& result) {
  return TryParse(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result);
}

Boolean SByte::TryParse(String s, NumberStyles style, IFormatProvider provider, SByte& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean SByte::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, SByte& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return TryParse(s, style, NumberFormatInfo::in::GetInstance(provider), result);
}

Boolean SByte::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, SByte& result) {
}

TypeCode SByte::GetTypeCode() {
  return TypeCode::SByte;
}

} // namespace System::Private::CoreLib::System::SByteNamespace
