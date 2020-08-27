#include "CancellationTokenSource-dep.h"

#include <System.Private.CoreLib/System/AggregateException-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenSource-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEvent-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinLock-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueueTimer-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::CancellationTokenSourceNamespace {
using namespace System::Collections::Generic;

void CancellationTokenSource___::CallbackNode___::ctor(CallbackPartition partition) {
  Partition = partition;
}

void CancellationTokenSource___::CallbackNode___::ExecuteCallback() {
  ExecutionContext executionContext = ExecutionContext;
  if (executionContext != nullptr) {
  } else {
    Callback(CallbackState);
  }
}

void Linked1CancellationTokenSource___::ctor(CancellationToken token1) {
  _reg1 = token1.UnsafeRegister(CancellationTokenSource::in::LinkedNCancellationTokenSource::in::s_linkedTokenCancelDelegate, (Linked1CancellationTokenSource)this);
}

void Linked1CancellationTokenSource___::Dispose(Boolean disposing) {
  if (disposing && !_disposed) {
    _reg1.Dispose();
    CancellationTokenSource::in::Dispose(disposing);
  }
}

void Linked2CancellationTokenSource___::ctor(CancellationToken token1, CancellationToken token2) {
  _reg1 = token1.UnsafeRegister(CancellationTokenSource::in::LinkedNCancellationTokenSource::in::s_linkedTokenCancelDelegate, (Linked2CancellationTokenSource)this);
  _reg2 = token2.UnsafeRegister(CancellationTokenSource::in::LinkedNCancellationTokenSource::in::s_linkedTokenCancelDelegate, (Linked2CancellationTokenSource)this);
}

void Linked2CancellationTokenSource___::Dispose(Boolean disposing) {
  if (disposing && !_disposed) {
    _reg1.Dispose();
    _reg2.Dispose();
    CancellationTokenSource::in::Dispose(disposing);
  }
}

void LinkedNCancellationTokenSource___::ctor(Array<CancellationToken> tokens) {
  _linkingRegistrations = rt::newarr<Array<CancellationTokenRegistration>>(tokens->get_Length());
  for (Int32 i = 0; i < tokens->get_Length(); i++) {
    if (tokens[i].get_CanBeCanceled()) {
      _linkingRegistrations[i] = tokens[i].UnsafeRegister(s_linkedTokenCancelDelegate, (LinkedNCancellationTokenSource)this);
    }
  }
}

void LinkedNCancellationTokenSource___::Dispose(Boolean disposing) {
  if (!disposing || _disposed) {
    return;
  }
  Array<CancellationTokenRegistration> linkingRegistrations = _linkingRegistrations;
  if (linkingRegistrations != nullptr) {
    _linkingRegistrations = nullptr;
    for (Int32 i = 0; i < linkingRegistrations->get_Length(); i++) {
      linkingRegistrations[i].Dispose();
    }
  }
  CancellationTokenSource::in::Dispose(disposing);
}

void LinkedNCancellationTokenSource___::cctor() {
}

void CancellationTokenSource___::CallbackPartition___::ctor(CancellationTokenSource source) {
  Lock = SpinLock(false);
  NextAvailableId = 1;
  Object::in::ctor();
  Source = source;
}

Boolean CancellationTokenSource___::CallbackPartition___::Unregister(Int64 id, CallbackNode node) {
  if (id == 0) {
    return false;
  }
  Boolean lockTaken = false;
  Lock.Enter(lockTaken);
  try {
    if (node->Id != id) {
      return false;
    }
    if (Callbacks == node) {
      Callbacks = node->Next;
    } else {
      node->Prev->Next = node->Next;
    }
    if (node->Next != nullptr) {
      node->Next->Prev = node->Prev;
    }
    node->Id = 0;
    node->Callback = nullptr;
    node->CallbackState = nullptr;
    node->ExecutionContext = nullptr;
    node->SynchronizationContext = nullptr;
    node->Prev = nullptr;
    node->Next = FreeNodeList;
    FreeNodeList = node;
    return true;
  } catch (...) {
  } finally: {
    Lock.Exit(false);
  }
}

