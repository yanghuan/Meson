#include "FileStream-dep.h"

#include <System.Private.CoreLib/System/IO/FileStream-dep.h>

namespace System::Private::CoreLib::System::IO::FileStreamNamespace {
NativeOverlapped* FileStream___::FileStreamCompletionSource___::get_Overlapped() {
  return nullptr;
}

void FileStream___::FileStreamCompletionSource___::ctor(FileStream stream, Int32 numBufferedBytes, Array<Byte> bytes) {
}

void FileStream___::FileStreamCompletionSource___::SetCompletedSynchronously(Int32 numBytes) {
}

void FileStream___::FileStreamCompletionSource___::RegisterForCancellation(CancellationToken cancellationToken) {
}

void FileStream___::FileStreamCompletionSource___::ReleaseNativeResource() {
}

void FileStream___::FileStreamCompletionSource___::IOCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOverlapped) {
}

void FileStream___::FileStreamCompletionSource___::CompleteCallback(UInt64 packedResult) {
}

void FileStream___::FileStreamCompletionSource___::Cancel(Object state) {
}

FileStream::in::FileStreamCompletionSource FileStream___::FileStreamCompletionSource___::Create(FileStream stream, Int32 numBufferedBytesRead, ReadOnlyMemory<Byte> memory) {
  return nullptr;
}

Object FileStream___::AsyncCopyToAwaitable___::get_CancellationLock() {
  return nullptr;
}

Boolean FileStream___::AsyncCopyToAwaitable___::get_IsCompleted() {
  return Boolean();
}

void FileStream___::AsyncCopyToAwaitable___::ctor(FileStream fileStream) {
}

void FileStream___::AsyncCopyToAwaitable___::ResetForNextOperation() {
}

void FileStream___::AsyncCopyToAwaitable___::IOCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOVERLAP) {
}

void FileStream___::AsyncCopyToAwaitable___::MarkCompleted() {
}

FileStream::in::AsyncCopyToAwaitable FileStream___::AsyncCopyToAwaitable___::GetAwaiter() {
  return nullptr;
}

void FileStream___::AsyncCopyToAwaitable___::GetResult() {
}

void FileStream___::AsyncCopyToAwaitable___::OnCompleted(Action<> continuation) {
}

void FileStream___::AsyncCopyToAwaitable___::UnsafeOnCompleted(Action<> continuation) {
}

void FileStream___::AsyncCopyToAwaitable___::ctor_static() {
}

void FileStream___::MemoryFileStreamCompletionSource___::ctor(FileStream stream, Int32 numBufferedBytes, ReadOnlyMemory<Byte> memory) {
}

void FileStream___::MemoryFileStreamCompletionSource___::ReleaseNativeResource() {
}

IntPtr FileStream___::get_Handle() {
  return IntPtr();
}

Boolean FileStream___::get_CanRead() {
  return Boolean();
}

Boolean FileStream___::get_CanWrite() {
  return Boolean();
}

SafeFileHandle FileStream___::get_SafeFileHandle() {
  return nullptr;
}

String FileStream___::get_Name() {
  return nullptr;
}

Boolean FileStream___::get_IsAsync() {
  return Boolean();
}

Int64 FileStream___::get_Length() {
  return Int64();
}

Int64 FileStream___::get_Position() {
  return Int64();
}

void FileStream___::set_Position(Int64 value) {
}

Boolean FileStream___::get_IsClosed() {
  return Boolean();
}

Boolean FileStream___::get_HasActiveBufferOperation() {
  return Boolean();
}

Boolean FileStream___::get_CanSeek() {
  return Boolean();
}

void FileStream___::ctor(IntPtr handle, FileAccess access) {
}

void FileStream___::ctor(IntPtr handle, FileAccess access, Boolean ownsHandle) {
}

void FileStream___::ctor(IntPtr handle, FileAccess access, Boolean ownsHandle, Int32 bufferSize) {
}

void FileStream___::ctor(IntPtr handle, FileAccess access, Boolean ownsHandle, Int32 bufferSize, Boolean isAsync) {
}

