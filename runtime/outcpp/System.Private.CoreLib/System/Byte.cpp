#include "Byte-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>

namespace System::Private::CoreLib::System::ByteNamespace {
Int32 Byte::CompareTo(Object value) {
  return Int32();
}

Int32 Byte::CompareTo(Byte value) {
  return Int32();
}

Boolean Byte::Equals(Object obj) {
  return Boolean();
}

Boolean Byte::Equals(Byte obj) {
  return Boolean();
}

Int32 Byte::GetHashCode() {
  return Int32();
}

Byte Byte::Parse(String s) {
  return Byte();
}

Byte Byte::Parse(String s, NumberStyles style) {
  return Byte();
}

Byte Byte::Parse(String s, IFormatProvider provider) {
  return Byte();
}

Byte Byte::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return Byte();
}

Byte Byte::Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider) {
  return Byte();
}

Byte Byte::Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info) {
  return Byte();
}

Boolean Byte::TryParse(String s, Byte& result) {
  return Boolean();
}

Boolean Byte::TryParse(ReadOnlySpan<Char> s, Byte& result) {
  return Boolean();
}

Boolean Byte::TryParse(String s, NumberStyles style, IFormatProvider provider, Byte& result) {
  return Boolean();
}

Boolean Byte::TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Byte& result) {
  return Boolean();
}

Boolean Byte::TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Byte& result) {
  return Boolean();
}

String Byte::ToString() {
  return nullptr;
}

String Byte::ToString(String format) {
  return nullptr;
}

String Byte::ToString(IFormatProvider provider) {
  return nullptr;
}

String Byte::ToString(String format, IFormatProvider provider) {
  return nullptr;
}

Boolean Byte::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
}

TypeCode Byte::GetTypeCode() {
  return TypeCode::String;
}

} // namespace System::Private::CoreLib::System::ByteNamespace
