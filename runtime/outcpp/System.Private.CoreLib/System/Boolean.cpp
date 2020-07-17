#include "Boolean-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>

namespace System::Private::CoreLib::System::BooleanNamespace {
Int32 Boolean::GetHashCode() {
  return Int32();
};

String Boolean::ToString() {
  return nullptr;
};

String Boolean::ToString(IFormatProvider provider) {
  return nullptr;
};

Boolean Boolean::TryFormat(Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};

Boolean Boolean::Equals(Object obj) {
  return Boolean();
};

Boolean Boolean::Equals(Boolean obj) {
  return Boolean();
};

Int32 Boolean::CompareTo(Object obj) {
  return Int32();
};

Int32 Boolean::CompareTo(Boolean value) {
  return Int32();
};

Boolean Boolean::IsTrueStringIgnoreCase(ReadOnlySpan<Char> value) {
  return Boolean();
};

Boolean Boolean::IsFalseStringIgnoreCase(ReadOnlySpan<Char> value) {
  return Boolean();
};

Boolean Boolean::Parse(String value) {
  return Boolean();
};

Boolean Boolean::Parse(ReadOnlySpan<Char> value) {
  return Boolean();
};

Boolean Boolean::TryParse(String value, Boolean& result) {
  return Boolean();
};

Boolean Boolean::TryParse(ReadOnlySpan<Char> value, Boolean& result) {
  return Boolean();
};

ReadOnlySpan<Char> Boolean::TrimWhiteSpaceAndNull(ReadOnlySpan<Char> value) {
  return ReadOnlySpan<Char>();
};

TypeCode Boolean::GetTypeCode() {
  return TypeCode::String;
};

void Boolean::SCtor() {
};

} // namespace System::Private::CoreLib::System::BooleanNamespace
