#include "ReaderWriterLock-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/Threading/AutoResetEvent-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEventSlim-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationLockException-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Threading/System/SR-dep.h>
#include <System.Threading/System/Threading/LockCookieFlags.h>
#include <System.Threading/System/Threading/ReaderWriterLock-dep.h>

namespace System::Threading::System::Threading::ReaderWriterLockNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;

void ReaderWriterLock___::ReaderWriterLockApplicationException___::ctor(Int32 errorHResult, String message) {
  Object->set_HResult = errorHResult;
}

void ReaderWriterLock___::ReaderWriterLockApplicationException___::ctor(SerializationInfo info, StreamingContext context) {
}

Boolean ReaderWriterLock___::ThreadLocalLockEntry___::get_IsFree() {
  return _readerLevel == 0;
}

void ReaderWriterLock___::ThreadLocalLockEntry___::ctor(Int64 lockID) {
  _lockID = lockID;
}

ReaderWriterLock::in::ThreadLocalLockEntry ReaderWriterLock___::ThreadLocalLockEntry___::GetCurrent(Int64 lockID) {
  ThreadLocalLockEntry threadLocalLockEntry = t_lockEntryHead;
  for (ThreadLocalLockEntry threadLocalLockEntry2 = threadLocalLockEntry; threadLocalLockEntry2 != nullptr; threadLocalLockEntry2 = threadLocalLockEntry2->_next) {
    if (threadLocalLockEntry2->_lockID == lockID) {
      if (!threadLocalLockEntry2->get_IsFree()) {
        return threadLocalLockEntry2;
      }
      return nullptr;
    }
  }
  return nullptr;
}

ReaderWriterLock::in::ThreadLocalLockEntry ReaderWriterLock___::ThreadLocalLockEntry___::GetOrCreateCurrent(Int64 lockID) {
  ThreadLocalLockEntry threadLocalLockEntry = t_lockEntryHead;
  if (threadLocalLockEntry != nullptr) {
    if (threadLocalLockEntry->_lockID == lockID) {
      return threadLocalLockEntry;
    }
    if (threadLocalLockEntry->get_IsFree()) {
      threadLocalLockEntry->_lockID = lockID;
      return threadLocalLockEntry;
    }
  }
  return GetOrCreateCurrentSlow(lockID, threadLocalLockEntry);
}

ReaderWriterLock::in::ThreadLocalLockEntry ReaderWriterLock___::ThreadLocalLockEntry___::GetOrCreateCurrentSlow(Int64 lockID, ThreadLocalLockEntry headEntry) {
  ThreadLocalLockEntry threadLocalLockEntry = nullptr;
  ThreadLocalLockEntry threadLocalLockEntry2 = nullptr;
  ThreadLocalLockEntry threadLocalLockEntry3 = nullptr;
  if (headEntry != nullptr) {
    if (headEntry->get_IsFree()) {
      threadLocalLockEntry3 = headEntry;
    }
    ThreadLocalLockEntry threadLocalLockEntry4 = headEntry;
    for (ThreadLocalLockEntry next = headEntry->_next; next != nullptr; next = next->_next) {
      if (next->_lockID == lockID) {
        threadLocalLockEntry4->_next = next->_next;
        threadLocalLockEntry = next;
        break;
      }
      if (threadLocalLockEntry3 == nullptr && next->get_IsFree()) {
        threadLocalLockEntry2 = threadLocalLockEntry4;
        threadLocalLockEntry3 = next;
      }
      threadLocalLockEntry4 = next;
    }
  }
  if (threadLocalLockEntry == nullptr) {
    if (threadLocalLockEntry3 != nullptr) {
      threadLocalLockEntry3->_lockID = lockID;
      if (threadLocalLockEntry2 == nullptr) {
        return threadLocalLockEntry3;
      }
      threadLocalLockEntry2->_next = threadLocalLockEntry3->_next;
      threadLocalLockEntry = threadLocalLockEntry3;
    } else {
      threadLocalLockEntry = rt::newobj<ThreadLocalLockEntry>(lockID);
    }
  }
  threadLocalLockEntry->_next = headEntry;
  t_lockEntryHead = threadLocalLockEntry;
  return threadLocalLockEntry;
}

Boolean ReaderWriterLock___::get_IsReaderLockHeld() {
  ThreadLocalLockEntry current = ThreadLocalLockEntry::in::GetCurrent(_lockID);
  if (current != nullptr) {
    return current->_readerLevel > 0;
  }
  return false;
}

