#include "FileStream-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ArraySegment-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IO/DisableMediaInsertionPrompt-dep.h>
#include <System.Private.CoreLib/System/IO/Error-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/IO/FileStream-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/IO/PathInternal-dep.h>
#include <System.Private.CoreLib/System/IO/SeekOrigin.h>
#include <System.Private.CoreLib/System/IO/StreamHelpers-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationInfo-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/PreAllocatedOverlapped-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskToApm-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolBoundHandle-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UnauthorizedAccessException-dep.h>

namespace System::Private::CoreLib::System::IO::FileStreamNamespace {
using namespace System::Buffers;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Serialization;
using namespace System::Threading;
using namespace System::Threading::Tasks;

NativeOverlapped* FileStream___::FileStreamCompletionSource___::get_Overlapped() {
  return _overlapped;
}

void FileStream___::FileStreamCompletionSource___::ctor(FileStream stream, Int32 numBufferedBytes, Array<Byte> bytes) {
  _numBufferedBytes = numBufferedBytes;
  _stream = stream;
  _result = 0;
  _overlapped = ((bytes != nullptr && _stream->CompareExchangeCurrentOverlappedOwner((FileStreamCompletionSource)this, nullptr) == nullptr) ? _stream->_fileHandle->get_ThreadPoolBinding()->AllocateNativeOverlapped(_stream->_preallocatedOverlapped) : _stream->_fileHandle->get_ThreadPoolBinding()->AllocateNativeOverlapped(s_ioCallback, (FileStreamCompletionSource)this, bytes));
}

void FileStream___::FileStreamCompletionSource___::SetCompletedSynchronously(Int32 numBytes) {
  ReleaseNativeResource();
  TrySetResult(numBytes + _numBufferedBytes);
}

void FileStream___::FileStreamCompletionSource___::RegisterForCancellation(CancellationToken cancellationToken) {
  if (_overlapped != nullptr) {
    Action<Object> callback = Cancel;
    Int64 num = Interlocked::CompareExchange(_result, 17179869184, 0);
    switch (num.get()) {
      case 0:
        _cancellationRegistration = cancellationToken.UnsafeRegister(callback, (FileStreamCompletionSource)this);
        num = Interlocked::Exchange(_result, 0);
        break;
      default:
        num = Interlocked::Exchange(_result, 0);
        break;
      case 34359738368:
        break;
    }
    if (num != 0 && num != 34359738368 && num != 17179869184) {
      CompleteCallback((UInt64)num);
    }
  }
}

void FileStream___::FileStreamCompletionSource___::ReleaseNativeResource() {
  _cancellationRegistration.Dispose();
  if (_overlapped != nullptr) {
    _stream->_fileHandle->get_ThreadPoolBinding()->FreeNativeOverlapped(_overlapped);
    _overlapped = nullptr;
  }
  _stream->CompareExchangeCurrentOverlappedOwner(nullptr, (FileStreamCompletionSource)this);
}

void FileStream___::FileStreamCompletionSource___::IOCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOverlapped) {
  Object nativeOverlappedState = ThreadPoolBoundHandle::in::GetNativeOverlappedState(pOverlapped);
  FileStream fileStream = rt::as<FileStream>(nativeOverlappedState);
  FileStreamCompletionSource fileStreamCompletionSource = (fileStream != nullptr) ? fileStream->_currentOverlappedOwner : ((FileStreamCompletionSource)nativeOverlappedState);
  UInt64 num = (errorCode == 0 || errorCode == 109 || errorCode == 232) ? (4294967296 | (UInt64)numBytes) : (8589934592 | (UInt64)errorCode);
  if (Interlocked::Exchange(fileStreamCompletionSource->_result, (Int64)num) == 0 && Interlocked::Exchange(fileStreamCompletionSource->_result, 34359738368) != 0) {
    fileStreamCompletionSource->CompleteCallback(num);
  }
}

void FileStream___::FileStreamCompletionSource___::CompleteCallback(UInt64 packedResult) {
  CancellationToken token = _cancellationRegistration.get_Token();
  ReleaseNativeResource();
  Int64 num = (Int64)packedResult & -4294967296;
  if (num == 8589934592) {
    Int32 num2 = (Int32)(packedResult & UInt32::MaxValue);
    if (num2 == 995) {
      TrySetCanceled(token.get_IsCancellationRequested() ? token : CancellationToken(true));
      return;
    }
    Exception exceptionForWin32Error = Win32Marshal::GetExceptionForWin32Error(num2);
    exceptionForWin32Error->SetCurrentStackTrace();
    TrySetException(exceptionForWin32Error);
  } else {
    TrySetResult((Int32)(packedResult & UInt32::MaxValue) + _numBufferedBytes);
  }
}

void FileStream___::FileStreamCompletionSource___::Cancel(Object state) {
  FileStreamCompletionSource fileStreamCompletionSource = (FileStreamCompletionSource)state;
  if (!fileStreamCompletionSource->_stream->_fileHandle->get_IsInvalid() && !Interop::Kernel32::CancelIoEx(fileStreamCompletionSource->_stream->_fileHandle, fileStreamCompletionSource->_overlapped)) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    if (lastWin32Error != 1168) {
      rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error));
    }
  }
}

FileStream::in::FileStreamCompletionSource FileStream___::FileStreamCompletionSource___::Create(FileStream stream, Int32 numBufferedBytesRead, ReadOnlyMemory<Byte> memory) {
  ArraySegment<Byte> segment;
  if (!MemoryMarshal::TryGetArray(memory, segment) || segment.get_Array() != stream->_buffer) {
    return rt::newobj<MemoryFileStreamCompletionSource>(stream, numBufferedBytesRead, memory);
  }
  return rt::newobj<FileStreamCompletionSource>(stream, numBufferedBytesRead, segment.get_Array());
}

Object FileStream___::AsyncCopyToAwaitable___::get_CancellationLock() {
  return (AsyncCopyToAwaitable)this;
}

Boolean FileStream___::AsyncCopyToAwaitable___::get_IsCompleted() {
  return (Object)_continuation == s_sentinel;
}

void FileStream___::AsyncCopyToAwaitable___::ctor(FileStream fileStream) {
  _fileStream = fileStream;
}

void FileStream___::AsyncCopyToAwaitable___::ResetForNextOperation() {
  _continuation = nullptr;
  _errorCode = 0u;
  _numBytes = 0u;
}

void FileStream___::AsyncCopyToAwaitable___::IOCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pOVERLAP) {
  AsyncCopyToAwaitable asyncCopyToAwaitable = (AsyncCopyToAwaitable)ThreadPoolBoundHandle::in::GetNativeOverlappedState(pOVERLAP);
  asyncCopyToAwaitable->_errorCode = errorCode;
  asyncCopyToAwaitable->_numBytes = numBytes;
  auto& default = asyncCopyToAwaitable->_continuation;
  auto& extern = (default != nullptr ? default : Interlocked::CompareExchange(asyncCopyToAwaitable->_continuation, s_sentinel, nullptr));
  extern == nullptr ? nullptr : extern->Invoke();
}

