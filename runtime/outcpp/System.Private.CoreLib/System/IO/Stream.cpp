#include "Stream-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArraySegment-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/Error-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/Stream-dep.h>
#include <System.Private.CoreLib/System/IO/StreamHelpers-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/ContextCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/LazyInitializer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskContinuationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskFactory-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::StreamNamespace {
using namespace System::Buffers;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::ExceptionServices;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
using namespace System::Threading::Tasks;

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

void Stream___::ReadWriteTask___::InvokeOfITaskCompletionAction(Task<> completingTask) {
  ExecutionContext context = _context;
  if (context == nullptr) {
    AsyncCallback callback = _callback;
    _callback = nullptr;
    callback(completingTask);
  } else {
    _context = nullptr;
    ContextCallback as = s_invokeAsyncCallback;
    ContextCallback callback2 = as != nullptr ? as : (s_invokeAsyncCallback = &InvokeAsyncCallback);
    ExecutionContext::in::RunInternal(context, callback2, (ReadWriteTask)this);
  }
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
    return Task<>::in::get_CompletedTask();
  }
  return Task<>::in::FromCanceled(cancellationToken);
}

void NullStream___::Dispose(Boolean disposing) {
}

void NullStream___::Flush() {
}

Task<> NullStream___::FlushAsync(CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::get_CompletedTask();
  }
  return Task<>::in::FromCanceled(cancellationToken);
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

template <>
ValueTask<Int32> NullStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>((Int32)0);
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
    return Task<>::in::get_CompletedTask();
  }
  return Task<>::in::FromCanceled(cancellationToken);
}

template <>
ValueTask<> NullStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return rt::default__;
  }
  return ValueTask<>::FromCanceled(cancellationToken);
}

void NullStream___::WriteByte(Byte value) {
}

Int64 NullStream___::Seek(Int64 offset, SeekOrigin origin) {
  return 0;
}

void NullStream___::SetLength(Int64 length) {
}

void NullStream___::cctor() {
  s_zeroTask = Task<>::in::FromResult(0);
}

void Stream___::SynchronousAsyncResult___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void Stream___::SynchronousAsyncResult___::__c___::ctor() {
}

ManualResetEvent Stream___::SynchronousAsyncResult___::__c___::_get_AsyncWaitHandle_b__12_0() {
  return rt::newobj<ManualResetEvent>(true);
}

Boolean Stream___::SynchronousAsyncResult___::get_IsCompleted() {
  return true;
}

WaitHandle Stream___::SynchronousAsyncResult___::get_AsyncWaitHandle() {
  Func<ManualResetEvent> as = __c::in::__9__12_0;
  return LazyInitializer::EnsureInitialized(_waitHandle, as != nullptr ? as : (__c::in::__9__12_0 = &__c::in::__9->_get_AsyncWaitHandle_b__12_0));
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
    _stream->set_Position(value);
  }
}

Int32 SyncStream___::get_ReadTimeout() {
  return _stream->get_ReadTimeout();
}

void SyncStream___::set_ReadTimeout(Int32 value) {
  _stream->set_ReadTimeout(value);
}

Int32 SyncStream___::get_WriteTimeout() {
  return _stream->get_WriteTimeout();
}

void SyncStream___::set_WriteTimeout(Int32 value) {
  _stream->set_WriteTimeout(value);
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
    try {
      _stream->Close();
    } catch (...) {
    } finally: {
      Stream::in::Dispose(true);
    }
  }
}

