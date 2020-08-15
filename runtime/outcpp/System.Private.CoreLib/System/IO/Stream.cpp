#include "Stream-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArraySegment-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/Error-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/Stream-dep.h>
#include <System.Private.CoreLib/System/IO/StreamHelpers-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::StreamNamespace {
using namespace System::Buffers;
using namespace System::Runtime::ExceptionServices;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
using namespace System::Threading::Tasks;

Boolean WriteCallbackStream___::get_CanRead() {
  return false;
}

Boolean WriteCallbackStream___::get_CanSeek() {
  return false;
}

Boolean WriteCallbackStream___::get_CanWrite() {
  return true;
}

Int64 WriteCallbackStream___::get_Length() {
  rt::throw_exception<NotSupportedException>();
}

Int64 WriteCallbackStream___::get_Position() {
  rt::throw_exception<NotSupportedException>();
}

void WriteCallbackStream___::set_Position(Int64 value) {
  rt::throw_exception<NotSupportedException>();
}

void WriteCallbackStream___::ctor(ReadOnlySpanAction<Byte, Object> action, Object state) {
  _action = action;
  _state = state;
}

void WriteCallbackStream___::ctor(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> func, Object state) {
  _func = func;
  _state = state;
}

void WriteCallbackStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  Write(ReadOnlySpan<Byte>(buffer, offset, count));
}

void WriteCallbackStream___::Write(ReadOnlySpan<Byte> span) {
  if (_action != nullptr) {
    _action(span, _state);
  } else {
    _func(span.ToArray(), _state, CancellationToken::get_None()).AsTask()->GetAwaiter().GetResult();
  }
}

Task<> WriteCallbackStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 length, CancellationToken cancellationToken) {
  return WriteAsync(ReadOnlyMemory<Byte>(buffer, offset, length), cancellationToken).AsTask();
}

ValueTask<> WriteCallbackStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  if (_func != nullptr) {
    return _func(buffer, _state, cancellationToken);
  }
  try{
    cancellationToken.ThrowIfCancellationRequested();
    _action(buffer.get_Span(), _state);
    return ValueTask();
  } catch (Exception exception) {
  }
}

void WriteCallbackStream___::Flush() {
}

Task<> WriteCallbackStream___::FlushAsync(CancellationToken token) {
  return Task::in::get_CompletedTask();
}

Int32 WriteCallbackStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  rt::throw_exception<NotSupportedException>();
}

Int64 WriteCallbackStream___::Seek(Int64 offset, SeekOrigin origin) {
  rt::throw_exception<NotSupportedException>();
}

void WriteCallbackStream___::SetLength(Int64 value) {
  rt::throw_exception<NotSupportedException>();
}

Boolean Stream___::ReadWriteTask___::get_InvokeMayRunArbitraryCodeOfITaskCompletionAction() {
  return true;
}

void Stream___::ReadWriteTask___::ClearBeginState() {
  _stream = nullptr;
  _buffer = nullptr;
}

void Stream___::ReadWriteTask___::ctor(Boolean isRead, Boolean apm, Func<Object, Int32> function, Object state, Stream stream, Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback) {
  _isRead = isRead;
  _apm = apm;
  _stream = stream;
  _buffer = buffer;
  _offset = offset;
  _count = count;
  if (callback != nullptr) {
    _callback = callback;
    _context = ExecutionContext::in::Capture();
    AddCompletionAction((ReadWriteTask)this);
  }
}

void Stream___::ReadWriteTask___::InvokeAsyncCallback(Object completedTask) {
  ReadWriteTask readWriteTask = (ReadWriteTask)completedTask;
  AsyncCallback callback = readWriteTask->_callback;
  readWriteTask->_callback = nullptr;
  callback(readWriteTask);
}

Boolean NullStream___::get_CanRead() {
  return true;
}

Boolean NullStream___::get_CanWrite() {
  return true;
}

Boolean NullStream___::get_CanSeek() {
  return true;
}

Int64 NullStream___::get_Length() {
  return 0;
}

Int64 NullStream___::get_Position() {
  return 0;
}

void NullStream___::set_Position(Int64 value) {
}

void NullStream___::ctor() {
}

void NullStream___::CopyTo(Stream destination, Int32 bufferSize) {
  StreamHelpers::ValidateCopyToArgs((NullStream)this, destination, bufferSize);
}

