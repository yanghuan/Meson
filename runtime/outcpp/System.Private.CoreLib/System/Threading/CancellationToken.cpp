#include "CancellationToken-dep.h"

#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>

namespace System::Private::CoreLib::System::Threading::CancellationTokenNamespace {
CancellationToken CancellationToken::get_None() {
  return CancellationToken();
};
Boolean CancellationToken::get_IsCancellationRequested() {
  return Boolean();
};
Boolean CancellationToken::get_CanBeCanceled() {
  return Boolean();
};
WaitHandle CancellationToken::get_WaitHandle() {
  return nullptr;
};
CancellationTokenRegistration CancellationToken::Register(Action<> callback) {
  return CancellationTokenRegistration();
};
CancellationTokenRegistration CancellationToken::Register(Action<> callback, Boolean useSynchronizationContext) {
  return CancellationTokenRegistration();
};
CancellationTokenRegistration CancellationToken::Register(Action<Object> callback, Object state) {
  return CancellationTokenRegistration();
};
CancellationTokenRegistration CancellationToken::Register(Action<Object> callback, Object state, Boolean useSynchronizationContext) {
  return CancellationTokenRegistration();
};
CancellationTokenRegistration CancellationToken::UnsafeRegister(Action<Object> callback, Object state) {
  return CancellationTokenRegistration();
};
CancellationTokenRegistration CancellationToken::Register(Action<Object> callback, Object state, Boolean useSynchronizationContext, Boolean useExecutionContext) {
  return CancellationTokenRegistration();
};
Boolean CancellationToken::Equals(CancellationToken other) {
  return Boolean();
};
Boolean CancellationToken::Equals(Object other) {
  return Boolean();
};
Int32 CancellationToken::GetHashCode() {
  return Int32();
};
void CancellationToken::ThrowIfCancellationRequested() {
};
void CancellationToken::ThrowOperationCanceledException() {
};
} // namespace System::Private::CoreLib::System::Threading::CancellationTokenNamespace
