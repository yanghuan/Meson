#include "UInt64-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::UInt64Namespace {
using namespace System::Globalization;

Int32 UInt64::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<UInt64>(value)) {
    UInt64 num = (UInt64)value;
    if (*this < num) {
      return -1;
    }
    if (*this > num) {
      return 1;
    }
    return 0;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeUInt64());
}

Int32 UInt64::CompareTo(UInt64 value) {
  if (*this < value) {
    return -1;
  }
  if (*this > value) {
    return 1;
  }
  return 0;
}

Boolean UInt64::Equals(Object obj) {
  if (!rt::is<UInt64>(obj)) {
    return false;
  }
  return *this == (UInt64)obj;
}

Boolean UInt64::Equals(UInt64 obj) {
  return *this == obj;
}

Int32 UInt64::GetHashCode() {
}

String UInt64::ToString() {
  return Number::UInt64ToDecStr(*this, -1);
}

String UInt64::ToString(IFormatProvider provider) {
  return Number::UInt64ToDecStr(*this, -1);
}

String UInt64::ToString(String format) {
  return Number::FormatUInt64(*this, format, nullptr);
}

String UInt64::ToString(String format, IFormatProvider provider) {
  return Number::FormatUInt64(*this, format, provider);
}

Boolean UInt64::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatUInt64(*this, format, provider, destination, charsWritten);
}

UInt64 UInt64::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseUInt64(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo());
}

UInt64 UInt64::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseUInt64(s, style, NumberFormatInfo::in::get_CurrentInfo());
}

UInt64 UInt64::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseUInt64(s, NumberStyles::Integer, NumberFormatInfo::in::GetInstance(provider));
}

UInt64 UInt64::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseUInt64(s, style, NumberFormatInfo::in::GetInstance(provider));
}

UInt64 UInt64::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Number::ParseUInt64(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Boolean UInt64::TryParse(String s, UInt64& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return Number::TryParseUInt64IntegerStyle(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
}

Boolean UInt64::TryParse(ReadOnlySpan<Char> s, UInt64& result) {
  return Number::TryParseUInt64IntegerStyle(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
}

Boolean UInt64::TryParse(String s, NumberStyles style, IFormatProvider provider, UInt64& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return Number::TryParseUInt64(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
}

Boolean UInt64::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt64& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Number::TryParseUInt64(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
}

TypeCode UInt64::GetTypeCode() {
  return TypeCode::UInt64;
}

} // namespace System::Private::CoreLib::System::UInt64Namespace