Boolean CancellationTokenSource___::get_IsCancellationRequested() {
  return _state >= 2;
}

Boolean CancellationTokenSource___::get_IsCancellationCompleted() {
  return _state == 3;
}

Int32 CancellationTokenSource___::get_ThreadIDExecutingCallbacks() {
  return _threadIDExecutingCallbacks;
}

void CancellationTokenSource___::set_ThreadIDExecutingCallbacks(Int32 value) {
  _threadIDExecutingCallbacks = value;
}

CancellationToken CancellationTokenSource___::get_Token() {
  ThrowIfDisposed();
  return CancellationToken((CancellationTokenSource)this);
}

WaitHandle CancellationTokenSource___::get_WaitHandle() {
  ThrowIfDisposed();
  if (_kernelEvent != nullptr) {
    return _kernelEvent;
  }
  ManualResetEvent manualResetEvent = rt::newobj<ManualResetEvent>(false);
  if (Interlocked::CompareExchange(_kernelEvent, manualResetEvent, (ManualResetEvent)nullptr) != nullptr) {
    manualResetEvent->Dispose();
  }
  if (get_IsCancellationRequested()) {
    _kernelEvent->Set();
  }
  return _kernelEvent;
}

Int64 CancellationTokenSource___::get_ExecutingCallback() {
  return Volatile::Read(_executingCallbackId);
}

void CancellationTokenSource___::ctor() {
  _threadIDExecutingCallbacks = -1;
  Object::in::ctor();
  _state = 1;
}

void CancellationTokenSource___::ctor(TimeSpan delay) {
  _threadIDExecutingCallbacks = -1;
  Object::in::ctor();
  Int64 num = (Int64)delay.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("delay");
  }
  InitializeWithTimer((Int32)num);
}

void CancellationTokenSource___::ctor(Int32 millisecondsDelay) {
  _threadIDExecutingCallbacks = -1;
  Object::in::ctor();
  if (millisecondsDelay < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsDelay");
  }
  InitializeWithTimer(millisecondsDelay);
}

void CancellationTokenSource___::InitializeWithTimer(Int32 millisecondsDelay) {
  if (millisecondsDelay == 0) {
    _state = 3;
    return;
  }
  _state = 1;
  _timer = rt::newobj<TimerQueueTimer>(s_timerCallback, (CancellationTokenSource)this, (UInt32)millisecondsDelay, UInt32::MaxValue, false);
}

void CancellationTokenSource___::Cancel() {
  Cancel(false);
}

void CancellationTokenSource___::Cancel(Boolean throwOnFirstException) {
  ThrowIfDisposed();
  NotifyCancellation(throwOnFirstException);
}

void CancellationTokenSource___::CancelAfter(TimeSpan delay) {
  Int64 num = (Int64)delay.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("delay");
  }
  CancelAfter((Int32)num);
}

void CancellationTokenSource___::CancelAfter(Int32 millisecondsDelay) {
  ThrowIfDisposed();
  if (millisecondsDelay < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsDelay");
  }
  if (get_IsCancellationRequested()) {
    return;
  }
  TimerQueueTimer timerQueueTimer = _timer;
  if (timerQueueTimer == nullptr) {
    timerQueueTimer = rt::newobj<TimerQueueTimer>(s_timerCallback, (CancellationTokenSource)this, UInt32::MaxValue, UInt32::MaxValue, false);
    TimerQueueTimer timerQueueTimer2 = Interlocked::CompareExchange(_timer, timerQueueTimer, (TimerQueueTimer)nullptr);
    if (timerQueueTimer2 != nullptr) {
      timerQueueTimer->Close();
      timerQueueTimer = timerQueueTimer2;
    }
  }
  try {
    timerQueueTimer->Change((UInt32)millisecondsDelay, UInt32::MaxValue);
  } catch (ObjectDisposedException) {
  }
}

void CancellationTokenSource___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((CancellationTokenSource)this);
}

