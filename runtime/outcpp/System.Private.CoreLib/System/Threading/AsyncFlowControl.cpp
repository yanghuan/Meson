#include "AsyncFlowControl-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/AsyncFlowControl-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>

namespace System::Private::CoreLib::System::Threading::AsyncFlowControlNamespace {
void AsyncFlowControl::Initialize(Thread currentThread) {
  _thread = currentThread;
}

void AsyncFlowControl::Undo() {
  if (_thread == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotUseAFCMultiple());
  }
  if (Thread::in::get_CurrentThread() != _thread) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotUseAFCOtherThread());
  }
  if (!ExecutionContext::in::IsFlowSuppressed()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_AsyncFlowCtrlCtxMismatch());
  }
  _thread = nullptr;
  ExecutionContext::in::RestoreFlow();
}

void AsyncFlowControl::Dispose() {
  Undo();
}

Boolean AsyncFlowControl::Equals(Object obj) {
  if (rt::is<AsyncFlowControl>(obj)) {
    return Equals((AsyncFlowControl)obj);
  }
  return false;
}

Boolean AsyncFlowControl::Equals(AsyncFlowControl obj) {
  return _thread == obj._thread;
}

Int32 AsyncFlowControl::GetHashCode() {
  auto& default = _thread;
  auto& extern = default == nullptr ? nullptr : default->GetHashCode();
  return extern != nullptr ? extern : 0;
}

Boolean AsyncFlowControl::op_Equality(AsyncFlowControl a, AsyncFlowControl b) {
  return a.Equals(b);
}

Boolean AsyncFlowControl::op_Inequality(AsyncFlowControl a, AsyncFlowControl b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Threading::AsyncFlowControlNamespace
