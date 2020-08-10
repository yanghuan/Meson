#include "UTF8Encoding-dep.h"

namespace System::Private::CoreLib::System::Text::UTF8EncodingNamespace {
ReadOnlySpan<Byte> UTF8EncodingSealed___::get_Preamble() {
  return ReadOnlySpan<Byte>();
}

void UTF8EncodingSealed___::ctor(Boolean encoderShouldEmitUTF8Identifier) {
}

Object UTF8EncodingSealed___::Clone() {
  return nullptr;
}

Array<Byte> UTF8EncodingSealed___::GetBytes(String s) {
  return Array<Byte>();
}

Array<Byte> UTF8EncodingSealed___::GetBytesForSmallInput(String s) {
  return Array<Byte>();
}

String UTF8EncodingSealed___::GetString(Array<Byte> bytes) {
  return nullptr;
}

String UTF8EncodingSealed___::GetStringForSmallInput(Array<Byte> bytes) {
  return nullptr;
}

ReadOnlySpan<Byte> UTF8Encoding___::get_PreambleSpan() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> UTF8Encoding___::get_Preamble() {
  return ReadOnlySpan<Byte>();
}

void UTF8Encoding___::ctor() {
}

void UTF8Encoding___::ctor(Boolean encoderShouldEmitUTF8Identifier) {
}

void UTF8Encoding___::ctor(Boolean encoderShouldEmitUTF8Identifier, Boolean throwOnInvalidBytes) {
}

void UTF8Encoding___::SetDefaultFallbacks() {
}

Int32 UTF8Encoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
  return Int32();
}

Int32 UTF8Encoding___::GetByteCount(String chars) {
  return Int32();
}

Int32 UTF8Encoding___::GetByteCount(Char* chars, Int32 count) {
  return Int32();
}

Int32 UTF8Encoding___::GetByteCount(ReadOnlySpan<Char> chars) {
  return Int32();
}

Int32 UTF8Encoding___::GetByteCountCommon(Char* pChars, Int32 charCount) {
  return Int32();
}

Int32 UTF8Encoding___::GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed) {
  return Int32();
}

Int32 UTF8Encoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return Int32();
}

Int32 UTF8Encoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return Int32();
}

Int32 UTF8Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  return Int32();
}

Int32 UTF8Encoding___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  return Int32();
}

Int32 UTF8Encoding___::GetBytesCommon(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount) {
  return Int32();
}

Int32 UTF8Encoding___::GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed) {
  return Int32();
}

Int32 UTF8Encoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return Int32();
}

Int32 UTF8Encoding___::GetCharCount(Byte* bytes, Int32 count) {
  return Int32();
}

Int32 UTF8Encoding___::GetCharCount(ReadOnlySpan<Byte> bytes) {
  return Int32();
}

Int32 UTF8Encoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return Int32();
}

Int32 UTF8Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  return Int32();
}

Int32 UTF8Encoding___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars) {
  return Int32();
}

Int32 UTF8Encoding___::GetCharsCommon(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount) {
  return Int32();
}

Int32 UTF8Encoding___::GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed) {
  return Int32();
}

Int32 UTF8Encoding___::GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder) {
  return Int32();
}

String UTF8Encoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
  return nullptr;
}

Int32 UTF8Encoding___::GetCharCountCommon(Byte* pBytes, Int32 byteCount) {
  return Int32();
}

Int32 UTF8Encoding___::GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed) {
  return Int32();
}

Decoder UTF8Encoding___::GetDecoder() {
  return nullptr;
}

Encoder UTF8Encoding___::GetEncoder() {
  return nullptr;
}

Boolean UTF8Encoding___::TryGetByteCount(Rune value, Int32& byteCount) {
  return Boolean();
}

OperationStatus UTF8Encoding___::EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten) {
  return OperationStatus::InvalidData;
}

OperationStatus UTF8Encoding___::DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed) {
  return OperationStatus::InvalidData;
}

Int32 UTF8Encoding___::GetMaxByteCount(Int32 charCount) {
  return Int32();
}

Int32 UTF8Encoding___::GetMaxCharCount(Int32 byteCount) {
  return Int32();
}

Array<Byte> UTF8Encoding___::GetPreamble() {
  return Array<Byte>();
}

Boolean UTF8Encoding___::Equals(Object value) {
  return Boolean();
}

Int32 UTF8Encoding___::GetHashCode() {
  return Int32();
}

void UTF8Encoding___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Text::UTF8EncodingNamespace
