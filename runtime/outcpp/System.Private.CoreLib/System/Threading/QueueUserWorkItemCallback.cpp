#include "QueueUserWorkItemCallback-dep.h"

#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitCallback-dep.h>

namespace System::Private::CoreLib::System::Threading::QueueUserWorkItemCallbackNamespace {
void QueueUserWorkItemCallback___<>::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void QueueUserWorkItemCallback___<>::__c___::ctor() {
}

void QueueUserWorkItemCallback___<>::__c___::_cctor_b__6_0(QueueUserWorkItemCallback<> quwi) {
  WaitCallback callback = quwi->_callback;
  quwi->_callback = nullptr;
  callback(quwi->_state);
}

void QueueUserWorkItemCallback___<>::ctor(WaitCallback callback, Object state, ExecutionContext context) {
  _callback = callback;
  _state = state;
  _context = context;
}

void QueueUserWorkItemCallback___<>::Execute() {
  QueueUserWorkItemCallbackBase::in::Execute();
  ExecutionContext::in::RunForThreadPoolUnsafe(_context, s_executionContextShim, (QueueUserWorkItemCallback<>)this);
}

void QueueUserWorkItemCallback___<>::cctor() {
  s_executionContextShim = {__c::in::__9, &__c::in::_cctor_b__6_0};
}

} // namespace System::Private::CoreLib::System::Threading::QueueUserWorkItemCallbackNamespace