Task<> NullStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  StreamHelpers::ValidateCopyToArgs((NullStream)this, destination, bufferSize);
  if (!cancellationToken.get_IsCancellationRequested()) {
    return Task::in::get_CompletedTask();
  }
  return Task::in::FromCanceled(cancellationToken);
}

void NullStream___::CopyTo(ReadOnlySpanAction<Byte, Object> callback, Object state, Int32 bufferSize) {
  StreamHelpers::ValidateCopyToArgs((NullStream)this, callback, bufferSize);
}

Task<> NullStream___::CopyToAsync(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> callback, Object state, Int32 bufferSize, CancellationToken cancellationToken) {
  StreamHelpers::ValidateCopyToArgs((NullStream)this, callback, bufferSize);
  if (!cancellationToken.get_IsCancellationRequested()) {
    return Task::in::get_CompletedTask();
  }
  return Task::in::FromCanceled(cancellationToken);
}

void NullStream___::Dispose(Boolean disposing) {
}

void NullStream___::Flush() {
}

Task<> NullStream___::FlushAsync(CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return Task::in::get_CompletedTask();
  }
  return Task::in::FromCanceled(cancellationToken);
}

IAsyncResult NullStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  if (!get_CanRead()) {
    rt::throw_exception(Error::GetReadNotSupported());
  }
  return BlockingBeginRead(buffer, offset, count, callback, state);
}

Int32 NullStream___::EndRead(IAsyncResult asyncResult) {
  if (asyncResult == nullptr) {
    rt::throw_exception<ArgumentNullException>("asyncResult");
  }
  return BlockingEndRead(asyncResult);
}

IAsyncResult NullStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
  return BlockingBeginWrite(buffer, offset, count, callback, state);
}

void NullStream___::EndWrite(IAsyncResult asyncResult) {
  if (asyncResult == nullptr) {
    rt::throw_exception<ArgumentNullException>("asyncResult");
  }
  BlockingEndWrite(asyncResult);
}

Int32 NullStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return 0;
}

Int32 NullStream___::Read(Span<Byte> buffer) {
  return 0;
}

Task<Int32> NullStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return s_zeroTask;
}

ValueTask<Int32> NullStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>(0);
}

Int32 NullStream___::ReadByte() {
  return -1;
}

void NullStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
}

void NullStream___::Write(ReadOnlySpan<Byte> buffer) {
}

Task<> NullStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return Task::in::get_CompletedTask();
  }
  return Task::in::FromCanceled(cancellationToken);
}

ValueTask<> NullStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return ValueTask();
  }
  return ValueTask(Task::in::FromCanceled(cancellationToken));
}

void NullStream___::WriteByte(Byte value) {
}

Int64 NullStream___::Seek(Int64 offset, SeekOrigin origin) {
  return 0;
}

void NullStream___::SetLength(Int64 length) {
}

void NullStream___::cctor() {
  s_zeroTask = Task::in::FromResult(0);
}

Boolean Stream___::SynchronousAsyncResult___::get_IsCompleted() {
  return true;
}

WaitHandle Stream___::SynchronousAsyncResult___::get_AsyncWaitHandle() {
}

Object Stream___::SynchronousAsyncResult___::get_AsyncState() {
  return _stateObject;
}

Boolean Stream___::SynchronousAsyncResult___::get_CompletedSynchronously() {
  return true;
}

void Stream___::SynchronousAsyncResult___::ctor(Int32 bytesRead, Object asyncStateObject) {
  _bytesRead = bytesRead;
  _stateObject = asyncStateObject;
}

void Stream___::SynchronousAsyncResult___::ctor(Object asyncStateObject) {
  _stateObject = asyncStateObject;
  _isWrite = true;
}

void Stream___::SynchronousAsyncResult___::ctor(Exception ex, Object asyncStateObject, Boolean isWrite) {
  _exceptionInfo = ExceptionDispatchInfo::in::Capture(ex);
  _stateObject = asyncStateObject;
  _isWrite = isWrite;
}

void Stream___::SynchronousAsyncResult___::ThrowIfError() {
  if (_exceptionInfo != nullptr) {
    _exceptionInfo->Throw();
  }
}