void CancellationTokenSource___::Dispose(Boolean disposing) {
  if (!disposing || _disposed) {
    return;
  }
  TimerQueueTimer timer = _timer;
  if (timer != nullptr) {
    _timer = nullptr;
    timer->Close();
  }
  _callbackPartitions = nullptr;
  if (_kernelEvent != nullptr) {
    ManualResetEvent manualResetEvent = Interlocked::Exchange(_kernelEvent, (ManualResetEvent)nullptr);
    if (manualResetEvent != nullptr && _state != 2) {
      manualResetEvent->Dispose();
    }
  }
  _disposed = true;
}

void CancellationTokenSource___::ThrowIfDisposed() {
  if (_disposed) {
    ThrowObjectDisposedException();
  }
}

void CancellationTokenSource___::ThrowObjectDisposedException() {
  rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_CancellationTokenSource_Disposed());
}

CancellationTokenRegistration CancellationTokenSource___::InternalRegister(Action<Object> callback, Object stateForCallback, SynchronizationContext syncContext, ExecutionContext executionContext) {
  if (!get_IsCancellationRequested()) {
    if (_disposed) {
      return CancellationTokenRegistration();
    }
    Array<CallbackPartition> array = _callbackPartitions;
    if (array == nullptr) {
      array = rt::newarr<Array<CallbackPartition>>(s_numPartitions);
      Array<CallbackPartition> as = Interlocked::CompareExchange(_callbackPartitions, array, (Array<CallbackPartition>)nullptr);
      array = (as != nullptr ? as : array);
    }
    Int32 num = Environment::get_CurrentManagedThreadId() & s_numPartitionsMask;
    CallbackPartition callbackPartition = array[num];
    if (callbackPartition == nullptr) {
      callbackPartition = rt::newobj<CallbackPartition>((CancellationTokenSource)this);
      CallbackPartition as = Interlocked::CompareExchange(array[num], callbackPartition, (CallbackPartition)nullptr);
      callbackPartition = (as != nullptr ? as : callbackPartition);
    }
    Boolean lockTaken = false;
    callbackPartition->Lock.Enter(lockTaken);
    Int64 id;
    CallbackNode callbackNode;
    try {
      id = callbackPartition->NextAvailableId++;
      callbackNode = callbackPartition->FreeNodeList;
      if (callbackNode != nullptr) {
        callbackPartition->FreeNodeList = callbackNode->Next;
      } else {
        callbackNode = rt::newobj<CallbackNode>(callbackPartition);
      }
      callbackNode->Id = id;
      callbackNode->Callback = callback;
      callbackNode->CallbackState = stateForCallback;
      callbackNode->ExecutionContext = executionContext;
      callbackNode->SynchronizationContext = syncContext;
      callbackNode->Next = callbackPartition->Callbacks;
      if (callbackNode->Next != nullptr) {
        callbackNode->Next->Prev = callbackNode;
      }
      callbackPartition->Callbacks = callbackNode;
    } catch (...) {
    } finally: {
      callbackPartition->Lock.Exit(false);
    }
    CancellationTokenRegistration result = CancellationTokenRegistration(id, callbackNode);
    if (!get_IsCancellationRequested() || !callbackPartition->Unregister(id, callbackNode)) {
      return result;
    }
  }
  callback(stateForCallback);
  return CancellationTokenRegistration();
}

void CancellationTokenSource___::NotifyCancellation(Boolean throwOnFirstException) {
  if (!get_IsCancellationRequested() && Interlocked::CompareExchange(_state, 2, 1) == 1) {
    TimerQueueTimer timer = _timer;
    if (timer != nullptr) {
      _timer = nullptr;
      timer->Close();
    }
    ManualResetEvent kernelEvent = _kernelEvent;
    if (kernelEvent != nullptr) {
      kernelEvent->Set();
    }
    ExecuteCallbackHandlers(throwOnFirstException);
  }
}

