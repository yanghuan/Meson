#include "ReaderWriterLockSlim-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/EventResetMode.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/LockRecursionException-dep.h>
#include <System.Private.CoreLib/System/Threading/ReaderWriterCount-dep.h>
#include <System.Private.CoreLib/System/Threading/ReaderWriterLockSlim-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationLockException-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::ReaderWriterLockSlimNamespace {
Int32 ReaderWriterLockSlim___::TimeoutTracker::get_RemainingMilliseconds() {
  if (_total == -1 || _total == 0) {
    return _total;
  }
  Int32 num = Environment::get_TickCount() - _start;
  if (num < 0 || num >= _total) {
    return 0;
  }
  return _total - num;
}

Boolean ReaderWriterLockSlim___::TimeoutTracker::get_IsExpired() {
  return get_RemainingMilliseconds() == 0;
}

ReaderWriterLockSlim___::TimeoutTracker::TimeoutTracker(TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout");
  }
  _total = (Int32)num;
  if (_total != -1 && _total != 0) {
    _start = Environment::get_TickCount();
  } else {
    _start = 0;
  }
}

ReaderWriterLockSlim___::TimeoutTracker::TimeoutTracker(Int32 millisecondsTimeout) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout");
  }
  _total = millisecondsTimeout;
  if (_total != -1 && _total != 0) {
    _start = Environment::get_TickCount();
  } else {
    _start = 0;
  }
}

UInt16 ReaderWriterLockSlim___::SpinLock::get_EnterForEnterAnyReadDeprioritizedCount() {
  return (UInt16)((UInt32)_enterDeprioritizationState >> 16);
}

UInt16 ReaderWriterLockSlim___::SpinLock::get_EnterForEnterAnyWriteDeprioritizedCount() {
  return (UInt16)_enterDeprioritizationState;
}

Int32 ReaderWriterLockSlim___::SpinLock::GetEnterDeprioritizationStateChange(EnterSpinLockReason reason) {
}

Boolean ReaderWriterLockSlim___::SpinLock::IsEnterDeprioritized(EnterSpinLockReason reason) {
}

Boolean ReaderWriterLockSlim___::SpinLock::TryEnter() {
  return Interlocked::CompareExchange(_isLocked, 1, 0) == 0;
}

void ReaderWriterLockSlim___::SpinLock::Enter(EnterSpinLockReason reason) {
  if (!TryEnter()) {
    EnterSpin(reason);
  }
}

void ReaderWriterLockSlim___::SpinLock::EnterSpin(EnterSpinLockReason reason) {
  Int32 enterDeprioritizationStateChange = GetEnterDeprioritizationStateChange(reason);
  if (enterDeprioritizationStateChange != 0) {
    Interlocked::Add(_enterDeprioritizationState, enterDeprioritizationStateChange);
  }
  Int32 processorCount = Environment::get_ProcessorCount();
  Int32 num = 0;
  while (true) {
    if (num < 10 && processorCount > 1) {
      Thread::in::SpinWait(20 * (num + 1));
    } else if (num < 15) {
      Thread::in::Sleep(0);
    } else {
      Thread::in::Sleep(1);
    }

    if (!IsEnterDeprioritized(reason)) {
      if (_isLocked == 0 && TryEnter()) {
        break;
      }
    } else if (num >= 20) {
      reason |= EnterSpinLockReason::Wait;
      num = -1;
    }

    num++;
  }
  if (enterDeprioritizationStateChange != 0) {
    Interlocked::Add(_enterDeprioritizationState, -enterDeprioritizationStateChange);
  }
}

void ReaderWriterLockSlim___::SpinLock::Exit() {
  Volatile::Write(_isLocked, 0);
}

Boolean ReaderWriterLockSlim___::get_HasNoWaiters() {
  return (_waiterStates & WaiterStates::NoWaiters) != 0;
}

void ReaderWriterLockSlim___::set_HasNoWaiters(Boolean value) {
  if (value) {
    _waiterStates |= WaiterStates::NoWaiters;
  } else {
    _waiterStates &= ~WaiterStates::NoWaiters;
  }
}

Boolean ReaderWriterLockSlim___::get_IsReadLockHeld() {
  if (get_RecursiveReadCount() > 0) {
    return true;
  }
  return false;
}

