#include "EventListener-dep.h"

#include <System.Private.CoreLib/System/AppContext-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventDispatcher-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventListener-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeEventDispatcher-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProviderType.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceCreatedEventArgs-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NativeRuntimeEventSource-dep.h>
#include <System.Private.CoreLib/System/EventHandler-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/WeakReference-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventListenerNamespace {
using namespace System::Collections::Generic;
using namespace System::Threading;

Object EventListener___::get_EventListenersLock() {
  if (s_EventSources == nullptr) {
    Interlocked::CompareExchange(s_EventSources, rt::newobj<List<WeakReference<EventSource>>>(2), (List<WeakReference<EventSource>>)nullptr);
  }
  return s_EventSources;
}

void EventListener___::cctor() {
  GC::KeepAlive(NativeRuntimeEventSource::in::Log);
}

void EventListener___::ctor() {
}

void EventListener___::Dispose() {
  {
    rt::lock(get_EventListenersLock());
    if (s_Listeners == nullptr) {
      return;
    }
    if ((EventListener)this == s_Listeners) {
      EventListener listenerToRemove = s_Listeners;
      s_Listeners = m_Next;
      RemoveReferencesToListenerInEventSources(listenerToRemove);
      return;
    }
    EventListener eventListener = s_Listeners;
    EventListener next;
    while (true) {
      next = eventListener->m_Next;
      if (next == nullptr) {
        return;
      }
      if (next == (EventListener)this) {
        break;
      }
      eventListener = next;
    }
    eventListener->m_Next = next->m_Next;
    RemoveReferencesToListenerInEventSources(next);
  }
}

void EventListener___::EnableEvents(EventSource eventSource, EventLevel level) {
  EnableEvents(eventSource, level, EventKeywords::None);
}

void EventListener___::EnableEvents(EventSource eventSource, EventLevel level, EventKeywords matchAnyKeyword) {
  EnableEvents(eventSource, level, matchAnyKeyword, nullptr);
}

void EventListener___::EnableEvents(EventSource eventSource, EventLevel level, EventKeywords matchAnyKeyword, IDictionary<String, String> arguments) {
  if (eventSource == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSource");
  }
  eventSource->SendCommand((EventListener)this, EventProviderType::None, 0, 0, EventCommand::Update, true, level, matchAnyKeyword, arguments);
  if (eventSource->GetType() == typeof<NativeRuntimeEventSource>()) {
    EventPipeEventDispatcher::in::Instance->SendCommand((EventListener)this, EventCommand::Update, true, level, matchAnyKeyword);
  }
}

void EventListener___::DisableEvents(EventSource eventSource) {
  if (eventSource == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSource");
  }
  eventSource->SendCommand((EventListener)this, EventProviderType::None, 0, 0, EventCommand::Update, false, EventLevel::LogAlways, EventKeywords::None, nullptr);
  if (eventSource->GetType() == typeof<NativeRuntimeEventSource>()) {
    EventPipeEventDispatcher::in::Instance->SendCommand((EventListener)this, EventCommand::Update, false, EventLevel::LogAlways, EventKeywords::None);
  }
}

Int32 EventListener___::EventSourceIndex(EventSource eventSource) {
  return eventSource->m_id;
}

void EventListener___::OnEventSourceCreated(EventSource eventSource) {
  EventHandler<EventSourceCreatedEventArgs> eventSourceCreated = _EventSourceCreated;
  if (eventSourceCreated != nullptr) {
    EventSourceCreatedEventArgs eventSourceCreatedEventArgs = rt::newobj<EventSourceCreatedEventArgs>();
    eventSourceCreatedEventArgs->set_EventSource(eventSource);
    eventSourceCreated((EventListener)this, eventSourceCreatedEventArgs);
  }
}

void EventListener___::OnEventWritten(EventWrittenEventArgs eventData) {
}

void EventListener___::AddEventSource(EventSource newEventSource) {
  {
    rt::lock(get_EventListenersLock());
    if (s_EventSources == nullptr) {
      s_EventSources = rt::newobj<List<WeakReference<EventSource>>>(2);
    }
    if (!s_EventSourceShutdownRegistered) {
      s_EventSourceShutdownRegistered = true;
    }
    Int32 num = -1;
    if (s_EventSources->get_Count() % 64 == 63) {
      Int32 num2 = s_EventSources->get_Count();
      while (0 < num2) {
        num2--;
        WeakReference<EventSource> weakReference = s_EventSources[num2];
        EventSource target;
        if (!weakReference->TryGetTarget(target)) {
          num = num2;
          weakReference->SetTarget(newEventSource);
          break;
        }
      }
    }
    if (num < 0) {
      num = s_EventSources->get_Count();
      s_EventSources->Add(rt::newobj<WeakReference<EventSource>>(newEventSource));
    }
    newEventSource->m_id = num;
    for (EventListener next = s_Listeners; next != nullptr; next = next->m_Next) {
      newEventSource->AddListener(next);
    }
  }
}

void EventListener___::DisposeOnShutdown(Object sender, EventArgs e) {
  {
    rt::lock(get_EventListenersLock());
    for (WeakReference<EventSource>& s_EventSource : s_EventSources) {
      EventSource target;
      if (s_EventSource->TryGetTarget(target)) {
        target->Dispose();
      }
    }
  }
}

void EventListener___::RemoveReferencesToListenerInEventSources(EventListener listenerToRemove) {
  for (WeakReference<EventSource>& s_EventSource : s_EventSources) {
    EventSource target;
    if (!s_EventSource->TryGetTarget(target)) {
      continue;
    }
    if (target->m_Dispatchers->m_Listener == listenerToRemove) {
      target->m_Dispatchers = target->m_Dispatchers->m_Next;
      continue;
    }
    EventDispatcher eventDispatcher = target->m_Dispatchers;
    while (true) {
      EventDispatcher next = eventDispatcher->m_Next;
      if (next == nullptr) {
        break;
      }
      if (next->m_Listener == listenerToRemove) {
        eventDispatcher->m_Next = next->m_Next;
        break;
      }
      eventDispatcher = next;
    }
  }
  EventPipeEventDispatcher::in::Instance->RemoveEventListener(listenerToRemove);
}

void EventListener___::CallBackForExistingEventSources(Boolean addToListenersList, EventHandler<EventSourceCreatedEventArgs> callback) {
  {
    rt::lock(get_EventListenersLock());
    if (s_CreatingListener) {
      rt::throw_exception<InvalidOperationException>(SR::get_EventSource_ListenerCreatedInsideCallback());
    }
    try {
      s_CreatingListener = true;
      if (addToListenersList) {
        m_Next = s_Listeners;
        s_Listeners = (EventListener)this;
      }
      if (callback == nullptr) {
        return;
      }
      Array<WeakReference<EventSource>> array = s_EventSources->ToArray();
      for (WeakReference<EventSource>& weakReference : array) {
        EventSource target;
        if (weakReference->TryGetTarget(target)) {
          EventSourceCreatedEventArgs eventSourceCreatedEventArgs = rt::newobj<EventSourceCreatedEventArgs>();
          eventSourceCreatedEventArgs->set_EventSource(target);
          callback((EventListener)this, eventSourceCreatedEventArgs);
        }
      }
    } catch (...) {
    } finally: {
      s_CreatingListener = false;
    }
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventListenerNamespace
