#include "Encoding-dep.h"

#include <System.Private.CoreLib/System/Text/Encoding-dep.h>

namespace System::Private::CoreLib::System::Text::EncodingNamespace {
Object Encoding___::DefaultEncoder___::GetRealObject(StreamingContext context) {
  return nullptr;
};

Int32 Encoding___::DefaultEncoder___::GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush) {
  return Int32();
};

Int32 Encoding___::DefaultEncoder___::GetByteCount(Char* chars, Int32 count, Boolean flush) {
  return Int32();
};

Int32 Encoding___::DefaultEncoder___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush) {
  return Int32();
};

Int32 Encoding___::DefaultEncoder___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush) {
  return Int32();
};

Object Encoding___::DefaultDecoder___::GetRealObject(StreamingContext context) {
  return nullptr;
};

Int32 Encoding___::DefaultDecoder___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return Int32();
};

Int32 Encoding___::DefaultDecoder___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush) {
  return Int32();
};

Int32 Encoding___::DefaultDecoder___::GetCharCount(Byte* bytes, Int32 count, Boolean flush) {
  return Int32();
};

Int32 Encoding___::DefaultDecoder___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return Int32();
};

Int32 Encoding___::DefaultDecoder___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush) {
  return Int32();
};

Int32 Encoding___::DefaultDecoder___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush) {
  return Int32();
};

Boolean Encoding___::EncodingCharBuffer___::get_MoreData() {
  return Boolean();
};

Int32 Encoding___::EncodingCharBuffer___::get_BytesUsed() {
  return Int32();
};

Int32 Encoding___::EncodingCharBuffer___::get_Count() {
  return Int32();
};

Boolean Encoding___::EncodingCharBuffer___::AddChar(Char ch, Int32 numBytes) {
  return Boolean();
};

Boolean Encoding___::EncodingCharBuffer___::AddChar(Char ch) {
  return Boolean();
};

void Encoding___::EncodingCharBuffer___::AdjustBytes(Int32 count) {
};

Byte Encoding___::EncodingCharBuffer___::GetNextByte() {
  return Byte();
};

Boolean Encoding___::EncodingCharBuffer___::Fallback(Byte fallbackByte) {
  return Boolean();
};

Boolean Encoding___::EncodingCharBuffer___::Fallback(Array<Byte> byteBuffer) {
  return Boolean();
};

Boolean Encoding___::EncodingByteBuffer___::get_MoreData() {
  return Boolean();
};

Int32 Encoding___::EncodingByteBuffer___::get_CharsUsed() {
  return Int32();
};

Int32 Encoding___::EncodingByteBuffer___::get_Count() {
  return Int32();
};

Boolean Encoding___::EncodingByteBuffer___::AddByte(Byte b, Int32 moreBytesExpected) {
  return Boolean();
};

Boolean Encoding___::EncodingByteBuffer___::AddByte(Byte b1) {
  return Boolean();
};

Boolean Encoding___::EncodingByteBuffer___::AddByte(Byte b1, Byte b2) {
  return Boolean();
};

Boolean Encoding___::EncodingByteBuffer___::AddByte(Byte b1, Byte b2, Int32 moreBytesExpected) {
  return Boolean();
};

void Encoding___::EncodingByteBuffer___::MovePrevious(Boolean bThrow) {
};

Char Encoding___::EncodingByteBuffer___::GetNextChar() {
  return Char();
};

Encoding Encoding___::get_Default() {
  return nullptr;
};

ReadOnlySpan<Byte> Encoding___::get_Preamble() {
  return ReadOnlySpan<Byte>();
};

String Encoding___::get_BodyName() {
  return nullptr;
};

String Encoding___::get_EncodingName() {
  return nullptr;
};

String Encoding___::get_HeaderName() {
  return nullptr;
};

String Encoding___::get_WebName() {
  return nullptr;
};

Int32 Encoding___::get_WindowsCodePage() {
  return Int32();
};

Boolean Encoding___::get_IsBrowserDisplay() {
  return Boolean();
};

Boolean Encoding___::get_IsBrowserSave() {
  return Boolean();
};

Boolean Encoding___::get_IsMailNewsDisplay() {
  return Boolean();
};

Boolean Encoding___::get_IsMailNewsSave() {
  return Boolean();
};

Boolean Encoding___::get_IsSingleByte() {
  return Boolean();
};

EncoderFallback Encoding___::get_EncoderFallback() {
  return nullptr;
};

