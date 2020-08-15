#include "EventPipeEventDispatcher-dep.h"

#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeWaitHandle-dep.h>
#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventListener-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeEventDispatcher-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeEventInstanceData-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeInternal-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeWaitHandle-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NativeRuntimeEventSource-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/EventWaitHandle-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeEventDispatcherNamespace {
using namespace Microsoft::Win32::SafeHandles;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::Threading::Tasks;

void EventPipeEventDispatcher___::EventListenerSubscription___::ctor(EventKeywords matchAnyKeywords, EventLevel level) {
  MatchAnyKeywords = matchAnyKeywords;
  Level = level;
}

void EventPipeEventDispatcher___::ctor() {
  m_dispatchTaskWaitHandle = rt::newobj<EventPipeWaitHandle>();
  m_dispatchControlLock = rt::newobj<Object>();
  m_subscriptions = rt::newobj<Dictionary<EventListener, EventListenerSubscription>>();
  Object::in::ctor();
  m_RuntimeProviderID = EventPipeInternal::GetProvider("Microsoft-Windows-DotNETRuntime");
  m_dispatchTaskWaitHandle->set_SafeWaitHandle = rt::newobj<SafeWaitHandle>(IntPtr::Zero, false);
}

void EventPipeEventDispatcher___::SendCommand(EventListener eventListener, EventCommand command, Boolean enable, EventLevel level, EventKeywords matchAnyKeywords) {
  if (command == EventCommand::Update && enable) {
    {
      rt::lock(m_dispatchControlLock);
      m_subscriptions[eventListener] = rt::newobj<EventListenerSubscription>(matchAnyKeywords, level);
      CommitDispatchConfiguration();
    }
  } else if (command == EventCommand::Update && !enable) {
    RemoveEventListener(eventListener);
  }

}

void EventPipeEventDispatcher___::RemoveEventListener(EventListener listener) {
  {
    rt::lock(m_dispatchControlLock);
    if (m_subscriptions->ContainsKey(listener)) {
      m_subscriptions->Remove(listener);
    }
    CommitDispatchConfiguration();
  }
}

void EventPipeEventDispatcher___::CommitDispatchConfiguration() {
  StopDispatchTask();
  EventPipeInternal::Disable(m_sessionID);
  if (m_subscriptions->get_Count() <= 0) {
    return;
  }
  EventKeywords eventKeywords = EventKeywords::None;
  EventLevel eventLevel = EventLevel::LogAlways;
}

void EventPipeEventDispatcher___::StartDispatchTask() {
  if (m_dispatchTask == nullptr) {
    m_stopDispatchTask = false;
    m_dispatchTaskWaitHandle->set_SafeWaitHandle = rt::newobj<SafeWaitHandle>(EventPipeInternal::GetWaitHandle(m_sessionID), false);
    m_dispatchTask = Task::in::get_Factory()->StartNew(rt::newobj<Action>(&DispatchEventsToEventListeners), CancellationToken::get_None(), TaskCreationOptions::LongRunning, TaskScheduler::in::get_Default());
  }
}

void EventPipeEventDispatcher___::StopDispatchTask() {
  if (m_dispatchTask != nullptr) {
    m_stopDispatchTask = true;
    EventWaitHandle::in::Set(m_dispatchTaskWaitHandle->get_SafeWaitHandle());
    m_dispatchTask->Wait();
    m_dispatchTask = nullptr;
  }
}

void EventPipeEventDispatcher___::DispatchEventsToEventListeners() {
  while (!m_stopDispatchTask) {
    Boolean flag = false;
    EventPipeEventInstanceData eventPipeEventInstanceData;
    while (!m_stopDispatchTask && EventPipeInternal::GetNextEvent(m_sessionID, &eventPipeEventInstanceData)) {
      flag = true;
      if (eventPipeEventInstanceData.ProviderID == m_RuntimeProviderID) {
        ReadOnlySpan<Byte> payload = ReadOnlySpan<Byte>((void*)eventPipeEventInstanceData.Payload, (Int32)eventPipeEventInstanceData.PayloadLength);
        DateTime timeStamp = TimeStampToDateTime(eventPipeEventInstanceData.TimeStamp);
        NativeRuntimeEventSource::in::Log->ProcessEvent(eventPipeEventInstanceData.EventID, eventPipeEventInstanceData.ThreadID, timeStamp, eventPipeEventInstanceData.ActivityId, eventPipeEventInstanceData.ChildActivityId, payload);
      }
    }
    if (!m_stopDispatchTask) {
      if (!flag) {
        m_dispatchTaskWaitHandle->WaitOne();
      }
      Thread::in::Sleep(10);
    }
  }
}

DateTime EventPipeEventDispatcher___::TimeStampToDateTime(Int64 timeStamp) {
  if (timeStamp == Int64::MaxValue) {
    return DateTime::MaxValue;
  }
  Int64 num = (Int64)((Double)(timeStamp - m_syncTimeQPC) * 10000000 / (Double)m_timeQPCFrequency) + m_syncTimeUtc.get_Ticks();
  if (num < 0 || 3155378975999999999 < num) {
    num = 3155378975999999999;
  }
  return DateTime(num, DateTimeKind::Utc);
}

void EventPipeEventDispatcher___::cctor() {
  Instance = rt::newobj<EventPipeEventDispatcher>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeEventDispatcherNamespace
