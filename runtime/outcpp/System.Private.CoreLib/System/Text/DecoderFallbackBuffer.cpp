#include "DecoderFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/Text/DecoderFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderFallbackBufferNamespace {
void DecoderFallbackBuffer___::Reset() {
};
void DecoderFallbackBuffer___::InternalReset() {
};
void DecoderFallbackBuffer___::InternalInitialize(Byte* byteStart, Char* charEnd) {
};
DecoderFallbackBuffer DecoderFallbackBuffer___::CreateAndInitialize(Encoding encoding, DecoderNLS decoder, Int32 originalByteCount) {
  return nullptr;
};
Boolean DecoderFallbackBuffer___::InternalFallback(Array<Byte> bytes, Byte* pBytes, Char*& chars) {
  return Boolean();
};
Int32 DecoderFallbackBuffer___::InternalFallback(Array<Byte> bytes, Byte* pBytes) {
  return Int32();
};
Int32 DecoderFallbackBuffer___::InternalFallbackGetCharCount(ReadOnlySpan<Byte> remainingBytes, Int32 fallbackLength) {
  return Int32();
};
Boolean DecoderFallbackBuffer___::TryInternalFallbackGetChars(ReadOnlySpan<Byte> remainingBytes, Int32 fallbackLength, Span<Char> chars, Int32& charsWritten) {
  return Boolean();
};
Rune DecoderFallbackBuffer___::GetNextRune() {
  return Rune();
};
Int32 DecoderFallbackBuffer___::DrainRemainingDataForGetCharCount() {
  return Int32();
};
Boolean DecoderFallbackBuffer___::TryDrainRemainingDataForGetChars(Span<Char> chars, Int32& charsWritten) {
  return Boolean();
};
void DecoderFallbackBuffer___::ThrowLastBytesRecursive(Array<Byte> bytesUnknown) {
};
} // namespace System::Private::CoreLib::System::Text::DecoderFallbackBufferNamespace