Int32 Stream___::SynchronousAsyncResult___::EndRead(IAsyncResult asyncResult) {
  SynchronousAsyncResult synchronousAsyncResult = rt::as<SynchronousAsyncResult>(asyncResult);
  if (synchronousAsyncResult == nullptr || synchronousAsyncResult->_isWrite) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_WrongAsyncResult());
  }
  if (synchronousAsyncResult->_endXxxCalled) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_EndReadCalledMultiple());
  }
  synchronousAsyncResult->_endXxxCalled = true;
  synchronousAsyncResult->ThrowIfError();
  return synchronousAsyncResult->_bytesRead;
}

void Stream___::SynchronousAsyncResult___::EndWrite(IAsyncResult asyncResult) {
  SynchronousAsyncResult synchronousAsyncResult = rt::as<SynchronousAsyncResult>(asyncResult);
  if (synchronousAsyncResult == nullptr || !synchronousAsyncResult->_isWrite) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_WrongAsyncResult());
  }
  if (synchronousAsyncResult->_endXxxCalled) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_EndWriteCalledMultiple());
  }
  synchronousAsyncResult->_endXxxCalled = true;
  synchronousAsyncResult->ThrowIfError();
}

Boolean SyncStream___::get_CanRead() {
  return _stream->get_CanRead();
}

Boolean SyncStream___::get_CanWrite() {
  return _stream->get_CanWrite();
}

Boolean SyncStream___::get_CanSeek() {
  return _stream->get_CanSeek();
}

Boolean SyncStream___::get_CanTimeout() {
  return _stream->get_CanTimeout();
}

Int64 SyncStream___::get_Length() {
  {
    rt::lock(_stream);
    return _stream->get_Length();
  }
}

Int64 SyncStream___::get_Position() {
  {
    rt::lock(_stream);
    return _stream->get_Position();
  }
}

void SyncStream___::set_Position(Int64 value) {
  {
    rt::lock(_stream);
    _stream->set_Position = value;
  }
}

Int32 SyncStream___::get_ReadTimeout() {
  return _stream->get_ReadTimeout();
}

void SyncStream___::set_ReadTimeout(Int32 value) {
  _stream->set_ReadTimeout = value;
}

Int32 SyncStream___::get_WriteTimeout() {
  return _stream->get_WriteTimeout();
}

void SyncStream___::set_WriteTimeout(Int32 value) {
  _stream->set_WriteTimeout = value;
}

void SyncStream___::ctor(Stream stream) {
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream");
  }
  _stream = stream;
}

void SyncStream___::Close() {
  {
    rt::lock(_stream);
    try{
      _stream->Close();
    } finally: {
      Stream::Dispose(true);
    }
  }
}

void SyncStream___::Dispose(Boolean disposing) {
  {
    rt::lock(_stream);
    try{
      if (disposing) {
        ((IDisposable)_stream)->Dispose();
      }
    } finally: {
      Stream::Dispose(disposing);
    }
  }
}

ValueTask<> SyncStream___::DisposeAsync() {
  {
    rt::lock(_stream);
    return _stream->DisposeAsync();
  }
}

void SyncStream___::Flush() {
  {
    rt::lock(_stream);
    _stream->Flush();
  }
}

Int32 SyncStream___::Read(Array<Byte> bytes, Int32 offset, Int32 count) {
  {
    rt::lock(_stream);
    return _stream->Read(bytes, offset, count);
  }
}

Int32 SyncStream___::Read(Span<Byte> buffer) {
  {
    rt::lock(_stream);
    return _stream->Read(buffer);
  }
}

Int32 SyncStream___::ReadByte() {
  {
    rt::lock(_stream);
    return _stream->ReadByte();
  }
}

IAsyncResult SyncStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  Boolean flag = _stream->HasOverriddenBeginEndRead();
  {
    rt::lock(_stream);
    return flag ? _stream->BeginRead(buffer, offset, count, callback, state) : _stream->BeginReadInternal(buffer, offset, count, callback, state, true, true);
  }
}

Int32 SyncStream___::EndRead(IAsyncResult asyncResult) {
  if (asyncResult == nullptr) {
    rt::throw_exception<ArgumentNullException>("asyncResult");
  }
  {
    rt::lock(_stream);
    return _stream->EndRead(asyncResult);
  }
}

Int64 SyncStream___::Seek(Int64 offset, SeekOrigin origin) {
  {
    rt::lock(_stream);
    return _stream->Seek(offset, origin);
  }
}

void SyncStream___::SetLength(Int64 length) {
  {
    rt::lock(_stream);
    _stream->SetLength(length);
  }
}

