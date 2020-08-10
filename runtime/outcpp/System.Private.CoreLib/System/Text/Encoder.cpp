#include "Encoder-dep.h"

namespace System::Private::CoreLib::System::Text::EncoderNamespace {
EncoderFallback Encoder___::get_Fallback() {
  return nullptr;
}

void Encoder___::set_Fallback(EncoderFallback value) {
}

EncoderFallbackBuffer Encoder___::get_FallbackBuffer() {
  return nullptr;
}

Boolean Encoder___::get_InternalHasFallbackBuffer() {
  return Boolean();
}

void Encoder___::ctor() {
}

void Encoder___::Reset() {
}

Int32 Encoder___::GetByteCount(Char* chars, Int32 count, Boolean flush) {
  return Int32();
}

Int32 Encoder___::GetByteCount(ReadOnlySpan<Char> chars, Boolean flush) {
  return Int32();
}

Int32 Encoder___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush) {
  return Int32();
}

Int32 Encoder___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Boolean flush) {
  return Int32();
}

void Encoder___::Convert(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
}

void Encoder___::Convert(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
}

void Encoder___::Convert(ReadOnlySpan<Char> chars, Span<Byte> bytes, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
}

} // namespace System::Private::CoreLib::System::Text::EncoderNamespace