void FileStream___::ctor(SafeFileHandle handle, FileAccess access) {
}

void FileStream___::ctor(SafeFileHandle handle, FileAccess access, Int32 bufferSize) {
}

void FileStream___::ValidateAndInitFromHandle(SafeFileHandle handle, FileAccess access, Int32 bufferSize, Boolean isAsync) {
}

void FileStream___::ctor(SafeFileHandle handle, FileAccess access, Int32 bufferSize, Boolean isAsync) {
}

void FileStream___::ctor(String path, FileMode mode) {
}

void FileStream___::ctor(String path, FileMode mode, FileAccess access) {
}

void FileStream___::ctor(String path, FileMode mode, FileAccess access, FileShare share) {
}

void FileStream___::ctor(String path, FileMode mode, FileAccess access, FileShare share, Int32 bufferSize) {
}

void FileStream___::ctor(String path, FileMode mode, FileAccess access, FileShare share, Int32 bufferSize, Boolean useAsync) {
}

void FileStream___::ctor(String path, FileMode mode, FileAccess access, FileShare share, Int32 bufferSize, FileOptions options) {
}

void FileStream___::Lock(Int64 position, Int64 length) {
}

void FileStream___::Unlock(Int64 position, Int64 length) {
}

Task<> FileStream___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
}

Int32 FileStream___::Read(Array<Byte> array, Int32 offset, Int32 count) {
  return Int32();
}

Int32 FileStream___::Read(Span<Byte> buffer) {
  return Int32();
}

Task<Int32> FileStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<Int32> FileStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

Task<Int32> FileStream___::ReadAsyncTask(Array<Byte> array, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

void FileStream___::Write(Array<Byte> array, Int32 offset, Int32 count) {
}

void FileStream___::Write(ReadOnlySpan<Byte> buffer) {
}

Task<> FileStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<> FileStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
}

void FileStream___::Flush() {
}

void FileStream___::Flush(Boolean flushToDisk) {
}

void FileStream___::ValidateReadWriteArgs(Array<Byte> array, Int32 offset, Int32 count) {
}

void FileStream___::SetLength(Int64 value) {
}

void FileStream___::VerifyOSHandlePosition() {
}

void FileStream___::PrepareForReading() {
}

Boolean FileStream___::IsIoRelatedException(Exception e) {
  return Boolean();
}

Array<Byte> FileStream___::GetBuffer() {
  return Array<Byte>();
}

void FileStream___::OnBufferAllocated() {
}

void FileStream___::FlushInternalBuffer() {
}

void FileStream___::FlushReadBuffer() {
}

Int32 FileStream___::ReadByte() {
  return Int32();
}

void FileStream___::WriteByte(Byte value) {
}

void FileStream___::PrepareForWriting() {
}

void FileStream___::Finalize() {
}

IAsyncResult FileStream___::BeginRead(Array<Byte> array, Int32 offset, Int32 numBytes, AsyncCallback callback, Object state) {
  return nullptr;
}

IAsyncResult FileStream___::BeginWrite(Array<Byte> array, Int32 offset, Int32 numBytes, AsyncCallback callback, Object state) {
  return nullptr;
}

Int32 FileStream___::EndRead(IAsyncResult asyncResult) {
  return Int32();
}

void FileStream___::EndWrite(IAsyncResult asyncResult) {
}

void FileStream___::Init(FileMode mode, FileShare share, String originalPath) {
}

void FileStream___::InitFromHandle(SafeFileHandle handle, FileAccess access, Boolean useAsyncIO) {
}

void FileStream___::InitFromHandleImpl(SafeFileHandle handle, Boolean useAsyncIO) {
}

Interop::Kernel32::SECURITY_ATTRIBUTES FileStream___::GetSecAttrs(FileShare share) {
  return Interop::Kernel32::SECURITY_ATTRIBUTES();
}

Int64 FileStream___::GetLengthInternal() {
  return Int64();
}