void FileStream___::AsyncCopyToAwaitable___::MarkCompleted() {
  _continuation = s_sentinel;
}

FileStream::in::AsyncCopyToAwaitable FileStream___::AsyncCopyToAwaitable___::GetAwaiter() {
  return (AsyncCopyToAwaitable)this;
}

void FileStream___::AsyncCopyToAwaitable___::GetResult() {
}

void FileStream___::AsyncCopyToAwaitable___::OnCompleted(Action<> continuation) {
  UnsafeOnCompleted(continuation);
}

void FileStream___::AsyncCopyToAwaitable___::UnsafeOnCompleted(Action<> continuation) {
  if ((Object)_continuation == s_sentinel || Interlocked::CompareExchange(_continuation, continuation, nullptr) != nullptr) {
    Task::in::Run(continuation);
  }
}

void FileStream___::AsyncCopyToAwaitable___::cctor() {
}

void FileStream___::MemoryFileStreamCompletionSource___::ctor(FileStream stream, Int32 numBufferedBytes, ReadOnlyMemory<Byte> memory) {
  _handle = memory.Pin();
}

void FileStream___::MemoryFileStreamCompletionSource___::ReleaseNativeResource() {
  _handle.Dispose();
  FileStreamCompletionSource::ReleaseNativeResource();
}

IntPtr FileStream___::get_Handle() {
  return get_SafeFileHandle()->DangerousGetHandle();
}

Boolean FileStream___::get_CanRead() {
  if (!_fileHandle->get_IsClosed()) {
    return (_access & FileAccess::Read) != 0;
  }
  return false;
}

Boolean FileStream___::get_CanWrite() {
  if (!_fileHandle->get_IsClosed()) {
    return (_access & FileAccess::Write) != 0;
  }
  return false;
}

SafeFileHandle FileStream___::get_SafeFileHandle() {
  Flush();
  _exposedHandle = true;
  return _fileHandle;
}

String FileStream___::get_Name() {
  auto& default = _path;
  return default != nullptr ? default : SR::get_IO_UnknownFileName();
}

Boolean FileStream___::get_IsAsync() {
  return _useAsyncIO;
}

Int64 FileStream___::get_Length() {
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (!get_CanSeek()) {
    rt::throw_exception(Error::GetSeekNotSupported());
  }
  return GetLengthInternal();
}

Int64 FileStream___::get_Position() {
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (!get_CanSeek()) {
    rt::throw_exception(Error::GetSeekNotSupported());
  }
  VerifyOSHandlePosition();
  return _filePosition - _readLength + _readPos + _writePos;
}

void FileStream___::set_Position(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Seek(value, SeekOrigin::Begin);
}

Boolean FileStream___::get_IsClosed() {
  return _fileHandle->get_IsClosed();
}

Boolean FileStream___::get_HasActiveBufferOperation() {
  return !_activeBufferOperation->get_IsCompleted();
}

Boolean FileStream___::get_CanSeek() {
  return _canSeek;
}

void FileStream___::ctor(IntPtr handle, FileAccess access) {
}

void FileStream___::ctor(IntPtr handle, FileAccess access, Boolean ownsHandle) {
}

void FileStream___::ctor(IntPtr handle, FileAccess access, Boolean ownsHandle, Int32 bufferSize) {
}

void FileStream___::ctor(IntPtr handle, FileAccess access, Boolean ownsHandle, Int32 bufferSize, Boolean isAsync) {
  _activeBufferOperation = Task::in::get_CompletedTask();
  Stream::ctor();
  SafeFileHandle safeFileHandle = rt::newobj<SafeFileHandle>(handle, ownsHandle);
  try{
    ValidateAndInitFromHandle(safeFileHandle, access, bufferSize, isAsync);
  } catch (...) {
  }
  _access = access;
  _useAsyncIO = isAsync;
  _fileHandle = safeFileHandle;
}

void FileStream___::ctor(SafeFileHandle handle, FileAccess access) {
}

void FileStream___::ctor(SafeFileHandle handle, FileAccess access, Int32 bufferSize) {
}

void FileStream___::ValidateAndInitFromHandle(SafeFileHandle handle, FileAccess access, Int32 bufferSize, Boolean isAsync) {
  if (handle->get_IsInvalid()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidHandle(), "handle");
  }
  if (access < FileAccess::Read || access > FileAccess::ReadWrite) {
    rt::throw_exception<ArgumentOutOfRangeException>("access", SR::get_ArgumentOutOfRange_Enum());
  }
  if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (handle->get_IsClosed()) {
    rt::throw_exception<ObjectDisposedException>(SR::get_ObjectDisposed_FileClosed());
  }
  if (handle->get_IsAsync().get_HasValue() && isAsync != handle->get_IsAsync().GetValueOrDefault()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_HandleNotAsync(), "handle");
  }
  _exposedHandle = true;
  _bufferLength = bufferSize;
  InitFromHandle(handle, access, isAsync);
}

void FileStream___::ctor(SafeFileHandle handle, FileAccess access, Int32 bufferSize, Boolean isAsync) {
  _activeBufferOperation = Task::in::get_CompletedTask();
  Stream::ctor();
  ValidateAndInitFromHandle(handle, access, bufferSize, isAsync);
  _access = access;
  _useAsyncIO = isAsync;
  _fileHandle = handle;
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
  _activeBufferOperation = Task::in::get_CompletedTask();
  Stream::ctor();
  if (path == nullptr) {
    rt::throw_exception<ArgumentNullException>("path", SR::get_ArgumentNull_Path());
  }
  if (path->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyPath(), "path");
  }
  FileShare fileShare = share & ~FileShare::Inheritable;
  String text = nullptr;
  if (mode < FileMode::CreateNew || mode > FileMode::Append) {
    text = "mode";
  } else if (access < FileAccess::Read || access > FileAccess::ReadWrite) {
    text = "access";
  } else if ((fileShare < FileShare::None) || fileShare > (FileShare::Read | FileShare::Write | FileShare::Delete)) {
    text = "share";
  }


  if (text != nullptr) {
    rt::throw_exception<ArgumentOutOfRangeException>(text, SR::get_ArgumentOutOfRange_Enum());
  }
  if (options != 0 && (options & (FileOptions)67092479) != 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("options", SR::get_ArgumentOutOfRange_Enum());
  }
  if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if ((access & FileAccess::Write) == 0 && (mode == FileMode::Truncate || mode == FileMode::CreateNew || mode == FileMode::Create || mode == FileMode::Append)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidFileModeAndAccessCombo(), mode, access), "access");
  }
  if ((access & FileAccess::Read) != 0 && mode == FileMode::Append) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidAppendMode(), "access");
  }
  String text2 = _path = Path::GetFullPath(path);
  _access = access;
  _bufferLength = bufferSize;
  if ((options & FileOptions::Asynchronous) != 0) {
    _useAsyncIO = true;
  }
  if ((access & FileAccess::Write) == FileAccess::Write) {
    SerializationInfo::in::ThrowIfDeserializationInProgress("AllowFileWrites", s_cachedSerializationSwitch);
  }
  _fileHandle = OpenHandle(mode, share, options);
  try{
    Init(mode, share, path);
  } catch (...) {
  }
}

