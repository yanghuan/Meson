#include "Stream-dep.h"

#include <System.Private.CoreLib/System/IO/Stream-dep.h>

namespace System::Private::CoreLib::System::IO::StreamNamespace {
Boolean WriteCallbackStream___::get_CanRead() {
  return Boolean();
}

Boolean WriteCallbackStream___::get_CanSeek() {
  return Boolean();
}

Boolean WriteCallbackStream___::get_CanWrite() {
  return Boolean();
}

Int64 WriteCallbackStream___::get_Length() {
  return Int64();
}

Int64 WriteCallbackStream___::get_Position() {
  return Int64();
}

void WriteCallbackStream___::set_Position(Int64 value) {
}

void WriteCallbackStream___::Ctor(ReadOnlySpanAction<Byte, Object> action, Object state) {
}

void WriteCallbackStream___::Ctor(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> func, Object state) {
}

void WriteCallbackStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
}

void WriteCallbackStream___::Write(ReadOnlySpan<Byte> span) {
}

Task<> WriteCallbackStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 length, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<> WriteCallbackStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
}

void WriteCallbackStream___::Flush() {
}

Task<> WriteCallbackStream___::FlushAsync(CancellationToken token) {
  return nullptr;
}

Int32 WriteCallbackStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return Int32();
}

Int64 WriteCallbackStream___::Seek(Int64 offset, SeekOrigin origin) {
  return Int64();
}

void WriteCallbackStream___::SetLength(Int64 value) {
}

Boolean Stream___::ReadWriteTask___::get_InvokeMayRunArbitraryCodeOfITaskCompletionAction() {
  return Boolean();
}

void Stream___::ReadWriteTask___::ClearBeginState() {
}

void Stream___::ReadWriteTask___::Ctor(Boolean isRead, Boolean apm, Func<Object, Int32> function, Object state, Stream stream, Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback) {
}

void Stream___::ReadWriteTask___::InvokeAsyncCallback(Object completedTask) {
}

Boolean NullStream___::get_CanRead() {
  return Boolean();
}

Boolean NullStream___::get_CanWrite() {
  return Boolean();
}

Boolean NullStream___::get_CanSeek() {
  return Boolean();
}

Int64 NullStream___::get_Length() {
  return Int64();
}

Int64 NullStream___::get_Position() {
  return Int64();
}

void NullStream___::set_Position(Int64 value) {
}

void NullStream___::Ctor() {
}

void NullStream___::CopyTo(Stream destination, Int32 bufferSize) {
}

Task<> NullStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

void NullStream___::CopyTo(ReadOnlySpanAction<Byte, Object> callback, Object state, Int32 bufferSize) {
}

Task<> NullStream___::CopyToAsync(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> callback, Object state, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

void NullStream___::Dispose(Boolean disposing) {
}

void NullStream___::Flush() {
}

Task<> NullStream___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
}

IAsyncResult NullStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

Int32 NullStream___::EndRead(IAsyncResult asyncResult) {
  return Int32();
}

IAsyncResult NullStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

void NullStream___::EndWrite(IAsyncResult asyncResult) {
}

Int32 NullStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return Int32();
}

Int32 NullStream___::Read(Span<Byte> buffer) {
  return Int32();
}

Task<Int32> NullStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<Int32> NullStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

Int32 NullStream___::ReadByte() {
  return Int32();
}

void NullStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
}

void NullStream___::Write(ReadOnlySpan<Byte> buffer) {
}

Task<> NullStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<> NullStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
}

void NullStream___::WriteByte(Byte value) {
}

Int64 NullStream___::Seek(Int64 offset, SeekOrigin origin) {
  return Int64();
}

void NullStream___::SetLength(Int64 length) {
}

void NullStream___::SCtor() {
}

Boolean Stream___::SynchronousAsyncResult___::get_IsCompleted() {
  return Boolean();
}

WaitHandle Stream___::SynchronousAsyncResult___::get_AsyncWaitHandle() {
  return nullptr;
}

Object Stream___::SynchronousAsyncResult___::get_AsyncState() {
  return nullptr;
}

Boolean Stream___::SynchronousAsyncResult___::get_CompletedSynchronously() {
  return Boolean();
}

void Stream___::SynchronousAsyncResult___::Ctor(Int32 bytesRead, Object asyncStateObject) {
}

void Stream___::SynchronousAsyncResult___::Ctor(Object asyncStateObject) {
}

void Stream___::SynchronousAsyncResult___::Ctor(Exception ex, Object asyncStateObject, Boolean isWrite) {
}

void Stream___::SynchronousAsyncResult___::ThrowIfError() {
}

Int32 Stream___::SynchronousAsyncResult___::EndRead(IAsyncResult asyncResult) {
  return Int32();
}

void Stream___::SynchronousAsyncResult___::EndWrite(IAsyncResult asyncResult) {
}

Boolean SyncStream___::get_CanRead() {
  return Boolean();
}

Boolean SyncStream___::get_CanWrite() {
  return Boolean();
}

Boolean SyncStream___::get_CanSeek() {
  return Boolean();
}

Boolean SyncStream___::get_CanTimeout() {
  return Boolean();
}

Int64 SyncStream___::get_Length() {
  return Int64();
}

Int64 SyncStream___::get_Position() {
  return Int64();
}

void SyncStream___::set_Position(Int64 value) {
}

Int32 SyncStream___::get_ReadTimeout() {
  return Int32();
}

void SyncStream___::set_ReadTimeout(Int32 value) {
}

Int32 SyncStream___::get_WriteTimeout() {
  return Int32();
}

void SyncStream___::set_WriteTimeout(Int32 value) {
}

void SyncStream___::Ctor(Stream stream) {
}

void SyncStream___::Close() {
}

void SyncStream___::Dispose(Boolean disposing) {
}

ValueTask<> SyncStream___::DisposeAsync() {
  return ValueTask<>();
}

void SyncStream___::Flush() {
}

Int32 SyncStream___::Read(Array<Byte> bytes, Int32 offset, Int32 count) {
  return Int32();
}

Int32 SyncStream___::Read(Span<Byte> buffer) {
  return Int32();
}

Int32 SyncStream___::ReadByte() {
  return Int32();
}

IAsyncResult SyncStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

Int32 SyncStream___::EndRead(IAsyncResult asyncResult) {
  return Int32();
}

Int64 SyncStream___::Seek(Int64 offset, SeekOrigin origin) {
  return Int64();
}

void SyncStream___::SetLength(Int64 length) {
}

void SyncStream___::Write(Array<Byte> bytes, Int32 offset, Int32 count) {
}

void SyncStream___::Write(ReadOnlySpan<Byte> buffer) {
}

void SyncStream___::WriteByte(Byte b) {
}

IAsyncResult SyncStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

void SyncStream___::EndWrite(IAsyncResult asyncResult) {
}

Boolean Stream___::get_CanTimeout() {
  return Boolean();
}

Int32 Stream___::get_ReadTimeout() {
  return Int32();
}

void Stream___::set_ReadTimeout(Int32 value) {
}

Int32 Stream___::get_WriteTimeout() {
  return Int32();
}

void Stream___::set_WriteTimeout(Int32 value) {
}

SemaphoreSlim Stream___::EnsureAsyncActiveSemaphoreInitialized() {
  return nullptr;
}

Task<> Stream___::CopyToAsync(Stream destination) {
  return nullptr;
}

Task<> Stream___::CopyToAsync(Stream destination, Int32 bufferSize) {
  return nullptr;
}

Task<> Stream___::CopyToAsync(Stream destination, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> Stream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> Stream___::CopyToAsyncInternal(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

void Stream___::CopyTo(Stream destination) {
}

void Stream___::CopyTo(Stream destination, Int32 bufferSize) {
}

Int32 Stream___::GetCopyBufferSize() {
  return Int32();
}

void Stream___::CopyTo(ReadOnlySpanAction<Byte, Object> callback, Object state, Int32 bufferSize) {
}

Task<> Stream___::CopyToAsync(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> callback, Object state, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

void Stream___::Close() {
}

void Stream___::Dispose() {
}

void Stream___::Dispose(Boolean disposing) {
}

ValueTask<> Stream___::DisposeAsync() {
  return ValueTask<>();
}

Task<> Stream___::FlushAsync() {
  return nullptr;
}

Task<> Stream___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
}

WaitHandle Stream___::CreateWaitHandle() {
  return nullptr;
}

IAsyncResult Stream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

IAsyncResult Stream___::BeginReadInternal(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state, Boolean serializeAsynchronously, Boolean apm) {
  return nullptr;
}

Int32 Stream___::EndRead(IAsyncResult asyncResult) {
  return Int32();
}

Task<Int32> Stream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  return nullptr;
}

Task<Int32> Stream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<Int32> Stream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

Task<Int32> Stream___::BeginEndReadAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  return nullptr;
}

IAsyncResult Stream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

IAsyncResult Stream___::BeginWriteInternal(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state, Boolean serializeAsynchronously, Boolean apm) {
  return nullptr;
}

void Stream___::RunReadWriteTaskWhenReady(Task<> asyncWaiter, ReadWriteTask readWriteTask) {
}

void Stream___::RunReadWriteTask(ReadWriteTask readWriteTask) {
}

void Stream___::FinishTrackingAsyncOperation(ReadWriteTask task) {
}

void Stream___::EndWrite(IAsyncResult asyncResult) {
}

Task<> Stream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  return nullptr;
}

Task<> Stream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<> Stream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
}

Task<> Stream___::FinishWriteAsync(Task<> writeTask, Array<Byte> localBuffer) {
  return nullptr;
}

Task<> Stream___::BeginEndWriteAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  return nullptr;
}

Int32 Stream___::Read(Span<Byte> buffer) {
  return Int32();
}

Int32 Stream___::ReadByte() {
  return Int32();
}

void Stream___::Write(ReadOnlySpan<Byte> buffer) {
}

void Stream___::WriteByte(Byte value) {
}

Stream Stream___::Synchronized(Stream stream) {
  return nullptr;
}

void Stream___::ObjectInvariant() {
}

IAsyncResult Stream___::BlockingBeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

Int32 Stream___::BlockingEndRead(IAsyncResult asyncResult) {
  return Int32();
}

IAsyncResult Stream___::BlockingBeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return nullptr;
}

void Stream___::BlockingEndWrite(IAsyncResult asyncResult) {
}

void Stream___::Ctor() {
}

void Stream___::SCtor() {
}

} // namespace System::Private::CoreLib::System::IO::StreamNamespace
