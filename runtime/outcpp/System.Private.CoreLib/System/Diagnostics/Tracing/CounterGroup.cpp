#include "CounterGroup-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/CounterGroup-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DiagnosticCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventListener-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/AutoResetEvent-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadStart-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>
#include <System.Private.CoreLib/System/WeakReference-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::CounterGroupNamespace {
using namespace System::Collections::Generic;
using namespace System::Threading;

void CounterGroup___::ctor(EventSource eventSource) {
  _eventSource = eventSource;
  _counters = rt::newobj<List<DiagnosticCounter>>();
  RegisterCommandCallback();
}

void CounterGroup___::Add(DiagnosticCounter eventCounter) {
  {
    rt::lock(s_counterGroupLock);
    _counters->Add(eventCounter);
  }
}

void CounterGroup___::Remove(DiagnosticCounter eventCounter) {
  {
    rt::lock(s_counterGroupLock);
    _counters->Remove(eventCounter);
  }
}

void CounterGroup___::RegisterCommandCallback() {
}

void CounterGroup___::OnEventSourceCommand(Object sender, EventCommandEventArgs e) {
  if (e->get_Command() == EventCommand::Enable || e->get_Command() == EventCommand::Update) {
    String value;
    Single result;
    if (e->get_Arguments()->TryGetValue("EventCounterIntervalSec", value) && Single::TryParse(value, result)) {
      {
        rt::lock(s_counterGroupLock);
        EnableTimer(result);
      }
    }
  } else if (e->get_Command() == EventCommand::Disable) {
    {
      rt::lock(s_counterGroupLock);
      DisableTimer();
    }
  }

}

void CounterGroup___::EnsureEventSourceIndexAvailable(Int32 eventSourceIndex) {
  if (s_counterGroups == nullptr) {
    s_counterGroups = rt::newarr<Array<WeakReference<CounterGroup>>>(eventSourceIndex + 1);
  } else if (eventSourceIndex >= s_counterGroups->get_Length()) {
    Array<WeakReference<CounterGroup>> destinationArray = rt::newarr<Array<WeakReference<CounterGroup>>>(eventSourceIndex + 1);
    Array<>::in::Copy(s_counterGroups, destinationArray, s_counterGroups->get_Length());
    s_counterGroups = destinationArray;
  }

}

CounterGroup CounterGroup___::GetCounterGroup(EventSource eventSource) {
  {
    rt::lock(s_counterGroupLock);
    Int32 num = EventListener::in::EventSourceIndex(eventSource);
    EnsureEventSourceIndexAvailable(num);
    WeakReference<CounterGroup> weakReference = s_counterGroups[num];
    CounterGroup target;
    if (weakReference == nullptr || !weakReference->TryGetTarget(target)) {
      target = rt::newobj<CounterGroup>(eventSource);
      s_counterGroups[num] = rt::newobj<WeakReference<CounterGroup>>(target);
    }
    return target;
  }
}

void CounterGroup___::EnableTimer(Single pollingIntervalInSeconds) {
  if (pollingIntervalInSeconds <= 0) {
    _pollingIntervalInMilliseconds = 0;
  } else {
    if (_pollingIntervalInMilliseconds != 0 && !(pollingIntervalInSeconds * 1000 < (Single)_pollingIntervalInMilliseconds)) {
      return;
    }
    _pollingIntervalInMilliseconds = (Int32)(pollingIntervalInSeconds * 1000);
    ResetCounters();
    _timeStampSinceCollectionStarted = DateTime::get_UtcNow();
    Boolean flag = false;
    try{
      if (!ExecutionContext::in::IsFlowSuppressed()) {
        ExecutionContext::in::SuppressFlow();
        flag = true;
      }
      _nextPollingTimeStamp = DateTime::get_UtcNow() + TimeSpan(0, 0, (Int32)pollingIntervalInSeconds);
      if (s_pollingThread == nullptr) {
        s_pollingThreadSleepEvent = rt::newobj<AutoResetEvent>(false);
        s_counterGroupEnabledList = rt::newobj<List<CounterGroup>>();
        s_pollingThread = rt::newobj<Thread>(rt::newobj<ThreadStart>(&PollForValues));
        s_pollingThread->Start();
      }
      if (!s_counterGroupEnabledList->Contains((CounterGroup)this)) {
        s_counterGroupEnabledList->Add((CounterGroup)this);
      }
      s_pollingThreadSleepEvent->Set();
    } catch (...) {
    } finally: {
      if (flag) {
        ExecutionContext::in::RestoreFlow();
      }
    }
  }
}

void CounterGroup___::DisableTimer() {
  _pollingIntervalInMilliseconds = 0;
  auto& default = s_counterGroupEnabledList;
  default == nullptr ? nullptr : default->Remove((CounterGroup)this);
}

void CounterGroup___::ResetCounters() {
  {
    rt::lock(s_counterGroupLock);
  }
}

void CounterGroup___::OnTimer() {
  if (!_eventSource->IsEnabled()) {
    return;
  }
  DateTime utcNow = DateTime::get_UtcNow();
  TimeSpan timeSpan = utcNow - _timeStampSinceCollectionStarted;
}

void CounterGroup___::PollForValues() {
  AutoResetEvent autoResetEvent = nullptr;
  while (true) {
    Int32 num = Int32::MaxValue;
    {
      rt::lock(s_counterGroupLock);
      autoResetEvent = s_pollingThreadSleepEvent;
    }
    if (num == Int32::MaxValue) {
      num = -1;
    }
    auto& default = autoResetEvent;
    default == nullptr ? nullptr : default->WaitOne(num);
  }
}

void CounterGroup___::cctor() {
  s_counterGroupLock = rt::newobj<Object>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::CounterGroupNamespace