void FileStream___::Lock(Int64 position, Int64 length) {
  if (position < 0 || length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((position < 0) ? "position" : "length", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  LockInternal(position, length);
}

void FileStream___::Unlock(Int64 position, Int64 length) {
  if (position < 0 || length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((position < 0) ? "position" : "length", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  UnlockInternal(position, length);
}

Task<> FileStream___::FlushAsync(CancellationToken cancellationToken) {
  if (GetType() != rt::typeof<FileStream>()) {
    return Stream::FlushAsync(cancellationToken);
  }
  return FlushAsyncInternal(cancellationToken);
}

Int32 FileStream___::Read(Array<Byte> array, Int32 offset, Int32 count) {
  ValidateReadWriteArgs(array, offset, count);
  if (!_useAsyncIO) {
    return ReadSpan(Span<Byte>(array, offset, count));
  }
  return ReadAsyncTask(array, offset, count, CancellationToken::get_None())->GetAwaiter().GetResult();
}

Int32 FileStream___::Read(Span<Byte> buffer) {
  if (GetType() == rt::typeof<FileStream>() && !_useAsyncIO) {
    if (_fileHandle->get_IsClosed()) {
      rt::throw_exception(Error::GetFileNotOpen());
    }
    return ReadSpan(buffer);
  }
  return Stream::Read(buffer);
}

Task<Int32> FileStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (GetType() != rt::typeof<FileStream>()) {
    return Stream::ReadAsync(buffer, offset, count, cancellationToken);
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task::in::FromCanceled<Int32>(cancellationToken);
  }
  if (get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (!_useAsyncIO) {
    return (Task<Int32>)BeginReadInternal(buffer, offset, count, nullptr, nullptr, true, false);
  }
  return ReadAsyncTask(buffer, offset, count, cancellationToken);
}

ValueTask<Int32> FileStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  if (GetType() != rt::typeof<FileStream>()) {
    return Stream::ReadAsync(buffer, cancellationToken);
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<Int32>(Task::in::FromCanceled<Int32>(cancellationToken));
  }
  if (get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (!_useAsyncIO) {
    ArraySegment<Byte> segment;
    if (!MemoryMarshal::TryGetArray(buffer, segment)) {
      return Stream::ReadAsync(buffer, cancellationToken);
    }
    return ValueTask<Int32>((Task<Int32>)BeginReadInternal(segment.get_Array(), segment.get_Offset(), segment.get_Count(), nullptr, nullptr, true, false));
  }
  Int32 synchronousResult;
  Task<Int32> task = ReadAsyncInternal(buffer, cancellationToken, synchronousResult);
  if (task == nullptr) {
    return ValueTask<Int32>(synchronousResult);
  }
  return ValueTask<Int32>(task);
}

Task<Int32> FileStream___::ReadAsyncTask(Array<Byte> array, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  Int32 synchronousResult;
  Task<Int32> task = ReadAsyncInternal(Memory<Byte>(array, offset, count), cancellationToken, synchronousResult);
  if (task == nullptr) {
    task = _lastSynchronouslyCompletedTask;
    if (task == nullptr || task->get_Result() != synchronousResult) {
      task = (_lastSynchronouslyCompletedTask = Task::in::FromResult(synchronousResult));
    }
  }
  return task;
}

void FileStream___::Write(Array<Byte> array, Int32 offset, Int32 count) {
  ValidateReadWriteArgs(array, offset, count);
  if (_useAsyncIO) {
    WriteAsyncInternal(ReadOnlyMemory<Byte>(array, offset, count), CancellationToken::get_None()).AsTask()->GetAwaiter().GetResult();
  } else {
    WriteSpan(ReadOnlySpan<Byte>(array, offset, count));
  }
}

void FileStream___::Write(ReadOnlySpan<Byte> buffer) {
  if (GetType() == rt::typeof<FileStream>() && !_useAsyncIO) {
    if (_fileHandle->get_IsClosed()) {
      rt::throw_exception(Error::GetFileNotOpen());
    }
    WriteSpan(buffer);
  } else {
    Stream::Write(buffer);
  }
}

Task<> FileStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (GetType() != rt::typeof<FileStream>()) {
    return Stream::WriteAsync(buffer, offset, count, cancellationToken);
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task::in::FromCanceled(cancellationToken);
  }
  if (get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (!_useAsyncIO) {
    return (Task)BeginWriteInternal(buffer, offset, count, nullptr, nullptr, true, false);
  }
  return WriteAsyncInternal(ReadOnlyMemory<Byte>(buffer, offset, count), cancellationToken).AsTask();
}

ValueTask<> FileStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  if (GetType() != rt::typeof<FileStream>()) {
    return Stream::WriteAsync(buffer, cancellationToken);
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask(Task::in::FromCanceled<Int32>(cancellationToken));
  }
  if (get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (!_useAsyncIO) {
    ArraySegment<Byte> segment;
    if (!MemoryMarshal::TryGetArray(buffer, segment)) {
      return Stream::WriteAsync(buffer, cancellationToken);
    }
    return ValueTask((Task)BeginWriteInternal(segment.get_Array(), segment.get_Offset(), segment.get_Count(), nullptr, nullptr, true, false));
  }
  return WriteAsyncInternal(buffer, cancellationToken);
}

void FileStream___::Flush() {
  Flush(false);
}

void FileStream___::Flush(Boolean flushToDisk) {
  if (get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  FlushInternalBuffer();
  if (flushToDisk && get_CanWrite()) {
    FlushOSBuffer();
  }
}

void FileStream___::ValidateReadWriteArgs(Array<Byte> array, Int32 offset, Int32 count) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
}

void FileStream___::SetLength(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (!get_CanSeek()) {
    rt::throw_exception(Error::GetSeekNotSupported());
  }
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
  SetLengthInternal(value);
}

void FileStream___::VerifyOSHandlePosition() {
  if (!_exposedHandle || !get_CanSeek()) {
    return;
  }
  Int64 filePosition = _filePosition;
  Int64 num = SeekCore(_fileHandle, 0, SeekOrigin::Current);
  if (filePosition != num) {
    _readPos = (_readLength = 0);
    if (_writePos > 0) {
      _writePos = 0;
      rt::throw_exception<IOException>(SR::get_IO_FileStreamHandlePosition());
    }
  }
}

void FileStream___::PrepareForReading() {
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (_readLength == 0 && !get_CanRead()) {
    rt::throw_exception(Error::GetReadNotSupported());
  }
}

Boolean FileStream___::IsIoRelatedException(Exception e) {
  if (!rt::is<IOException>(e) && !rt::is<UnauthorizedAccessException>(e) && !rt::is<NotSupportedException>(e)) {
    if (rt::is<ArgumentException>(e)) {
      return !rt::is<ArgumentNullException>(e);
    }
    return false;
  }
  return true;
}

Array<Byte> FileStream___::GetBuffer() {
  if (_buffer == nullptr) {
    _buffer = rt::newarr<Array<Byte>>(_bufferLength);
    OnBufferAllocated();
  }
  return _buffer;
}

void FileStream___::OnBufferAllocated() {
  if (_useAsyncIO) {
    _preallocatedOverlapped = rt::newobj<PreAllocatedOverlapped>(s_ioCallback, (FileStream)this, _buffer);
  }
}

void FileStream___::FlushInternalBuffer() {
  if (_writePos > 0) {
    FlushWriteBuffer();
  } else if (_readPos < _readLength && get_CanSeek()) {
    FlushReadBuffer();
  }

}

void FileStream___::FlushReadBuffer() {
  Int32 num = _readPos - _readLength;
  if (num != 0) {
    SeekCore(_fileHandle, num, SeekOrigin::Current);
  }
  _readPos = (_readLength = 0);
}

Int32 FileStream___::ReadByte() {
  PrepareForReading();
  Array<Byte> buffer = GetBuffer();
  if (_readPos == _readLength) {
    FlushWriteBuffer();
    _readLength = FillReadBufferForReadByte();
    _readPos = 0;
    if (_readLength == 0) {
      return -1;
    }
  }
  return buffer[_readPos++];
}

void FileStream___::WriteByte(Byte value) {
  PrepareForWriting();
  if (_writePos == _bufferLength) {
    FlushWriteBufferForWriteByte();
  }
  GetBuffer()[_writePos++] = value;
}

void FileStream___::PrepareForWriting() {
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (_writePos == 0) {
    if (!get_CanWrite()) {
      rt::throw_exception(Error::GetWriteNotSupported());
    }
    FlushReadBuffer();
  }
}

void FileStream___::Finalize() {
  Dispose(false);
}

IAsyncResult FileStream___::BeginRead(Array<Byte> array, Int32 offset, Int32 numBytes, AsyncCallback callback, Object state) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (numBytes < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("numBytes", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - offset < numBytes) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (get_IsClosed()) {
    rt::throw_exception<ObjectDisposedException>(SR::get_ObjectDisposed_FileClosed());
  }
  if (!get_CanRead()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnreadableStream());
  }
  if (!get_IsAsync()) {
    return Stream::BeginRead(array, offset, numBytes, callback, state);
  }
  return TaskToApm::Begin(ReadAsyncTask(array, offset, numBytes, CancellationToken::get_None()), callback, state);
}

IAsyncResult FileStream___::BeginWrite(Array<Byte> array, Int32 offset, Int32 numBytes, AsyncCallback callback, Object state) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (numBytes < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("numBytes", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - offset < numBytes) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (get_IsClosed()) {
    rt::throw_exception<ObjectDisposedException>(SR::get_ObjectDisposed_FileClosed());
  }
  if (!get_CanWrite()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnwritableStream());
  }
  if (!get_IsAsync()) {
    return Stream::BeginWrite(array, offset, numBytes, callback, state);
  }
  return TaskToApm::Begin(WriteAsyncInternal(ReadOnlyMemory<Byte>(array, offset, numBytes), CancellationToken::get_None()).AsTask(), callback, state);
}

Int32 FileStream___::EndRead(IAsyncResult asyncResult) {
  if (asyncResult == nullptr) {
    rt::throw_exception<ArgumentNullException>("asyncResult");
  }
  if (!get_IsAsync()) {
    return Stream::EndRead(asyncResult);
  }
  return TaskToApm::End<Int32>(asyncResult);
}

void FileStream___::EndWrite(IAsyncResult asyncResult) {
  if (asyncResult == nullptr) {
    rt::throw_exception<ArgumentNullException>("asyncResult");
  }
  if (!get_IsAsync()) {
    Stream::EndWrite(asyncResult);
  } else {
    TaskToApm::End(asyncResult);
  }
}

void FileStream___::Init(FileMode mode, FileShare share, String originalPath) {
  if (!PathInternal::IsExtended(originalPath)) {
    Int32 fileType = Interop::Kernel32::GetFileType(_fileHandle);
    if (fileType != 1) {
      Int32 num = (fileType == 0) ? Marshal::GetLastWin32Error() : 0;
      _fileHandle->Dispose();
      if (num != 0) {
        rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(num));
      }
      rt::throw_exception<NotSupportedException>(SR::get_NotSupported_FileStreamOnNonFiles());
    }
  }
  if (_useAsyncIO) {
    try{
      _fileHandle->set_ThreadPoolBinding = ThreadPoolBoundHandle::in::BindHandle(_fileHandle);
    } catch (ArgumentException innerException) {
    } finally: {
      if (_fileHandle->get_ThreadPoolBinding() == nullptr) {
        _fileHandle->Dispose();
      }
    }
  }
  _canSeek = true;
  if (mode == FileMode::Append) {
    _appendStart = SeekCore(_fileHandle, 0, SeekOrigin::End);
  } else {
    _appendStart = -1;
  }
}

void FileStream___::InitFromHandle(SafeFileHandle handle, FileAccess access, Boolean useAsyncIO) {
  InitFromHandleImpl(handle, useAsyncIO);
}

void FileStream___::InitFromHandleImpl(SafeFileHandle handle, Boolean useAsyncIO) {
  Int32 fileType = Interop::Kernel32::GetFileType(handle);
  _canSeek = (fileType == 1);
  _isPipe = (fileType == 3);
  if (useAsyncIO && !handle->get_IsAsync().GetValueOrDefault()) {
    try{
      handle->set_ThreadPoolBinding = ThreadPoolBoundHandle::in::BindHandle(handle);
    } catch (Exception innerException) {
    }
  } else if (!useAsyncIO) {
    VerifyHandleIsSync(handle);
  }

  if (_canSeek) {
    SeekCore(handle, 0, SeekOrigin::Current);
  } else {
    _filePosition = 0;
  }
}

Interop::Kernel32::SECURITY_ATTRIBUTES FileStream___::GetSecAttrs(FileShare share) {
  Interop::Kernel32::SECURITY_ATTRIBUTES result = Interop::Kernel32::SECURITY_ATTRIBUTES();
  if ((share & FileShare::Inheritable) != 0) {
    Interop::Kernel32::SECURITY_ATTRIBUTES result2 = Interop::Kernel32::SECURITY_ATTRIBUTES();
    result2.nLength = (UInt32)sizeof(Interop::Kernel32::SECURITY_ATTRIBUTES);
    result2.bInheritHandle = Interop::BOOL::TRUE;
    return result2;
  }
  return result;
}

Int64 FileStream___::GetLengthInternal() {
  Interop::Kernel32::FILE_STANDARD_INFO fILE_STANDARD_INFO;
  if (!Interop::Kernel32::GetFileInformationByHandleEx(_fileHandle, 1, &fILE_STANDARD_INFO, (UInt32)sizeof(Interop::Kernel32::FILE_STANDARD_INFO))) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error(_path));
  }
  Int64 num = fILE_STANDARD_INFO.EndOfFile;
  if (_writePos > 0 && _filePosition + _writePos > num) {
    num = _writePos + _filePosition;
  }
  return num;
}

