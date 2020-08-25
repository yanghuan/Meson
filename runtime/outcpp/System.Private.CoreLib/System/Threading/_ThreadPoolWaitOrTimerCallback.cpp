#include "_ThreadPoolWaitOrTimerCallback-dep.h"

#include <System.Private.CoreLib/System/Threading/_ThreadPoolWaitOrTimerCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>

namespace System::Private::CoreLib::System::Threading::_ThreadPoolWaitOrTimerCallbackNamespace {
void _ThreadPoolWaitOrTimerCallback___::ctor(WaitOrTimerCallback waitOrTimerCallback, Object state, Boolean flowExecutionContext) {
  _waitOrTimerCallback = waitOrTimerCallback;
  _state = state;
  if (flowExecutionContext) {
    _executionContext = ExecutionContext::in::Capture();
  }
}

void _ThreadPoolWaitOrTimerCallback___::WaitOrTimerCallback_Context_t(Object state) {
  WaitOrTimerCallback_Context(state, true);
}

void _ThreadPoolWaitOrTimerCallback___::WaitOrTimerCallback_Context_f(Object state) {
  WaitOrTimerCallback_Context(state, false);
}

void _ThreadPoolWaitOrTimerCallback___::WaitOrTimerCallback_Context(Object state, Boolean timedOut) {
  _ThreadPoolWaitOrTimerCallback threadPoolWaitOrTimerCallback = (_ThreadPoolWaitOrTimerCallback)state;
  threadPoolWaitOrTimerCallback->_waitOrTimerCallback(threadPoolWaitOrTimerCallback->_state, timedOut);
}

void _ThreadPoolWaitOrTimerCallback___::PerformWaitOrTimerCallback(_ThreadPoolWaitOrTimerCallback helper, Boolean timedOut) {
  ExecutionContext executionContext = helper->_executionContext;
  if (executionContext == nullptr) {
    WaitOrTimerCallback waitOrTimerCallback = helper->_waitOrTimerCallback;
    waitOrTimerCallback(helper->_state, timedOut);
  } else {
    ExecutionContext::in::Run(executionContext, timedOut ? _ccbt : _ccbf, helper);
  }
}

void _ThreadPoolWaitOrTimerCallback___::cctor() {
  _ccbt = &WaitOrTimerCallback_Context_t;
  _ccbf = &WaitOrTimerCallback_Context_f;
}

} // namespace System::Private::CoreLib::System::Threading::_ThreadPoolWaitOrTimerCallbackNamespace