Boolean ReaderWriterLockSlim___::get_IsUpgradeableReadLockHeld() {
  if (get_RecursiveUpgradeCount() > 0) {
    return true;
  }
  return false;
}

Boolean ReaderWriterLockSlim___::get_IsWriteLockHeld() {
  if (get_RecursiveWriteCount() > 0) {
    return true;
  }
  return false;
}

LockRecursionPolicy ReaderWriterLockSlim___::get_RecursionPolicy() {
  if (_fIsReentrant) {
    return LockRecursionPolicy::SupportsRecursion;
  }
  return LockRecursionPolicy::NoRecursion;
}

Int32 ReaderWriterLockSlim___::get_CurrentReadCount() {
  Int32 numReaders = (Int32)GetNumReaders();
  if (_upgradeLockOwnerId != -1) {
    return numReaders - 1;
  }
  return numReaders;
}

Int32 ReaderWriterLockSlim___::get_RecursiveReadCount() {
  Int32 result = 0;
  ReaderWriterCount threadRWCount = GetThreadRWCount(true);
  if (threadRWCount != nullptr) {
    result = threadRWCount->readercount;
  }
  return result;
}

Int32 ReaderWriterLockSlim___::get_RecursiveUpgradeCount() {
  if (_fIsReentrant) {
    Int32 result = 0;
    ReaderWriterCount threadRWCount = GetThreadRWCount(true);
    if (threadRWCount != nullptr) {
      result = threadRWCount->upgradecount;
    }
    return result;
  }
  if (Environment::get_CurrentManagedThreadId() == _upgradeLockOwnerId) {
    return 1;
  }
  return 0;
}

Int32 ReaderWriterLockSlim___::get_RecursiveWriteCount() {
  if (_fIsReentrant) {
    Int32 result = 0;
    ReaderWriterCount threadRWCount = GetThreadRWCount(true);
    if (threadRWCount != nullptr) {
      result = threadRWCount->writercount;
    }
    return result;
  }
  if (Environment::get_CurrentManagedThreadId() == _writeLockOwnerId) {
    return 1;
  }
  return 0;
}

Int32 ReaderWriterLockSlim___::get_WaitingReadCount() {
  return (Int32)_numReadWaiters;
}

Int32 ReaderWriterLockSlim___::get_WaitingUpgradeCount() {
  return (Int32)_numUpgradeWaiters;
}

Int32 ReaderWriterLockSlim___::get_WaitingWriteCount() {
  return (Int32)_numWriteWaiters;
}

void ReaderWriterLockSlim___::InitializeThreadCounts() {
  _upgradeLockOwnerId = -1;
  _writeLockOwnerId = -1;
}

void ReaderWriterLockSlim___::ctor() {
}

void ReaderWriterLockSlim___::ctor(LockRecursionPolicy recursionPolicy) {
  if (recursionPolicy == LockRecursionPolicy::SupportsRecursion) {
    _fIsReentrant = true;
  }
  InitializeThreadCounts();
  _waiterStates = WaiterStates::NoWaiters;
  _lockID = Interlocked::Increment(s_nextLockID);
}

Boolean ReaderWriterLockSlim___::IsRWEntryEmpty(ReaderWriterCount rwc) {
  if (rwc->lockID == 0) {
    return true;
  }
  if (rwc->readercount == 0 && rwc->writercount == 0 && rwc->upgradecount == 0) {
    return true;
  }
  return false;
}

Boolean ReaderWriterLockSlim___::IsRwHashEntryChanged(ReaderWriterCount lrwc) {
  return lrwc->lockID != _lockID;
}

ReaderWriterCount ReaderWriterLockSlim___::GetThreadRWCount(Boolean dontAllocate) {
  ReaderWriterCount next = t_rwc;
  ReaderWriterCount readerWriterCount = nullptr;
  while (next != nullptr) {
    if (next->lockID == _lockID) {
      return next;
    }
    if (!dontAllocate && readerWriterCount == nullptr && IsRWEntryEmpty(next)) {
      readerWriterCount = next;
    }
    next = next->next;
  }
  if (dontAllocate) {
    return nullptr;
  }
  if (readerWriterCount == nullptr) {
    readerWriterCount = rt::newobj<ReaderWriterCount>();
    readerWriterCount->next = t_rwc;
    t_rwc = readerWriterCount;
  }
  readerWriterCount->lockID = _lockID;
  return readerWriterCount;
}