void FileStream___::Dispose(Boolean disposing) {
  try{
    if (_fileHandle != nullptr && !_fileHandle->get_IsClosed() && _writePos > 0) {
      try{
        FlushWriteBuffer(!disposing);
      } catch (Exception e) {
      }
    }
  } finally: {
    if (_fileHandle != nullptr && !_fileHandle->get_IsClosed()) {
      auto& default = _fileHandle->get_ThreadPoolBinding();
      default == nullptr ? nullptr : default->Dispose();
      _fileHandle->Dispose();
    }
    auto& default = _preallocatedOverlapped;
    default == nullptr ? nullptr : default->Dispose();
    _canSeek = false;
  }
}

ValueTask<> FileStream___::DisposeAsync() {
  if (!(GetType() == rt::typeof<FileStream>())) {
    return Stream::DisposeAsync();
  }
  return DisposeAsyncCore();
}

ValueTask<> FileStream___::DisposeAsyncCore() {
  try{
    if (_fileHandle != nullptr && !_fileHandle->get_IsClosed() && _writePos > 0) {
    }
  } finally: {
    if (_fileHandle != nullptr && !_fileHandle->get_IsClosed()) {
      auto& default = _fileHandle->get_ThreadPoolBinding();
      default == nullptr ? nullptr : default->Dispose();
      _fileHandle->Dispose();
    }
    auto& default = _preallocatedOverlapped;
    default == nullptr ? nullptr : default->Dispose();
    _canSeek = false;
    GC::SuppressFinalize((FileStream)this);
  }
}

