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
#include <System.Private.CoreLib/System/Threading/SynchronizationLockException-dep.h>
#include <System.Private.CoreLib/System/Threading/TimeoutHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::SpinLockNamespace {
Nullable<Boolean> SystemThreading_SpinLockDebugView___::get_IsHeldByCurrentThread() {
  try {
    return _spinLock.get_IsHeldByCurrentThread();
  } catch (InvalidOperationException) {
    return nullptr;
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
  return (_owner & 1) != 0;
}

Boolean SpinLock::get_IsHeldByCurrentThread() {
  if (!get_IsThreadOwnerTrackingEnabled()) {
    rt::throw_exception<InvalidOperationException>(SR::get_SpinLock_IsHeldByCurrentThread());
  }
  return (_owner & 2147483647) == Environment::get_CurrentManagedThreadId();
}

Boolean SpinLock::get_IsThreadOwnerTrackingEnabled() {
  return (_owner & Int32::MinValue) == 0;
}

Int32 SpinLock::CompareExchange(Int32& location, Int32 value, Int32 comparand, Boolean& success) {
  Int32 num = Interlocked::CompareExchange(location, value, comparand);
  success = num == comparand;
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
  if (lockTaken || (owner & -2147483647) != Int32::MinValue || CompareExchange(_owner, owner | 1, owner, lockTaken) != owner) {
    ContinueTryEnter(-1, lockTaken);
  }
}

void SpinLock::TryEnter(Boolean& lockTaken) {
  Int32 owner = _owner;
  if (((owner & Int32::MinValue) == 0) | lockTaken) {
    ContinueTryEnter(0, lockTaken);
  } else if (((UInt32)owner & (true ? 1u : 0u)) != 0) {
    lockTaken = false;
  } else {
    CompareExchange(_owner, owner | 1, owner, lockTaken);
  }

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
  if (((millisecondsTimeout < -1) | lockTaken) || (owner & -2147483647) != Int32::MinValue || CompareExchange(_owner, owner | 1, owner, lockTaken) != owner) {
    ContinueTryEnter(millisecondsTimeout, lockTaken);
  }
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
  if ((owner & 1) == 0) {
    if (CompareExchange(_owner, owner | 1, owner, lockTaken) == owner || millisecondsTimeout == 0) {
      return;
    }
  } else {
    if (millisecondsTimeout == 0) {
      return;
    }
    if ((owner & 2147483646) != 2147483646) {
      num = (Interlocked::Add(_owner, 2) & 2147483646) >> 1;
    }
  }
  SpinWait spinWait;
  if (num > Environment::get_ProcessorCount()) {
    spinWait.set_Count(10);
  }
  do {
    spinWait.SpinOnce(40);
    owner = _owner;
    if ((owner & 1) == 0) {
      Int32 value = (((owner & 2147483646) == 0) ? (owner | 1) : ((owner - 2) | 1));
      if (CompareExchange(_owner, value, owner, lockTaken) == owner) {
        return;
      }
    }
  } while (spinWait.get_Count() % 10 != 0 || millisecondsTimeout == -1 || TimeoutHelper::UpdateTimeOut(startTime, millisecondsTimeout) > 0);
  DecrementWaiters();
}

void SpinLock::DecrementWaiters() {
  SpinWait spinWait;
  while (true) {
    Int32 owner = _owner;
    if (((UInt32)owner & 2147483646u) != 0 && Interlocked::CompareExchange(_owner, owner - 2, owner) != owner) {
      spinWait.SpinOnce();
      continue;
    }
    break;
  }
}

void SpinLock::ContinueTryEnterWithThreadTracking(Int32 millisecondsTimeout, UInt32 startTime, Boolean& lockTaken) {
  Int32 currentManagedThreadId = Environment::get_CurrentManagedThreadId();
  if (_owner == currentManagedThreadId) {
    rt::throw_exception<LockRecursionException>(SR::get_SpinLock_TryEnter_LockRecursionException());
  }
  SpinWait spinWait;
  while (true) {
    spinWait.SpinOnce();
    if (_owner == 0 && CompareExchange(_owner, currentManagedThreadId, 0, lockTaken) == 0) {
      break;
    }
    switch (millisecondsTimeout.get()) {
      case -1:
        continue;
      case 0:
        return;
    }
    if (spinWait.get_NextSpinWillYield() && TimeoutHelper::UpdateTimeOut(startTime, millisecondsTimeout) <= 0) {
      return;
    }
  }
}

void SpinLock::Exit() {
  if ((_owner & Int32::MinValue) == 0) {
    ExitSlowPath(true);
  } else {
    Interlocked::Decrement(_owner);
  }
}

void SpinLock::Exit(Boolean useMemoryBarrier) {
  Int32 owner = _owner;
  if ((owner & Int32::MinValue) != 0 && !useMemoryBarrier) {
    _owner = owner & -2;
  } else {
    ExitSlowPath(useMemoryBarrier);
  }
}

void SpinLock::ExitSlowPath(Boolean useMemoryBarrier) {
  Boolean flag = (_owner & Int32::MinValue) == 0;
  if (flag && !get_IsHeldByCurrentThread()) {
    rt::throw_exception<SynchronizationLockException>(SR::get_SpinLock_Exit_SynchronizationLockException());
  }
  if (useMemoryBarrier) {
    if (flag) {
      Interlocked::Exchange(_owner, 0);
    } else {
      Interlocked::Decrement(_owner);
    }
  } else if (flag) {
    _owner = 0;
  } else {
    Int32 owner = _owner;
    _owner = owner & -2;
  }

}

} // namespace System::Private::CoreLib::System::Threading::SpinLockNamespace
