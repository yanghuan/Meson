#include "ManualResetEventSlim-dep.h"

namespace System::Private::CoreLib::System::Threading::ManualResetEventSlimNamespace {
WaitHandle ManualResetEventSlim___::get_WaitHandle() {
  return nullptr;
};

Boolean ManualResetEventSlim___::get_IsSet() {
  return Boolean();
};

void ManualResetEventSlim___::set_IsSet(Boolean value) {
};

Int32 ManualResetEventSlim___::get_SpinCount() {
  return Int32();
};

void ManualResetEventSlim___::set_SpinCount(Int32 value) {
};

Int32 ManualResetEventSlim___::get_Waiters() {
  return Int32();
};

void ManualResetEventSlim___::set_Waiters(Int32 value) {
};

void ManualResetEventSlim___::Initialize(Boolean initialState, Int32 spinCount) {
};

void ManualResetEventSlim___::EnsureLockObjectCreated() {
};

void ManualResetEventSlim___::LazyInitializeEvent() {
};

void ManualResetEventSlim___::Set() {
};

void ManualResetEventSlim___::Set(Boolean duringCancellation) {
};

void ManualResetEventSlim___::Reset() {
};

void ManualResetEventSlim___::Wait() {
};

void ManualResetEventSlim___::Wait(CancellationToken cancellationToken) {
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
};

void ManualResetEventSlim___::Dispose(Boolean disposing) {
};

void ManualResetEventSlim___::ThrowIfDisposed() {
};

void ManualResetEventSlim___::CancellationTokenCallback(Object obj) {
};

void ManualResetEventSlim___::UpdateStateAtomically(Int32 newBits, Int32 updateBitsMask) {
};

Int32 ManualResetEventSlim___::ExtractStatePortionAndShiftRight(Int32 state, Int32 mask, Int32 rightBitShiftCount) {
  return Int32();
};

Int32 ManualResetEventSlim___::ExtractStatePortion(Int32 state, Int32 mask) {
  return Int32();
};

} // namespace System::Private::CoreLib::System::Threading::ManualResetEventSlimNamespace