void FileStream___::FlushOSBuffer() {
  if (!Interop::Kernel32::FlushFileBuffers(_fileHandle)) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error(_path));
  }
}

Task<> FileStream___::FlushWriteAsync(CancellationToken cancellationToken) {
  if (_writePos == 0) {
    return Task::in::get_CompletedTask();
  }
  Task task = WriteAsyncInternalCore(ReadOnlyMemory<Byte>(GetBuffer(), 0, _writePos), cancellationToken);
  _writePos = 0;
  _activeBufferOperation = (get_HasActiveBufferOperation() ? Task::in::WhenAll(rt::newarr<Array<Task>>(2, _activeBufferOperation, task)) : task);
  return task;
}

void FileStream___::FlushWriteBufferForWriteByte() {
  FlushWriteBuffer();
}

void FileStream___::FlushWriteBuffer(Boolean calledFromFinalizer) {
  if (_writePos == 0) {
    return;
  }
  if (_useAsyncIO) {
    Task task = FlushWriteAsync(CancellationToken::get_None());
    if (!calledFromFinalizer) {
      task->GetAwaiter().GetResult();
    }
  } else {
    WriteCore(ReadOnlySpan<Byte>(GetBuffer(), 0, _writePos));
  }
  _writePos = 0;
}

void FileStream___::SetLengthInternal(Int64 value) {
  if (_writePos > 0) {
    FlushWriteBuffer();
  } else if (_readPos < _readLength) {
    FlushReadBuffer();
  }

  _readPos = 0;
  _readLength = 0;
  if (_appendStart != -1 && value < _appendStart) {
    rt::throw_exception<IOException>(SR::get_IO_SetLengthAppendTruncate());
  }
  SetLengthCore(value);
}

void FileStream___::SetLengthCore(Int64 value) {
  Int64 filePosition = _filePosition;
  VerifyOSHandlePosition();
  if (_filePosition != value) {
    SeekCore(_fileHandle, value, SeekOrigin::Begin);
  }
  if (!Interop::Kernel32::SetEndOfFile(_fileHandle)) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    if (lastWin32Error == 87) {
      rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_FileLengthTooBig());
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error, _path));
  }
  if (filePosition != value) {
    if (filePosition < value) {
      SeekCore(_fileHandle, filePosition, SeekOrigin::Begin);
    } else {
      SeekCore(_fileHandle, 0, SeekOrigin::End);
    }
  }
}

FileStream::in::FileStreamCompletionSource FileStream___::CompareExchangeCurrentOverlappedOwner(FileStreamCompletionSource newSource, FileStreamCompletionSource existingSource) {
  return Interlocked::CompareExchange(_currentOverlappedOwner, newSource, existingSource);
}

Int32 FileStream___::ReadSpan(Span<Byte> destination) {
  Boolean flag = false;
  Int32 num = _readLength - _readPos;
  if (num == 0) {
    if (!get_CanRead()) {
      rt::throw_exception(Error::GetReadNotSupported());
    }
    if (_writePos > 0) {
      FlushWriteBuffer();
    }
    if (!get_CanSeek() || destination.get_Length() >= _bufferLength) {
      num = ReadNative(destination);
      _readPos = 0;
      _readLength = 0;
      return num;
    }
    num = ReadNative(GetBuffer());
    if (num == 0) {
      return 0;
    }
    flag = (num < _bufferLength);
    _readPos = 0;
    _readLength = num;
  }
  if (num > destination.get_Length()) {
    num = destination.get_Length();
  }
  ReadOnlySpan<Byte>(GetBuffer(), _readPos, num).CopyTo(destination);
  _readPos += num;
  if (!_isPipe && num < destination.get_Length() && !flag) {
    Int32 num2 = ReadNative(destination.Slice(num));
    num += num2;
    _readPos = 0;
    _readLength = 0;
  }
  return num;
}

Int32 FileStream___::FillReadBufferForReadByte() {
  if (!_useAsyncIO) {
    return ReadNative(_buffer);
  }
  return ReadNativeAsync(Memory<Byte>(_buffer), 0, CancellationToken::get_None())->GetAwaiter().GetResult();
}