void Encoding___::set_EncoderFallback(EncoderFallback value) {
};

DecoderFallback Encoding___::get_DecoderFallback() {
  return nullptr;
};

void Encoding___::set_DecoderFallback(DecoderFallback value) {
};

Boolean Encoding___::get_IsReadOnly() {
  return Boolean();
};

void Encoding___::set_IsReadOnly(Boolean value) {
};

Encoding Encoding___::get_ASCII() {
  return nullptr;
};

Encoding Encoding___::get_Latin1() {
  return nullptr;
};

Int32 Encoding___::get_CodePage() {
  return Int32();
};

Encoding Encoding___::get_Unicode() {
  return nullptr;
};

Encoding Encoding___::get_BigEndianUnicode() {
  return nullptr;
};

Encoding Encoding___::get_UTF7() {
  return nullptr;
};

Encoding Encoding___::get_UTF8() {
  return nullptr;
};

Encoding Encoding___::get_UTF32() {
  return nullptr;
};

Encoding Encoding___::get_BigEndianUTF32() {
  return nullptr;
};

void Encoding___::SetDefaultFallbacks() {
};

Array<Byte> Encoding___::Convert(Encoding srcEncoding, Encoding dstEncoding, Array<Byte> bytes) {
  return Array<Byte>();
};

Array<Byte> Encoding___::Convert(Encoding srcEncoding, Encoding dstEncoding, Array<Byte> bytes, Int32 index, Int32 count) {
  return Array<Byte>();
};

void Encoding___::RegisterProvider(EncodingProvider provider) {
};

Encoding Encoding___::GetEncoding(Int32 codepage) {
  return nullptr;
};

Encoding Encoding___::GetEncoding(Int32 codepage, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  return nullptr;
};

Encoding Encoding___::GetEncoding(String name) {
  return nullptr;
};

Encoding Encoding___::GetEncoding(String name, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  return nullptr;
};

Array<EncodingInfo> Encoding___::GetEncodings() {
  return Array<EncodingInfo>();
};

Array<Byte> Encoding___::GetPreamble() {
  return Array<Byte>();
};

void Encoding___::GetDataItem() {
};

Object Encoding___::Clone() {
  return nullptr;
};

Int32 Encoding___::GetByteCount(Array<Char> chars) {
  return Int32();
};

Int32 Encoding___::GetByteCount(String s) {
  return Int32();
};

Int32 Encoding___::GetByteCount(String s, Int32 index, Int32 count) {
  return Int32();
};

Int32 Encoding___::GetByteCount(Char* chars, Int32 count) {
  return Int32();
};

Int32 Encoding___::GetByteCount(ReadOnlySpan<Char> chars) {
  return Int32();
};

Array<Byte> Encoding___::GetBytes(Array<Char> chars) {
  return Array<Byte>();
};

Array<Byte> Encoding___::GetBytes(Array<Char> chars, Int32 index, Int32 count) {
  return Array<Byte>();
};

Array<Byte> Encoding___::GetBytes(String s) {
  return Array<Byte>();
};

Array<Byte> Encoding___::GetBytes(String s, Int32 index, Int32 count) {
  return Array<Byte>();
};

Int32 Encoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return Int32();
};

Int32 Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  return Int32();
};

Int32 Encoding___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  return Int32();
};

Int32 Encoding___::GetCharCount(Array<Byte> bytes) {
  return Int32();
};

Int32 Encoding___::GetCharCount(Byte* bytes, Int32 count) {
  return Int32();
};

Int32 Encoding___::GetCharCount(ReadOnlySpan<Byte> bytes) {
  return Int32();
};

Array<Char> Encoding___::GetChars(Array<Byte> bytes) {
  return Array<Char>();
};

Array<Char> Encoding___::GetChars(Array<Byte> bytes, Int32 index, Int32 count) {
  return Array<Char>();
};

Int32 Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  return Int32();
};

Int32 Encoding___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars) {
  return Int32();
};

String Encoding___::GetString(Byte* bytes, Int32 byteCount) {
  return nullptr;
};

String Encoding___::GetString(ReadOnlySpan<Byte> bytes) {
  return nullptr;
};

Boolean Encoding___::IsAlwaysNormalized() {
  return Boolean();
};

Boolean Encoding___::IsAlwaysNormalized(NormalizationForm form) {
  return Boolean();
};

Decoder Encoding___::GetDecoder() {
  return nullptr;
};

