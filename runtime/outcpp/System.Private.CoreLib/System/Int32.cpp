#include "Int32-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::Int32Namespace {
Int32 Int32::CompareTo(Object value) {
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
  return Int32();
};
Int32 Int32::Parse(String s, NumberStyles style) {
  return Int32();
};
Int32 Int32::Parse(String s, IFormatProvider provider) {
  return Int32();
};
Int32 Int32::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return Int32();
};
Int32 Int32::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  return Int32();
};
Boolean Int32::TryParse(String s, Int32& result) {
  return Boolean();
};
Boolean Int32::TryParse(ReadOnlySpan<Char> s, Int32& result) {
  return Boolean();
};
Boolean Int32::TryParse(String s, NumberStyles style, IFormatProvider provider, Int32& result) {
  return Boolean();
};
Boolean Int32::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int32& result) {
  return Boolean();
};
TypeCode Int32::GetTypeCode() {
  return TypeCode::String;
};
} // namespace System::Private::CoreLib::System::Int32Namespace
