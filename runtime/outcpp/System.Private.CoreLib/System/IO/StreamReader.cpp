#include "StreamReader-dep.h"

namespace System::Private::CoreLib::System::IO::StreamReaderNamespace {
Encoding NullStreamReader___::get_CurrentEncoding() {
  return nullptr;
}

void NullStreamReader___::Dispose(Boolean disposing) {
}

Int32 NullStreamReader___::Peek() {
  return Int32();
}

Int32 NullStreamReader___::Read() {
  return Int32();
}

Int32 NullStreamReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

String NullStreamReader___::ReadLine() {
  return nullptr;
}

String NullStreamReader___::ReadToEnd() {
  return nullptr;
}

Int32 NullStreamReader___::ReadBuffer() {
  return Int32();
}

void NullStreamReader___::ctor() {
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

void StreamReader___::ctor() {
}

void StreamReader___::ctor(Stream stream) {
}

void StreamReader___::ctor(Stream stream, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::ctor(Stream stream, Encoding encoding) {
}

void StreamReader___::ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize) {
}

void StreamReader___::ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize, Boolean leaveOpen) {
}

void StreamReader___::ctor(String path) {
}

void StreamReader___::ctor(String path, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::ctor(String path, Encoding encoding) {
}

void StreamReader___::ctor(String path, Encoding encoding, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::ctor(String path, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize) {
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

void StreamReader___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::IO::StreamReaderNamespace