Boolean ReaderWriterLock___::get_IsWriterLockHeld() {
  return _writerID == GetCurrentThreadID();
}

Int32 ReaderWriterLock___::get_WriterSeqNum() {
  return _writerSeqNum;
}

void ReaderWriterLock___::ctor() {
  _writerID = -1;
  _writerSeqNum = 1;
}

Boolean ReaderWriterLock___::AnyWritersSince(Int32 seqNum) {
  if (_writerID == GetCurrentThreadID()) {
    seqNum++;
  }
  return (UInt32)_writerSeqNum > (UInt32)seqNum;
}

void ReaderWriterLock___::AcquireReaderLock(Int32 millisecondsTimeout) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception(GetInvalidTimeoutException("millisecondsTimeout"));
  }
  ThreadLocalLockEntry orCreateCurrent = ThreadLocalLockEntry::in::GetOrCreateCurrent(_lockID);
  if (Interlocked::CompareExchange(_state, 1, 0) != 0) {
    if (orCreateCurrent->_readerLevel > 0) {
      if (orCreateCurrent->_readerLevel == UInt16::MaxValue) {
        rt::throw_exception<OverflowException>(SR::get_Overflow_UInt16());
      }
      orCreateCurrent->_readerLevel++;
      return;
    }
    if (_writerID == GetCurrentThreadID()) {
      AcquireWriterLock(millisecondsTimeout);
      return;
    }
    Int32 num = 0;
    Int32 num2 = _state;
  }
  orCreateCurrent->_readerLevel++;
}

void ReaderWriterLock___::AcquireReaderLock(TimeSpan timeout) {
  AcquireReaderLock(ToTimeoutMilliseconds(timeout));
}

void ReaderWriterLock___::AcquireWriterLock(Int32 millisecondsTimeout) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception(GetInvalidTimeoutException("millisecondsTimeout"));
  }
  Int32 currentThreadID = GetCurrentThreadID();
  if (Interlocked::CompareExchange(_state, 4096, 0) != 0) {
    if (_writerID == currentThreadID) {
      if (_writerLevel == UInt16::MaxValue) {
        rt::throw_exception<OverflowException>(SR::get_Overflow_UInt16());
      }
      _writerLevel++;
      return;
    }
    Int32 num = 0;
    Int32 num2 = _state;
  }
  _writerID = currentThreadID;
  _writerLevel = 1;
  _writerSeqNum++;
}

void ReaderWriterLock___::AcquireWriterLock(TimeSpan timeout) {
  AcquireWriterLock(ToTimeoutMilliseconds(timeout));
}

void ReaderWriterLock___::ReleaseReaderLock() {
  if (_writerID == GetCurrentThreadID()) {
    ReleaseWriterLock();
    return;
  }
  ThreadLocalLockEntry current = ThreadLocalLockEntry::in::GetCurrent(_lockID);
  if (current == nullptr) {
    rt::throw_exception(GetNotOwnerException());
  }
  current->_readerLevel--;
  if (current->_readerLevel > 0) {
    return;
  }
  AutoResetEvent autoResetEvent = nullptr;
  ManualResetEventSlim manualResetEventSlim = nullptr;
  Int32 num = _state;
  Boolean flag;
  Boolean flag2;
  Int32 num2;
}

void ReaderWriterLock___::ReleaseWriterLock() {
  if (_writerID != GetCurrentThreadID()) {
    rt::throw_exception(GetNotOwnerException());
  }
  _writerLevel--;
  if (_writerLevel > 0) {
    return;
  }
  _writerID = -1;
  ManualResetEventSlim manualResetEventSlim = nullptr;
  AutoResetEvent autoResetEvent = nullptr;
  Int32 num = _state;
  Boolean flag;
  Int32 num2;
}

