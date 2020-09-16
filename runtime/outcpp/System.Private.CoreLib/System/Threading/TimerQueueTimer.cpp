#include "TimerQueueTimer-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/FrameworkEventSource-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/EventWaitHandle-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueueTimer-dep.h>

namespace System::Private::CoreLib::System::Threading::TimerQueueTimerNamespace {
using namespace System::Diagnostics::Tracing;
using namespace System::Threading::Tasks;

void TimerQueueTimer___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void TimerQueueTimer___::__c___::ctor() {
}

void TimerQueueTimer___::__c___::_cctor_b__23_0(Object state) {
  TimerQueueTimer timerQueueTimer = (TimerQueueTimer)state;
  timerQueueTimer->_timerCallback(timerQueueTimer->_state);
}

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
  {
    rt::lock(_associatedTimerQueue);
    if (_canceled) {
      rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_Generic());
    }
    _period = period;
    if (dueTime == UInt32::MaxValue) {
      _associatedTimerQueue->DeleteTimer((TimerQueueTimer)this);
      return true;
    }
    if (FrameworkEventSource::in::Log->IsEnabled(EventLevel::Informational, (EventKeywords)16)) {
      FrameworkEventSource::in::Log->ThreadTransferSendObj((TimerQueueTimer)this, 1, String::in::Empty, true, (Int32)dueTime, (Int32)period);
    }
    return _associatedTimerQueue->UpdateTimer((TimerQueueTimer)this, dueTime, period);
  }
}

void TimerQueueTimer___::Close() {
  {
    rt::lock(_associatedTimerQueue);
    if (!_canceled) {
      _canceled = true;
      _associatedTimerQueue->DeleteTimer((TimerQueueTimer)this);
    }
  }
}

Boolean TimerQueueTimer___::Close(WaitHandle toSignal) {
  Boolean flag = false;
  Boolean result;
  {
    rt::lock(_associatedTimerQueue);
    if (_canceled) {
      result = false;
    } else {
      _canceled = true;
      _notifyWhenNoCallbacksRunning = toSignal;
      _associatedTimerQueue->DeleteTimer((TimerQueueTimer)this);
      flag = (_callbacksRunning == 0);
      result = true;
    }
  }
  if (flag) {
    SignalNoCallbacksRunning();
  }
  return result;
}

ValueTask<> TimerQueueTimer___::CloseAsync() {
  {
    rt::lock(_associatedTimerQueue);
    Object notifyWhenNoCallbacksRunning = _notifyWhenNoCallbacksRunning;
    if (_canceled) {
      if (rt::is<WaitHandle>(notifyWhenNoCallbacksRunning)) {
        InvalidOperationException ex = rt::newobj<InvalidOperationException>(SR::get_InvalidOperation_TimerAlreadyClosed());
        ex->SetCurrentStackTrace();
        return ValueTask<>::FromException(ex);
      }
    } else {
      _canceled = true;
      _associatedTimerQueue->DeleteTimer((TimerQueueTimer)this);
    }
    if (_callbacksRunning == 0) {
      return rt::default__;
    }
    if (notifyWhenNoCallbacksRunning == nullptr) {
      return ValueTask<>((Task<>)(_notifyWhenNoCallbacksRunning = rt::newobj<Task<Boolean>>((Object)nullptr, TaskCreationOptions::RunContinuationsAsynchronously)));
    }
    return ValueTask<>((Task<Boolean>)notifyWhenNoCallbacksRunning);
  }
}

void TimerQueueTimer___::ExecuteOfIThreadPoolWorkItem() {
  Fire(true);
}

void TimerQueueTimer___::Fire(Boolean isThreadPool) {
  Boolean flag = false;
  {
    rt::lock(_associatedTimerQueue);
    flag = _canceled;
    if (!flag) {
      _callbacksRunning++;
    }
  }
  if (flag) {
    return;
  }
  CallCallback(isThreadPool);
  Boolean flag2 = false;
  {
    rt::lock(_associatedTimerQueue);
    _callbacksRunning--;
    if (_canceled && _callbacksRunning == 0 && _notifyWhenNoCallbacksRunning != nullptr) {
      flag2 = true;
    }
  }
  if (flag2) {
    SignalNoCallbacksRunning();
  }
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
  s_callCallbackInContext = {__c::in::__9, &__c::in::_cctor_b__23_0};
}

} // namespace System::Private::CoreLib::System::Threading::TimerQueueTimerNamespace
