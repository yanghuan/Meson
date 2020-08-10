#include "UTF7Encoding-dep.h"

namespace System::Private::CoreLib::System::Text::UTF7EncodingNamespace {
Boolean UTF7Encoding___::Decoder___::get_HasState() {
  return Boolean();
}

void UTF7Encoding___::Decoder___::ctor(UTF7Encoding encoding) {
}

void UTF7Encoding___::Decoder___::Reset() {
}

Boolean UTF7Encoding___::Encoder___::get_HasState() {
  return Boolean();
}

void UTF7Encoding___::Encoder___::ctor(UTF7Encoding encoding) {
}

void UTF7Encoding___::Encoder___::Reset() {
}

Int32 UTF7Encoding___::DecoderUTF7Fallback___::get_MaxCharCount() {
  return Int32();
}

DecoderFallbackBuffer UTF7Encoding___::DecoderUTF7Fallback___::CreateFallbackBuffer() {
  return nullptr;
}

Boolean UTF7Encoding___::DecoderUTF7Fallback___::Equals(Object value) {
  return Boolean();
}

Int32 UTF7Encoding___::DecoderUTF7Fallback___::GetHashCode() {
  return Int32();
}

void UTF7Encoding___::DecoderUTF7Fallback___::ctor() {
}

Int32 UTF7Encoding___::DecoderUTF7FallbackBuffer___::get_Remaining() {
  return Int32();
}

Boolean UTF7Encoding___::DecoderUTF7FallbackBuffer___::Fallback(Array<Byte> bytesUnknown, Int32 index) {
  return Boolean();
}

Char UTF7Encoding___::DecoderUTF7FallbackBuffer___::GetNextChar() {
  return Char();
}

Boolean UTF7Encoding___::DecoderUTF7FallbackBuffer___::MovePrevious() {
  return Boolean();
}

void UTF7Encoding___::DecoderUTF7FallbackBuffer___::Reset() {
}

Int32 UTF7Encoding___::DecoderUTF7FallbackBuffer___::InternalFallback(Array<Byte> bytes, Byte* pBytes) {
  return Int32();
}

void UTF7Encoding___::DecoderUTF7FallbackBuffer___::ctor() {
}

void UTF7Encoding___::ctor() {
}

void UTF7Encoding___::ctor(Boolean allowOptionals) {
}

void UTF7Encoding___::MakeTables() {
}

void UTF7Encoding___::SetDefaultFallbacks() {
}

Boolean UTF7Encoding___::Equals(Object value) {
  return Boolean();
}

Int32 UTF7Encoding___::GetHashCode() {
  return Int32();
}

Int32 UTF7Encoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
  return Int32();
}

Int32 UTF7Encoding___::GetByteCount(String s) {
  return Int32();
}

Int32 UTF7Encoding___::GetByteCount(Char* chars, Int32 count) {
  return Int32();
}

Int32 UTF7Encoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return Int32();
}

Int32 UTF7Encoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  return Int32();
}

Int32 UTF7Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  return Int32();
}

Int32 UTF7Encoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  return Int32();
}

Int32 UTF7Encoding___::GetCharCount(Byte* bytes, Int32 count) {
  return Int32();
}

Int32 UTF7Encoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  return Int32();
}

Int32 UTF7Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  return Int32();
}

String UTF7Encoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
  return nullptr;
}

Int32 UTF7Encoding___::GetByteCount(Char* chars, Int32 count, EncoderNLS baseEncoder) {
  return Int32();
}

Int32 UTF7Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS baseEncoder) {
  return Int32();
}

Int32 UTF7Encoding___::GetCharCount(Byte* bytes, Int32 count, DecoderNLS baseDecoder) {
  return Int32();
}

Int32 UTF7Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS baseDecoder) {
  return Int32();
}

Decoder UTF7Encoding___::GetDecoder() {
  return nullptr;
}

Encoder UTF7Encoding___::GetEncoder() {
  return nullptr;
}

Int32 UTF7Encoding___::GetMaxByteCount(Int32 charCount) {
  return Int32();
}

Int32 UTF7Encoding___::GetMaxCharCount(Int32 byteCount) {
  return Int32();
}

void UTF7Encoding___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Text::UTF7EncodingNamespace
