#include "Guid-dep.h"

#include <System.Private.CoreLib/System/Guid-dep.h>

namespace System::Private::CoreLib::System::GuidNamespace {
void GuidResult::SetFailure(Boolean overflow, String failureMessageID) {
};

Guid Guid::Parse(String input) {
  return Guid();
};

Guid Guid::Parse(ReadOnlySpan<Char> input) {
  return Guid();
};

Boolean Guid::TryParse(String input, Guid& result) {
  return Boolean();
};

Boolean Guid::TryParse(ReadOnlySpan<Char> input, Guid& result) {
  return Boolean();
};

Guid Guid::ParseExact(String input, String format) {
  return Guid();
};

Guid Guid::ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format) {
  return Guid();
};

Boolean Guid::TryParseExact(String input, String format, Guid& result) {
  return Boolean();
};

Boolean Guid::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, Guid& result) {
  return Boolean();
};

Boolean Guid::TryParseGuid(ReadOnlySpan<Char> guidString, GuidResult& result) {
  return Boolean();
};

Boolean Guid::TryParseExactB(ReadOnlySpan<Char> guidString, GuidResult& result) {
  return Boolean();
};

Boolean Guid::TryParseExactD(ReadOnlySpan<Char> guidString, GuidResult& result) {
  return Boolean();
};

Boolean Guid::TryParseExactN(ReadOnlySpan<Char> guidString, GuidResult& result) {
  return Boolean();
};

Boolean Guid::TryParseExactP(ReadOnlySpan<Char> guidString, GuidResult& result) {
  return Boolean();
};

Boolean Guid::TryParseExactX(ReadOnlySpan<Char> guidString, GuidResult& result) {
  return Boolean();
};

Boolean Guid::TryParseHex(ReadOnlySpan<Char> guidString, Int16& result, Boolean& overflow) {
  return Boolean();
};

Boolean Guid::TryParseHex(ReadOnlySpan<Char> guidString, UInt32& result) {
  return Boolean();
};

Boolean Guid::TryParseHex(ReadOnlySpan<Char> guidString, UInt32& result, Boolean& overflow) {
  return Boolean();
};

ReadOnlySpan<Char> Guid::EatAllWhitespace(ReadOnlySpan<Char> str) {
  return ReadOnlySpan<Char>();
};

Boolean Guid::IsHexPrefix(ReadOnlySpan<Char> str, Int32 i) {
  return Boolean();
};

Array<Byte> Guid::ToByteArray() {
  return Array<Byte>();
};

Boolean Guid::TryWriteBytes(Span<Byte> destination) {
  return Boolean();
};

String Guid::ToString() {
  return nullptr;
};

Int32 Guid::GetHashCode() {
  return Int32();
};

Boolean Guid::Equals(Object o) {
  return Boolean();
};

Boolean Guid::Equals(Guid g) {
  return Boolean();
};

Int32 Guid::GetResult(UInt32 me, UInt32 them) {
  return Int32();
};

Int32 Guid::CompareTo(Object value) {
  return Int32();
};

Int32 Guid::CompareTo(Guid value) {
  return Int32();
};

Boolean Guid::op_Equality(Guid a, Guid b) {
  return Boolean();
};

Boolean Guid::op_Inequality(Guid a, Guid b) {
  return Boolean();
};

String Guid::ToString(String format) {
  return nullptr;
};

Int32 Guid::HexsToChars(Char* guidChars, Int32 a, Int32 b) {
  return Int32();
};

Int32 Guid::HexsToCharsHexOutput(Char* guidChars, Int32 a, Int32 b) {
  return Int32();
};

String Guid::ToString(String format, IFormatProvider provider) {
  return nullptr;
};

Boolean Guid::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format) {
  return Boolean();
};

Guid Guid::NewGuid() {
  return Guid();
};

} // namespace System::Private::CoreLib::System::GuidNamespace
