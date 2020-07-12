#include "EncoderFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderFallbackBufferNamespace {
void EncoderFallbackBuffer___::Reset() {
};

void EncoderFallbackBuffer___::InternalReset() {
};

void EncoderFallbackBuffer___::InternalInitialize(Char* charStart, Char* charEnd, EncoderNLS encoder, Boolean setEncoder) {
};

EncoderFallbackBuffer EncoderFallbackBuffer___::CreateAndInitialize(Encoding encoding, EncoderNLS encoder, Int32 originalCharCount) {
  return nullptr;
};

Char EncoderFallbackBuffer___::InternalGetNextChar() {
  return Char();
};

Boolean EncoderFallbackBuffer___::InternalFallback(ReadOnlySpan<Char> chars, Int32& charsConsumed) {
  return Boolean();
};

Int32 EncoderFallbackBuffer___::InternalFallbackGetByteCount(ReadOnlySpan<Char> chars, Int32& charsConsumed) {
  return Int32();
};

Boolean EncoderFallbackBuffer___::TryInternalFallbackGetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& charsConsumed, Int32& bytesWritten) {
  return Boolean();
};

Boolean EncoderFallbackBuffer___::TryDrainRemainingDataForGetBytes(Span<Byte> bytes, Int32& bytesWritten) {
  return Boolean();
};

Int32 EncoderFallbackBuffer___::DrainRemainingDataForGetByteCount() {
  return Int32();
};

Rune EncoderFallbackBuffer___::GetNextRune() {
  return Rune();
};

Boolean EncoderFallbackBuffer___::InternalFallback(Char ch, Char*& chars) {
  return Boolean();
};

void EncoderFallbackBuffer___::ThrowLastCharRecursive(Int32 charRecursive) {
};

} // namespace System::Private::CoreLib::System::Text::EncoderFallbackBufferNamespace
