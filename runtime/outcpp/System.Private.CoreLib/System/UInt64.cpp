#include "UInt64-dep.h"

#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::UInt64Namespace {
Int32 UInt64::CompareTo(Object value) {
  return Int32();
};
Int32 UInt64::CompareTo(UInt64 value) {
  return Int32();
};
Boolean UInt64::Equals(Object obj) {
  return Boolean();
};
Boolean UInt64::Equals(UInt64 obj) {
  return Boolean();
};
Int32 UInt64::GetHashCode() {
  return Int32();
};
String UInt64::ToString() {
  return nullptr;
};
String UInt64::ToString(IFormatProvider provider) {
  return nullptr;
};
String UInt64::ToString(String format) {
  return nullptr;
};
String UInt64::ToString(String format, IFormatProvider provider) {
  return nullptr;
};
Boolean UInt64::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
};
UInt64 UInt64::Parse(String s) {
  return UInt64();
};
UInt64 UInt64::Parse(String s, NumberStyles style) {
  return UInt64();
};
UInt64 UInt64::Parse(String s, IFormatProvider provider) {
  return UInt64();
};
UInt64 UInt64::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return UInt64();
};
UInt64 UInt64::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  return UInt64();
};
Boolean UInt64::TryParse(String s, UInt64& result) {
  return Boolean();
};
Boolean UInt64::TryParse(ReadOnlySpan<Char> s, UInt64& result) {
  return Boolean();
};
Boolean UInt64::TryParse(String s, NumberStyles style, IFormatProvider provider, UInt64& result) {
  return Boolean();
};
Boolean UInt64::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt64& result) {
  return Boolean();
};
TypeCode UInt64::GetTypeCode() {
  return TypeCode::String;
};
} // namespace System::Private::CoreLib::System::UInt64Namespace