Int32 FileStream___::ReadNative(Span<Byte> buffer) {
  VerifyOSHandlePosition();
  Int32 errorCode;
  Int32 num = ReadFileNative(_fileHandle, buffer, nullptr, errorCode);
  if (num == -1) {
    switch (errorCode.get()) {
      case 109:
        break;
      case 87:
        rt::throw_exception<ArgumentException>(SR::get_Arg_HandleNotSync(), "_fileHandle");
      default:
        rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(errorCode, _path));
    }
    num = 0;
  }
  _filePosition += num;
  return num;
}

Int64 FileStream___::Seek(Int64 offset, SeekOrigin origin) {
  if (origin < SeekOrigin::Begin || origin > SeekOrigin::End) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidSeekOrigin(), "origin");
  }
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  if (!get_CanSeek()) {
    rt::throw_exception(Error::GetSeekNotSupported());
  }
  if (_writePos > 0) {
    FlushWriteBuffer();
  } else if (origin == SeekOrigin::Current) {
    offset -= _readLength - _readPos;
  }

  _readPos = (_readLength = 0);
  VerifyOSHandlePosition();
  Int64 num = _filePosition + (_readPos - _readLength);
  Int64 num2 = SeekCore(_fileHandle, offset, origin);
  if (_appendStart != -1 && num2 < _appendStart) {
    SeekCore(_fileHandle, num, SeekOrigin::Begin);
    rt::throw_exception<IOException>(SR::get_IO_SeekAppendOverwrite());
  }
  if (_readLength > 0) {
    if (num == num2) {
      if (_readPos > 0) {
        Buffer::BlockCopy(GetBuffer(), _readPos, GetBuffer(), 0, _readLength - _readPos);
        _readLength -= _readPos;
        _readPos = 0;
      }
      if (_readLength > 0) {
        SeekCore(_fileHandle, _readLength, SeekOrigin::Current);
      }
    } else if (num - _readPos < num2 && num2 < num + _readLength - _readPos) {
      Int32 num3 = (Int32)(num2 - num);
      Buffer::BlockCopy(GetBuffer(), _readPos + num3, GetBuffer(), 0, _readLength - (_readPos + num3));
      _readLength -= _readPos + num3;
      _readPos = 0;
      if (_readLength > 0) {
        SeekCore(_fileHandle, _readLength, SeekOrigin::Current);
      }
    } else {
      _readPos = 0;
      _readLength = 0;
    }

  }
  return num2;
}

Int64 FileStream___::SeekCore(SafeFileHandle fileHandle, Int64 offset, SeekOrigin origin, Boolean closeInvalidHandle) {
  Int64 lpNewFilePointer;
  if (!Interop::Kernel32::SetFilePointerEx(fileHandle, offset, lpNewFilePointer, (UInt32)origin)) {
    if (closeInvalidHandle) {
      rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(GetLastWin32ErrorAndDisposeHandleIfInvalid(), _path));
    }
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error(_path));
  }
  _filePosition = lpNewFilePointer;
  return lpNewFilePointer;
}

void FileStream___::WriteSpan(ReadOnlySpan<Byte> source) {
  if (_writePos == 0) {
    if (!get_CanWrite()) {
      rt::throw_exception(Error::GetWriteNotSupported());
    }
    if (_readPos < _readLength) {
      FlushReadBuffer();
    }
    _readPos = 0;
    _readLength = 0;
  }
  if (_writePos > 0) {
    Int32 num = _bufferLength - _writePos;
    if (num > 0) {
      if (num >= source.get_Length()) {
        source.CopyTo(MemoryExtensions::AsSpan(GetBuffer(), _writePos));
        _writePos += source.get_Length();
        return;
      }
      source.Slice(0, num).CopyTo(MemoryExtensions::AsSpan(GetBuffer(), _writePos));
      _writePos += num;
      source = source.Slice(num);
    }
    WriteCore(ReadOnlySpan<Byte>(GetBuffer(), 0, _writePos));
    _writePos = 0;
  }
  if (source.get_Length() >= _bufferLength) {
    WriteCore(source);
  } else if (source.get_Length() != 0) {
    source.CopyTo(MemoryExtensions::AsSpan(GetBuffer(), _writePos));
    _writePos = source.get_Length();
  }

}

void FileStream___::WriteCore(ReadOnlySpan<Byte> source) {
  VerifyOSHandlePosition();
  Int32 errorCode;
  Int32 num = WriteFileNative(_fileHandle, source, nullptr, errorCode);
  if (num == -1) {
    switch (errorCode.get()) {
      case 232:
        break;
      case 87:
        rt::throw_exception<IOException>(SR::get_IO_FileTooLongOrHandleNotSync());
      default:
        rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(errorCode, _path));
    }
    num = 0;
  }
  _filePosition += num;
}

Task<Int32> FileStream___::ReadAsyncInternal(Memory<Byte> destination, CancellationToken cancellationToken, Int32& synchronousResult) {
  if (!get_CanRead()) {
    rt::throw_exception(Error::GetReadNotSupported());
  }
  if (_isPipe) {
    if (_readPos < _readLength) {
      Int32 num = Math::Min(_readLength - _readPos, destination.get_Length());
      Span<Byte>(GetBuffer(), _readPos, num).CopyTo(destination.get_Span());
      _readPos += num;
      synchronousResult = num;
      return nullptr;
    }
    synchronousResult = 0;
    return ReadNativeAsync(destination, 0, cancellationToken);
  }
  if (_writePos > 0) {
    FlushWriteBuffer();
  }
  if (_readPos == _readLength) {
    if (destination.get_Length() < _bufferLength) {
      Task<Int32> task = ReadNativeAsync(Memory<Byte>(GetBuffer()), 0, cancellationToken);
      _readLength = task->GetAwaiter().GetResult();
      Int32 num2 = Math::Min(_readLength, destination.get_Length());
      Span<Byte>(GetBuffer(), 0, num2).CopyTo(destination.get_Span());
      _readPos = num2;
      synchronousResult = num2;
      return nullptr;
    }
    _readPos = 0;
    _readLength = 0;
    synchronousResult = 0;
    return ReadNativeAsync(destination, 0, cancellationToken);
  }
  Int32 num3 = Math::Min(_readLength - _readPos, destination.get_Length());
  Span<Byte>(GetBuffer(), _readPos, num3).CopyTo(destination.get_Span());
  _readPos += num3;
  if (num3 == destination.get_Length()) {
    synchronousResult = num3;
    return nullptr;
  }
  _readPos = 0;
  _readLength = 0;
  synchronousResult = 0;
  return ReadNativeAsync(destination.Slice(num3), num3, cancellationToken);
}

