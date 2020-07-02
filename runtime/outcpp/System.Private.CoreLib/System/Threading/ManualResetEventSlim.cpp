#include "ManualResetEventSlim-dep.h"

namespace System::Private::CoreLib::System::Threading::ManualResetEventSlimNamespace {
WaitHandle ManualResetEventSlim___::get_WaitHandle() {
  return nullptr;
};
Boolean ManualResetEventSlim___::get_IsSet() {
  return Boolean();
};
void ManualResetEventSlim___::set_IsSet(Boolean value) {
  return void();
};
Int32 ManualResetEventSlim___::get_SpinCount() {
  return Int32();
};
void ManualResetEventSlim___::set_SpinCount(Int32 value) {
  return void();
};
Int32 ManualResetEventSlim___::get_Waiters() {
  return Int32();
};
void ManualResetEventSlim___::set_Waiters(Int32 value) {
  return void();
};
void ManualResetEventSlim___::Initialize(Boolean initialState, Int32 spinCount) {
  return void();
};
void ManualResetEventSlim___::EnsureLockObjectCreated() {
  return void();
};
Boolean ManualResetEventSlim___::LazyInitializeEvent() {
  return Boolean();
};
void ManualResetEventSlim___::Set() {
  return void();
};
void ManualResetEventSlim___::Set(Boolean duringCancellation) {
  return void();
};
void ManualResetEventSlim___::Reset() {
  return void();
};
void ManualResetEventSlim___::Wait() {
  return void();
};
void ManualResetEventSlim___::Wait(CancellationToken cancellationToken) {
  return void();
};
Boolean ManualResetEventSlim___::Wait(TimeSpan timeout) {
  return Boolean();
};
Boolean ManualResetEventSlim___::Wait(TimeSpan timeout, CancellationToken cancellationToken) {
  return Boolean();
};
Boolean ManualResetEventSlim___::Wait(Int32 millisecondsTimeout) {
  return Boolean();
};
Boolean ManualResetEventSlim___::Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  return Boolean();
};
void ManualResetEventSlim___::Dispose() {
  return void();
};
void ManualResetEventSlim___::Dispose(Boolean disposing) {
  return void();
};
void ManualResetEventSlim___::ThrowIfDisposed() {
  return void();
};
void ManualResetEventSlim___::CancellationTokenCallback(Object obj) {
  return void();
};
void ManualResetEventSlim___::UpdateStateAtomically(Int32 newBits, Int32 updateBitsMask) {
  return void();
};
Int32 ManualResetEventSlim___::ExtractStatePortionAndShiftRight(Int32 state, Int32 mask, Int32 rightBitShiftCount) {
  return Int32();
};
Int32 ManualResetEventSlim___::ExtractStatePortion(Int32 state, Int32 mask) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Threading::ManualResetEventSlimNamespace
