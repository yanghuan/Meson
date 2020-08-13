#include "UInt32-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::UInt32Namespace {
using namespace System::Globalization;

Int32 UInt32::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<UInt32>(value)) {
    UInt32 num = (UInt32)value;
    if (*this < num) {
      return -1;
    }
    if (*this > num) {
      return 1;
    }
    return 0;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeUInt32());
}

Int32 UInt32::CompareTo(UInt32 value) {
  if (*this < value) {
    return -1;
  }
  if (*this > value) {
    return 1;
  }
  return 0;
}

Boolean UInt32::Equals(Object obj) {
  if (!rt::is<UInt32>(obj)) {
    return false;
  }
  return *this == (UInt32)obj;
}

Boolean UInt32::Equals(UInt32 obj) {
  return *this == obj;
}

Int32 UInt32::GetHashCode() {
  return (Int32)*this;
}

String UInt32::ToString() {
  return Number::UInt32ToDecStr(*this);
}

String UInt32::ToString(IFormatProvider provider) {
  return Number::UInt32ToDecStr(*this);
}

String UInt32::ToString(String format) {
  return Number::FormatUInt32(*this, format, nullptr);
}

String UInt32::ToString(String format, IFormatProvider provider) {
  return Number::FormatUInt32(*this, format, provider);
}

Boolean UInt32::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatUInt32(*this, format, provider, destination, charsWritten);
}

UInt32 UInt32::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseUInt32(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo());
}

UInt32 UInt32::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseUInt32(s, style, NumberFormatInfo::in::get_CurrentInfo());
}

UInt32 UInt32::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseUInt32(s, NumberStyles::Integer, NumberFormatInfo::in::GetInstance(provider));
}

UInt32 UInt32::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseUInt32(s, style, NumberFormatInfo::in::GetInstance(provider));
}

UInt32 UInt32::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Number::ParseUInt32(s, style, NumberFormatInfo::in::GetInstance(provider));
}

Boolean UInt32::TryParse(String s, UInt32& result) {
  if (s == nullptr) {
    result = 0u;
    return false;
  }
  return Number::TryParseUInt32IntegerStyle(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
}

Boolean UInt32::TryParse(ReadOnlySpan<Char> s, UInt32& result) {
  return Number::TryParseUInt32IntegerStyle(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
}

Boolean UInt32::TryParse(String s, NumberStyles style, IFormatProvider provider, UInt32& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    result = 0u;
    return false;
  }
  return Number::TryParseUInt32(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
}

Boolean UInt32::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt32& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Number::TryParseUInt32(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
}

TypeCode UInt32::GetTypeCode() {
  return TypeCode::UInt32;
}

} // namespace System::Private::CoreLib::System::UInt32Namespace