Task<Int32> FileStream___::ReadNativeAsync(Memory<Byte> destination, Int32 numBufferedBytesRead, CancellationToken cancellationToken) {
  FileStreamCompletionSource fileStreamCompletionSource = FileStreamCompletionSource::in::Create((FileStream)this, numBufferedBytesRead, destination);
  NativeOverlapped* overlapped = fileStreamCompletionSource->get_Overlapped();
  if (get_CanSeek()) {
    Int64 length = get_Length();
    VerifyOSHandlePosition();
    if (_filePosition + destination.get_Length() > length) {
      destination = ((_filePosition > length) ? Memory<T>() : destination.Slice(0, (Int32)(length - _filePosition)));
    }
    overlapped->OffsetLow = (Int32)_filePosition;
    overlapped->OffsetHigh = (Int32)(_filePosition >> 32);
    SeekCore(_fileHandle, destination.get_Length(), SeekOrigin::Current);
  }
  Int32 errorCode;
  Int32 num = ReadFileNative(_fileHandle, destination.get_Span(), overlapped, errorCode);
  if (num == -1) {
    switch (errorCode.get()) {
      case 109:
        overlapped->InternalLow = IntPtr::Zero;
        fileStreamCompletionSource->SetCompletedSynchronously(0);
        break;
      default:
        if (!_fileHandle->get_IsClosed() && get_CanSeek()) {
          SeekCore(_fileHandle, 0, SeekOrigin::Current);
        }
        fileStreamCompletionSource->ReleaseNativeResource();
        if (errorCode == 38) {
          rt::throw_exception(Error::GetEndOfFile());
        }
        rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(errorCode, _path));
      case 997:
        if (cancellationToken.get_CanBeCanceled()) {
          fileStreamCompletionSource->RegisterForCancellation(cancellationToken);
        }
        break;
    }
  }
  return fileStreamCompletionSource->get_Task();
}

ValueTask<> FileStream___::WriteAsyncInternal(ReadOnlyMemory<Byte> source, CancellationToken cancellationToken) {
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
  Boolean flag = false;
  if (!_isPipe) {
    if (_writePos == 0) {
      if (_readPos < _readLength) {
        FlushReadBuffer();
      }
      _readPos = 0;
      _readLength = 0;
    }
    Int32 num = _bufferLength - _writePos;
    if (source.get_Length() < _bufferLength && !get_HasActiveBufferOperation() && source.get_Length() <= num) {
      source.get_Span().CopyTo(Span<Byte>(GetBuffer(), _writePos, source.get_Length()));
      _writePos += source.get_Length();
      flag = true;
      if (source.get_Length() != num) {
        return ValueTask();
      }
    }
  }
  Task task = nullptr;
  if (_writePos > 0) {
    task = FlushWriteAsync(cancellationToken);
    if (flag || task->get_IsFaulted() || task->get_IsCanceled()) {
      return ValueTask(task);
    }
  }
  Task task2 = WriteAsyncInternalCore(source, cancellationToken);
  return ValueTask((task == nullptr || task->get_Status() == TaskStatus::RanToCompletion) ? task2 : ((task2->get_Status() == TaskStatus::RanToCompletion) ? task : Task::in::WhenAll(rt::newarr<Array<Task>>(2, task, task2))));
}

Task<> FileStream___::WriteAsyncInternalCore(ReadOnlyMemory<Byte> source, CancellationToken cancellationToken) {
  FileStreamCompletionSource fileStreamCompletionSource = FileStreamCompletionSource::in::Create((FileStream)this, 0, source);
  NativeOverlapped* overlapped = fileStreamCompletionSource->get_Overlapped();
  if (get_CanSeek()) {
    Int64 length = get_Length();
    VerifyOSHandlePosition();
    if (_filePosition + source.get_Length() > length) {
      SetLengthCore(_filePosition + source.get_Length());
    }
    overlapped->OffsetLow = (Int32)_filePosition;
    overlapped->OffsetHigh = (Int32)(_filePosition >> 32);
    SeekCore(_fileHandle, source.get_Length(), SeekOrigin::Current);
  }
  Int32 errorCode;
  Int32 num = WriteFileNative(_fileHandle, source.get_Span(), overlapped, errorCode);
  if (num == -1) {
    switch (errorCode.get()) {
      case 232:
        fileStreamCompletionSource->SetCompletedSynchronously(0);
        return Task::in::get_CompletedTask();
      default:
        if (!_fileHandle->get_IsClosed() && get_CanSeek()) {
          SeekCore(_fileHandle, 0, SeekOrigin::Current);
        }
        fileStreamCompletionSource->ReleaseNativeResource();
        if (errorCode == 38) {
          rt::throw_exception(Error::GetEndOfFile());
        }
        rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(errorCode, _path));
      case 997:
        break;
    }
    if (cancellationToken.get_CanBeCanceled()) {
      fileStreamCompletionSource->RegisterForCancellation(cancellationToken);
    }
  }
  return fileStreamCompletionSource->get_Task();
}

Int32 FileStream___::ReadFileNative(SafeFileHandle handle, Span<Byte> bytes, NativeOverlapped* overlapped, Int32& errorCode) {
  Int32 numBytesRead = 0;
  Int32 num;
  {
    Byte* bytes2 = &MemoryMarshal::GetReference(bytes);
    num = (_useAsyncIO ? Interop::Kernel32::ReadFile(handle, bytes2, bytes.get_Length(), IntPtr::Zero, overlapped) : Interop::Kernel32::ReadFile(handle, bytes2, bytes.get_Length(), numBytesRead, IntPtr::Zero));
  }
  if (num == 0) {
    errorCode = GetLastWin32ErrorAndDisposeHandleIfInvalid();
    return -1;
  }
  errorCode = 0;
  return numBytesRead;
}

Int32 FileStream___::WriteFileNative(SafeFileHandle handle, ReadOnlySpan<Byte> buffer, NativeOverlapped* overlapped, Int32& errorCode) {
  Int32 numBytesWritten = 0;
  Int32 num;
  {
    Byte* bytes = &MemoryMarshal::GetReference(buffer);
    num = (_useAsyncIO ? Interop::Kernel32::WriteFile(handle, bytes, buffer.get_Length(), IntPtr::Zero, overlapped) : Interop::Kernel32::WriteFile(handle, bytes, buffer.get_Length(), numBytesWritten, IntPtr::Zero));
  }
  if (num == 0) {
    errorCode = GetLastWin32ErrorAndDisposeHandleIfInvalid();
    return -1;
  }
  errorCode = 0;
  return numBytesWritten;
}

Int32 FileStream___::GetLastWin32ErrorAndDisposeHandleIfInvalid() {
  Int32 lastWin32Error = Marshal::GetLastWin32Error();
  if (lastWin32Error == 6) {
    _fileHandle->Dispose();
  }
  return lastWin32Error;
}

Task<> FileStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  if (!_useAsyncIO || GetType() != rt::typeof<FileStream>()) {
    return Stream::CopyToAsync(destination, bufferSize, cancellationToken);
  }
  StreamHelpers::ValidateCopyToArgs((FileStream)this, destination, bufferSize);
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task::in::FromCanceled<Int32>(cancellationToken);
  }
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  return AsyncModeCopyToAsync(destination, bufferSize, cancellationToken);
}

