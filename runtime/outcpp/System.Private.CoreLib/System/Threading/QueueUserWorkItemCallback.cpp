#include "QueueUserWorkItemCallback-dep.h"

#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallback-dep.h>

namespace System::Private::CoreLib::System::Threading::QueueUserWorkItemCallbackNamespace {
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
}

} // namespace System::Private::CoreLib::System::Threading::QueueUserWorkItemCallbackNamespace
