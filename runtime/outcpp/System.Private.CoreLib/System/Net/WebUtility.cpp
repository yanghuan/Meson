#include "WebUtility-dep.h"

namespace System::Private::CoreLib::System::Net::WebUtilityNamespace {
void WebUtility::UrlDecoder::FlushBytes() {
}

WebUtility::UrlDecoder::UrlDecoder(Int32 bufferSize, Encoding encoding) {
}

void WebUtility::UrlDecoder::AddChar(Char ch) {
}

void WebUtility::UrlDecoder::AddByte(Byte b) {
}

String WebUtility::UrlDecoder::GetString() {
  return nullptr;
}

Char WebUtility::HtmlEntities::Lookup(ReadOnlySpan<Char> entity) {
  return Char();
}

UInt64 WebUtility::HtmlEntities::ToUInt64Key(ReadOnlySpan<Char> entity) {
  return UInt64();
}

void WebUtility::HtmlEntities::SCtor() {
}

String WebUtility::HtmlEncode(String value) {
  return nullptr;
}

void WebUtility::HtmlEncode(String value, TextWriter output) {
}

void WebUtility::HtmlEncode(ReadOnlySpan<Char> input, ValueStringBuilder& output) {
}

String WebUtility::HtmlDecode(String value) {
  return nullptr;
}

void WebUtility::HtmlDecode(String value, TextWriter output) {
}

void WebUtility::HtmlDecode(ReadOnlySpan<Char> input, ValueStringBuilder& output) {
}

Int32 WebUtility::IndexOfHtmlEncodingChars(ReadOnlySpan<Char> input) {
  return Int32();
}

void WebUtility::GetEncodedBytes(Array<Byte> originalBytes, Int32 offset, Int32 count, Array<Byte> expandedBytes) {
}

String WebUtility::UrlEncode(String value) {
  return nullptr;
}

Array<Byte> WebUtility::UrlEncodeToBytes(Array<Byte> value, Int32 offset, Int32 count) {
  return Array<Byte>();
}

String WebUtility::UrlDecodeInternal(String value, Encoding encoding) {
  return nullptr;
}

Array<Byte> WebUtility::UrlDecodeInternal(Array<Byte> bytes, Int32 offset, Int32 count) {
  return Array<Byte>();
}

String WebUtility::UrlDecode(String encodedValue) {
  return nullptr;
}

Array<Byte> WebUtility::UrlDecodeToBytes(Array<Byte> encodedValue, Int32 offset, Int32 count) {
  return Array<Byte>();
}

void WebUtility::ConvertSmpToUtf16(UInt32 smpChar, Char& leadingSurrogate, Char& trailingSurrogate) {
}

Int32 WebUtility::GetNextUnicodeScalarValueFromUtf16Surrogate(ReadOnlySpan<Char> input, Int32& index) {
  return Int32();
}

Int32 WebUtility::HexToInt(Char h) {
  return Int32();
}

Boolean WebUtility::IsUrlSafeChar(Char ch) {
  return Boolean();
}

Boolean WebUtility::ValidateUrlEncodingParameters(Array<Byte> bytes, Int32 offset, Int32 count) {
  return Boolean();
}

Int32 WebUtility::IndexOfHtmlDecodingChars(ReadOnlySpan<Char> input) {
  return Int32();
}

} // namespace System::Private::CoreLib::System::Net::WebUtilityNamespace
