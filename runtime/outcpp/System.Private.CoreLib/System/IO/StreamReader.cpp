#include "StreamReader-dep.h"

namespace System::Private::CoreLib::System::IO::StreamReaderNamespace {
Encoding StreamReader___::NullStreamReader___::get_CurrentEncoding() {
  return nullptr;
}

void StreamReader___::NullStreamReader___::Dispose(Boolean disposing) {
}

Int32 StreamReader___::NullStreamReader___::Peek() {
  return Int32();
}

Int32 StreamReader___::NullStreamReader___::Read() {
  return Int32();
}

Int32 StreamReader___::NullStreamReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

String StreamReader___::NullStreamReader___::ReadLine() {
  return nullptr;
}

String StreamReader___::NullStreamReader___::ReadToEnd() {
  return nullptr;
}

Int32 StreamReader___::NullStreamReader___::ReadBuffer() {
  return Int32();
}

void StreamReader___::NullStreamReader___::Ctor() {
}

Encoding StreamReader___::get_CurrentEncoding() {
  return nullptr;
}

Stream StreamReader___::get_BaseStream() {
  return nullptr;
}

Boolean StreamReader___::get_EndOfStream() {
  return Boolean();
}

void StreamReader___::CheckAsyncTaskInProgress() {
}

void StreamReader___::ThrowAsyncIOInProgress() {
}

void StreamReader___::Ctor() {
}

void StreamReader___::Ctor(Stream stream) {
}

void StreamReader___::Ctor(Stream stream, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::Ctor(Stream stream, Encoding encoding) {
}

void StreamReader___::Ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::Ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize) {
}

void StreamReader___::Ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize, Boolean leaveOpen) {
}

void StreamReader___::Ctor(String path) {
}

void StreamReader___::Ctor(String path, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::Ctor(String path, Encoding encoding) {
}

void StreamReader___::Ctor(String path, Encoding encoding, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::Ctor(String path, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize) {
}

Stream StreamReader___::ValidateArgsAndOpenPath(String path, Encoding encoding, Int32 bufferSize) {
  return nullptr;
}

void StreamReader___::Close() {
}

void StreamReader___::Dispose(Boolean disposing) {
}

void StreamReader___::DiscardBufferedData() {
}

Int32 StreamReader___::Peek() {
  return Int32();
}

Int32 StreamReader___::Read() {
  return Int32();
}

Int32 StreamReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

Int32 StreamReader___::Read(Span<Char> buffer) {
  return Int32();
}

Int32 StreamReader___::ReadSpan(Span<Char> buffer) {
  return Int32();
}

String StreamReader___::ReadToEnd() {
  return nullptr;
}

Int32 StreamReader___::ReadBlock(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

Int32 StreamReader___::ReadBlock(Span<Char> buffer) {
  return Int32();
}

void StreamReader___::CompressBuffer(Int32 n) {
}

void StreamReader___::DetectEncoding() {
}

Boolean StreamReader___::IsPreamble() {
  return Boolean();
}

Int32 StreamReader___::ReadBuffer() {
  return Int32();
}

Int32 StreamReader___::ReadBuffer(Span<Char> userBuffer, Boolean& readToUserBuffer) {
  return Int32();
}

String StreamReader___::ReadLine() {
  return nullptr;
}

Task<String> StreamReader___::ReadLineAsync() {
  return nullptr;
}

Task<String> StreamReader___::ReadLineAsyncInternal() {
  return nullptr;
}

Task<String> StreamReader___::ReadToEndAsync() {
  return nullptr;
}

Task<String> StreamReader___::ReadToEndAsyncInternal() {
  return nullptr;
}

Task<Int32> StreamReader___::ReadAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

ValueTask<Int32> StreamReader___::ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

ValueTask<Int32> StreamReader___::ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

Task<Int32> StreamReader___::ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

ValueTask<Int32> StreamReader___::ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

ValueTask<Int32> StreamReader___::ReadBufferAsync(CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

void StreamReader___::ThrowIfDisposed() {
}

void StreamReader___::SCtor() {
}

} // namespace System::Private::CoreLib::System::IO::StreamReaderNamespace
