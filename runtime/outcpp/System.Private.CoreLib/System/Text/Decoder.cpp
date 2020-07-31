#include "Decoder-dep.h"

namespace System::Private::CoreLib::System::Text::DecoderNamespace {
DecoderFallback Decoder___::get_Fallback() {
  return nullptr;
}

void Decoder___::set_Fallback(DecoderFallback value) {
}

DecoderFallbackBuffer Decoder___::get_FallbackBuffer() {
  return nullptr;
}

Boolean Decoder___::get_InternalHasFallbackBuffer() {
  return Boolean();
}

void Decoder___::Ctor() {
}

void Decoder___::Reset() {
}

Int32 Decoder___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush) {
  return Int32();
}

Int32 Decoder___::GetCharCount(Byte* bytes, Int32 count, Boolean flush) {
  return Int32();
}

Int32 Decoder___::GetCharCount(ReadOnlySpan<Byte> bytes, Boolean flush) {
  return Int32();
}

Int32 Decoder___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush) {
  return Int32();
}

Int32 Decoder___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush) {
  return Int32();
}

Int32 Decoder___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars, Boolean flush) {
  return Int32();
}

void Decoder___::Convert(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
}

void Decoder___::Convert(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
}

void Decoder___::Convert(ReadOnlySpan<Byte> bytes, Span<Char> chars, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
}

} // namespace System::Private::CoreLib::System::Text::DecoderNamespace
