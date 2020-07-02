#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitOrTimerCallback)
FORWARD(ExecutionContext)
FORWARD_(ContextCallback, T1, T2)
namespace _ThreadPoolWaitOrTimerCallbackNamespace {
CLASS(_ThreadPoolWaitOrTimerCallback) {
  private: static void WaitOrTimerCallback_Context_t(Object state);
  private: static void WaitOrTimerCallback_Context_f(Object state);
  private: static void WaitOrTimerCallback_Context(Object state, Boolean timedOut);
  public: static void PerformWaitOrTimerCallback(_ThreadPoolWaitOrTimerCallback helper, Boolean timedOut);
  private: WaitOrTimerCallback _waitOrTimerCallback;
  private: ExecutionContext _executionContext;
  private: Object _state;
  private: static ContextCallback<> _ccbt;
  private: static ContextCallback<> _ccbf;
};
} // namespace _ThreadPoolWaitOrTimerCallbackNamespace
using _ThreadPoolWaitOrTimerCallback = _ThreadPoolWaitOrTimerCallbackNamespace::_ThreadPoolWaitOrTimerCallback;
} // namespace System::Private::CoreLib::System::Threading
