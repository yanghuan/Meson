#include "Int32-dep.h"

#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>

namespace System::Private::CoreLib::System::Int32Namespace {
using namespace Globalization;
Int32 Int32::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (rt::is<Int32>(value)) {
    Int32 num = rt::cast<Int32>(value);
  }
};
Int32 Int32::CompareTo(Int32 value) {
};
Boolean Int32::Equals(Object obj) {
};
Boolean Int32::Equals(Int32 obj) {
};
Int32 Int32::GetHashCode() {
};
String Int32::ToString() {
};
String Int32::ToString(String format) {
  return ToString(format, nullptr);
};
String Int32::ToString(IFormatProvider provider) {
};
String Int32::ToString(String format, IFormatProvider provider) {
};
Boolean Int32::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
};
Int32 Int32::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
};
Int32 Int32::Parse(String s, NumberStyles style) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
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
  }
};
Boolean Int32::TryParse(ReadOnlySpan<Char> s, Int32& result) {
};
Boolean Int32::TryParse(String s, NumberStyles style, IFormatProvider provider, Int32& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
  if (s == nullptr) {
  }
};
Boolean Int32::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int32& result) {
  NumberFormatInfo::in::ValidateParseStyleInteger(style);
};
TypeCode Int32::GetTypeCode() {
  return TypeCode::Int32;
};
} // namespace System::Private::CoreLib::System::Int32Namespace