void ReaderWriterLockSlim___::EnterReadLock() {
  TryEnterReadLock(-1);
}

Boolean ReaderWriterLockSlim___::TryEnterReadLock(TimeSpan timeout) {
  return TryEnterReadLock(TimeoutTracker(timeout));
}

Boolean ReaderWriterLockSlim___::TryEnterReadLock(Int32 millisecondsTimeout) {
  return TryEnterReadLock(TimeoutTracker(millisecondsTimeout));
}

Boolean ReaderWriterLockSlim___::TryEnterReadLock(TimeoutTracker timeout) {
  return TryEnterReadLockCore(timeout);
}

Boolean ReaderWriterLockSlim___::TryEnterReadLockCore(TimeoutTracker timeout) {
  if (_fDisposed) {
    rt::throw_exception<ObjectDisposedException>(nullptr);
  }
  Int32 currentManagedThreadId = Environment::get_CurrentManagedThreadId();
  ReaderWriterCount threadRWCount;
  if (!_fIsReentrant) {
    if (currentManagedThreadId == _writeLockOwnerId) {
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_ReadAfterWriteNotAllowed());
    }
    _spinLock.Enter(EnterSpinLockReason::EnterAnyRead);
    threadRWCount = GetThreadRWCount(false);
    if (threadRWCount->readercount > 0) {
      _spinLock.Exit();
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_RecursiveReadNotAllowed());
    }
    if (currentManagedThreadId == _upgradeLockOwnerId) {
      threadRWCount->readercount++;
      _owners++;
      _spinLock.Exit();
      return true;
    }
  } else {
    _spinLock.Enter(EnterSpinLockReason::EnterAnyRead);
    threadRWCount = GetThreadRWCount(false);
    if (threadRWCount->readercount > 0) {
      threadRWCount->readercount++;
      _spinLock.Exit();
      return true;
    }
    if (currentManagedThreadId == _upgradeLockOwnerId) {
      threadRWCount->readercount++;
      _owners++;
      _spinLock.Exit();
      _fUpgradeThreadHoldingRead = true;
      return true;
    }
    if (currentManagedThreadId == _writeLockOwnerId) {
      threadRWCount->readercount++;
      _owners++;
      _spinLock.Exit();
      return true;
    }
  }
  Boolean flag = true;
  Int32 num = 0;
  while (true) {
    if (_owners < 268435454) {
      _owners++;
      threadRWCount->readercount++;
      _spinLock.Exit();
      return flag;
    }
    if (timeout.get_IsExpired()) {
      _spinLock.Exit();
      return false;
    }
    if (num < 20 && ShouldSpinForEnterAnyRead()) {
      _spinLock.Exit();
      num++;
      SpinWait(num);
      _spinLock.Enter(EnterSpinLockReason::EnterAnyRead);
      if (IsRwHashEntryChanged(threadRWCount)) {
        threadRWCount = GetThreadRWCount(false);
      }
    } else if (_readEvent == nullptr) {
      LazyCreateEvent(_readEvent, EnterLockType::Read);
      if (IsRwHashEntryChanged(threadRWCount)) {
        threadRWCount = GetThreadRWCount(false);
      }
    } else {
      flag = WaitOnEvent(_readEvent, _numReadWaiters, timeout, EnterLockType::Read);
      if (!flag) {
        break;
      }
      if (IsRwHashEntryChanged(threadRWCount)) {
        threadRWCount = GetThreadRWCount(false);
      }
    }

  }
  return false;
}

void ReaderWriterLockSlim___::EnterWriteLock() {
  TryEnterWriteLock(-1);
}

Boolean ReaderWriterLockSlim___::TryEnterWriteLock(TimeSpan timeout) {
  return TryEnterWriteLock(TimeoutTracker(timeout));
}

Boolean ReaderWriterLockSlim___::TryEnterWriteLock(Int32 millisecondsTimeout) {
  return TryEnterWriteLock(TimeoutTracker(millisecondsTimeout));
}

