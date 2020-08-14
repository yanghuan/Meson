#include "CancellationToken-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>

namespace System::Private::CoreLib::System::Threading::CancellationTokenNamespace {
CancellationToken CancellationToken::get_None() {
  return CancellationToken();
}

Boolean CancellationToken::get_IsCancellationRequested() {
  if (_source != nullptr) {
    return _source->get_IsCancellationRequested();
  }
  return false;
}

Boolean CancellationToken::get_CanBeCanceled() {
  return _source != nullptr;
}

WaitHandle CancellationToken::get_WaitHandle() {
}

CancellationToken::CancellationToken(CancellationTokenSource source) {
  _source = source;
}

CancellationToken::CancellationToken(Boolean canceled) {
}

CancellationTokenRegistration CancellationToken::Register(Action<> callback) {
}

CancellationTokenRegistration CancellationToken::Register(Action<> callback, Boolean useSynchronizationContext) {
}

CancellationTokenRegistration CancellationToken::Register(Action<Object> callback, Object state) {
  return Register(callback, state, false, true);
}

CancellationTokenRegistration CancellationToken::Register(Action<Object> callback, Object state, Boolean useSynchronizationContext) {
  return Register(callback, state, useSynchronizationContext, true);
}

CancellationTokenRegistration CancellationToken::UnsafeRegister(Action<Object> callback, Object state) {
  return Register(callback, state, false, false);
}

CancellationTokenRegistration CancellationToken::Register(Action<Object> callback, Object state, Boolean useSynchronizationContext, Boolean useExecutionContext) {
  if (callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
}

Boolean CancellationToken::Equals(CancellationToken other) {
  return _source == other._source;
}

Boolean CancellationToken::Equals(Object other) {
  if (rt::is<CancellationToken>(other)) {
    return Equals((CancellationToken)other);
  }
  return false;
}

Int32 CancellationToken::GetHashCode() {
}

Boolean CancellationToken::op_Equality(CancellationToken left, CancellationToken right) {
  return left.Equals(right);
}

Boolean CancellationToken::op_Inequality(CancellationToken left, CancellationToken right) {
  return !left.Equals(right);
}

void CancellationToken::ThrowIfCancellationRequested() {
  if (get_IsCancellationRequested()) {
    ThrowOperationCanceledException();
  }
}

void CancellationToken::ThrowOperationCanceledException() {
  rt::throw_exception<OperationCanceledException>(SR::get_OperationCanceled(), *this);
}

void CancellationToken::cctor() {
}

} // namespace System::Private::CoreLib::System::Threading::CancellationTokenNamespace