void SyncStream___::Write(Array<Byte> bytes, Int32 offset, Int32 count) {
  {
    rt::lock(_stream);
    _stream->Write(bytes, offset, count);
  }
}

void SyncStream___::Write(ReadOnlySpan<Byte> buffer) {
  {
    rt::lock(_stream);
    _stream->Write(buffer);
  }
}

void SyncStream___::WriteByte(Byte b) {
  {
    rt::lock(_stream);
    _stream->WriteByte(b);
  }
}

IAsyncResult SyncStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  Boolean flag = _stream->HasOverriddenBeginEndWrite();
  {
    rt::lock(_stream);
    return flag ? _stream->BeginWrite(buffer, offset, count, callback, state) : _stream->BeginWriteInternal(buffer, offset, count, callback, state, true, true);
  }
}

void SyncStream___::EndWrite(IAsyncResult asyncResult) {
  if (asyncResult == nullptr) {
    rt::throw_exception<ArgumentNullException>("asyncResult");
  }
  {
    rt::lock(_stream);
    _stream->EndWrite(asyncResult);
  }
}

Boolean Stream___::get_CanTimeout() {
  return false;
}

Int32 Stream___::get_ReadTimeout() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_TimeoutsNotSupported());
}

void Stream___::set_ReadTimeout(Int32 value) {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_TimeoutsNotSupported());
}

Int32 Stream___::get_WriteTimeout() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_TimeoutsNotSupported());
}

void Stream___::set_WriteTimeout(Int32 value) {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_TimeoutsNotSupported());
}

SemaphoreSlim Stream___::EnsureAsyncActiveSemaphoreInitialized() {
}

Task<> Stream___::CopyToAsync(Stream destination) {
  Int32 copyBufferSize = GetCopyBufferSize();
  return CopyToAsync(destination, copyBufferSize);
}

Task<> Stream___::CopyToAsync(Stream destination, Int32 bufferSize) {
  return CopyToAsync(destination, bufferSize, CancellationToken::get_None());
}

Task<> Stream___::CopyToAsync(Stream destination, CancellationToken cancellationToken) {
  Int32 copyBufferSize = GetCopyBufferSize();
  return CopyToAsync(destination, copyBufferSize, cancellationToken);
}

Task<> Stream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  StreamHelpers::ValidateCopyToArgs((Stream)this, destination, bufferSize);
  return CopyToAsyncInternal(destination, bufferSize, cancellationToken);
}

Task<> Stream___::CopyToAsyncInternal(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  Array<Byte> buffer = ArrayPool<Byte>::in::get_Shared()->Rent(bufferSize);
  try{
    while (true) {
    }
  } finally: {
    ArrayPool<Byte>::in::get_Shared()->Return(buffer);
  }
}

void Stream___::CopyTo(Stream destination) {
  Int32 copyBufferSize = GetCopyBufferSize();
  CopyTo(destination, copyBufferSize);
}

void Stream___::CopyTo(Stream destination, Int32 bufferSize) {
  StreamHelpers::ValidateCopyToArgs((Stream)this, destination, bufferSize);
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(bufferSize);
  try{
    Int32 count;
    while ((count = Read(array, 0, array->get_Length())) != 0) {
      destination->Write(array, 0, count);
    }
  } finally: {
    ArrayPool<Byte>::in::get_Shared()->Return(array);
  }
}

Int32 Stream___::GetCopyBufferSize() {
  Int32 num = 81920;
  if (get_CanSeek()) {
    Int64 length = get_Length();
    Int64 position = get_Position();
    if (length <= position) {
      num = 1;
    } else {
      Int64 num2 = length - position;
      if (num2 > 0) {
        num = (Int32)Math::Min(num, num2);
      }
    }
  }
  return num;
}