void SyncStream___::Dispose(Boolean disposing) {
  {
    rt::lock(_stream);
    try {
      if (disposing) {
        ((IDisposable)_stream)->Dispose();
      }
    } catch (...) {
    } finally: {
      Stream::in::Dispose(disposing);
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

void Stream___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void Stream___::__c___::ctor() {
}

SemaphoreSlim Stream___::__c___::_EnsureAsyncActiveSemaphoreInitialized_b__5_0() {
  return rt::newobj<SemaphoreSlim>(1, 1);
}

void Stream___::__c___::_FlushAsync_b__39_0(Object state) {
  ((Stream)state)->Flush();
}

Int32 Stream___::__c___::_BeginReadInternal_b__42_0(Object _p0_) {
  ReadWriteTask readWriteTask = rt::as<ReadWriteTask>(Task<>::in::get_InternalCurrent());
  try {
    return readWriteTask->_stream->Read(readWriteTask->_buffer, readWriteTask->_offset, readWriteTask->_count);
  } catch (...) {
  } finally: {
    if (!readWriteTask->_apm) {
      readWriteTask->_stream->FinishTrackingAsyncOperation(readWriteTask);
    }
    readWriteTask->ClearBeginState();
  }
}

IAsyncResult Stream___::__c___::_BeginEndReadAsync_b__47_0(Stream stream, ReadWriteParameters args, AsyncCallback callback, Object state) {
  return stream->BeginRead(args.Buffer, args.Offset, args.Count, callback, state);
}

Int32 Stream___::__c___::_BeginEndReadAsync_b__47_1(Stream stream, IAsyncResult asyncResult) {
  return stream->EndRead(asyncResult);
}

Int32 Stream___::__c___::_BeginWriteInternal_b__50_0(Object _p0_) {
  ReadWriteTask readWriteTask = rt::as<ReadWriteTask>(Task<>::in::get_InternalCurrent());
  try {
    readWriteTask->_stream->Write(readWriteTask->_buffer, readWriteTask->_offset, readWriteTask->_count);
    return 0;
  } catch (...) {
  } finally: {
    if (!readWriteTask->_apm) {
      readWriteTask->_stream->FinishTrackingAsyncOperation(readWriteTask);
    }
    readWriteTask->ClearBeginState();
  }
}

void Stream___::__c___::_RunReadWriteTaskWhenReady_b__51_0(Task<> t, Object state) {
  ReadWriteTask readWriteTask = (ReadWriteTask)state;
  readWriteTask->_stream->RunReadWriteTask(readWriteTask);
}

IAsyncResult Stream___::__c___::_BeginEndWriteAsync_b__60_0(Stream stream, ReadWriteParameters args, AsyncCallback callback, Object state) {
  return stream->BeginWrite(args.Buffer, args.Offset, args.Count, callback, state);
}

VoidTaskResult Stream___::__c___::_BeginEndWriteAsync_b__60_1(Stream stream, IAsyncResult asyncResult) {
  stream->EndWrite(asyncResult);
  return rt::default__;
}

void Stream___::_CopyToAsyncInternal_d__29::MoveNext() {
  Int32 num = <>1__state;
  Stream stream = <>4__this;
  try {
    if ((UInt32)num > 1u) {
      <buffer>5__2 = ArrayPool<Byte>::in::get_Shared()->Rent(bufferSize);
    }
    try {
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter;
      if (num != 0) {
        if (num != 1) {
          goto IL_0033;
        }
        awaiter = <>u__2;
        <>u__2 = rt::default__;
        num = (<>1__state = -1);
        goto IL_0133;
      }
      ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter2 = <>u__1;
      <>u__1 = rt::default__;
      num = (<>1__state = -1);
      goto IL_00a9;

    IL_00a9:
      Int32 result = awaiter2.GetResult();
      Int32 num2 = result;
      if (num2 != 0) {
        awaiter = destination->WriteAsync(ReadOnlyMemory<Byte>(<buffer>5__2, 0, num2), cancellationToken).ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (<>1__state = 1);
          <>u__2 = awaiter;
          <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
        goto IL_0133;
      }
      goto end_IL_0029;

    IL_0033:
      awaiter2 = stream->ReadAsync(Memory<Byte>(<buffer>5__2), cancellationToken).ConfigureAwait(false).GetAwaiter();
      if (!awaiter2.get_IsCompleted()) {
        num = (<>1__state = 0);
        <>u__1 = awaiter2;
        <>t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
        return;
      }
      goto IL_00a9;

    IL_0133:
      awaiter.GetResult();
      goto IL_0033;

    end_IL_0029:
    } catch (...) {
    } finally: {
      if (num < 0) {
        ArrayPool<Byte>::in::get_Shared()->Return(<buffer>5__2);
      }
    }
  } catch (Exception exception) {
    <>1__state = -2;
    <buffer>5__2 = nullptr;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <buffer>5__2 = nullptr;
  <>t__builder.SetResult();
}

void Stream___::_CopyToAsyncInternal_d__29::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
}

void Stream___::_FinishWriteAsync_d__59::MoveNext() {
  Int32 num = <>1__state;
  try {
    try {
      ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
      if (num != 0) {
        awaiter = writeTask->ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (<>1__state = 0);
          <>u__1 = awaiter;
          <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
      } else {
        awaiter = <>u__1;
        <>u__1 = rt::default__;
        num = (<>1__state = -1);
      }
      awaiter.GetResult();
    } catch (...) {
    } finally: {
      if (num < 0) {
        ArrayPool<Byte>::in::get_Shared()->Return(localBuffer);
      }
    }
  } catch (Exception exception) {
    <>1__state = -2;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <>t__builder.SetResult();
}

void Stream___::_FinishWriteAsync_d__59::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
}

void Stream___::__ReadAsync_g__FinishReadAsync46_0_d::MoveNext() {
  Int32 num = <>1__state;
  Int32 result2;
  try {
    try {
      ConfiguredTaskAwaitable<TResult>::ConfiguredTaskAwaiter awaiter;
      if (num != 0) {
        awaiter = readTask->ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (<>1__state = 0);
          <>u__1 = awaiter;
          <>t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
      } else {
        awaiter = <>u__1;
        <>u__1 = rt::default__;
        num = (<>1__state = -1);
      }
      Int32 result = awaiter.GetResult();
      Int32 num2 = result;
      Span<Byte>(localBuffer, 0, num2).CopyTo(localDestination.get_Span());
      result2 = num2;
    } catch (...) {
    } finally: {
      if (num < 0) {
        ArrayPool<Byte>::in::get_Shared()->Return(localBuffer);
      }
    }
  } catch (Exception exception) {
    <>1__state = -2;
    <>t__builder.SetException(exception);
    return;
  }
  <>1__state = -2;
  <>t__builder.SetResult(result2);
}

void Stream___::__ReadAsync_g__FinishReadAsync46_0_d::SetStateMachine(IAsyncStateMachine stateMachine) {
  <>t__builder.SetStateMachine(stateMachine);
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
  Func<SemaphoreSlim> as = __c::in::__9__5_0;
  return LazyInitializer::EnsureInitialized(_asyncActiveSemaphore, as != nullptr ? as : (__c::in::__9__5_0 = &__c::in::__9->_EnsureAsyncActiveSemaphoreInitialized_b__5_0));
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
  _CopyToAsyncInternal_d__29 stateMachine;
  stateMachine.__t__builder = AsyncTaskMethodBuilder<>::Create();
  stateMachine.__4__this = (Stream)this;
  stateMachine.destination = destination;
  stateMachine.bufferSize = bufferSize;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

void Stream___::CopyTo(Stream destination) {
  Int32 copyBufferSize = GetCopyBufferSize();
  CopyTo(destination, copyBufferSize);
}

void Stream___::CopyTo(Stream destination, Int32 bufferSize) {
  StreamHelpers::ValidateCopyToArgs((Stream)this, destination, bufferSize);
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(bufferSize);
  try {
    Int32 count;
    while ((count = Read(array, 0, array->get_Length())) != 0) {
      destination->Write(array, 0, count);
    }
  } catch (...) {
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
  try {
    Dispose();
    return rt::default__;
  } catch (Exception exception) {
    return ValueTask<>::FromException(exception);
  }
}

Task<> Stream___::FlushAsync() {
  return FlushAsync(CancellationToken::get_None());
}

Task<> Stream___::FlushAsync(CancellationToken cancellationToken) {
  Action<Object> as = __c::in::__9__39_0;
  return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__39_0 = &__c::in::__9->_FlushAsync_b__39_0), (Stream)this, cancellationToken, TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
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
  Task<> task = nullptr;
  if (serializeAsynchronously) {
    task = semaphoreSlim->WaitAsync();
  } else {
    semaphoreSlim->Wait();
  }
  Func<Object, Int32> as = __c::in::__9__42_0;
  ReadWriteTask readWriteTask = rt::newobj<ReadWriteTask>(true, apm, as != nullptr ? as : (__c::in::__9__42_0 = &__c::in::__9->_BeginReadInternal_b__42_0), state, (Stream)this, buffer, offset, count, callback);
  if (task != nullptr) {
    RunReadWriteTaskWhenReady(task, readWriteTask);
  } else {
    RunReadWriteTask(readWriteTask);
  }
  return readWriteTask;
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
  try {
    return readWriteTask->GetAwaiter().GetResult();
  } catch (...) {
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
  return Task<>::in::FromCanceled<Int32>(cancellationToken);
}

template <>
ValueTask<Int32> Stream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  auto FinishReadAsync = [](Task<Int32> readTask, Array<Byte> localBuffer, Memory<Byte> localDestination) -> ValueTask<Int32> {
    __ReadAsync_g__FinishReadAsync46_0_d stateMachine;
    stateMachine.__t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
    stateMachine.readTask = readTask;
    stateMachine.localBuffer = localBuffer;
    stateMachine.localDestination = localDestination;
    stateMachine.__1__state = -1;
    stateMachine.__t__builder.Start(stateMachine);
    return stateMachine.__t__builder.get_Task();
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
  Func<Stream, ReadWriteParameters, AsyncCallback, Object, IAsyncResult> as = __c::in::__9__47_0;
  Func<Stream, IAsyncResult, Int32> is = __c::in::__9__47_1;
  return TaskFactory<Int32>::in::FromAsyncTrim((Stream)this, ReadWriteParameters(), as != nullptr ? as : (__c::in::__9__47_0 = &__c::in::__9->_BeginEndReadAsync_b__47_0), is != nullptr ? is : (__c::in::__9__47_1 = &__c::in::__9->_BeginEndReadAsync_b__47_1));
}

IAsyncResult Stream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return BeginWriteInternal(buffer, offset, count, callback, state, false, true);
}

IAsyncResult Stream___::BeginWriteInternal(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state, Boolean serializeAsynchronously, Boolean apm) {
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
  SemaphoreSlim semaphoreSlim = EnsureAsyncActiveSemaphoreInitialized();
  Task<> task = nullptr;
  if (serializeAsynchronously) {
    task = semaphoreSlim->WaitAsync();
  } else {
    semaphoreSlim->Wait();
  }
  Func<Object, Int32> as = __c::in::__9__50_0;
  ReadWriteTask readWriteTask = rt::newobj<ReadWriteTask>(false, apm, as != nullptr ? as : (__c::in::__9__50_0 = &__c::in::__9->_BeginWriteInternal_b__50_0), state, (Stream)this, buffer, offset, count, callback);
  if (task != nullptr) {
    RunReadWriteTaskWhenReady(task, readWriteTask);
  } else {
    RunReadWriteTask(readWriteTask);
  }
  return readWriteTask;
}

void Stream___::RunReadWriteTaskWhenReady(Task<> asyncWaiter, ReadWriteTask readWriteTask) {
  if (asyncWaiter->get_IsCompleted()) {
    RunReadWriteTask(readWriteTask);
  } else {
    Action<Task<>, Object> as = __c::in::__9__51_0;
    asyncWaiter->ContinueWith(as != nullptr ? as : (__c::in::__9__51_0 = &__c::in::__9->_RunReadWriteTaskWhenReady_b__51_0), readWriteTask, rt::default__, TaskContinuationOptions::ExecuteSynchronously, TaskScheduler::in::get_Default());
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
  try {
    readWriteTask->GetAwaiter().GetResult();
  } catch (...) {
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
  return Task<>::in::FromCanceled(cancellationToken);
}

template <>
ValueTask<> Stream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  ArraySegment<Byte> segment;
  if (MemoryMarshal::TryGetArray(buffer, segment)) {
    return ValueTask<>(WriteAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count(), cancellationToken));
  }
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(buffer.get_Length());
  buffer.get_Span().CopyTo(array);
  return ValueTask<>(FinishWriteAsync(WriteAsync(array, 0, buffer.get_Length(), cancellationToken), array));
}

Task<> Stream___::FinishWriteAsync(Task<> writeTask, Array<Byte> localBuffer) {
  _FinishWriteAsync_d__59 stateMachine;
  stateMachine.__t__builder = AsyncTaskMethodBuilder<>::Create();
  stateMachine.writeTask = writeTask;
  stateMachine.localBuffer = localBuffer;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

Task<> Stream___::BeginEndWriteAsync(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (!HasOverriddenBeginEndWrite()) {
    return (Task<>)BeginWriteInternal(buffer, offset, count, nullptr, nullptr, true, false);
  }
  Func<Stream, ReadWriteParameters, AsyncCallback, Object, IAsyncResult> as = __c::in::__9__60_0;
  Func<Stream, IAsyncResult, VoidTaskResult> is = __c::in::__9__60_1;
  return TaskFactory<VoidTaskResult>::in::FromAsyncTrim((Stream)this, ReadWriteParameters(), as != nullptr ? as : (__c::in::__9__60_0 = &__c::in::__9->_BeginEndWriteAsync_b__60_0), is != nullptr ? is : (__c::in::__9__60_1 = &__c::in::__9->_BeginEndWriteAsync_b__60_1));
}

Int32 Stream___::Read(Span<Byte> buffer) {
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(buffer.get_Length());
  try {
    Int32 num = Read(array, 0, buffer.get_Length());
    if ((UInt32)num > (UInt32)buffer.get_Length()) {
      rt::throw_exception<IOException>(SR::get_IO_StreamTooLong());
    }
    Span<Byte>(array, 0, num).CopyTo(buffer);
    return num;
  } catch (...) {
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
  try {
    buffer.CopyTo(array);
    Write(array, 0, buffer.get_Length());
  } catch (...) {
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
  try {
    Int32 bytesRead = Read(buffer, offset, count);
    synchronousAsyncResult = rt::newobj<SynchronousAsyncResult>(bytesRead, state);
  } catch (IOException ex) {
    synchronousAsyncResult = rt::newobj<SynchronousAsyncResult>(ex, state, false);
  }
  if (callback != nullptr) {
    callback(synchronousAsyncResult);
  }
  return synchronousAsyncResult;
}

Int32 Stream___::BlockingEndRead(IAsyncResult asyncResult) {
  return SynchronousAsyncResult::in::EndRead(asyncResult);
}

IAsyncResult Stream___::BlockingBeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  SynchronousAsyncResult synchronousAsyncResult;
  try {
    Write(buffer, offset, count);
    synchronousAsyncResult = rt::newobj<SynchronousAsyncResult>(state);
  } catch (IOException ex) {
    synchronousAsyncResult = rt::newobj<SynchronousAsyncResult>(ex, state, true);
  }
  if (callback != nullptr) {
    callback(synchronousAsyncResult);
  }
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

ValueTask<Int32> Stream___::_ReadAsync_g__FinishReadAsync46_0(Task<Int32> readTask, Array<Byte> localBuffer, Memory<Byte> localDestination) {
  __ReadAsync_g__FinishReadAsync46_0_d stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
  stateMachine.readTask = readTask;
  stateMachine.localBuffer = localBuffer;
  stateMachine.localDestination = localDestination;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

} // namespace System::Private::CoreLib::System::IO::StreamNamespace