Boolean ReaderWriterLockSlim___::TryEnterWriteLock(TimeoutTracker timeout) {
  return TryEnterWriteLockCore(timeout);
}

Boolean ReaderWriterLockSlim___::TryEnterWriteLockCore(TimeoutTracker timeout) {
  if (_fDisposed) {
    rt::throw_exception<ObjectDisposedException>(nullptr);
  }
  Int32 currentManagedThreadId = Environment::get_CurrentManagedThreadId();
  Boolean flag = false;
  ReaderWriterCount threadRWCount;
  if (!_fIsReentrant) {
    if (currentManagedThreadId == _writeLockOwnerId) {
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_RecursiveWriteNotAllowed());
    }
    EnterSpinLockReason reason;
    if (currentManagedThreadId == _upgradeLockOwnerId) {
      flag = true;
      reason = EnterSpinLockReason::UpgradeToWrite;
    } else {
      reason = EnterSpinLockReason::EnterWrite;
    }
    _spinLock.Enter(reason);
    threadRWCount = GetThreadRWCount(true);
    if (threadRWCount != nullptr && threadRWCount->readercount > 0) {
      _spinLock.Exit();
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_WriteAfterReadNotAllowed());
    }
  } else {
    EnterSpinLockReason reason2 = ((currentManagedThreadId == _writeLockOwnerId) ? EnterSpinLockReason::EnterRecursiveWrite : ((currentManagedThreadId != _upgradeLockOwnerId) ? EnterSpinLockReason::EnterWrite : EnterSpinLockReason::UpgradeToWrite));
    _spinLock.Enter(reason2);
    threadRWCount = GetThreadRWCount(false);
    if (currentManagedThreadId == _writeLockOwnerId) {
      threadRWCount->writercount++;
      _spinLock.Exit();
      return true;
    }
    if (currentManagedThreadId == _upgradeLockOwnerId) {
      flag = true;
    } else if (threadRWCount->readercount > 0) {
      _spinLock.Exit();
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_WriteAfterReadNotAllowed());
    }

  }
  Boolean flag2 = true;
  Int32 num = 0;
  while (true) {
    if (IsWriterAcquired()) {
      SetWriterAcquired();
      break;
    }
    if (flag) {
      UInt32 numReaders = GetNumReaders();
      if (numReaders == 1) {
        SetWriterAcquired();
        break;
      }
      if (numReaders == 2 && threadRWCount != nullptr) {
        if (IsRwHashEntryChanged(threadRWCount)) {
          threadRWCount = GetThreadRWCount(false);
        }
        if (threadRWCount->readercount > 0) {
          SetWriterAcquired();
          break;
        }
      }
    }
    if (timeout.get_IsExpired()) {
      _spinLock.Exit();
      return false;
    }
    if (num < 20 && ShouldSpinForEnterAnyWrite(flag)) {
      _spinLock.Exit();
      num++;
      SpinWait(num);
      _spinLock.Enter(flag ? EnterSpinLockReason::UpgradeToWrite : EnterSpinLockReason::EnterWrite);
    } else if (flag) {
      if (_waitUpgradeEvent == nullptr) {
        LazyCreateEvent(_waitUpgradeEvent, EnterLockType::UpgradeToWrite);
      } else if (!WaitOnEvent(_waitUpgradeEvent, _numWriteUpgradeWaiters, timeout, EnterLockType::UpgradeToWrite)) {
        return false;
      }

    } else if (_writeEvent == nullptr) {
      LazyCreateEvent(_writeEvent, EnterLockType::Write);
    } else if (!WaitOnEvent(_writeEvent, _numWriteWaiters, timeout, EnterLockType::Write)) {
      return false;
    }



  }
  if (_fIsReentrant) {
    if (IsRwHashEntryChanged(threadRWCount)) {
      threadRWCount = GetThreadRWCount(false);
    }
    threadRWCount->writercount++;
  }
  _spinLock.Exit();
  _writeLockOwnerId = currentManagedThreadId;
  return true;
}

void ReaderWriterLockSlim___::EnterUpgradeableReadLock() {
  TryEnterUpgradeableReadLock(-1);
}

Boolean ReaderWriterLockSlim___::TryEnterUpgradeableReadLock(TimeSpan timeout) {
  return TryEnterUpgradeableReadLock(TimeoutTracker(timeout));
}