void Stream___::CopyTo(ReadOnlySpanAction<Byte, Object> callback, Object state, Int32 bufferSize) {
  if (callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
  CopyTo(rt::newobj<WriteCallbackStream>(callback, state), bufferSize);
}

Task<> Stream___::CopyToAsync(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> callback, Object state, Int32 bufferSize, CancellationToken cancellationToken) {
  if (callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
  return CopyToAsync(rt::newobj<WriteCallbackStream>(callback, state), bufferSize, cancellationToken);
}

void Stream___::Close() {
  Dispose(true);
  GC::SuppressFinalize((Stream)this);
}

void Stream___::Dispose() {
  Close();
}

void Stream___::Dispose(Boolean disposing) {
}

ValueTask<> Stream___::DisposeAsync() {
  try{
    Dispose();
    return ValueTask();
  } catch (Exception exception) {
  }
}

Task<> Stream___::FlushAsync() {
  return FlushAsync(CancellationToken::get_None());
}

Task<> Stream___::FlushAsync(CancellationToken cancellationToken) {
}

WaitHandle Stream___::CreateWaitHandle() {
  return rt::newobj<ManualResetEvent>(false);
}

IAsyncResult Stream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return BeginReadInternal(buffer, offset, count, callback, state, false, true);
}

IAsyncResult Stream___::BeginReadInternal(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state, Boolean serializeAsynchronously, Boolean apm) {
  if (!get_CanRead()) {
    rt::throw_exception(Error::GetReadNotSupported());
  }
  SemaphoreSlim semaphoreSlim = EnsureAsyncActiveSemaphoreInitialized();
  Task task = nullptr;
  if (serializeAsynchronously) {
    task = semaphoreSlim->WaitAsync();
  } else {
    semaphoreSlim->Wait();
  }
}

Int32 Stream___::EndRead(IAsyncResult asyncResult) {
  if (asyncResult == nullptr) {
    rt::throw_exception<ArgumentNullException>("asyncResult");
  }
  ReadWriteTask readWriteTask = rt::as<ReadWriteTask>(asyncResult);
  if (readWriteTask == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_WrongAsyncResultOrEndReadCalledMultiple());
  }
  if (readWriteTask->_endCalled) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_WrongAsyncResultOrEndReadCalledMultiple());
  }
  if (!readWriteTask->_isRead) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_WrongAsyncResultOrEndReadCalledMultiple());
  }
  try{
    return readWriteTask->GetAwaiter().GetResult();
  } finally: {
    FinishTrackingAsyncOperation(readWriteTask);
  }
}

Task<Int32> Stream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  return ReadAsync(buffer, offset, count, CancellationToken::get_None());
}

Task<Int32> Stream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return BeginEndReadAsync(buffer, offset, count);
  }
  return Task::in::FromCanceled<Int32>(cancellationToken);
}

ValueTask<Int32> Stream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  auto FinishReadAsync = [](Task<Int32> readTask, Array<Byte> localBuffer, Memory<Byte> localDestination) -> ValueTask<Int32> {
    try{
    } finally: {
      ArrayPool<Byte>::in::get_Shared()->Return(localBuffer);
    }
  };
  ArraySegment<Byte> segment;
  if (MemoryMarshal::TryGetArray(buffer, segment)) {
    return ValueTask<Int32>(ReadAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count(), cancellationToken));
  }
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(buffer.get_Length());
  return FinishReadAsync(ReadAsync(array, 0, buffer.get_Length(), cancellationToken), array, buffer);
}

Task<Int32> Stream___::BeginEndReadAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (!HasOverriddenBeginEndRead()) {
    return (Task<Int32>)BeginReadInternal(buffer, offset, count, nullptr, nullptr, true, false);
  }
}

IAsyncResult Stream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return BeginWriteInternal(buffer, offset, count, callback, state, false, true);
}

IAsyncResult Stream___::BeginWriteInternal(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state, Boolean serializeAsynchronously, Boolean apm) {
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
  SemaphoreSlim semaphoreSlim = EnsureAsyncActiveSemaphoreInitialized();
  Task task = nullptr;
  if (serializeAsynchronously) {
    task = semaphoreSlim->WaitAsync();
  } else {
    semaphoreSlim->Wait();
  }
}

void Stream___::RunReadWriteTaskWhenReady(Task<> asyncWaiter, ReadWriteTask readWriteTask) {
  if (asyncWaiter->get_IsCompleted()) {
    RunReadWriteTask(readWriteTask);
    return;
  }
}

void Stream___::RunReadWriteTask(ReadWriteTask readWriteTask) {
  readWriteTask->m_taskScheduler = TaskScheduler::in::get_Default();
  readWriteTask->ScheduleAndStart(false);
}

void Stream___::FinishTrackingAsyncOperation(ReadWriteTask task) {
  task->_endCalled = true;
  _asyncActiveSemaphore->Release();
}

