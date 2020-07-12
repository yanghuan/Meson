#include "SpinLock-dep.h"

namespace System::Private::CoreLib::System::Threading::SpinLockNamespace {
Nullable<Boolean> SystemThreading_SpinLockDebugView___::get_IsHeldByCurrentThread() {
  return Nullable<Boolean>();
};

Nullable<Int32> SystemThreading_SpinLockDebugView___::get_OwnerThreadID() {
  return Nullable<Int32>();
};

Boolean SystemThreading_SpinLockDebugView___::get_IsHeld() {
  return Boolean();
};

Boolean SpinLock::get_IsHeld() {
  return Boolean();
};

Boolean SpinLock::get_IsHeldByCurrentThread() {
  return Boolean();
};

Boolean SpinLock::get_IsThreadOwnerTrackingEnabled() {
  return Boolean();
};

Int32 SpinLock::CompareExchange(Int32& location, Int32 value, Int32 comparand, Boolean& success) {
  return Int32();
};

void SpinLock::Enter(Boolean& lockTaken) {
};

void SpinLock::TryEnter(Boolean& lockTaken) {
};

void SpinLock::TryEnter(TimeSpan timeout, Boolean& lockTaken) {
};

void SpinLock::TryEnter(Int32 millisecondsTimeout, Boolean& lockTaken) {
};

void SpinLock::ContinueTryEnter(Int32 millisecondsTimeout, Boolean& lockTaken) {
};

void SpinLock::DecrementWaiters() {
};

void SpinLock::ContinueTryEnterWithThreadTracking(Int32 millisecondsTimeout, UInt32 startTime, Boolean& lockTaken) {
};

void SpinLock::Exit() {
};

void SpinLock::Exit(Boolean useMemoryBarrier) {
};

void SpinLock::ExitSlowPath(Boolean useMemoryBarrier) {
};

} // namespace System::Private::CoreLib::System::Threading::SpinLockNamespace
