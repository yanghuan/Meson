#include "TranscodingStream-dep.h"

namespace System::Private::CoreLib::System::Text::TranscodingStreamNamespace {
Boolean TranscodingStream___::get_CanRead() {
  return Boolean();
};

Boolean TranscodingStream___::get_CanSeek() {
  return Boolean();
};

Boolean TranscodingStream___::get_CanWrite() {
  return Boolean();
};

Int64 TranscodingStream___::get_Length() {
  return Int64();
};

Int64 TranscodingStream___::get_Position() {
  return Int64();
};

void TranscodingStream___::set_Position(Int64 value) {
};

void TranscodingStream___::Ctor(Stream innerStream, Encoding innerEncoding, Encoding thisEncoding, Boolean leaveOpen) {
};

IAsyncResult TranscodingStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
};

IAsyncResult TranscodingStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
};

void TranscodingStream___::Dispose(Boolean disposing) {
};

ValueTask<> TranscodingStream___::DisposeAsync() {
  return ValueTask<>();
};

Int32 TranscodingStream___::EndRead(IAsyncResult asyncResult) {
  return Int32();
};

void TranscodingStream___::EndWrite(IAsyncResult asyncResult) {
};

void TranscodingStream___::EnsurePreReadConditions() {
};

void TranscodingStream___::EnsurePreWriteConditions() {
};

ArraySegment<Byte> TranscodingStream___::FinalFlushWriteBuffers() {
  return ArraySegment<Byte>();
};

void TranscodingStream___::Flush() {
};

Task<> TranscodingStream___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
};

Int32 TranscodingStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return Int32();
};

Int32 TranscodingStream___::Read(Span<Byte> buffer) {
  return Int32();
};

Task<Int32> TranscodingStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};

ValueTask<Int32> TranscodingStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
};

Int32 TranscodingStream___::ReadByte() {
  return Int32();
};

Int64 TranscodingStream___::Seek(Int64 offset, SeekOrigin origin) {
  return Int64();
};

void TranscodingStream___::SetLength(Int64 value) {
};

void TranscodingStream___::ThrowIfDisposed() {
};

void TranscodingStream___::ThrowObjectDisposedException() {
};

void TranscodingStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
};

void TranscodingStream___::Write(ReadOnlySpan<Byte> buffer) {
};

Task<> TranscodingStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};

ValueTask<> TranscodingStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
};

void TranscodingStream___::WriteByte(Byte value) {
};

} // namespace System::Private::CoreLib::System::Text::TranscodingStreamNamespace
