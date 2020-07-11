#include "Int32-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>

namespace System::Private::CoreLib::System::Int32Namespace {
using namespace Globalization;
Int32 Int32::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<Int32>(value)) {
    Int32 num = (Int32)value;
    if (*this < num) {
      return -1;
    }
    if (*this > num) {
      return 1;
    }
    return 0;
  }
  //rt::throw_exception(rt::newobj<ArgumentException>(SR::get_Arg_MustBeInt32()));
};
Int32 Int32::CompareTo(Int32 value) {
  if (*this < value) {
    return -1;
  }
  if (*this > value) {
    return 1;
  }
  return 0;
};
Boolean Int32::Equals(Object obj) {
  if (!rt::is<Int32>(obj)) {
    return false;
  }
  return *this == (Int32)obj;
};
Boolean Int32::Equals(Int32 obj) {
  return *this == obj;
};
Int32 Int32::GetHashCode() {
  return *this;
};
String Int32::ToString() {
  return Number::Int32ToDecStr(*this);
};
String Int32::ToString(String format) {
  return ToString(format, nullptr);
};
String Int32::ToString(IFormatProvider provider) {
  return Number::FormatInt32(*this, 0, nullptr, provider);
};
String Int32::ToString(String format, IFormatProvider provider) {
  return Number::FormatInt32(*this, -1, format, provider);
};
Boolean Int32::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Number::TryFormatInt32(*this, -1, format, provider, destination, charsWritten);
};
Int32 Int32::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseInt32(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo());
};
Int32 Int32::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseInt32(s, style, NumberFormatInfo::in::get_CurrentInfo());
};
Int32 Int32::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseInt32(s, NumberStyles::Integer, NumberFormatInfo::in::GetInstance(provider));
};
Int32 Int32::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Number::ParseInt32(s, style, NumberFormatInfo::in::GetInstance(provider));
};
Int32 Int32::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Number::ParseInt32(s, style, NumberFormatInfo::in::GetInstance(provider));
};
Boolean Int32::TryParse(String s, Int32& result) {
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return Number::TryParseInt32IntegerStyle(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
};
Boolean Int32::TryParse(ReadOnlySpan<Char> s, Int32& result) {
  return Number::TryParseInt32IntegerStyle(s, NumberStyles::Integer, NumberFormatInfo::in::get_CurrentInfo(), result) == Number::ParsingStatus::OK;
};
Boolean Int32::TryParse(String s, NumberStyles style, IFormatProvider provider, Int32& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    result = 0;
    return false;
  }
  return Number::TryParseInt32(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
};
Boolean Int32::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int32& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  return Number::TryParseInt32(s, style, NumberFormatInfo::in::GetInstance(provider), result) == Number::ParsingStatus::OK;
};
TypeCode Int32::GetTypeCode() {
  return TypeCode::Int32;
};
} // namespace System::Private::CoreLib::System::Int32Namespace
