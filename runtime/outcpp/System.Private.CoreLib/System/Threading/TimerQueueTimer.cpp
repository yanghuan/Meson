#include "TimerQueueTimer-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/FrameworkEventSource-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/EventWaitHandle-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueueTimer-dep.h>

namespace System::Private::CoreLib::System::Threading::TimerQueueTimerNamespace {
using namespace System::Diagnostics::Tracing;
using namespace System::Threading::Tasks;

void TimerQueueTimer___::ctor(TimerCallback timerCallback, Object state, UInt32 dueTime, UInt32 period, Boolean flowExecutionContext) {
  _timerCallback = timerCallback;
  _state = state;
  _dueTime = UInt32::MaxValue;
  _period = UInt32::MaxValue;
  if (flowExecutionContext) {
    _executionContext = ExecutionContext::in::Capture();
  }
  _associatedTimerQueue = TimerQueue::in::get_Instances()[Thread::in::GetCurrentProcessorId() % TimerQueue::in::get_Instances()->get_Length()];
  if (dueTime != UInt32::MaxValue) {
    Change(dueTime, period);
  }
}

Boolean TimerQueueTimer___::Change(UInt32 dueTime, UInt32 period) {
}

void TimerQueueTimer___::Close() {
}

Boolean TimerQueueTimer___::Close(WaitHandle toSignal) {
  Boolean flag = false;
  Boolean result;
}

ValueTask<> TimerQueueTimer___::CloseAsync() {
}

void TimerQueueTimer___::Fire(Boolean isThreadPool) {
  Boolean flag = false;
}

void TimerQueueTimer___::SignalNoCallbacksRunning() {
  Object notifyWhenNoCallbacksRunning = _notifyWhenNoCallbacksRunning;
  WaitHandle waitHandle = rt::as<WaitHandle>(notifyWhenNoCallbacksRunning);
  if (waitHandle != nullptr) {
    EventWaitHandle::in::Set(waitHandle->get_SafeWaitHandle());
  } else {
    ((Task<Boolean>)notifyWhenNoCallbacksRunning)->TrySetResult(true);
  }
}

void TimerQueueTimer___::CallCallback(Boolean isThreadPool) {
  if (FrameworkEventSource::in::Log->IsEnabled(EventLevel::Informational, (EventKeywords)16)) {
    FrameworkEventSource::in::Log->ThreadTransferReceiveObj((TimerQueueTimer)this, 1, String::in::Empty);
  }
  ExecutionContext executionContext = _executionContext;
  if (executionContext == nullptr) {
    _timerCallback(_state);
  } else if (isThreadPool) {
    ExecutionContext::in::RunFromThreadPoolDispatchLoop(Thread::in::get_CurrentThread(), executionContext, s_callCallbackInContext, (TimerQueueTimer)this);
  } else {
    ExecutionContext::in::RunInternal(executionContext, s_callCallbackInContext, (TimerQueueTimer)this);
  }

}

void TimerQueueTimer___::cctor() {
}

} // namespace System::Private::CoreLib::System::Threading::TimerQueueTimerNamespace