void FileStream___::Dispose(Boolean disposing) {
}

ValueTask<> FileStream___::DisposeAsync() {
  return ValueTask<>();
}

ValueTask<> FileStream___::DisposeAsyncCore() {
  return ValueTask<>();
}

void FileStream___::FlushOSBuffer() {
}

Task<> FileStream___::FlushWriteAsync(CancellationToken cancellationToken) {
  return nullptr;
}

void FileStream___::FlushWriteBufferForWriteByte() {
}

void FileStream___::FlushWriteBuffer(Boolean calledFromFinalizer) {
}

void FileStream___::SetLengthInternal(Int64 value) {
}

void FileStream___::SetLengthCore(Int64 value) {
}

FileStream::in::FileStreamCompletionSource FileStream___::CompareExchangeCurrentOverlappedOwner(FileStreamCompletionSource newSource, FileStreamCompletionSource existingSource) {
  return nullptr;
}

Int32 FileStream___::ReadSpan(Span<Byte> destination) {
  return Int32();
}

Int32 FileStream___::FillReadBufferForReadByte() {
  return Int32();
}

Int32 FileStream___::ReadNative(Span<Byte> buffer) {
  return Int32();
}

Int64 FileStream___::Seek(Int64 offset, SeekOrigin origin) {
  return Int64();
}

Int64 FileStream___::SeekCore(SafeFileHandle fileHandle, Int64 offset, SeekOrigin origin, Boolean closeInvalidHandle) {
  return Int64();
}

void FileStream___::WriteSpan(ReadOnlySpan<Byte> source) {
}

void FileStream___::WriteCore(ReadOnlySpan<Byte> source) {
}

Task<Int32> FileStream___::ReadAsyncInternal(Memory<Byte> destination, CancellationToken cancellationToken, Int32& synchronousResult) {
  return nullptr;
}

Task<Int32> FileStream___::ReadNativeAsync(Memory<Byte> destination, Int32 numBufferedBytesRead, CancellationToken cancellationToken) {
  return nullptr;
}

ValueTask<> FileStream___::WriteAsyncInternal(ReadOnlyMemory<Byte> source, CancellationToken cancellationToken) {
  return ValueTask<>();
}

Task<> FileStream___::WriteAsyncInternalCore(ReadOnlyMemory<Byte> source, CancellationToken cancellationToken) {
  return nullptr;
}

Int32 FileStream___::ReadFileNative(SafeFileHandle handle, Span<Byte> bytes, NativeOverlapped* overlapped, Int32& errorCode) {
  return Int32();
}

Int32 FileStream___::WriteFileNative(SafeFileHandle handle, ReadOnlySpan<Byte> buffer, NativeOverlapped* overlapped, Int32& errorCode) {
  return Int32();
}

Int32 FileStream___::GetLastWin32ErrorAndDisposeHandleIfInvalid() {
  return Int32();
}

Task<> FileStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> FileStream___::AsyncModeCopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> FileStream___::FlushAsyncInternal(CancellationToken cancellationToken) {
  return nullptr;
}

void FileStream___::LockInternal(Int64 position, Int64 length) {
}

void FileStream___::UnlockInternal(Int64 position, Int64 length) {
}

SafeFileHandle FileStream___::ValidateFileHandle(SafeFileHandle fileHandle) {
  return nullptr;
}

SafeFileHandle FileStream___::OpenHandle(FileMode mode, FileShare share, FileOptions options) {
  return nullptr;
}

SafeFileHandle FileStream___::CreateFileOpenHandle(FileMode mode, FileShare share, FileOptions options) {
  return nullptr;
}

Boolean FileStream___::GetDefaultIsAsync(SafeFileHandle handle) {
  return Boolean();
}

Nullable<Boolean> FileStream___::IsHandleSynchronous(SafeFileHandle fileHandle, Boolean ignoreInvalid) {
  return Nullable<Boolean>();
}

void FileStream___::VerifyHandleIsSync(SafeFileHandle handle) {
}

void FileStream___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::IO::FileStreamNamespace