void CancellationTokenSource___::ExecuteCallbackHandlers(Boolean throwOnFirstException) {
  get_ThreadIDExecutingCallbacks(Environment::get_CurrentManagedThreadId());
  Array<CallbackPartition> array = Interlocked::Exchange(_callbackPartitions, (Array<CallbackPartition>)nullptr);
  if (array == nullptr) {
    Interlocked::Exchange(_state, 3);
    return;
  }
  List<Exception> list = nullptr;
  try {
    Array<CallbackPartition> array2 = array;
    for (CallbackPartition& callbackPartition : array2) {
      if (callbackPartition == nullptr) {
        continue;
      }
      while (true) {
        Boolean lockTaken = false;
        callbackPartition->Lock.Enter(lockTaken);
        CallbackNode callbacks;
        try {
          callbacks = callbackPartition->Callbacks;
          if (callbacks == nullptr) {
            break;
          }
          if (callbacks->Next != nullptr) {
            callbacks->Next->Prev = nullptr;
          }
          callbackPartition->Callbacks = callbacks->Next;
          _executingCallbackId = callbacks->Id;
          callbacks->Id = 0;
          goto IL_00ad;
        } catch (...) {
        } finally: {
          callbackPartition->Lock.Exit(false);
        }

      IL_00ad:
        try {
          if (callbacks->SynchronizationContext != nullptr) {
          } else {
            callbacks->ExecuteCallback();
          }
        } catch (Exception item) {
        }
      }
    }
  } catch (...) {
  } finally: {
    _state = 3;
    Volatile::Write(_executingCallbackId, 0);
    Interlocked::MemoryBarrier();
  }
  if (list == nullptr) {
    return;
  }
  rt::throw_exception<AggregateException>(list);
}

Int32 CancellationTokenSource___::GetPartitionCount() {
  Int32 processorCount = Environment::get_ProcessorCount();
  return (processorCount > 8) ? 16 : ((processorCount > 4) ? 8 : ((processorCount > 2) ? 4 : ((processorCount <= 1) ? 1 : 2)));
}

CancellationTokenSource CancellationTokenSource___::CreateLinkedTokenSource(CancellationToken token1, CancellationToken token2) {
  if (token1.get_CanBeCanceled()) {
    if (!token2.get_CanBeCanceled()) {
      return rt::newobj<Linked1CancellationTokenSource>(token1);
    }
    return rt::newobj<Linked2CancellationTokenSource>(token1, token2);
  }
  return CreateLinkedTokenSource(token2);
}

CancellationTokenSource CancellationTokenSource___::CreateLinkedTokenSource(CancellationToken token) {
  if (!token.get_CanBeCanceled()) {
    return rt::newobj<CancellationTokenSource>();
  }
  return rt::newobj<Linked1CancellationTokenSource>(token);
}

CancellationTokenSource CancellationTokenSource___::CreateLinkedTokenSource(Array<CancellationToken> tokens) {
  if (tokens == nullptr) {
    rt::throw_exception<ArgumentNullException>("tokens");
  }
  switch (tokens->get_Length().get()) {
    case 0:
      rt::throw_exception<ArgumentException>(SR::get_CancellationToken_CreateLinkedToken_TokensIsEmpty());
    case 1:
      return CreateLinkedTokenSource(tokens[0]);
    case 2:
      return CreateLinkedTokenSource(tokens[0], tokens[1]);
    default:
      return rt::newobj<LinkedNCancellationTokenSource>(tokens);
  }
}

void CancellationTokenSource___::WaitForCallbackToComplete(Int64 id) {
  SpinWait spinWait = SpinWait();
  while (get_ExecutingCallback() == id) {
    spinWait.SpinOnce();
  }
}

ValueTask<> CancellationTokenSource___::WaitForCallbackToCompleteAsync(Int64 id) {
  if (get_ExecutingCallback() != id) {
    return ValueTask<>();
  }
}

void CancellationTokenSource___::cctor() {
  s_canceledSource = rt::newobj<CancellationTokenSource>();
  s_neverCanceledSource = rt::newobj<CancellationTokenSource>();
}

} // namespace System::Private::CoreLib::System::Threading::CancellationTokenSourceNamespace
