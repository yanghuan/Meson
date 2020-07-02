#include "FileStream-dep.h"

#include <System.Private.CoreLib/System/IO/FileStream-dep.h>

namespace System::Private::CoreLib::System::IO::FileStreamNamespace {
Object FileStream___::AsyncCopyToAwaitable___::get_CancellationLock() {
  return nullptr;
};
Boolean FileStream___::AsyncCopyToAwaitable___::get_IsCompleted() {
  return Boolean();
};
void FileStream___::AsyncCopyToAwaitable___::ResetForNextOperation() {
  return void();
};
void FileStream___::AsyncCopyToAwaitable___::IOCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOVERLAP) {
  return void();
};
void FileStream___::AsyncCopyToAwaitable___::MarkCompleted() {
  return void();
};
FileStream::in::AsyncCopyToAwaitable FileStream___::AsyncCopyToAwaitable___::GetAwaiter() {
  return nullptr;
};
void FileStream___::AsyncCopyToAwaitable___::GetResult() {
  return void();
};
void FileStream___::AsyncCopyToAwaitable___::OnCompleted(Action<> continuation) {
  return void();
};
void FileStream___::AsyncCopyToAwaitable___::UnsafeOnCompleted(Action<> continuation) {
  return void();
};
NativeOverlapped* FileStream___::FileStreamCompletionSource___::get_Overlapped() {
  return nullptr;
};
void FileStream___::FileStreamCompletionSource___::SetCompletedSynchronously(Int32 numBytes) {
  return void();
};
void FileStream___::FileStreamCompletionSource___::RegisterForCancellation(CancellationToken cancellationToken) {
  return void();
};
void FileStream___::FileStreamCompletionSource___::ReleaseNativeResource() {
  return void();
};
void FileStream___::FileStreamCompletionSource___::IOCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOverlapped) {
  return void();
};
void FileStream___::FileStreamCompletionSource___::CompleteCallback(UInt64 packedResult) {
  return void();
};
void FileStream___::FileStreamCompletionSource___::Cancel(Object state) {
  return void();
};
FileStream::in::FileStreamCompletionSource FileStream___::FileStreamCompletionSource___::Create(FileStream stream, Int32 numBufferedBytesRead, ReadOnlyMemory<Byte> memory) {
  return nullptr;
};
void FileStream___::MemoryFileStreamCompletionSource___::ReleaseNativeResource() {
  return void();
};
IntPtr FileStream___::get_Handle() {
  return IntPtr();
};
Boolean FileStream___::get_CanRead() {
  return Boolean();
};
Boolean FileStream___::get_CanWrite() {
  return Boolean();
};
SafeFileHandle FileStream___::get_SafeFileHandle() {
  return nullptr;
};
String FileStream___::get_Name() {
  return nullptr;
};
Boolean FileStream___::get_IsAsync() {
  return Boolean();
};
Int64 FileStream___::get_Length() {
  return Int64();
};
Int64 FileStream___::get_Position() {
  return Int64();
};
void FileStream___::set_Position(Int64 value) {
  return void();
};
Boolean FileStream___::get_IsClosed() {
  return Boolean();
};
Boolean FileStream___::get_HasActiveBufferOperation() {
  return Boolean();
};
Boolean FileStream___::get_CanSeek() {
  return Boolean();
};
void FileStream___::ValidateAndInitFromHandle(SafeFileHandle handle, FileAccess access, Int32 bufferSize, Boolean isAsync) {
  return void();
};
void FileStream___::Lock(Int64 position, Int64 length) {
  return void();
};
void FileStream___::Unlock(Int64 position, Int64 length) {
  return void();
};
Task<> FileStream___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
};
Int32 FileStream___::Read(Array<Byte> array, Int32 offset, Int32 count) {
  return Int32();
};
Int32 FileStream___::Read(Span<Byte> buffer) {
  return Int32();
};
Task<Int32> FileStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<Int32> FileStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
};
Task<Int32> FileStream___::ReadAsyncTask(Array<Byte> array, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
void FileStream___::Write(Array<Byte> array, Int32 offset, Int32 count) {
  return void();
};
void FileStream___::Write(ReadOnlySpan<Byte> buffer) {
  return void();
};
Task<> FileStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<> FileStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
};
void FileStream___::Flush() {
  return void();
};
void FileStream___::Flush(Boolean flushToDisk) {
  return void();
};
void FileStream___::ValidateReadWriteArgs(Array<Byte> array, Int32 offset, Int32 count) {
  return void();
};
void FileStream___::SetLength(Int64 value) {
  return void();
};
void FileStream___::VerifyOSHandlePosition() {
  return void();
};
void FileStream___::PrepareForReading() {
  return void();
};
Boolean FileStream___::IsIoRelatedException(Exception e) {
  return Boolean();
};
Array<Byte> FileStream___::GetBuffer() {
  return Array<Byte>();
};
void FileStream___::OnBufferAllocated() {
  return void();
};
void FileStream___::FlushInternalBuffer() {
  return void();
};
void FileStream___::FlushReadBuffer() {
  return void();
};
Int32 FileStream___::ReadByte() {
  return Int32();
};
void FileStream___::WriteByte(Byte value) {
  return void();
};
void FileStream___::PrepareForWriting() {
  return void();
};
void FileStream___::Finalize() {
  return void();
};
IAsyncResult FileStream___::BeginRead(Array<Byte> array, Int32 offset, Int32 numBytes, AsyncCallback callback, Object state) {
  return nullptr;
};
IAsyncResult FileStream___::BeginWrite(Array<Byte> array, Int32 offset, Int32 numBytes, AsyncCallback callback, Object state) {
  return nullptr;
};
Int32 FileStream___::EndRead(IAsyncResult asyncResult) {
  return Int32();
};
void FileStream___::EndWrite(IAsyncResult asyncResult) {
  return void();
};
void FileStream___::Init(FileMode mode, FileShare share, String originalPath) {
  return void();
};
void FileStream___::InitFromHandle(SafeFileHandle handle, FileAccess access, Boolean useAsyncIO) {
  return void();
};
void FileStream___::InitFromHandleImpl(SafeFileHandle handle, FileAccess access, Boolean useAsyncIO) {
  return void();
};
Interop::Kernel32::SECURITY_ATTRIBUTES FileStream___::GetSecAttrs(FileShare share) {
  return Interop::Kernel32::SECURITY_ATTRIBUTES();
};
Int64 FileStream___::GetLengthInternal() {
  return Int64();
};
void FileStream___::Dispose(Boolean disposing) {
  return void();
};
ValueTask<> FileStream___::DisposeAsync() {
  return ValueTask<>();
};
ValueTask<> FileStream___::DisposeAsyncCore() {
  return ValueTask<>();
};
void FileStream___::FlushOSBuffer() {
  return void();
};
Task<> FileStream___::FlushWriteAsync(CancellationToken cancellationToken) {
  return nullptr;
};
void FileStream___::FlushWriteBufferForWriteByte() {
  return void();
};
void FileStream___::FlushWriteBuffer(Boolean calledFromFinalizer) {
  return void();
};
void FileStream___::SetLengthInternal(Int64 value) {
  return void();
};
void FileStream___::SetLengthCore(Int64 value) {
  return void();
};
FileStream::in::FileStreamCompletionSource FileStream___::CompareExchangeCurrentOverlappedOwner(FileStreamCompletionSource newSource, FileStreamCompletionSource existingSource) {
  return nullptr;
};
Int32 FileStream___::ReadSpan(Span<Byte> destination) {
  return Int32();
};
Int32 FileStream___::FillReadBufferForReadByte() {
  return Int32();
};
Int32 FileStream___::ReadNative(Span<Byte> buffer) {
  return Int32();
};
Int64 FileStream___::Seek(Int64 offset, SeekOrigin origin) {
  return Int64();
};
Int64 FileStream___::SeekCore(SafeFileHandle fileHandle, Int64 offset, SeekOrigin origin, Boolean closeInvalidHandle) {
  return Int64();
};
void FileStream___::WriteSpan(ReadOnlySpan<Byte> source) {
  return void();
};
void FileStream___::WriteCore(ReadOnlySpan<Byte> source) {
  return void();
};
Task<Int32> FileStream___::ReadAsyncInternal(Memory<Byte> destination, CancellationToken cancellationToken, Int32& synchronousResult) {
  return nullptr;
};
Task<Int32> FileStream___::ReadNativeAsync(Memory<Byte> destination, Int32 numBufferedBytesRead, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<> FileStream___::WriteAsyncInternal(ReadOnlyMemory<Byte> source, CancellationToken cancellationToken) {
  return ValueTask<>();
};
Task<> FileStream___::WriteAsyncInternalCore(ReadOnlyMemory<Byte> source, CancellationToken cancellationToken) {
  return nullptr;
};
Int32 FileStream___::ReadFileNative(SafeFileHandle handle, Span<Byte> bytes, NativeOverlapped* overlapped, Int32& errorCode) {
  return Int32();
};
Int32 FileStream___::WriteFileNative(SafeFileHandle handle, ReadOnlySpan<Byte> buffer, NativeOverlapped* overlapped, Int32& errorCode) {
  return Int32();
};
Int32 FileStream___::GetLastWin32ErrorAndDisposeHandleIfInvalid() {
  return Int32();
};
Task<> FileStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
};
Task<> FileStream___::AsyncModeCopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
};
Task<> FileStream___::FlushAsyncInternal(CancellationToken cancellationToken) {
  return nullptr;
};
void FileStream___::LockInternal(Int64 position, Int64 length) {
  return void();
};
void FileStream___::UnlockInternal(Int64 position, Int64 length) {
  return void();
};
SafeFileHandle FileStream___::ValidateFileHandle(SafeFileHandle fileHandle) {
  return nullptr;
};
SafeFileHandle FileStream___::OpenHandle(FileMode mode, FileShare share, FileOptions options) {
  return nullptr;
};
SafeFileHandle FileStream___::CreateFileOpenHandle(FileMode mode, FileShare share, FileOptions options) {
  return nullptr;
};
Boolean FileStream___::GetDefaultIsAsync(SafeFileHandle handle) {
  return Boolean();
};
Nullable<Boolean> FileStream___::IsHandleSynchronous(SafeFileHandle fileHandle, Boolean ignoreInvalid) {
  return Nullable<Boolean>();
};
void FileStream___::VerifyHandleIsSync(SafeFileHandle handle, Int32 fileType, FileAccess access) {
  return void();
};
} // namespace System::Private::CoreLib::System::IO::FileStreamNamespace
