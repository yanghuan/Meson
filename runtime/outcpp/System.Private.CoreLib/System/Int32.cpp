#include "Int32-dep.h"

#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Int32Namespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Globalization;
Int32 Int32::CompareTo(Object value) {
  if (value == nullptr) {
  }
  return Int32();
};
Int32 Int32::CompareTo(Int32 value) {
  return Int32();
};
Boolean Int32::Equals(Object obj) {
  return Boolean();
};
Boolean Int32::Equals(Int32 obj) {
  return Boolean();
};
Int32 Int32::GetHashCode() {
  return Int32();
};
String Int32::ToString() {
  return nullptr;
};
String Int32::ToString(String format) {
  return nullptr;
};
String Int32::ToString(IFormatProvider provider) {
  return nullptr;
};
String Int32::ToString(String format, IFormatProvider provider) {
  return nullptr;
};
Boolean Int32::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
};
Int32 Int32::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Int32();
};
Int32 Int32::Parse(String s, NumberStyles style) {
  NumberFormatInfo::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Int32();
};
Int32 Int32::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Int32();
};
Int32 Int32::Parse(String s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::ValidateParseStyleInteger(style);
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return Int32();
};
Int32 Int32::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  NumberFormatInfo::ValidateParseStyleInteger(style);
  return Int32();
};
Boolean Int32::TryParse(String s, Int32& result) {
  if (s == nullptr) {
  }
  return Boolean();
};
Boolean Int32::TryParse(ReadOnlySpan<Char> s, Int32& result) {
  return Boolean();
};
Boolean Int32::TryParse(String s, NumberStyles style, IFormatProvider provider, Int32& result) {
  NumberFormatInfo::ValidateParseStyleInteger(style);
  if (s == nullptr) {
  }
  return Boolean();
};
Boolean Int32::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int32& result) {
  NumberFormatInfo::ValidateParseStyleInteger(style);
  return Boolean();
};
TypeCode Int32::GetTypeCode() {
  return TypeCode::String;
};
} // namespace System::Private::CoreLib::System::Int32Namespace
