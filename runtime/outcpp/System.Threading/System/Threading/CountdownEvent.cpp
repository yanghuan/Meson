#include "CountdownEvent-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEventSlim-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Threading/System/SR-dep.h>
#include <System.Threading/System/Threading/CountdownEvent-dep.h>

namespace System::Threading::System::Threading::CountdownEventNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;

Int32 CountdownEvent___::get_CurrentCount() {
  Int32 currentCount = _currentCount;
  if (currentCount >= 0) {
    return currentCount;
  }
  return 0;
}

Int32 CountdownEvent___::get_InitialCount() {
  return _initialCount;
}

Boolean CountdownEvent___::get_IsSet() {
  return _currentCount <= 0;
}

WaitHandle CountdownEvent___::get_WaitHandle() {
  ThrowIfDisposed();
  return _event->get_WaitHandle();
}

void CountdownEvent___::ctor(Int32 initialCount) {
  if (initialCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("initialCount");
  }
  _initialCount = initialCount;
  _currentCount = initialCount;
  _event = rt::newobj<ManualResetEventSlim>();
  if (initialCount == 0) {
    _event->Set();
  }
}

void CountdownEvent___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((CountdownEvent)this);
}

void CountdownEvent___::Dispose(Boolean disposing) {
  if (disposing) {
    _event->Dispose();
    _disposed = true;
  }
}

Boolean CountdownEvent___::Signal() {
  ThrowIfDisposed();
  if (_currentCount <= 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_CountdownEvent_Decrement_BelowZero());
  }
  Int32 num = Interlocked::Decrement(_currentCount);
  if (num == 0) {
    _event->Set();
    return true;
  }
  if (num < 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_CountdownEvent_Decrement_BelowZero());
  }
  return false;
}

Boolean CountdownEvent___::Signal(Int32 signalCount) {
  if (signalCount <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("signalCount");
  }
  ThrowIfDisposed();
  SpinWait spinWait = SpinWait();
  Int32 currentCount;
  while (true) {
    currentCount = _currentCount;
    if (currentCount < signalCount) {
      rt::throw_exception<InvalidOperationException>(SR::get_CountdownEvent_Decrement_BelowZero());
    }
    if (Interlocked::CompareExchange(_currentCount, currentCount - signalCount, currentCount) == currentCount) {
      break;
    }
    spinWait.SpinOnce(-1);
  }
  if (currentCount == signalCount) {
    _event->Set();
    return true;
  }
  return false;
}

void CountdownEvent___::AddCount() {
  AddCount(1);
}

Boolean CountdownEvent___::TryAddCount() {
  return TryAddCount(1);
}

void CountdownEvent___::AddCount(Int32 signalCount) {
  if (!TryAddCount(signalCount)) {
    rt::throw_exception<InvalidOperationException>(SR::get_CountdownEvent_Increment_AlreadyZero());
  }
}

Boolean CountdownEvent___::TryAddCount(Int32 signalCount) {
  if (signalCount <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("signalCount");
  }
  ThrowIfDisposed();
  SpinWait spinWait = SpinWait();
  while (true) {
    Int32 currentCount = _currentCount;
    if (currentCount <= 0) {
      return false;
    }
    if (currentCount > Int32::MaxValue - signalCount) {
      rt::throw_exception<InvalidOperationException>(SR::get_CountdownEvent_Increment_AlreadyMax());
    }
    if (Interlocked::CompareExchange(_currentCount, currentCount + signalCount, currentCount) == currentCount) {
      break;
    }
    spinWait.SpinOnce(-1);
  }
  return true;
}

void CountdownEvent___::Reset() {
  Reset(_initialCount);
}

void CountdownEvent___::Reset(Int32 count) {
  ThrowIfDisposed();
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count");
  }
  _currentCount = count;
  _initialCount = count;
  if (count == 0) {
    _event->Set();
  } else {
    _event->Reset();
  }
}

void CountdownEvent___::Wait() {
  Wait(-1, CancellationToken::get_None());
}

void CountdownEvent___::Wait(CancellationToken cancellationToken) {
  Wait(-1, cancellationToken);
}

Boolean CountdownEvent___::Wait(TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout");
  }
  return Wait((Int32)num, CancellationToken::get_None());
}

Boolean CountdownEvent___::Wait(TimeSpan timeout, CancellationToken cancellationToken) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout");
  }
  return Wait((Int32)num, cancellationToken);
}

Boolean CountdownEvent___::Wait(Int32 millisecondsTimeout) {
  return Wait(millisecondsTimeout, CancellationToken::get_None());
}

Boolean CountdownEvent___::Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout");
  }
  ThrowIfDisposed();
  cancellationToken.ThrowIfCancellationRequested();
  Boolean flag = _event->get_IsSet();
  if (!flag) {
    flag = _event->Wait(millisecondsTimeout, cancellationToken);
  }
  return flag;
}

void CountdownEvent___::ThrowIfDisposed() {
  if (_disposed) {
    rt::throw_exception<ObjectDisposedException>("CountdownEvent");
  }
}

} // namespace System::Threading::System::Threading::CountdownEventNamespace