LockCookie ReaderWriterLock___::UpgradeToWriterLock(Int32 millisecondsTimeout) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception(GetInvalidTimeoutException("millisecondsTimeout"));
  }
  LockCookie lockCookie = LockCookie();
  Int32 num = lockCookie._threadID = GetCurrentThreadID();
  if (_writerID == num) {
    lockCookie._flags = (LockCookieFlags::Upgrade | LockCookieFlags::OwnedWriter);
    lockCookie._writerLevel = _writerLevel;
    AcquireWriterLock(millisecondsTimeout);
    return lockCookie;
  }
  ThreadLocalLockEntry current = ThreadLocalLockEntry::in::GetCurrent(_lockID);
  if (current == nullptr) {
    lockCookie._flags = (LockCookieFlags::Upgrade | LockCookieFlags::OwnedNone);
  } else {
    lockCookie._flags = (LockCookieFlags::Upgrade | LockCookieFlags::OwnedReader);
    lockCookie._readerLevel = current->_readerLevel;
    Int32 num2 = Interlocked::CompareExchange(_state, 4096, 1);
    if (num2 == 1) {
      current->_readerLevel = 0;
      _writerID = num;
      _writerLevel = 1;
      _writerSeqNum++;
      return lockCookie;
    }
    current->_readerLevel = 1;
    ReleaseReaderLock();
  }
  Boolean flag = false;
  try{
    AcquireWriterLock(millisecondsTimeout);
    flag = true;
    return lockCookie;
  } finally: {
    if (!flag) {
      LockCookieFlags flags = lockCookie._flags;
      lockCookie._flags = LockCookieFlags::Invalid;
      RecoverLock(lockCookie, flags & LockCookieFlags::OwnedReader);
    }
  }
}

LockCookie ReaderWriterLock___::UpgradeToWriterLock(TimeSpan timeout) {
  return UpgradeToWriterLock(ToTimeoutMilliseconds(timeout));
}

void ReaderWriterLock___::DowngradeFromWriterLock(LockCookie& lockCookie) {
  Int32 currentThreadID = GetCurrentThreadID();
  if (_writerID != currentThreadID) {
    rt::throw_exception(GetNotOwnerException());
  }
  LockCookieFlags flags = lockCookie._flags;
  UInt16 writerLevel = lockCookie._writerLevel;
  if ((flags & LockCookieFlags::Invalid) != 0 || lockCookie._threadID != currentThreadID || ((flags & (LockCookieFlags::OwnedNone | LockCookieFlags::OwnedWriter)) != 0 && _writerLevel <= writerLevel)) {
    rt::throw_exception(GetInvalidLockCookieException());
  }
  if ((flags & LockCookieFlags::OwnedReader) != 0) {
    ThreadLocalLockEntry orCreateCurrent = ThreadLocalLockEntry::in::GetOrCreateCurrent(_lockID);
    _writerID = -1;
    _writerLevel = 0;
    ManualResetEventSlim manualResetEventSlim = nullptr;
    Int32 num = _state;
    Int32 num2;
  } else if ((flags & (LockCookieFlags::OwnedNone | LockCookieFlags::OwnedWriter)) != 0) {
    if (writerLevel > 0) {
      _writerLevel = writerLevel;
    } else {
      if (_writerLevel != 1) {
        _writerLevel = 1;
      }
      ReleaseWriterLock();
    }
  }

  lockCookie._flags = LockCookieFlags::Invalid;
}

LockCookie ReaderWriterLock___::ReleaseLock() {
  LockCookie result = LockCookie();
  Int32 num = result._threadID = GetCurrentThreadID();
  if (_writerID == num) {
    result._flags = (LockCookieFlags::Release | LockCookieFlags::OwnedWriter);
    result._writerLevel = _writerLevel;
    _writerLevel = 1;
    ReleaseWriterLock();
    return result;
  }
  ThreadLocalLockEntry current = ThreadLocalLockEntry::in::GetCurrent(_lockID);
  if (current == nullptr) {
    result._flags = (LockCookieFlags::Release | LockCookieFlags::OwnedNone);
    return result;
  }
  result._flags = (LockCookieFlags::Release | LockCookieFlags::OwnedReader);
  result._readerLevel = current->_readerLevel;
  current->_readerLevel = 1;
  ReleaseReaderLock();
  return result;
}

void ReaderWriterLock___::RestoreLock(LockCookie& lockCookie) {
  Int32 currentThreadID = GetCurrentThreadID();
  if (lockCookie._threadID != currentThreadID) {
    rt::throw_exception(GetInvalidLockCookieException());
  }
  if (_writerID == currentThreadID || ThreadLocalLockEntry::in::GetCurrent(_lockID) != nullptr) {
    rt::throw_exception<SynchronizationLockException>(SR::get_ReaderWriterLock_RestoreLockWithOwnedLocks());
  }
  LockCookieFlags flags = lockCookie._flags;
  if ((flags & LockCookieFlags::Invalid) != 0) {
    rt::throw_exception(GetInvalidLockCookieException());
  }
  if ((flags & LockCookieFlags::OwnedNone) == 0) {
    if ((flags & LockCookieFlags::OwnedWriter) != 0) {
      if (Interlocked::CompareExchange(_state, 4096, 0) == 0) {
        _writerID = currentThreadID;
        _writerLevel = lockCookie._writerLevel;
        _writerSeqNum++;
      }
    } else if ((flags & LockCookieFlags::OwnedReader) != 0) {
      ThreadLocalLockEntry orCreateCurrent = ThreadLocalLockEntry::in::GetOrCreateCurrent(_lockID);
      Int32 state = _state;
      if (state < 1023 && Interlocked::CompareExchange(_state, state + 1, state) == state) {
        orCreateCurrent->_readerLevel = lockCookie._readerLevel;
      }
    }

    RecoverLock(lockCookie, flags);
  }
}

