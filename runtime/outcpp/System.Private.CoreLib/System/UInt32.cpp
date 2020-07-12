#include "UInt32-dep.h"

#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::UInt32Namespace {
Int32 UInt32::CompareTo(Object value) {
  return Int32();
};

Int32 UInt32::CompareTo(UInt32 value) {
  return Int32();
};

Boolean UInt32::Equals(Object obj) {
  return Boolean();
};

Boolean UInt32::Equals(UInt32 obj) {
  return Boolean();
};

Int32 UInt32::GetHashCode() {
  return Int32();
};

String UInt32::ToString() {
  return nullptr;
};

String UInt32::ToString(IFormatProvider provider) {
  return nullptr;
};

String UInt32::ToString(String format) {
  return nullptr;
};

String UInt32::ToString(String format, IFormatProvider provider) {
  return nullptr;
};

Boolean UInt32::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
};

UInt32 UInt32::Parse(String s) {
  return UInt32();
};

UInt32 UInt32::Parse(String s, NumberStyles style) {
  return UInt32();
};

UInt32 UInt32::Parse(String s, IFormatProvider provider) {
  return UInt32();
};

UInt32 UInt32::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return UInt32();
};

UInt32 UInt32::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  return UInt32();
};

Boolean UInt32::TryParse(String s, UInt32& result) {
  return Boolean();
};

Boolean UInt32::TryParse(ReadOnlySpan<Char> s, UInt32& result) {
  return Boolean();
};

Boolean UInt32::TryParse(String s, NumberStyles style, IFormatProvider provider, UInt32& result) {
  return Boolean();
};

Boolean UInt32::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt32& result) {
  return Boolean();
};

TypeCode UInt32::GetTypeCode() {
  return TypeCode::String;
};

} // namespace System::Private::CoreLib::System::UInt32Namespace
