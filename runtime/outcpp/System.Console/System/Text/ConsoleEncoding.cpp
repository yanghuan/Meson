#include "ConsoleEncoding-dep.h"

namespace System::Console::System::Text::ConsoleEncodingNamespace {
Int32 ConsoleEncoding___::get_CodePage() {
  return _encoding->get_CodePage();
}

Boolean ConsoleEncoding___::get_IsSingleByte() {
  return _encoding->get_IsSingleByte();
}

String ConsoleEncoding___::get_EncodingName() {
  return _encoding->get_EncodingName();
}

String ConsoleEncoding___::get_WebName() {
  return _encoding->get_WebName();
}

void ConsoleEncoding___::ctor(Encoding encoding) {
  _encoding = encoding;
}

Array<Byte> ConsoleEncoding___::GetPreamble() {
  return Array<>::in::Empty<Byte>();
}

Int32 ConsoleEncoding___::GetByteCount(Array<Char> chars) {
  return _encoding->GetByteCount(chars);
}

Int32 ConsoleEncoding___::GetByteCount(Char* chars, Int32 count) {
  return _encoding->GetByteCount(chars, count);
}

Int32 ConsoleEncoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
  return _encoding->GetByteCount(chars, index, count);
}

Int32 ConsoleEncoding___::GetByteCount(String s) {
  return _encoding->GetByteCount(s);
}

Int32 ConsoleEncoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  return _encoding->GetBytes(chars, charCount, bytes, byteCount);
}

Array<Byte> ConsoleEncoding___::GetBytes(Array<Char> chars) {
  return _encoding->GetBytes(chars);
}

Array<Byte> ConsoleEncoding___::GetBytes(Array<Char> chars, Int32 index, Int32 count) {
  return _encoding->GetBytes(chars, index, count);
}

Int32 ConsoleEncoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return _encoding->GetBytes(chars, charIndex, charCount, bytes, byteIndex);
}

Array<Byte> ConsoleEncoding___::GetBytes(String s) {
  return _encoding->GetBytes(s);
}

Int32 ConsoleEncoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return _encoding->GetBytes(s, charIndex, charCount, bytes, byteIndex);
}

Int32 ConsoleEncoding___::GetCharCount(Byte* bytes, Int32 count) {
  return _encoding->GetCharCount(bytes, count);
}

Int32 ConsoleEncoding___::GetCharCount(Array<Byte> bytes) {
  return _encoding->GetCharCount(bytes);
}

Int32 ConsoleEncoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return _encoding->GetCharCount(bytes, index, count);
}

Int32 ConsoleEncoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  return _encoding->GetChars(bytes, byteCount, chars, charCount);
}

Array<Char> ConsoleEncoding___::GetChars(Array<Byte> bytes) {
  return _encoding->GetChars(bytes);
}

Array<Char> ConsoleEncoding___::GetChars(Array<Byte> bytes, Int32 index, Int32 count) {
  return _encoding->GetChars(bytes, index, count);
}

Int32 ConsoleEncoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return _encoding->GetChars(bytes, byteIndex, byteCount, chars, charIndex);
}

Decoder ConsoleEncoding___::GetDecoder() {
  return _encoding->GetDecoder();
}

Encoder ConsoleEncoding___::GetEncoder() {
  return _encoding->GetEncoder();
}

Int32 ConsoleEncoding___::GetMaxByteCount(Int32 charCount) {
  return _encoding->GetMaxByteCount(charCount);
}

Int32 ConsoleEncoding___::GetMaxCharCount(Int32 byteCount) {
  return _encoding->GetMaxCharCount(byteCount);
}

String ConsoleEncoding___::GetString(Array<Byte> bytes) {
  return _encoding->GetString(bytes);
}

String ConsoleEncoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
  return _encoding->GetString(bytes, index, count);
}

} // namespace System::Console::System::Text::ConsoleEncodingNamespace
