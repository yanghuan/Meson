#include "CancellationTokenSource-dep.h"

#include <System.Private.CoreLib/System/Threading/CancellationTokenSource-dep.h>

namespace System::Private::CoreLib::System::Threading::CancellationTokenSourceNamespace {
void CancellationTokenSource___::CallbackNode___::ExecuteCallback() {
  return void();
};
void CancellationTokenSource___::Linked1CancellationTokenSource___::Dispose(Boolean disposing) {
  return void();
};
void CancellationTokenSource___::Linked2CancellationTokenSource___::Dispose(Boolean disposing) {
  return void();
};
void CancellationTokenSource___::LinkedNCancellationTokenSource___::Dispose(Boolean disposing) {
  return void();
};
Boolean CancellationTokenSource___::CallbackPartition___::Unregister(Int64 id, CallbackNode node) {
  return Boolean();
};
Boolean CancellationTokenSource___::get_IsCancellationRequested() {
  return Boolean();
};
Boolean CancellationTokenSource___::get_IsCancellationCompleted() {
  return Boolean();
};
Int32 CancellationTokenSource___::get_ThreadIDExecutingCallbacks() {
  return Int32();
};
void CancellationTokenSource___::set_ThreadIDExecutingCallbacks(Int32 value) {
  return void();
};
CancellationToken CancellationTokenSource___::get_Token() {
  return CancellationToken();
};
WaitHandle CancellationTokenSource___::get_WaitHandle() {
  return nullptr;
};
Int64 CancellationTokenSource___::get_ExecutingCallback() {
  return Int64();
};
void CancellationTokenSource___::InitializeWithTimer(Int32 millisecondsDelay) {
  return void();
};
void CancellationTokenSource___::Cancel() {
  return void();
};
void CancellationTokenSource___::Cancel(Boolean throwOnFirstException) {
  return void();
};
void CancellationTokenSource___::CancelAfter(TimeSpan delay) {
  return void();
};
void CancellationTokenSource___::CancelAfter(Int32 millisecondsDelay) {
  return void();
};
void CancellationTokenSource___::Dispose() {
  return void();
};
void CancellationTokenSource___::Dispose(Boolean disposing) {
  return void();
};
void CancellationTokenSource___::ThrowIfDisposed() {
  return void();
};
void CancellationTokenSource___::ThrowObjectDisposedException() {
  return void();
};
CancellationTokenRegistration CancellationTokenSource___::InternalRegister(Action<Object> callback, Object stateForCallback, SynchronizationContext syncContext, ExecutionContext executionContext) {
  return CancellationTokenRegistration();
};
void CancellationTokenSource___::NotifyCancellation(Boolean throwOnFirstException) {
  return void();
};
void CancellationTokenSource___::ExecuteCallbackHandlers(Boolean throwOnFirstException) {
  return void();
};
Int32 CancellationTokenSource___::GetPartitionCount() {
  return Int32();
};
CancellationTokenSource CancellationTokenSource___::CreateLinkedTokenSource(CancellationToken token1, CancellationToken token2) {
  return nullptr;
};
CancellationTokenSource CancellationTokenSource___::CreateLinkedTokenSource(CancellationToken token) {
  return nullptr;
};
CancellationTokenSource CancellationTokenSource___::CreateLinkedTokenSource(Array<CancellationToken> tokens) {
  return nullptr;
};
void CancellationTokenSource___::WaitForCallbackToComplete(Int64 id) {
  return void();
};
ValueTask<> CancellationTokenSource___::WaitForCallbackToCompleteAsync(Int64 id) {
  return ValueTask<>();
};
} // namespace System::Private::CoreLib::System::Threading::CancellationTokenSourceNamespace
