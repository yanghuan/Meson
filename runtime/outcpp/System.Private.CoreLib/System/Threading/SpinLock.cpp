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
  return void();
};
void SpinLock::TryEnter(Boolean& lockTaken) {
  return void();
};
void SpinLock::TryEnter(TimeSpan timeout, Boolean& lockTaken) {
  return void();
};
void SpinLock::TryEnter(Int32 millisecondsTimeout, Boolean& lockTaken) {
  return void();
};
void SpinLock::ContinueTryEnter(Int32 millisecondsTimeout, Boolean& lockTaken) {
  return void();
};
void SpinLock::DecrementWaiters() {
  return void();
};
void SpinLock::ContinueTryEnterWithThreadTracking(Int32 millisecondsTimeout, UInt32 startTime, Boolean& lockTaken) {
  return void();
};
void SpinLock::Exit() {
  return void();
};
void SpinLock::Exit(Boolean useMemoryBarrier) {
  return void();
};
void SpinLock::ExitSlowPath(Boolean useMemoryBarrier) {
  return void();
};
} // namespace System::Private::CoreLib::System::Threading::SpinLockNamespace
