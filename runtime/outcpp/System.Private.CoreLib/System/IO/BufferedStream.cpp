#include "BufferedStream-dep.h"

namespace System::Private::CoreLib::System::IO::BufferedStreamNamespace {
Stream BufferedStream___::get_UnderlyingStream() {
  return nullptr;
}

Int32 BufferedStream___::get_BufferSize() {
  return Int32();
}

Boolean BufferedStream___::get_CanRead() {
  return Boolean();
}

Boolean BufferedStream___::get_CanWrite() {
  return Boolean();
}

Boolean BufferedStream___::get_CanSeek() {
  return Boolean();
}

Int64 BufferedStream___::get_Length() {
  return Int64();
}

Int64 BufferedStream___::get_Position() {
  return Int64();
}

void BufferedStream___::set_Position(Int64 value) {
}

SemaphoreSlim BufferedStream___::LazyEnsureAsyncActiveSemaphoreInitialized() {
  return nullptr;
}

void BufferedStream___::ctor(Stream stream) {
}

void BufferedStream___::ctor(Stream stream, Int32 bufferSize) {
}

void BufferedStream___::EnsureNotClosed() {
}

void BufferedStream___::EnsureCanSeek() {
}

void BufferedStream___::EnsureCanRead() {
}

void BufferedStream___::EnsureCanWrite() {
}

void BufferedStream___::EnsureShadowBufferAllocated() {
}

void BufferedStream___::EnsureBufferAllocated() {
}

void BufferedStream___::Dispose(Boolean disposing) {
}

ValueTask<> BufferedStream___::DisposeAsync() {
  return ValueTask<>();
}

void BufferedStream___::Flush() {
}

Task<> BufferedStream___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
}

Task<> BufferedStream___::FlushAsyncInternal(CancellationToken cancellationToken) {
  return nullptr;
}

void BufferedStream___::FlushRead() {
}

void BufferedStream___::ClearReadBufferBeforeWrite() {
}

void BufferedStream___::FlushWrite() {
}

ValueTask<> BufferedStream___::FlushWriteAsync(CancellationToken cancellationToken) {
  return ValueTask<>();
}

Int32 BufferedStream___::ReadFromBuffer(Array<Byte> array, Int32 offset, Int32 count) {
  return Int32();
}

Int32 BufferedStream___::ReadFromBuffer(Span<Byte> destination) {
  return Int32();
}

Int32 BufferedStream___::ReadFromBuffer(Array<Byte> array, Int32 offset, Int32 count, Exception& error) {
  return Int32();
}

Int32 BufferedStream___::Read(Array<Byte> array, Int32 offset, Int32 count) {
  return Int32();
}

Int32 BufferedStream___::Read(Span<Byte> destination) {
  return Int32();
}

Task<Int32> BufferedStream___::LastSyncCompletedReadTask(Int32 val) {
  return nullptr;
}

Task<Int32> BufferedStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<Int32> BufferedStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

ValueTask<Int32> BufferedStream___::ReadFromUnderlyingStreamAsync(Memory<Byte> buffer, CancellationToken cancellationToken, Int32 bytesAlreadySatisfied, Task<> semaphoreLockTask) {
  return ValueTask<Int32>();
}

IAsyncResult BufferedStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

Int32 BufferedStream___::EndRead(IAsyncResult asyncResult) {
  return Int32();
}

Int32 BufferedStream___::ReadByte() {
  return Int32();
}

Int32 BufferedStream___::ReadByteSlow() {
  return Int32();
}

void BufferedStream___::WriteToBuffer(Array<Byte> array, Int32& offset, Int32& count) {
}

Int32 BufferedStream___::WriteToBuffer(ReadOnlySpan<Byte> buffer) {
  return Int32();
}

void BufferedStream___::Write(Array<Byte> array, Int32 offset, Int32 count) {
}

void BufferedStream___::Write(ReadOnlySpan<Byte> buffer) {
}

Task<> BufferedStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<> BufferedStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
}

ValueTask<> BufferedStream___::WriteToUnderlyingStreamAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken, Task<> semaphoreLockTask) {
  return ValueTask<>();
}

IAsyncResult BufferedStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

void BufferedStream___::EndWrite(IAsyncResult asyncResult) {
}

void BufferedStream___::WriteByte(Byte value) {
}

Int64 BufferedStream___::Seek(Int64 offset, SeekOrigin origin) {
  return Int64();
}

void BufferedStream___::SetLength(Int64 value) {
}

void BufferedStream___::CopyTo(Stream destination, Int32 bufferSize) {
}

Task<> BufferedStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> BufferedStream___::CopyToAsyncCore(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::IO::BufferedStreamNamespace
