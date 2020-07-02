#include "SemaphoreSlim-dep.h"

#include <System.Private.CoreLib/System/Threading/SemaphoreSlim-dep.h>

namespace System::Private::CoreLib::System::Threading::SemaphoreSlimNamespace {
Int32 SemaphoreSlim___::get_CurrentCount() {
  return Int32();
};
WaitHandle SemaphoreSlim___::get_AvailableWaitHandle() {
  return nullptr;
};
void SemaphoreSlim___::Wait() {
  return void();
};
void SemaphoreSlim___::Wait(CancellationToken cancellationToken) {
  return void();
};
Boolean SemaphoreSlim___::Wait(TimeSpan timeout) {
  return Boolean();
};
Boolean SemaphoreSlim___::Wait(TimeSpan timeout, CancellationToken cancellationToken) {
  return Boolean();
};
Boolean SemaphoreSlim___::Wait(Int32 millisecondsTimeout) {
  return Boolean();
};
Boolean SemaphoreSlim___::Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  return Boolean();
};
Boolean SemaphoreSlim___::WaitUntilCountOrTimeout(Int32 millisecondsTimeout, UInt32 startTime, CancellationToken cancellationToken) {
  return Boolean();
};
Task<> SemaphoreSlim___::WaitAsync() {
  return nullptr;
};
Task<> SemaphoreSlim___::WaitAsync(CancellationToken cancellationToken) {
  return nullptr;
};
Task<Boolean> SemaphoreSlim___::WaitAsync(Int32 millisecondsTimeout) {
  return nullptr;
};
Task<Boolean> SemaphoreSlim___::WaitAsync(TimeSpan timeout) {
  return nullptr;
};
Task<Boolean> SemaphoreSlim___::WaitAsync(TimeSpan timeout, CancellationToken cancellationToken) {
  return nullptr;
};
Task<Boolean> SemaphoreSlim___::WaitAsync(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  return nullptr;
};
SemaphoreSlim::in::TaskNode SemaphoreSlim___::CreateAndAddAsyncWaiter() {
  return nullptr;
};
Boolean SemaphoreSlim___::RemoveAsyncWaiter(TaskNode task) {
  return Boolean();
};
Task<Boolean> SemaphoreSlim___::WaitUntilCountOrTimeoutAsync(TaskNode asyncWaiter, Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  return nullptr;
};
Int32 SemaphoreSlim___::Release() {
  return Int32();
};
Int32 SemaphoreSlim___::Release(Int32 releaseCount) {
  return Int32();
};
void SemaphoreSlim___::Dispose() {
  return void();
};
void SemaphoreSlim___::Dispose(Boolean disposing) {
  return void();
};
void SemaphoreSlim___::CancellationTokenCanceledEventHandler(Object obj) {
  return void();
};
void SemaphoreSlim___::CheckDispose() {
  return void();
};
} // namespace System::Private::CoreLib::System::Threading::SemaphoreSlimNamespace
