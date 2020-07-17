#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
FORWARD(WaitOrTimerCallback)
namespace _ThreadPoolWaitOrTimerCallbackNamespace {
CLASS(_ThreadPoolWaitOrTimerCallback) {
  public: void Ctor(WaitOrTimerCallback waitOrTimerCallback, Object state, Boolean flowExecutionContext);
  private: static void WaitOrTimerCallback_Context_t(Object state);
  private: static void WaitOrTimerCallback_Context_f(Object state);
  private: static void WaitOrTimerCallback_Context(Object state, Boolean timedOut);
  public: static void PerformWaitOrTimerCallback(_ThreadPoolWaitOrTimerCallback helper, Boolean timedOut);
  private: static void SCtor();
  private: WaitOrTimerCallback _waitOrTimerCallback;
  private: ExecutionContext _executionContext;
  private: Object _state;
  private: static ContextCallback<> _ccbt;
  private: static ContextCallback<> _ccbf;
};
} // namespace _ThreadPoolWaitOrTimerCallbackNamespace
using _ThreadPoolWaitOrTimerCallback = _ThreadPoolWaitOrTimerCallbackNamespace::_ThreadPoolWaitOrTimerCallback;
} // namespace System::Private::CoreLib::System::Threading
