#include "ASCIIEncoding-dep.h"

namespace System::Private::CoreLib::System::Text::ASCIIEncodingNamespace {
Object ASCIIEncoding___::ASCIIEncodingSealed___::Clone() {
  return nullptr;
};
Boolean ASCIIEncoding___::get_IsSingleByte() {
  return Boolean();
};
void ASCIIEncoding___::SetDefaultFallbacks() {
  return void();
};
Int32 ASCIIEncoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
  return Int32();
};
Int32 ASCIIEncoding___::GetByteCount(String chars) {
  return Int32();
};
Int32 ASCIIEncoding___::GetByteCount(Char* chars, Int32 count) {
  return Int32();
};
Int32 ASCIIEncoding___::GetByteCount(ReadOnlySpan<Char> chars) {
  return Int32();
};
Int32 ASCIIEncoding___::GetByteCountCommon(Char* pChars, Int32 charCount) {
  return Int32();
};
Int32 ASCIIEncoding___::GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed) {
  return Int32();
};
Int32 ASCIIEncoding___::GetBytes(String chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return Int32();
};
Int32 ASCIIEncoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return Int32();
};
Int32 ASCIIEncoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  return Int32();
};
Int32 ASCIIEncoding___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  return Int32();
};
Int32 ASCIIEncoding___::GetBytesCommon(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount) {
  return Int32();
};
Int32 ASCIIEncoding___::GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed) {
  return Int32();
};
Int32 ASCIIEncoding___::GetBytesWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, Span<Byte> bytes, Int32 originalBytesLength, EncoderNLS encoder) {
  return Int32();
};
Int32 ASCIIEncoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return Int32();
};
Int32 ASCIIEncoding___::GetCharCount(Byte* bytes, Int32 count) {
  return Int32();
};
Int32 ASCIIEncoding___::GetCharCount(ReadOnlySpan<Byte> bytes) {
  return Int32();
};
Int32 ASCIIEncoding___::GetCharCountCommon(Byte* pBytes, Int32 byteCount) {
  return Int32();
};
Int32 ASCIIEncoding___::GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed) {
  return Int32();
};
Int32 ASCIIEncoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return Int32();
};
Int32 ASCIIEncoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  return Int32();
};
Int32 ASCIIEncoding___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars) {
  return Int32();
};
Int32 ASCIIEncoding___::GetCharsCommon(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount) {
  return Int32();
};
Int32 ASCIIEncoding___::GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed) {
  return Int32();
};
Int32 ASCIIEncoding___::GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder) {
  return Int32();
};
String ASCIIEncoding___::GetString(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount) {
  return nullptr;
};
Boolean ASCIIEncoding___::TryGetByteCount(Rune value, Int32& byteCount) {
  return Boolean();
};
OperationStatus ASCIIEncoding___::EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten) {
  return OperationStatus();
};
OperationStatus ASCIIEncoding___::DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed) {
  return OperationStatus();
};
Int32 ASCIIEncoding___::GetMaxByteCount(Int32 charCount) {
  return Int32();
};
Int32 ASCIIEncoding___::GetMaxCharCount(Int32 byteCount) {
  return Int32();
};
Decoder ASCIIEncoding___::GetDecoder() {
  return nullptr;
};
Encoder ASCIIEncoding___::GetEncoder() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Text::ASCIIEncodingNamespace
