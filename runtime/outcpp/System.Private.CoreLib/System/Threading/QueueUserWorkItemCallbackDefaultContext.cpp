#include "QueueUserWorkItemCallbackDefaultContext-dep.h"

namespace System::Private::CoreLib::System::Threading::QueueUserWorkItemCallbackDefaultContextNamespace {
void QueueUserWorkItemCallbackDefaultContext___<>::ctor(WaitCallback callback, Object state) {
  _callback = callback;
  _state = state;
}

void QueueUserWorkItemCallbackDefaultContext___<>::Execute() {
  QueueUserWorkItemCallbackBase::in::Execute();
  WaitCallback callback = _callback;
  _callback = nullptr;
  callback(_state);
}

} // namespace System::Private::CoreLib::System::Threading::QueueUserWorkItemCallbackDefaultContextNamespace