Encoder Encoding___::GetEncoder() {
  return nullptr;
};

String Encoding___::GetString(Array<Byte> bytes) {
  return nullptr;
};

String Encoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
  return nullptr;
};

Boolean Encoding___::Equals(Object value) {
  return Boolean();
};

Int32 Encoding___::GetHashCode() {
  return Int32();
};

Stream Encoding___::CreateTranscodingStream(Stream innerStream, Encoding innerStreamEncoding, Encoding outerStreamEncoding, Boolean leaveOpen) {
  return nullptr;
};

Array<Char> Encoding___::GetBestFitUnicodeToBytesData() {
  return Array<Char>();
};

Array<Char> Encoding___::GetBestFitBytesToUnicodeData() {
  return Array<Char>();
};

void Encoding___::ThrowBytesOverflow() {
};

void Encoding___::ThrowBytesOverflow(EncoderNLS encoder, Boolean nothingEncoded) {
};

void Encoding___::ThrowConversionOverflow() {
};

void Encoding___::ThrowCharsOverflow() {
};

void Encoding___::ThrowCharsOverflow(DecoderNLS decoder, Boolean nothingDecoded) {
};

OperationStatus Encoding___::DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed) {
  return OperationStatus::InvalidData;
};

OperationStatus Encoding___::EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten) {
  return OperationStatus::InvalidData;
};

Boolean Encoding___::TryGetByteCount(Rune value, Int32& byteCount) {
  return Boolean();
};

Int32 Encoding___::GetByteCount(Char* pChars, Int32 charCount, EncoderNLS encoder) {
  return Int32();
};

Int32 Encoding___::GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed) {
  return Int32();
};

Int32 Encoding___::GetByteCountWithFallback(Char* pCharsOriginal, Int32 originalCharCount, Int32 charsConsumedSoFar) {
  return Int32();
};

Int32 Encoding___::GetByteCountWithFallback(Char* pOriginalChars, Int32 originalCharCount, Int32 charsConsumedSoFar, EncoderNLS encoder) {
  return Int32();
};

Int32 Encoding___::GetByteCountWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, EncoderNLS encoder) {
  return Int32();
};

Int32 Encoding___::GetBytes(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount, EncoderNLS encoder) {
  return Int32();
};

Int32 Encoding___::GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed) {
  return Int32();
};

Int32 Encoding___::GetBytesWithFallback(Char* pOriginalChars, Int32 originalCharCount, Byte* pOriginalBytes, Int32 originalByteCount, Int32 charsConsumedSoFar, Int32 bytesWrittenSoFar) {
  return Int32();
};

Int32 Encoding___::GetBytesWithFallback(Char* pOriginalChars, Int32 originalCharCount, Byte* pOriginalBytes, Int32 originalByteCount, Int32 charsConsumedSoFar, Int32 bytesWrittenSoFar, EncoderNLS encoder) {
  return Int32();
};

Int32 Encoding___::GetBytesWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, Span<Byte> bytes, Int32 originalBytesLength, EncoderNLS encoder) {
  return Int32();
};

Int32 Encoding___::GetCharCount(Byte* pBytes, Int32 byteCount, DecoderNLS decoder) {
  return Int32();
};

Int32 Encoding___::GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed) {
  return Int32();
};

Int32 Encoding___::GetCharCountWithFallback(Byte* pBytesOriginal, Int32 originalByteCount, Int32 bytesConsumedSoFar) {
  return Int32();
};

Int32 Encoding___::GetCharCountWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Int32 bytesConsumedSoFar, DecoderNLS decoder) {
  return Int32();
};

Int32 Encoding___::GetCharCountWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, DecoderNLS decoder) {
  return Int32();
};

Int32 Encoding___::GetChars(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount, DecoderNLS decoder) {
  return Int32();
};

Int32 Encoding___::GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed) {
  return Int32();
};

Int32 Encoding___::GetCharsWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Char* pOriginalChars, Int32 originalCharCount, Int32 bytesConsumedSoFar, Int32 charsWrittenSoFar) {
  return Int32();
};

Int32 Encoding___::GetCharsWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Char* pOriginalChars, Int32 originalCharCount, Int32 bytesConsumedSoFar, Int32 charsWrittenSoFar, DecoderNLS decoder) {
  return Int32();
};

Int32 Encoding___::GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder) {
  return Int32();
};

} // namespace System::Private::CoreLib::System::Text::EncodingNamespace
