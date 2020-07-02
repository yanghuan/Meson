#include "DecoderNLS-dep.h"

namespace System::Private::CoreLib::System::Text::DecoderNLSNamespace {
Boolean DecoderNLS___::get_MustFlush() {
  return Boolean();
};
Boolean DecoderNLS___::get_HasState() {
  return Boolean();
};
Boolean DecoderNLS___::get_HasLeftoverData() {
  return Boolean();
};
void DecoderNLS___::Reset() {
  return void();
};
Int32 DecoderNLS___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return Int32();
};
Int32 DecoderNLS___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush) {
  return Int32();
};
Int32 DecoderNLS___::GetCharCount(Byte* bytes, Int32 count, Boolean flush) {
  return Int32();
};
Int32 DecoderNLS___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return Int32();
};
Int32 DecoderNLS___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush) {
  return Int32();
};
Int32 DecoderNLS___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush) {
  return Int32();
};
void DecoderNLS___::Convert(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
  return void();
};
void DecoderNLS___::Convert(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed) {
  return void();
};
void DecoderNLS___::ClearMustFlush() {
  return void();
};
ReadOnlySpan<Byte> DecoderNLS___::GetLeftoverData() {
  return ReadOnlySpan<Byte>();
};
void DecoderNLS___::SetLeftoverData(ReadOnlySpan<Byte> bytes) {
  return void();
};
void DecoderNLS___::ClearLeftoverData() {
  return void();
};
Int32 DecoderNLS___::DrainLeftoverDataForGetCharCount(ReadOnlySpan<Byte> bytes, Int32& bytesConsumed) {
  return Int32();
};
Int32 DecoderNLS___::DrainLeftoverDataForGetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars, Int32& bytesConsumed) {
  return Int32();
};
Int32 DecoderNLS___::ConcatInto(ReadOnlySpan<Byte> srcLeft, ReadOnlySpan<Byte> srcRight, Span<Byte> dest) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Text::DecoderNLSNamespace
