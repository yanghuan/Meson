#include "WaitHandle-dep.h"

namespace System::Private::CoreLib::System::Threading::WaitHandleNamespace {
IntPtr WaitHandle___::get_Handle() {
  return IntPtr();
};
void WaitHandle___::set_Handle(IntPtr value) {
  return void();
};
SafeWaitHandle WaitHandle___::get_SafeWaitHandle() {
  return nullptr;
};
void WaitHandle___::set_SafeWaitHandle(SafeWaitHandle value) {
  return void();
};
Int32 WaitHandle___::WaitMultipleIgnoringSyncContext(Span<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  return Int32();
};
Int32 WaitHandle___::SignalAndWaitCore(IntPtr waitHandleToSignal, IntPtr waitHandleToWaitOn, Int32 millisecondsTimeout) {
  return Int32();
};
Int32 WaitHandle___::ToTimeoutMilliseconds(TimeSpan timeout) {
  return Int32();
};
void WaitHandle___::Close() {
  return void();
};
void WaitHandle___::Dispose(Boolean explicitDisposing) {
  return void();
};
void WaitHandle___::Dispose() {
  return void();
};
Boolean WaitHandle___::WaitOne(Int32 millisecondsTimeout) {
  return Boolean();
};
Boolean WaitHandle___::WaitOneNoCheck(Int32 millisecondsTimeout) {
  return Boolean();
};
Array<SafeWaitHandle> WaitHandle___::RentSafeWaitHandleArray(Int32 capacity) {
  return Array<SafeWaitHandle>();
};
void WaitHandle___::ReturnSafeWaitHandleArray(Array<SafeWaitHandle> safeWaitHandles) {
  return void();
};
void WaitHandle___::ObtainSafeWaitHandles(ReadOnlySpan<WaitHandle> waitHandles, Span<SafeWaitHandle> safeWaitHandles, Span<IntPtr> unsafeWaitHandles) {
  return void();
};
Int32 WaitHandle___::WaitMultiple(Array<WaitHandle> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  return Int32();
};
Int32 WaitHandle___::WaitMultiple(ReadOnlySpan<WaitHandle> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  return Int32();
};
Boolean WaitHandle___::SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, Int32 millisecondsTimeout) {
  return Boolean();
};
Boolean WaitHandle___::WaitOne(TimeSpan timeout) {
  return Boolean();
};
Boolean WaitHandle___::WaitOne() {
  return Boolean();
};
Boolean WaitHandle___::WaitOne(Int32 millisecondsTimeout, Boolean exitContext) {
  return Boolean();
};
Boolean WaitHandle___::WaitOne(TimeSpan timeout, Boolean exitContext) {
  return Boolean();
};
Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout) {
  return Boolean();
};
Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles, TimeSpan timeout) {
  return Boolean();
};
Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles) {
  return Boolean();
};
Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout, Boolean exitContext) {
  return Boolean();
};
Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles, TimeSpan timeout, Boolean exitContext) {
  return Boolean();
};
Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout) {
  return Int32();
};
Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles, TimeSpan timeout) {
  return Int32();
};
Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles) {
  return Int32();
};
Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout, Boolean exitContext) {
  return Int32();
};
Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles, TimeSpan timeout, Boolean exitContext) {
  return Int32();
};
Boolean WaitHandle___::SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn) {
  return Boolean();
};
Boolean WaitHandle___::SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, TimeSpan timeout, Boolean exitContext) {
  return Boolean();
};
Boolean WaitHandle___::SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, Int32 millisecondsTimeout, Boolean exitContext) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Threading::WaitHandleNamespace