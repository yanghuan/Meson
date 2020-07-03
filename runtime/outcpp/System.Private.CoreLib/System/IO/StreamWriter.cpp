#include "StreamWriter-dep.h"

namespace System::Private::CoreLib::System::IO::StreamWriterNamespace {
Encoding StreamWriter___::get_UTF8NoBOM() {
  return nullptr;
};
Boolean StreamWriter___::get_AutoFlush() {
  return Boolean();
};
void StreamWriter___::set_AutoFlush(Boolean value) {
};
Stream StreamWriter___::get_BaseStream() {
  return nullptr;
};
Encoding StreamWriter___::get_Encoding() {
  return nullptr;
};
void StreamWriter___::CheckAsyncTaskInProgress() {
};
void StreamWriter___::ThrowAsyncIOInProgress() {
};
Stream StreamWriter___::ValidateArgsAndOpenPath(String path, Boolean append, Encoding encoding, Int32 bufferSize) {
  return nullptr;
};
void StreamWriter___::Close() {
};
void StreamWriter___::Dispose(Boolean disposing) {
};
void StreamWriter___::CloseStreamFromDispose(Boolean disposing) {
};
ValueTask<> StreamWriter___::DisposeAsync() {
  return ValueTask<>();
};
ValueTask<> StreamWriter___::DisposeAsyncCore() {
  return ValueTask<>();
};
void StreamWriter___::Flush() {
};
void StreamWriter___::Flush(Boolean flushStream, Boolean flushEncoder) {
};
void StreamWriter___::Write(Char value) {
};
void StreamWriter___::Write(Array<Char> buffer) {
};
void StreamWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
};
void StreamWriter___::Write(ReadOnlySpan<Char> buffer) {
};
void StreamWriter___::WriteSpan(ReadOnlySpan<Char> buffer, Boolean appendNewLine) {
};
void StreamWriter___::Write(String value) {
};
void StreamWriter___::WriteLine(String value) {
};
void StreamWriter___::WriteLine(ReadOnlySpan<Char> value) {
};
void StreamWriter___::WriteFormatHelper(String format, ParamsArray args, Boolean appendNewLine) {
};
void StreamWriter___::Write(String format, Object arg0) {
};
void StreamWriter___::Write(String format, Object arg0, Object arg1) {
};
void StreamWriter___::Write(String format, Object arg0, Object arg1, Object arg2) {
};
void StreamWriter___::Write(String format, Array<Object> arg) {
};
void StreamWriter___::WriteLine(String format, Object arg0) {
};
void StreamWriter___::WriteLine(String format, Object arg0, Object arg1) {
};
void StreamWriter___::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
};
void StreamWriter___::WriteLine(String format, Array<Object> arg) {
};
Task<> StreamWriter___::WriteAsync(Char value) {
  return nullptr;
};
Task<> StreamWriter___::WriteAsyncInternal(StreamWriter _this, Char value, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine) {
  return nullptr;
};
Task<> StreamWriter___::WriteAsync(String value) {
  return nullptr;
};
Task<> StreamWriter___::WriteAsyncInternal(StreamWriter _this, String value, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine) {
  return nullptr;
};
Task<> StreamWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
};
Task<> StreamWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  return nullptr;
};
Task<> StreamWriter___::WriteAsyncInternal(StreamWriter _this, ReadOnlyMemory<Char> source, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine, CancellationToken cancellationToken) {
  return nullptr;
};
Task<> StreamWriter___::WriteLineAsync() {
  return nullptr;
};
Task<> StreamWriter___::WriteLineAsync(Char value) {
  return nullptr;
};
Task<> StreamWriter___::WriteLineAsync(String value) {
  return nullptr;
};
Task<> StreamWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
};
Task<> StreamWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  return nullptr;
};
Task<> StreamWriter___::FlushAsync() {
  return nullptr;
};
Task<> StreamWriter___::FlushAsyncInternal(Boolean flushStream, Boolean flushEncoder, Array<Char> sCharBuffer, Int32 sCharPos, CancellationToken cancellationToken) {
  return nullptr;
};
Task<> StreamWriter___::FlushAsyncInternal(StreamWriter _this, Boolean flushStream, Boolean flushEncoder, Array<Char> charBuffer, Int32 charPos, Boolean haveWrittenPreamble, Encoding encoding, Encoder encoder, Array<Byte> byteBuffer, Stream stream, CancellationToken cancellationToken) {
  return nullptr;
};
void StreamWriter___::ThrowIfDisposed() {
};
} // namespace System::Private::CoreLib::System::IO::StreamWriterNamespace