Boolean ReaderWriterLockSlim___::TryEnterUpgradeableReadLock(Int32 millisecondsTimeout) {
  return TryEnterUpgradeableReadLock(TimeoutTracker(millisecondsTimeout));
}

Boolean ReaderWriterLockSlim___::TryEnterUpgradeableReadLock(TimeoutTracker timeout) {
  return TryEnterUpgradeableReadLockCore(timeout);
}

Boolean ReaderWriterLockSlim___::TryEnterUpgradeableReadLockCore(TimeoutTracker timeout) {
  if (_fDisposed) {
    rt::throw_exception<ObjectDisposedException>(nullptr);
  }
  Int32 currentManagedThreadId = Environment::get_CurrentManagedThreadId();
  ReaderWriterCount threadRWCount;
  if (!_fIsReentrant) {
    if (currentManagedThreadId == _upgradeLockOwnerId) {
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_RecursiveUpgradeNotAllowed());
    }
    if (currentManagedThreadId == _writeLockOwnerId) {
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_UpgradeAfterWriteNotAllowed());
    }
    _spinLock.Enter(EnterSpinLockReason::EnterAnyRead);
    threadRWCount = GetThreadRWCount(true);
    if (threadRWCount != nullptr && threadRWCount->readercount > 0) {
      _spinLock.Exit();
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_UpgradeAfterReadNotAllowed());
    }
  } else {
    _spinLock.Enter(EnterSpinLockReason::EnterAnyRead);
    threadRWCount = GetThreadRWCount(false);
    if (currentManagedThreadId == _upgradeLockOwnerId) {
      threadRWCount->upgradecount++;
      _spinLock.Exit();
      return true;
    }
    if (currentManagedThreadId == _writeLockOwnerId) {
      _owners++;
      _upgradeLockOwnerId = currentManagedThreadId;
      threadRWCount->upgradecount++;
      if (threadRWCount->readercount > 0) {
        _fUpgradeThreadHoldingRead = true;
      }
      _spinLock.Exit();
      return true;
    }
    if (threadRWCount->readercount > 0) {
      _spinLock.Exit();
      rt::throw_exception<LockRecursionException>(SR::get_LockRecursionException_UpgradeAfterReadNotAllowed());
    }
  }
  Boolean flag = true;
  Int32 num = 0;
  while (true) {
    if (_upgradeLockOwnerId == -1 && _owners < 268435454) {
      _owners++;
      _upgradeLockOwnerId = currentManagedThreadId;
      if (_fIsReentrant) {
        if (IsRwHashEntryChanged(threadRWCount)) {
          threadRWCount = GetThreadRWCount(false);
        }
        threadRWCount->upgradecount++;
      }
      break;
    }
    if (timeout.get_IsExpired()) {
      _spinLock.Exit();
      return false;
    }
    if (num < 20 && ShouldSpinForEnterAnyRead()) {
      _spinLock.Exit();
      num++;
      SpinWait(num);
      _spinLock.Enter(EnterSpinLockReason::EnterAnyRead);
    } else if (_upgradeEvent == nullptr) {
      LazyCreateEvent(_upgradeEvent, EnterLockType::UpgradeableRead);
    } else if (!WaitOnEvent(_upgradeEvent, _numUpgradeWaiters, timeout, EnterLockType::UpgradeableRead)) {
      return false;
    }


  }
  _spinLock.Exit();
  return true;
}

void ReaderWriterLockSlim___::ExitReadLock() {
  _spinLock.Enter(EnterSpinLockReason::ExitAnyRead);
  ReaderWriterCount threadRWCount = GetThreadRWCount(true);
  if (threadRWCount == nullptr || threadRWCount->readercount < 1) {
    _spinLock.Exit();
    rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_MisMatchedRead());
  }
  if (_fIsReentrant) {
    if (threadRWCount->readercount > 1) {
      threadRWCount->readercount--;
      _spinLock.Exit();
      return;
    }
    if (Environment::get_CurrentManagedThreadId() == _upgradeLockOwnerId) {
      _fUpgradeThreadHoldingRead = false;
    }
  }
  _owners--;
  threadRWCount->readercount--;
  ExitAndWakeUpAppropriateWaiters();
}

