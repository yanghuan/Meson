#include "Int64-dep.h"

#include <System.Private.CoreLib/System/Int64-dep.h>

namespace System::Private::CoreLib::System::Int64Namespace {
Int32 Int64::CompareTo(Object value) {
  return Int32();
};

Int32 Int64::CompareTo(Int64 value) {
  return Int32();
};

Boolean Int64::Equals(Object obj) {
  return Boolean();
};

Boolean Int64::Equals(Int64 obj) {
  return Boolean();
};

Int32 Int64::GetHashCode() {
  return Int32();
};

String Int64::ToString() {
  return nullptr;
};

String Int64::ToString(IFormatProvider provider) {
  return nullptr;
};

String Int64::ToString(String format) {
  return nullptr;
};

String Int64::ToString(String format, IFormatProvider provider) {
  return nullptr;
};

Boolean Int64::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
};

Int64 Int64::Parse(String s) {
  return Int64();
};

Int64 Int64::Parse(String s, NumberStyles style) {
  return Int64();
};

Int64 Int64::Parse(String s, IFormatProvider provider) {
  return Int64();
};

Int64 Int64::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return Int64();
};

Int64 Int64::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  return Int64();
};

Boolean Int64::TryParse(String s, Int64& result) {
  return Boolean();
};

Boolean Int64::TryParse(ReadOnlySpan<Char> s, Int64& result) {
  return Boolean();
};

Boolean Int64::TryParse(String s, NumberStyles style, IFormatProvider provider, Int64& result) {
  return Boolean();
};

Boolean Int64::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int64& result) {
  return Boolean();
};

TypeCode Int64::GetTypeCode() {
  return TypeCode::String;
};

} // namespace System::Private::CoreLib::System::Int64Namespace