void ReaderWriterLock___::RecoverLock(LockCookie& lockCookie, LockCookieFlags flags) {
  if ((flags & LockCookieFlags::OwnedWriter) != 0) {
    AcquireWriterLock(-1);
    _writerLevel = lockCookie._writerLevel;
  } else if ((flags & LockCookieFlags::OwnedReader) != 0) {
    AcquireReaderLock(-1);
    ThreadLocalLockEntry current = ThreadLocalLockEntry::in::GetCurrent(_lockID);
    current->_readerLevel = lockCookie._readerLevel;
  }

}

Int32 ReaderWriterLock___::GetCurrentThreadID() {
  return Environment::get_CurrentManagedThreadId();
}

Boolean ReaderWriterLock___::YieldProcessor() {
  Thread::in::SpinWait(1);
  return true;
}

ManualResetEventSlim ReaderWriterLock___::GetOrCreateReaderEvent() {
  ManualResetEventSlim readerEvent = _readerEvent;
  if (readerEvent != nullptr) {
    return readerEvent;
  }
  readerEvent = rt::newobj<ManualResetEventSlim>(false, 0);
  ManualResetEventSlim manualResetEventSlim = Interlocked::CompareExchange(_readerEvent, readerEvent, nullptr);
  if (manualResetEventSlim == nullptr) {
    return readerEvent;
  }
  readerEvent->Dispose();
  return manualResetEventSlim;
}

AutoResetEvent ReaderWriterLock___::GetOrCreateWriterEvent() {
  AutoResetEvent writerEvent = _writerEvent;
  if (writerEvent != nullptr) {
    return writerEvent;
  }
  writerEvent = rt::newobj<AutoResetEvent>(false);
  AutoResetEvent autoResetEvent = Interlocked::CompareExchange(_writerEvent, writerEvent, nullptr);
  if (autoResetEvent == nullptr) {
    return writerEvent;
  }
  writerEvent->Dispose();
  return autoResetEvent;
}

ManualResetEventSlim ReaderWriterLock___::TryGetOrCreateReaderEvent() {
  try{
    return GetOrCreateReaderEvent();
  } catch (...) {
  }
}

AutoResetEvent ReaderWriterLock___::TryGetOrCreateWriterEvent() {
  try{
    return GetOrCreateWriterEvent();
  } catch (...) {
  }
}

void ReaderWriterLock___::ReleaseEvents() {
  AutoResetEvent writerEvent = _writerEvent;
  _writerEvent = nullptr;
  ManualResetEventSlim readerEvent = _readerEvent;
  _readerEvent = nullptr;
  Interlocked::Add(_state, -3072);
}

ArgumentOutOfRangeException ReaderWriterLock___::GetInvalidTimeoutException(String parameterName) {
  return rt::newobj<ArgumentOutOfRangeException>(parameterName, SR::get_ArgumentOutOfRange_TimeoutMilliseconds());
}

Int32 ReaderWriterLock___::ToTimeoutMilliseconds(TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception(GetInvalidTimeoutException("timeout"));
  }
  return (Int32)num;
}

ApplicationException ReaderWriterLock___::GetTimeoutException() {
  return rt::newobj<ReaderWriterLockApplicationException>(-2147023436, SR::get_ReaderWriterLock_Timeout());
}

ApplicationException ReaderWriterLock___::GetNotOwnerException() {
  return rt::newobj<ReaderWriterLockApplicationException>(288, SR::get_ReaderWriterLock_NotOwner());
}

ApplicationException ReaderWriterLock___::GetInvalidLockCookieException() {
  return rt::newobj<ReaderWriterLockApplicationException>(-2147024809, SR::get_ReaderWriterLock_InvalidLockCookie());
}

void ReaderWriterLock___::cctor() {
  DefaultSpinCount = ((Environment::get_ProcessorCount() != 1) ? 500 : 0);
}

} // namespace System::Threading::System::Threading::ReaderWriterLockNamespace