void ReaderWriterLockSlim___::ExitWriteLock() {
  if (!_fIsReentrant) {
    if (Environment::get_CurrentManagedThreadId() != _writeLockOwnerId) {
      rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_MisMatchedWrite());
    }
    _spinLock.Enter(EnterSpinLockReason::ExitAnyWrite);
  } else {
    _spinLock.Enter(EnterSpinLockReason::ExitAnyWrite);
    ReaderWriterCount threadRWCount = GetThreadRWCount(false);
    if (threadRWCount == nullptr) {
      _spinLock.Exit();
      rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_MisMatchedWrite());
    }
    if (threadRWCount->writercount < 1) {
      _spinLock.Exit();
      rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_MisMatchedWrite());
    }
    threadRWCount->writercount--;
    if (threadRWCount->writercount > 0) {
      _spinLock.Exit();
      return;
    }
  }
  ClearWriterAcquired();
  _writeLockOwnerId = -1;
  ExitAndWakeUpAppropriateWaiters();
}

void ReaderWriterLockSlim___::ExitUpgradeableReadLock() {
  if (!_fIsReentrant) {
    if (Environment::get_CurrentManagedThreadId() != _upgradeLockOwnerId) {
      rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_MisMatchedUpgrade());
    }
    _spinLock.Enter(EnterSpinLockReason::ExitAnyRead);
  } else {
    _spinLock.Enter(EnterSpinLockReason::ExitAnyRead);
    ReaderWriterCount threadRWCount = GetThreadRWCount(true);
    if (threadRWCount == nullptr) {
      _spinLock.Exit();
      rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_MisMatchedUpgrade());
    }
    if (threadRWCount->upgradecount < 1) {
      _spinLock.Exit();
      rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_MisMatchedUpgrade());
    }
    threadRWCount->upgradecount--;
    if (threadRWCount->upgradecount > 0) {
      _spinLock.Exit();
      return;
    }
    _fUpgradeThreadHoldingRead = false;
  }
  _owners--;
  _upgradeLockOwnerId = -1;
  ExitAndWakeUpAppropriateWaiters();
}

void ReaderWriterLockSlim___::LazyCreateEvent(EventWaitHandle& waitEvent, EnterLockType enterLockType) {
  _spinLock.Exit();
  EventWaitHandle eventWaitHandle = rt::newobj<EventWaitHandle>(false, (enterLockType == EnterLockType::Read) ? EventResetMode::ManualReset : EventResetMode::AutoReset);
  EnterSpinLockReason reason;
  switch (enterLockType) {
    case EnterLockType::Read:
    case EnterLockType::UpgradeableRead:
      reason = EnterSpinLockReason::Wait;
      break;
    case EnterLockType::Write:
      reason = (EnterSpinLockReason)10;
      break;
    default:
      reason = (EnterSpinLockReason)11;
      break;
  }
  _spinLock.Enter(reason);
  if (waitEvent == nullptr) {
    waitEvent = eventWaitHandle;
  } else {
    eventWaitHandle->Dispose();
  }
}

Boolean ReaderWriterLockSlim___::WaitOnEvent(EventWaitHandle waitEvent, UInt32& numWaiters, TimeoutTracker timeout, EnterLockType enterLockType) {
  WaiterStates waiterStates = WaiterStates::None;
  EnterSpinLockReason reason;
}

void ReaderWriterLockSlim___::ExitAndWakeUpAppropriateWaiters() {
  if (get_HasNoWaiters()) {
    _spinLock.Exit();
  } else {
    ExitAndWakeUpAppropriateWaitersPreferringWriters();
  }
}

void ReaderWriterLockSlim___::ExitAndWakeUpAppropriateWaitersPreferringWriters() {
  UInt32 numReaders = GetNumReaders();
  if (_fIsReentrant && _numWriteUpgradeWaiters != 0 && _fUpgradeThreadHoldingRead && numReaders == 2) {
    _spinLock.Exit();
    _waitUpgradeEvent->Set();
  } else if (numReaders == 1 && _numWriteUpgradeWaiters != 0) {
    _spinLock.Exit();
    _waitUpgradeEvent->Set();
  } else if (numReaders == 0 && _numWriteWaiters != 0) {
    WaiterStates waiterStates = _waiterStates & WaiterStates::WriteWaiterSignaled;
    if (waiterStates == WaiterStates::None) {
      _waiterStates |= WaiterStates::WriteWaiterSignaled;
    }
    _spinLock.Exit();
    if (waiterStates == WaiterStates::None) {
      _writeEvent->Set();
    }
  } else {
    ExitAndWakeUpAppropriateReadWaiters();
  }


}

