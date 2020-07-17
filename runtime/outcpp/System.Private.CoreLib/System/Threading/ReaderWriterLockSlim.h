#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARDS(TimeSpan)
FORWARDS(UInt16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
enum class LockRecursionPolicy;
FORWARD(EventWaitHandle)
FORWARD(ReaderWriterCount)
namespace ReaderWriterLockSlimNamespace {
CLASS(ReaderWriterLockSlim) {
  private: enum class WaiterStates : uint8_t {
    None = 0,
    NoWaiters = 1,
    WriteWaiterSignaled = 2,
    UpgradeableReadWaiterSignaled = 4,
  };
  private: enum class EnterSpinLockReason {
    EnterAnyRead = 0,
    ExitAnyRead = 1,
    EnterWrite = 2,
    UpgradeToWrite = 3,
    EnterRecursiveWrite = 4,
    ExitAnyWrite = 5,
    OperationMask = 7,
    Wait = 8,
  };
  private: enum class EnterLockType {
    Read = 0,
    UpgradeableRead = 1,
    Write = 2,
    UpgradeToWrite = 3,
  };
  private: struct TimeoutTracker {
    public: Int32 get_RemainingMilliseconds();
    public: Boolean get_IsExpired();
    public: void Ctor(TimeSpan timeout);
    public: void Ctor(Int32 millisecondsTimeout);
    public: void Ctor();
    private: Int32 _total;
    private: Int32 _start;
  };
  private: struct SpinLock {
    private: UInt16 get_EnterForEnterAnyReadDeprioritizedCount();
    private: UInt16 get_EnterForEnterAnyWriteDeprioritizedCount();
    private: static Int32 GetEnterDeprioritizationStateChange(EnterSpinLockReason reason);
    private: Boolean IsEnterDeprioritized(EnterSpinLockReason reason);
    private: Boolean TryEnter();
    public: void Enter(EnterSpinLockReason reason);
    private: void EnterSpin(EnterSpinLockReason reason);
    public: void Exit();
    public: void Ctor();
    private: Int32 _isLocked;
    private: Int32 _enterDeprioritizationState;
  };
  private: Boolean get_HasNoWaiters();
  private: void set_HasNoWaiters(Boolean value);
  public: Boolean get_IsReadLockHeld();
  public: Boolean get_IsUpgradeableReadLockHeld();
  public: Boolean get_IsWriteLockHeld();
  public: LockRecursionPolicy get_RecursionPolicy();
  public: Int32 get_CurrentReadCount();
  public: Int32 get_RecursiveReadCount();
  public: Int32 get_RecursiveUpgradeCount();
  public: Int32 get_RecursiveWriteCount();
  public: Int32 get_WaitingReadCount();
  public: Int32 get_WaitingUpgradeCount();
  public: Int32 get_WaitingWriteCount();
  private: void InitializeThreadCounts();
  public: void Ctor();
  public: void Ctor(LockRecursionPolicy recursionPolicy);
  private: static Boolean IsRWEntryEmpty(ReaderWriterCount rwc);
  private: Boolean IsRwHashEntryChanged(ReaderWriterCount lrwc);
  private: ReaderWriterCount GetThreadRWCount(Boolean dontAllocate);
  public: void EnterReadLock();
  public: Boolean TryEnterReadLock(TimeSpan timeout);
  public: Boolean TryEnterReadLock(Int32 millisecondsTimeout);
  private: Boolean TryEnterReadLock(TimeoutTracker timeout);
  private: Boolean TryEnterReadLockCore(TimeoutTracker timeout);
  public: void EnterWriteLock();
  public: Boolean TryEnterWriteLock(TimeSpan timeout);
  public: Boolean TryEnterWriteLock(Int32 millisecondsTimeout);
  private: Boolean TryEnterWriteLock(TimeoutTracker timeout);
  private: Boolean TryEnterWriteLockCore(TimeoutTracker timeout);
  public: void EnterUpgradeableReadLock();
  public: Boolean TryEnterUpgradeableReadLock(TimeSpan timeout);
  public: Boolean TryEnterUpgradeableReadLock(Int32 millisecondsTimeout);
  private: Boolean TryEnterUpgradeableReadLock(TimeoutTracker timeout);
  private: Boolean TryEnterUpgradeableReadLockCore(TimeoutTracker timeout);
  public: void ExitReadLock();
  public: void ExitWriteLock();
  public: void ExitUpgradeableReadLock();
  private: void LazyCreateEvent(EventWaitHandle& waitEvent, EnterLockType enterLockType);
  private: Boolean WaitOnEvent(EventWaitHandle waitEvent, UInt32& numWaiters, TimeoutTracker timeout, EnterLockType enterLockType);
  private: void ExitAndWakeUpAppropriateWaiters();
  private: void ExitAndWakeUpAppropriateWaitersPreferringWriters();
  private: void ExitAndWakeUpAppropriateReadWaiters();
  private: Boolean IsWriterAcquired();
  private: void SetWriterAcquired();
  private: void ClearWriterAcquired();
  private: void SetWritersWaiting();
  private: void ClearWritersWaiting();
  private: void SetUpgraderWaiting();
  private: void ClearUpgraderWaiting();
  private: UInt32 GetNumReaders();
  private: Boolean ShouldSpinForEnterAnyRead();
  private: Boolean ShouldSpinForEnterAnyWrite(Boolean isUpgradeToWrite);
  private: static void SpinWait(Int32 spinCount);
  public: void Dispose();
  private: void Dispose(Boolean disposing);
  private: Boolean _fIsReentrant;
  private: SpinLock _spinLock;
  private: UInt32 _numWriteWaiters;
  private: UInt32 _numReadWaiters;
  private: UInt32 _numWriteUpgradeWaiters;
  private: UInt32 _numUpgradeWaiters;
  private: WaiterStates _waiterStates;
  private: Int32 _upgradeLockOwnerId;
  private: Int32 _writeLockOwnerId;
  private: EventWaitHandle _writeEvent;
  private: EventWaitHandle _readEvent;
  private: EventWaitHandle _upgradeEvent;
  private: EventWaitHandle _waitUpgradeEvent;
  private: static Int64 s_nextLockID;
  private: Int64 _lockID;
  private: static ReaderWriterCount t_rwc;
  private: Boolean _fUpgradeThreadHoldingRead;
  private: UInt32 _owners;
  private: Boolean _fDisposed;
};
} // namespace ReaderWriterLockSlimNamespace
using ReaderWriterLockSlim = ReaderWriterLockSlimNamespace::ReaderWriterLockSlim;
} // namespace System::Private::CoreLib::System::Threading