void Stream___::EndWrite(IAsyncResult asyncResult) {
  if (asyncResult == nullptr) {
    rt::throw_exception<ArgumentNullException>("asyncResult");
  }
  ReadWriteTask readWriteTask = rt::as<ReadWriteTask>(asyncResult);
  if (readWriteTask == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_WrongAsyncResultOrEndWriteCalledMultiple());
  }
  if (readWriteTask->_endCalled) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_WrongAsyncResultOrEndWriteCalledMultiple());
  }
  if (readWriteTask->_isRead) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_WrongAsyncResultOrEndWriteCalledMultiple());
  }
  try{
    readWriteTask->GetAwaiter().GetResult();
  } finally: {
    FinishTrackingAsyncOperation(readWriteTask);
  }
}

Task<> Stream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  return WriteAsync(buffer, offset, count, CancellationToken::get_None());
}

Task<> Stream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return BeginEndWriteAsync(buffer, offset, count);
  }
  return Task::in::FromCanceled(cancellationToken);
}

ValueTask<> Stream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  ArraySegment<Byte> segment;
  if (MemoryMarshal::TryGetArray(buffer, segment)) {
    return ValueTask(WriteAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count(), cancellationToken));
  }
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(buffer.get_Length());
  buffer.get_Span().CopyTo(array);
  return ValueTask(FinishWriteAsync(WriteAsync(array, 0, buffer.get_Length(), cancellationToken), array));
}

Task<> Stream___::FinishWriteAsync(Task<> writeTask, Array<Byte> localBuffer) {
  try{
  } finally: {
    ArrayPool<Byte>::in::get_Shared()->Return(localBuffer);
  }
}

Task<> Stream___::BeginEndWriteAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (!HasOverriddenBeginEndWrite()) {
    return (Task)BeginWriteInternal(buffer, offset, count, nullptr, nullptr, true, false);
  }
}

Int32 Stream___::Read(Span<Byte> buffer) {
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(buffer.get_Length());
  try{
    Int32 num = Read(array, 0, buffer.get_Length());
    if ((UInt32)num > (UInt32)buffer.get_Length()) {
      rt::throw_exception<IOException>(SR::get_IO_StreamTooLong());
    }
    Span<Byte>(array, 0, num).CopyTo(buffer);
    return num;
  } finally: {
    ArrayPool<Byte>::in::get_Shared()->Return(array);
  }
}

Int32 Stream___::ReadByte() {
  Array<Byte> array = rt::newarr<Array<Byte>>(1);
  if (Read(array, 0, 1) == 0) {
    return -1;
  }
  return array[0];
}

void Stream___::Write(ReadOnlySpan<Byte> buffer) {
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(buffer.get_Length());
  try{
    buffer.CopyTo(array);
    Write(array, 0, buffer.get_Length());
  } finally: {
    ArrayPool<Byte>::in::get_Shared()->Return(array);
  }
}

void Stream___::WriteByte(Byte value) {
  Write(rt::newarr<Array<Byte>>(1), 0, 1);
}

Stream Stream___::Synchronized(Stream stream) {
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream");
  }
  if (rt::is<SyncStream>(stream)) {
    return stream;
  }
  return rt::newobj<SyncStream>(stream);
}

void Stream___::ObjectInvariant() {
}

IAsyncResult Stream___::BlockingBeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  SynchronousAsyncResult synchronousAsyncResult;
  try{
    Int32 bytesRead = Read(buffer, offset, count);
    synchronousAsyncResult = rt::newobj<SynchronousAsyncResult>(bytesRead, state);
  } catch (IOException ex) {
  }
  auto& default = callback;
  default == nullptr ? nullptr : default->Invoke(synchronousAsyncResult);
  return synchronousAsyncResult;
}

Int32 Stream___::BlockingEndRead(IAsyncResult asyncResult) {
  return SynchronousAsyncResult::in::EndRead(asyncResult);
}

IAsyncResult Stream___::BlockingBeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  SynchronousAsyncResult synchronousAsyncResult;
  try{
    Write(buffer, offset, count);
    synchronousAsyncResult = rt::newobj<SynchronousAsyncResult>(state);
  } catch (IOException ex) {
  }
  auto& default = callback;
  default == nullptr ? nullptr : default->Invoke(synchronousAsyncResult);
  return synchronousAsyncResult;
}

void Stream___::BlockingEndWrite(IAsyncResult asyncResult) {
  SynchronousAsyncResult::in::EndWrite(asyncResult);
}

void Stream___::ctor() {
}

void Stream___::cctor() {
  Null = rt::newobj<NullStream>();
}

} // namespace System::Private::CoreLib::System::IO::StreamNamespace