void ReaderWriterLockSlim___::ExitAndWakeUpAppropriateReadWaiters() {
  if (_numWriteWaiters != 0 || _numWriteUpgradeWaiters != 0 || get_HasNoWaiters()) {
    _spinLock.Exit();
    return;
  }
  Boolean flag = _numReadWaiters != 0;
  Boolean flag2 = _numUpgradeWaiters != 0 && _upgradeLockOwnerId == -1;
  if (flag2) {
    if ((_waiterStates & WaiterStates::UpgradeableReadWaiterSignaled) == 0) {
      _waiterStates |= WaiterStates::UpgradeableReadWaiterSignaled;
    } else {
      flag2 = false;
    }
  }
  _spinLock.Exit();
  if (flag) {
    _readEvent->Set();
  }
  if (flag2) {
    _upgradeEvent->Set();
  }
}

Boolean ReaderWriterLockSlim___::IsWriterAcquired() {
  return (_owners & 3221225471u) == 0;
}

void ReaderWriterLockSlim___::SetWriterAcquired() {
  _owners |= 2147483648u;
}

void ReaderWriterLockSlim___::ClearWriterAcquired() {
  _owners &= 2147483647u;
}

void ReaderWriterLockSlim___::SetWritersWaiting() {
  _owners |= 1073741824u;
}

void ReaderWriterLockSlim___::ClearWritersWaiting() {
  _owners &= 3221225471u;
}

void ReaderWriterLockSlim___::SetUpgraderWaiting() {
  _owners |= 536870912u;
}

void ReaderWriterLockSlim___::ClearUpgraderWaiting() {
  _owners &= 3758096383u;
}

UInt32 ReaderWriterLockSlim___::GetNumReaders() {
  return _owners & 268435455u;
}

Boolean ReaderWriterLockSlim___::ShouldSpinForEnterAnyRead() {
  if (!get_HasNoWaiters()) {
    if (_numWriteWaiters == 0) {
      return _numWriteUpgradeWaiters == 0;
    }
    return false;
  }
  return true;
}

Boolean ReaderWriterLockSlim___::ShouldSpinForEnterAnyWrite(Boolean isUpgradeToWrite) {
  if (!isUpgradeToWrite) {
    return _numWriteUpgradeWaiters == 0;
  }
  return true;
}

void ReaderWriterLockSlim___::SpinWait(Int32 spinCount) {
  if (spinCount < 5 && Environment::get_ProcessorCount() > 1) {
    Thread::in::SpinWait(20 * spinCount);
  } else {
    Thread::in::Sleep(0);
  }
}

void ReaderWriterLockSlim___::Dispose() {
  Dispose(true);
}

void ReaderWriterLockSlim___::Dispose(Boolean disposing) {
  if (disposing && !_fDisposed) {
    if (get_WaitingReadCount() > 0 || get_WaitingUpgradeCount() > 0 || get_WaitingWriteCount() > 0) {
      rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_IncorrectDispose());
    }
    if (get_IsReadLockHeld() || get_IsUpgradeableReadLockHeld() || get_IsWriteLockHeld()) {
      rt::throw_exception<SynchronizationLockException>(SR::get_SynchronizationLockException_IncorrectDispose());
    }
    if (_writeEvent != nullptr) {
      _writeEvent->Dispose();
      _writeEvent = nullptr;
    }
    if (_readEvent != nullptr) {
      _readEvent->Dispose();
      _readEvent = nullptr;
    }
    if (_upgradeEvent != nullptr) {
      _upgradeEvent->Dispose();
      _upgradeEvent = nullptr;
    }
    if (_waitUpgradeEvent != nullptr) {
      _waitUpgradeEvent->Dispose();
      _waitUpgradeEvent = nullptr;
    }
    _fDisposed = true;
  }
}

} // namespace System::Private::CoreLib::System::Threading::ReaderWriterLockSlimNamespace
