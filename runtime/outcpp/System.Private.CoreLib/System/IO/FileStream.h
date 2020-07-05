#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Buffers/MemoryHandle.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Byte)
FORWARD(Exception)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARDS(Memory, T)
FORWARDS_(Nullable, T1, T2)
FORWARD(Object)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD(IOCompletionCallback)
FORWARDS(NativeOverlapped)
FORWARD(PreAllocatedOverlapped)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeFileHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
enum class FileAccess;
enum class FileMode;
enum class FileOptions;
enum class FileShare;
enum class SeekOrigin;
FORWARD(Stream)
namespace FileStreamNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
using namespace Buffers;
using namespace Threading;
using namespace Threading::Tasks;
CLASS(FileStream) {
  private: CLASS(AsyncCopyToAwaitable) {
    public: Object get_CancellationLock();
    public: Boolean get_IsCompleted();
    public: void ResetForNextOperation();
    public: static void IOCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOVERLAP);
    public: void MarkCompleted();
    public: AsyncCopyToAwaitable GetAwaiter();
    public: void GetResult();
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    private: static Action<> s_sentinel;
    public: static IOCompletionCallback s_callback;
    public: FileStream _fileStream;
    public: Int64 _position;
    public: NativeOverlapped* _nativeOverlapped;
    public: Action<> _continuation;
    public: UInt32 _errorCode;
    public: UInt32 _numBytes;
  };
  private: CLASS(FileStreamCompletionSource) {
    public: NativeOverlapped* get_Overlapped();
    public: void SetCompletedSynchronously(Int32 numBytes);
    public: void RegisterForCancellation(CancellationToken cancellationToken);
    public: void ReleaseNativeResource();
    public: static void IOCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOverlapped);
    private: void CompleteCallback(UInt64 packedResult);
    private: static void Cancel(Object state);
    public: static FileStreamCompletionSource Create(FileStream stream, Int32 numBufferedBytesRead, ReadOnlyMemory<Byte> memory);
    private: static Action<Object> s_cancelCallback;
    private: FileStream _stream;
    private: Int32 _numBufferedBytes;
    private: CancellationTokenRegistration _cancellationRegistration;
    private: NativeOverlapped* _overlapped;
    private: Int64 _result;
  };
  private: CLASS(MemoryFileStreamCompletionSource) {
    public: void ReleaseNativeResource();
    private: MemoryHandle _handle;
  };
  public: IntPtr get_Handle();
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: SafeFileHandle get_SafeFileHandle();
  public: String get_Name();
  public: Boolean get_IsAsync();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: Boolean get_IsClosed();
  private: Boolean get_HasActiveBufferOperation();
  public: Boolean get_CanSeek();
  private: void ValidateAndInitFromHandle(SafeFileHandle handle, FileAccess access, Int32 bufferSize, Boolean isAsync);
  public: void Lock(Int64 position, Int64 length);
  public: void Unlock(Int64 position, Int64 length);
  public: Task<> FlushAsync(CancellationToken cancellationToken);
  public: Int32 Read(Array<Byte> array, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<Int32> ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken);
  private: Task<Int32> ReadAsyncTask(Array<Byte> array, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: void Write(Array<Byte> array, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken);
  public: void Flush();
  public: void Flush(Boolean flushToDisk);
  private: void ValidateReadWriteArgs(Array<Byte> array, Int32 offset, Int32 count);
  public: void SetLength(Int64 value);
  private: void VerifyOSHandlePosition();
  private: void PrepareForReading();
  private: static Boolean IsIoRelatedException(Exception e);
  private: Array<Byte> GetBuffer();
  private: void OnBufferAllocated();
  private: void FlushInternalBuffer();
  private: void FlushReadBuffer();
  public: Int32 ReadByte();
  public: void WriteByte(Byte value);
  private: void PrepareForWriting();
  protected: void Finalize();
  public: IAsyncResult BeginRead(Array<Byte> array, Int32 offset, Int32 numBytes, AsyncCallback callback, Object state);
  public: IAsyncResult BeginWrite(Array<Byte> array, Int32 offset, Int32 numBytes, AsyncCallback callback, Object state);
  public: Int32 EndRead(IAsyncResult asyncResult);
  public: void EndWrite(IAsyncResult asyncResult);
  private: void Init(FileMode mode, FileShare share, String originalPath);
  private: void InitFromHandle(SafeFileHandle handle, FileAccess access, Boolean useAsyncIO);
  private: void InitFromHandleImpl(SafeFileHandle handle, Boolean useAsyncIO);
  private: static Interop::Kernel32::SECURITY_ATTRIBUTES GetSecAttrs(FileShare share);
  private: Int64 GetLengthInternal();
  protected: void Dispose(Boolean disposing);
  public: ValueTask<> DisposeAsync();
  private: ValueTask<> DisposeAsyncCore();
  private: void FlushOSBuffer();
  private: Task<> FlushWriteAsync(CancellationToken cancellationToken);
  private: void FlushWriteBufferForWriteByte();
  private: void FlushWriteBuffer(Boolean calledFromFinalizer);
  private: void SetLengthInternal(Int64 value);
  private: void SetLengthCore(Int64 value);
  private: FileStreamCompletionSource CompareExchangeCurrentOverlappedOwner(FileStreamCompletionSource newSource, FileStreamCompletionSource existingSource);
  private: Int32 ReadSpan(Span<Byte> destination);
  private: Int32 FillReadBufferForReadByte();
  private: Int32 ReadNative(Span<Byte> buffer);
  public: Int64 Seek(Int64 offset, SeekOrigin origin);
  private: Int64 SeekCore(SafeFileHandle fileHandle, Int64 offset, SeekOrigin origin, Boolean closeInvalidHandle);
  private: void WriteSpan(ReadOnlySpan<Byte> source);
  private: void WriteCore(ReadOnlySpan<Byte> source);
  private: Task<Int32> ReadAsyncInternal(Memory<Byte> destination, CancellationToken cancellationToken, Int32& synchronousResult);
  private: Task<Int32> ReadNativeAsync(Memory<Byte> destination, Int32 numBufferedBytesRead, CancellationToken cancellationToken);
  private: ValueTask<> WriteAsyncInternal(ReadOnlyMemory<Byte> source, CancellationToken cancellationToken);
  private: Task<> WriteAsyncInternalCore(ReadOnlyMemory<Byte> source, CancellationToken cancellationToken);
  private: Int32 ReadFileNative(SafeFileHandle handle, Span<Byte> bytes, NativeOverlapped* overlapped, Int32& errorCode);
  private: Int32 WriteFileNative(SafeFileHandle handle, ReadOnlySpan<Byte> buffer, NativeOverlapped* overlapped, Int32& errorCode);
  private: Int32 GetLastWin32ErrorAndDisposeHandleIfInvalid();
  public: Task<> CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  private: Task<> AsyncModeCopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  private: Task<> FlushAsyncInternal(CancellationToken cancellationToken);
  private: void LockInternal(Int64 position, Int64 length);
  private: void UnlockInternal(Int64 position, Int64 length);
  private: SafeFileHandle ValidateFileHandle(SafeFileHandle fileHandle);
  private: SafeFileHandle OpenHandle(FileMode mode, FileShare share, FileOptions options);
  private: SafeFileHandle CreateFileOpenHandle(FileMode mode, FileShare share, FileOptions options);
  private: static Boolean GetDefaultIsAsync(SafeFileHandle handle);
  private: static Nullable<Boolean> IsHandleSynchronous(SafeFileHandle fileHandle, Boolean ignoreInvalid);
  private: static void VerifyHandleIsSync(SafeFileHandle handle);
  private: Array<Byte> _buffer;
  private: Int32 _bufferLength;
  private: SafeFileHandle _fileHandle;
  private: FileAccess _access;
  private: String _path;
  private: Int32 _readPos;
  private: Int32 _readLength;
  private: Int32 _writePos;
  private: Boolean _useAsyncIO;
  private: Task<Int32> _lastSynchronouslyCompletedTask;
  private: Int64 _filePosition;
  private: Boolean _exposedHandle;
  private: static Int32 s_cachedSerializationSwitch;
  private: Boolean _canSeek;
  private: Boolean _isPipe;
  private: Int64 _appendStart;
  private: static IOCompletionCallback s_ioCallback;
  private: Task<> _activeBufferOperation;
  private: PreAllocatedOverlapped _preallocatedOverlapped;
  private: FileStreamCompletionSource _currentOverlappedOwner;
};
} // namespace FileStreamNamespace
using FileStream = FileStreamNamespace::FileStream;
} // namespace System::Private::CoreLib::System::IO
