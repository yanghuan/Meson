#include "Int64-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
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

} // namespace System::Private::CoreLib::System::Int64Namespace
