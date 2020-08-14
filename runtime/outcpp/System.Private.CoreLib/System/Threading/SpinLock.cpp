#include "SpinLock-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/LockRecursionException-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Private.CoreLib/System/Threading/TimeoutHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::SpinLockNamespace {
Nullable<Boolean> SystemThreading_SpinLockDebugView___::get_IsHeldByCurrentThread() {
  try{
    return _spinLock.get_IsHeldByCurrentThread();
  } catch (InvalidOperationException) {
  }
}

Nullable<Int32> SystemThreading_SpinLockDebugView___::get_OwnerThreadID() {
  if (_spinLock.get_IsThreadOwnerTrackingEnabled()) {
    return _spinLock._owner;
  }
  return nullptr;
}

Boolean SystemThreading_SpinLockDebugView___::get_IsHeld() {
  return _spinLock.get_IsHeld();
}

void SystemThreading_SpinLockDebugView___::ctor(SpinLock spinLock) {
  _spinLock = spinLock;
}

Boolean SpinLock::get_IsHeld() {
  if (get_IsThreadOwnerTrackingEnabled()) {
    return _owner != 0;
  }
}

Boolean SpinLock::get_IsHeldByCurrentThread() {
  if (!get_IsThreadOwnerTrackingEnabled()) {
    rt::throw_exception<InvalidOperationException>(SR::get_SpinLock_IsHeldByCurrentThread());
  }
}

Boolean SpinLock::get_IsThreadOwnerTrackingEnabled() {
}

Int32 SpinLock::CompareExchange(Int32& location, Int32 value, Int32 comparand, Boolean& success) {
  Int32 num = Interlocked::CompareExchange(location, value, comparand);
  success = (num == comparand);
  return num;
}

SpinLock::SpinLock(Boolean enableThreadOwnerTracking) {
  _owner = 0;
  if (!enableThreadOwnerTracking) {
    _owner |= Int32::MinValue;
  }
}

void SpinLock::Enter(Boolean& lockTaken) {
  Int32 owner = _owner;
}

void SpinLock::TryEnter(Boolean& lockTaken) {
  Int32 owner = _owner;
}

void SpinLock::TryEnter(TimeSpan timeout, Boolean& lockTaken) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", timeout, SR::get_SpinLock_TryEnter_ArgumentOutOfRange());
  }
  TryEnter((Int32)timeout.get_TotalMilliseconds(), lockTaken);
}

void SpinLock::TryEnter(Int32 millisecondsTimeout, Boolean& lockTaken) {
  Int32 owner = _owner;
}

void SpinLock::ContinueTryEnter(Int32 millisecondsTimeout, Boolean& lockTaken) {
  if (lockTaken) {
    lockTaken = false;
    rt::throw_exception<ArgumentException>(SR::get_SpinLock_TryReliableEnter_ArgumentException());
  }
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", millisecondsTimeout, SR::get_SpinLock_TryEnter_ArgumentOutOfRange());
  }
  UInt32 startTime = 0u;
  if (millisecondsTimeout != -1 && millisecondsTimeout != 0) {
    startTime = TimeoutHelper::GetTime();
  }
  if (get_IsThreadOwnerTrackingEnabled()) {
    ContinueTryEnterWithThreadTracking(millisecondsTimeout, startTime, lockTaken);
    return;
  }
  Int32 num = Int32::MaxValue;
  Int32 owner = _owner;
}

void SpinLock::DecrementWaiters() {
  SpinWait spinWait = SpinWait();
  while (true) {
    Int32 owner = _owner;
  }
}

void SpinLock::ContinueTryEnterWithThreadTracking(Int32 millisecondsTimeout, UInt32 startTime, Boolean& lockTaken) {
  Int32 currentManagedThreadId = Environment::get_CurrentManagedThreadId();
  if (_owner == currentManagedThreadId) {
    rt::throw_exception<LockRecursionException>(SR::get_SpinLock_TryEnter_LockRecursionException());
  }
  SpinWait spinWait = SpinWait();
  while (true) {
    spinWait.SpinOnce();
    if (_owner == 0 && CompareExchange(_owner, currentManagedThreadId, 0, lockTaken) == 0) {
      break;
    }
  }
}

void SpinLock::Exit() {
}

void SpinLock::Exit(Boolean useMemoryBarrier) {
  Int32 owner = _owner;
}

void SpinLock::ExitSlowPath(Boolean useMemoryBarrier) {
}

} // namespace System::Private::CoreLib::System::Threading::SpinLockNamespace
