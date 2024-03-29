#include "CancellationToken-dep.h"

#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenSource-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>

namespace System::Private::CoreLib::System::Threading::CancellationTokenNamespace {
void CancellationToken::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void CancellationToken::__c___::ctor() {
}

void CancellationToken::__c___::_cctor_b__26_0(Object obj) {
  ((Action<>)obj)();
}

CancellationToken CancellationToken::get_None() {
  return rt::default__;
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
  CancellationTokenSource as = _source;
  return (as != nullptr ? as : CancellationTokenSource::in::s_neverCanceledSource)->get_WaitHandle();
}

CancellationToken::CancellationToken(CancellationTokenSource source) {
  _source = source;
}

CancellationToken::CancellationToken(Boolean canceled) {
}

CancellationTokenRegistration CancellationToken::Register(Action<> callback) {
  Action<Object> callback2 = s_actionToActionObjShunt;
  if (callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
  return Register(callback2, callback, false, true);
}

CancellationTokenRegistration CancellationToken::Register(Action<> callback, Boolean useSynchronizationContext) {
  Action<Object> callback2 = s_actionToActionObjShunt;
  if (callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
  return Register(callback2, callback, useSynchronizationContext, true);
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
  CancellationTokenSource source = _source;
  if (source == nullptr) {
    return rt::default__;
  }
  return source->InternalRegister(callback, state, useSynchronizationContext ? SynchronizationContext::in::get_Current() : nullptr, useExecutionContext ? ExecutionContext::in::Capture() : nullptr);
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
  CancellationTokenSource as = _source;
  return (as != nullptr ? as : CancellationTokenSource::in::s_neverCanceledSource)->GetHashCode();
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
  s_actionToActionObjShunt = {__c::in::__9, &__c::in::_cctor_b__26_0};
}

} // namespace System::Private::CoreLib::System::Threading::CancellationTokenNamespace