Task<> FileStream___::AsyncModeCopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  if (_writePos > 0) {
  }
  if (GetBuffer() != nullptr) {
    Int32 num = _readLength - _readPos;
    if (num > 0) {
    }
  }
  AsyncCopyToAwaitable readAwaitable = rt::newobj<AsyncCopyToAwaitable>((FileStream)this);
  Boolean canSeek = get_CanSeek();
  if (canSeek) {
    VerifyOSHandlePosition();
    readAwaitable->_position = _filePosition;
  }
  Array<Byte> copyBuffer = ArrayPool<Byte>::in::get_Shared()->Rent(bufferSize);
  PreAllocatedOverlapped awaitableOverlapped = rt::newobj<PreAllocatedOverlapped>(AsyncCopyToAwaitable::in::s_callback, readAwaitable, copyBuffer);
  CancellationTokenRegistration cancellationReg = CancellationTokenRegistration();
  try{
    if (cancellationToken.get_CanBeCanceled()) {
    }
    while (true) {
      cancellationToken.ThrowIfCancellationRequested();
      readAwaitable->ResetForNextOperation();
      try{
        readAwaitable->_nativeOverlapped = _fileHandle->get_ThreadPoolBinding()->AllocateNativeOverlapped(awaitableOverlapped);
        if (canSeek) {
          readAwaitable->_nativeOverlapped->OffsetLow = (Int32)readAwaitable->_position;
          readAwaitable->_nativeOverlapped->OffsetHigh = (Int32)(readAwaitable->_position >> 32);
        }
        Int32 errorCode;
        if (ReadFileNative(_fileHandle, copyBuffer, readAwaitable->_nativeOverlapped, errorCode) < 0) {
          switch (errorCode.get()) {
            case 38:
            case 109:
              readAwaitable->MarkCompleted();
              break;
            default:
              rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(errorCode, _path));
            case 997:
              break;
          }
        }
      } finally: {
        NativeOverlapped* nativeOverlapped;
        {
          rt::lock(readAwaitable->get_CancellationLock());
          nativeOverlapped = readAwaitable->_nativeOverlapped;
          readAwaitable->_nativeOverlapped = nullptr;
        }
        if (nativeOverlapped != nullptr) {
          _fileHandle->get_ThreadPoolBinding()->FreeNativeOverlapped(nativeOverlapped);
        }
      }
    }
  } finally: {
    cancellationReg.Dispose();
    awaitableOverlapped->Dispose();
    ArrayPool<Byte>::in::get_Shared()->Return(copyBuffer);
    if (!_fileHandle->get_IsClosed() && get_CanSeek()) {
      SeekCore(_fileHandle, 0, SeekOrigin::End);
    }
  }
}

Task<> FileStream___::FlushAsyncInternal(CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task::in::FromCanceled(cancellationToken);
  }
  if (_fileHandle->get_IsClosed()) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  try{
    FlushInternalBuffer();
  } catch (Exception exception) {
  }
  return Task::in::get_CompletedTask();
}

void FileStream___::LockInternal(Int64 position, Int64 length) {
  Int32 offsetLow = (Int32)position;
  Int32 offsetHigh = (Int32)(position >> 32);
  Int32 countLow = (Int32)length;
  Int32 countHigh = (Int32)(length >> 32);
  if (!Interop::Kernel32::LockFile(_fileHandle, offsetLow, offsetHigh, countLow, countHigh)) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error(_path));
  }
}

void FileStream___::UnlockInternal(Int64 position, Int64 length) {
  Int32 offsetLow = (Int32)position;
  Int32 offsetHigh = (Int32)(position >> 32);
  Int32 countLow = (Int32)length;
  Int32 countHigh = (Int32)(length >> 32);
  if (!Interop::Kernel32::UnlockFile(_fileHandle, offsetLow, offsetHigh, countLow, countHigh)) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error(_path));
  }
}

SafeFileHandle FileStream___::ValidateFileHandle(SafeFileHandle fileHandle) {
  if (fileHandle->get_IsInvalid()) {
    Int32 num = Marshal::GetLastWin32Error();
    if (num == 3 && _path->get_Length() == PathInternal::GetRootLength(_path)) {
      num = 5;
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(num, _path));
  }
  fileHandle->set_IsAsync = _useAsyncIO;
  return fileHandle;
}

SafeFileHandle FileStream___::OpenHandle(FileMode mode, FileShare share, FileOptions options) {
  return CreateFileOpenHandle(mode, share, options);
}

SafeFileHandle FileStream___::CreateFileOpenHandle(FileMode mode, FileShare share, FileOptions options) {
  Interop::Kernel32::SECURITY_ATTRIBUTES secAttrs = GetSecAttrs(share);
  Int32 dwDesiredAccess = (((_access & FileAccess::Read) == FileAccess::Read) ? Int32::MinValue : 0) | (((_access & FileAccess::Write) == FileAccess::Write) ? 1073741824 : 0);
  share &= ~FileShare::Inheritable;
  if (mode == FileMode::Append) {
    mode = FileMode::OpenOrCreate;
  }
  Int32 num = (Int32)options;
  num |= 1048576;
  {
    DisableMediaInsertionPrompt::Create();
    return ValidateFileHandle(Interop::Kernel32::CreateFile(_path, dwDesiredAccess, share, &secAttrs, mode, num, IntPtr::Zero));
  }
}

Boolean FileStream___::GetDefaultIsAsync(SafeFileHandle handle) {
  auto& default = handle->get_IsAsync();
  return default != nullptr ? default : (!IsHandleSynchronous(handle, true)).GetValueOrDefault();
}

Nullable<Boolean> FileStream___::IsHandleSynchronous(SafeFileHandle fileHandle, Boolean ignoreInvalid) {
  if (fileHandle->get_IsInvalid()) {
    return nullptr;
  }
  Interop::NtDll::IO_STATUS_BLOCK IoStatusBlock;
  UInt32 num;
  switch (Interop::NtDll::NtQueryInformationFile(fileHandle, IoStatusBlock, &num, 4u, 16u).get()) {
    case -1073741816:
      if (!ignoreInvalid) {
        rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(6));
      }
      return nullptr;
    default:
      return nullptr;
    case 0:
      return (num & 48) != 0;
  }
}

void FileStream___::VerifyHandleIsSync(SafeFileHandle handle) {
  auto& default = IsHandleSynchronous(handle, false);
  if (!handle->get_IsAsync().get_HasValue() || (default != nullptr ? default : true)) {
    return;
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_HandleNotSync(), "handle");
}

void FileStream___::cctor() {
  s_cachedSerializationSwitch = 0;
  s_ioCallback = FileStreamCompletionSource::in::IOCallback;
}

} // namespace System::Private::CoreLib::System::IO::FileStreamNamespace
