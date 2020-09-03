#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ContextCallback)
FORWARD(ExecutionContext)
FORWARD(WaitOrTimerCallback)
namespace _ThreadPoolWaitOrTimerCallbackNamespace {
CLASS(_ThreadPoolWaitOrTimerCallback) : public object {
  public: void ctor(WaitOrTimerCallback waitOrTimerCallback, Object state, Boolean flowExecutionContext);
  private: static void WaitOrTimerCallback_Context_t(Object state);
  private: static void WaitOrTimerCallback_Context_f(Object state);
  private: static void WaitOrTimerCallback_Context(Object state, Boolean timedOut);
  public: static void PerformWaitOrTimerCallback(_ThreadPoolWaitOrTimerCallback helper, Boolean timedOut);
  private: static void cctor();
  private: WaitOrTimerCallback _waitOrTimerCallback;
  private: ExecutionContext _executionContext;
  private: Object _state;
  private: static ContextCallback _ccbt;
  private: static ContextCallback _ccbf;
};
} // namespace _ThreadPoolWaitOrTimerCallbackNamespace
using _ThreadPoolWaitOrTimerCallback = _ThreadPoolWaitOrTimerCallbackNamespace::_ThreadPoolWaitOrTimerCallback;
} // namespace System::Private::CoreLib::System::Threading
