#include "ValueStringBuilder-dep.h"

namespace System::Private::Uri::System::Text::ValueStringBuilderNamespace {
Int32 ValueStringBuilder::get_Length() {
  return Int32();
}

ValueStringBuilder::ValueStringBuilder(Span<Char> initialBuffer) {
}

ValueStringBuilder::ValueStringBuilder(Int32 initialCapacity) {
}

void ValueStringBuilder::EnsureCapacity(Int32 capacity) {
}

String ValueStringBuilder::ToString() {
  return nullptr;
}

ReadOnlySpan<Char> ValueStringBuilder::AsSpan() {
  return ReadOnlySpan<Char>();
}

ReadOnlySpan<Char> ValueStringBuilder::AsSpan(Int32 start) {
  return ReadOnlySpan<Char>();
}

Boolean ValueStringBuilder::TryCopyTo(Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

void ValueStringBuilder::Append(Char c) {
}

void ValueStringBuilder::Append(ReadOnlySpan<Char> value) {
}

Span<Char> ValueStringBuilder::AppendSpan(Int32 length) {
  return Span<Char>();
}

void ValueStringBuilder::GrowAndAppend(Char c) {
}

void ValueStringBuilder::Grow(Int32 additionalCapacityBeyondPos) {
}

void ValueStringBuilder::Dispose() {
}

} // namespace System::Private::Uri::System::Text::ValueStringBuilderNamespace
