#include "EncoderNLS-dep.h"

namespace System::Private::CoreLib::System::Text::EncoderNLSNamespace {
Encoding EncoderNLS___::get_Encoding() {
  return nullptr;
};
Boolean EncoderNLS___::get_MustFlush() {
  return Boolean();
};
Boolean EncoderNLS___::get_HasLeftoverData() {
  return Boolean();
};
Boolean EncoderNLS___::get_HasState() {
  return Boolean();
};
void EncoderNLS___::Reset() {
  return void();
};
Int32 EncoderNLS___::GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush) {
  return Int32();
};
Int32 EncoderNLS___::GetByteCount(Char* chars, Int32 count, Boolean flush) {
  return Int32();
};
Int32 EncoderNLS___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush) {
  return Int32();
};
Int32 EncoderNLS___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush) {
  return Int32();
};
void EncoderNLS___::Convert(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
  return void();
};
void EncoderNLS___::Convert(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed) {
  return void();
};
void EncoderNLS___::ClearMustFlush() {
  return void();
};
Int32 EncoderNLS___::DrainLeftoverDataForGetByteCount(ReadOnlySpan<Char> chars, Int32& charsConsumed) {
  return Int32();
};
Boolean EncoderNLS___::TryDrainLeftoverDataForGetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& charsConsumed, Int32& bytesWritten) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Text::EncoderNLSNamespace
