#include "StandardFormat-dep.h"

#include <System.Private.CoreLib/System/Buffers/StandardFormat-dep.h>

namespace System::Private::CoreLib::System::Buffers::StandardFormatNamespace {
Char StandardFormat::get_Symbol() {
  return Char();
};
Byte StandardFormat::get_Precision() {
  return Byte();
};
Boolean StandardFormat::get_HasPrecision() {
  return Boolean();
};
Boolean StandardFormat::get_IsDefault() {
  return Boolean();
};
StandardFormat StandardFormat::op_Implicit(Char symbol) {
  return StandardFormat();
};
StandardFormat StandardFormat::Parse(ReadOnlySpan<Char> format) {
  return StandardFormat();
};
StandardFormat StandardFormat::Parse(String format) {
  return StandardFormat();
};
Boolean StandardFormat::TryParse(ReadOnlySpan<Char> format, StandardFormat& result) {
  return Boolean();
};
Boolean StandardFormat::ParseHelper(ReadOnlySpan<Char> format, StandardFormat& standardFormat, Boolean throws) {
  return Boolean();
};
Boolean StandardFormat::Equals(Object obj) {
  return Boolean();
};
Int32 StandardFormat::GetHashCode() {
  return Int32();
};
Boolean StandardFormat::Equals(StandardFormat other) {
  return Boolean();
};
String StandardFormat::ToString() {
  return nullptr;
};
Int32 StandardFormat::Format(Span<Char> destination) {
  return Int32();
};
Boolean StandardFormat::op_Equality(StandardFormat left, StandardFormat right) {
  return Boolean();
};
Boolean StandardFormat::op_Inequality(StandardFormat left, StandardFormat right) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Buffers::StandardFormatNamespace
