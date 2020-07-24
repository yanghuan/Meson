#include "ReaderWriterLockSlim-dep.h"

namespace System::Private::CoreLib::System::Threading::ReaderWriterLockSlimNamespace {
Int32 ReaderWriterLockSlim___::TimeoutTracker::get_RemainingMilliseconds() {
  return Int32();
};

Boolean ReaderWriterLockSlim___::TimeoutTracker::get_IsExpired() {
  return Boolean();
};

ReaderWriterLockSlim___::TimeoutTracker::TimeoutTracker(TimeSpan timeout) {
};

ReaderWriterLockSlim___::TimeoutTracker::TimeoutTracker(Int32 millisecondsTimeout) {
};

UInt16 ReaderWriterLockSlim___::SpinLock::get_EnterForEnterAnyReadDeprioritizedCount() {
  return UInt16();
};

UInt16 ReaderWriterLockSlim___::SpinLock::get_EnterForEnterAnyWriteDeprioritizedCount() {
  return UInt16();
};

Int32 ReaderWriterLockSlim___::SpinLock::GetEnterDeprioritizationStateChange(EnterSpinLockReason reason) {
  return Int32();
};

Boolean ReaderWriterLockSlim___::SpinLock::IsEnterDeprioritized(EnterSpinLockReason reason) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::SpinLock::TryEnter() {
  return Boolean();
};

void ReaderWriterLockSlim___::SpinLock::Enter(EnterSpinLockReason reason) {
};

void ReaderWriterLockSlim___::SpinLock::EnterSpin(EnterSpinLockReason reason) {
};

void ReaderWriterLockSlim___::SpinLock::Exit() {
};

Boolean ReaderWriterLockSlim___::get_HasNoWaiters() {
  return Boolean();
};

void ReaderWriterLockSlim___::set_HasNoWaiters(Boolean value) {
};

Boolean ReaderWriterLockSlim___::get_IsReadLockHeld() {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::get_IsUpgradeableReadLockHeld() {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::get_IsWriteLockHeld() {
  return Boolean();
};

LockRecursionPolicy ReaderWriterLockSlim___::get_RecursionPolicy() {
  return LockRecursionPolicy::SupportsRecursion;
};

Int32 ReaderWriterLockSlim___::get_CurrentReadCount() {
  return Int32();
};

Int32 ReaderWriterLockSlim___::get_RecursiveReadCount() {
  return Int32();
};

Int32 ReaderWriterLockSlim___::get_RecursiveUpgradeCount() {
  return Int32();
};

Int32 ReaderWriterLockSlim___::get_RecursiveWriteCount() {
  return Int32();
};

Int32 ReaderWriterLockSlim___::get_WaitingReadCount() {
  return Int32();
};

Int32 ReaderWriterLockSlim___::get_WaitingUpgradeCount() {
  return Int32();
};

Int32 ReaderWriterLockSlim___::get_WaitingWriteCount() {
  return Int32();
};

void ReaderWriterLockSlim___::InitializeThreadCounts() {
};

void ReaderWriterLockSlim___::Ctor() {
};

void ReaderWriterLockSlim___::Ctor(LockRecursionPolicy recursionPolicy) {
};

Boolean ReaderWriterLockSlim___::IsRWEntryEmpty(ReaderWriterCount rwc) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::IsRwHashEntryChanged(ReaderWriterCount lrwc) {
  return Boolean();
};

ReaderWriterCount ReaderWriterLockSlim___::GetThreadRWCount(Boolean dontAllocate) {
  return nullptr;
};

void ReaderWriterLockSlim___::EnterReadLock() {
};

Boolean ReaderWriterLockSlim___::TryEnterReadLock(TimeSpan timeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterReadLock(Int32 millisecondsTimeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterReadLock(TimeoutTracker timeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterReadLockCore(TimeoutTracker timeout) {
  return Boolean();
};

void ReaderWriterLockSlim___::EnterWriteLock() {
};

Boolean ReaderWriterLockSlim___::TryEnterWriteLock(TimeSpan timeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterWriteLock(Int32 millisecondsTimeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterWriteLock(TimeoutTracker timeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterWriteLockCore(TimeoutTracker timeout) {
  return Boolean();
};

void ReaderWriterLockSlim___::EnterUpgradeableReadLock() {
};

Boolean ReaderWriterLockSlim___::TryEnterUpgradeableReadLock(TimeSpan timeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterUpgradeableReadLock(Int32 millisecondsTimeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterUpgradeableReadLock(TimeoutTracker timeout) {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::TryEnterUpgradeableReadLockCore(TimeoutTracker timeout) {
  return Boolean();
};

void ReaderWriterLockSlim___::ExitReadLock() {
};

void ReaderWriterLockSlim___::ExitWriteLock() {
};

void ReaderWriterLockSlim___::ExitUpgradeableReadLock() {
};

void ReaderWriterLockSlim___::LazyCreateEvent(EventWaitHandle& waitEvent, EnterLockType enterLockType) {
};

Boolean ReaderWriterLockSlim___::WaitOnEvent(EventWaitHandle waitEvent, UInt32& numWaiters, TimeoutTracker timeout, EnterLockType enterLockType) {
  return Boolean();
};

void ReaderWriterLockSlim___::ExitAndWakeUpAppropriateWaiters() {
};

void ReaderWriterLockSlim___::ExitAndWakeUpAppropriateWaitersPreferringWriters() {
};

void ReaderWriterLockSlim___::ExitAndWakeUpAppropriateReadWaiters() {
};

Boolean ReaderWriterLockSlim___::IsWriterAcquired() {
  return Boolean();
};

void ReaderWriterLockSlim___::SetWriterAcquired() {
};

void ReaderWriterLockSlim___::ClearWriterAcquired() {
};

void ReaderWriterLockSlim___::SetWritersWaiting() {
};

void ReaderWriterLockSlim___::ClearWritersWaiting() {
};

void ReaderWriterLockSlim___::SetUpgraderWaiting() {
};

void ReaderWriterLockSlim___::ClearUpgraderWaiting() {
};

UInt32 ReaderWriterLockSlim___::GetNumReaders() {
  return UInt32();
};

Boolean ReaderWriterLockSlim___::ShouldSpinForEnterAnyRead() {
  return Boolean();
};

Boolean ReaderWriterLockSlim___::ShouldSpinForEnterAnyWrite(Boolean isUpgradeToWrite) {
  return Boolean();
};

void ReaderWriterLockSlim___::SpinWait(Int32 spinCount) {
};

void ReaderWriterLockSlim___::Dispose() {
};

void ReaderWriterLockSlim___::Dispose(Boolean disposing) {
};

} // namespace System::Private::CoreLib::System::Threading::ReaderWriterLockSlimNamespace
