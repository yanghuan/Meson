#include "ValueStringBuilder-dep.h"

namespace System::Private::CoreLib::System::Text::ValueStringBuilderNamespace {
Int32 ValueStringBuilder::get_Length() {
  return Int32();
};
void ValueStringBuilder::set_Length(Int32 value) {
};
Int32 ValueStringBuilder::get_Capacity() {
  return Int32();
};
Char& ValueStringBuilder::get_Item(Int32 index) {
  return Char();
};
Span<Char> ValueStringBuilder::get_RawChars() {
  return Span<Char>();
};
void ValueStringBuilder::EnsureCapacity(Int32 capacity) {
};
String ValueStringBuilder::ToString() {
  return nullptr;
};
ReadOnlySpan<Char> ValueStringBuilder::AsSpan(Boolean terminate) {
  return ReadOnlySpan<Char>();
};
ReadOnlySpan<Char> ValueStringBuilder::AsSpan() {
  return ReadOnlySpan<Char>();
};
ReadOnlySpan<Char> ValueStringBuilder::AsSpan(Int32 start) {
  return ReadOnlySpan<Char>();
};
ReadOnlySpan<Char> ValueStringBuilder::AsSpan(Int32 start, Int32 length) {
  return ReadOnlySpan<Char>();
};
Boolean ValueStringBuilder::TryCopyTo(Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};
void ValueStringBuilder::Insert(Int32 index, String s) {
};
void ValueStringBuilder::Append(Char c) {
};
void ValueStringBuilder::Append(String s) {
};
void ValueStringBuilder::AppendSlow(String s) {
};
void ValueStringBuilder::Append(Char c, Int32 count) {
};
void ValueStringBuilder::Append(Char* value, Int32 length) {
};
void ValueStringBuilder::Append(ReadOnlySpan<Char> value) {
};
Span<Char> ValueStringBuilder::AppendSpan(Int32 length) {
  return Span<Char>();
};
void ValueStringBuilder::GrowAndAppend(Char c) {
};
void ValueStringBuilder::Grow(Int32 additionalCapacityBeyondPos) {
};
void ValueStringBuilder::Dispose() {
};
} // namespace System::Private::CoreLib::System::Text::ValueStringBuilderNamespace
