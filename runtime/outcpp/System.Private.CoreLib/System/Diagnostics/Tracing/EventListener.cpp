#include "EventListener-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventListener-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProviderType.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceCreatedEventArgs-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NativeRuntimeEventSource-dep.h>
#include <System.Private.CoreLib/System/EventHandler-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/WeakReference-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventListenerNamespace {
using namespace System::Collections::Generic;
using namespace System::Threading;

Object EventListener___::get_EventListenersLock() {
  if (s_EventSources == nullptr) {
    Interlocked::CompareExchange(s_EventSources, rt::newobj<List<WeakReference<EventSource>>>(2), nullptr);
  }
  return s_EventSources;
}

void EventListener___::cctor() {
  GC::KeepAlive(NativeRuntimeEventSource::in::Log);
}

void EventListener___::ctor() {
}

void EventListener___::Dispose() {
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
}

void EventListener___::DisableEvents(EventSource eventSource) {
  if (eventSource == nullptr) {
    rt::throw_exception<ArgumentNullException>("eventSource");
  }
  eventSource->SendCommand((EventListener)this, EventProviderType::None, 0, 0, EventCommand::Update, false, EventLevel::LogAlways, EventKeywords::None, nullptr);
}

Int32 EventListener___::EventSourceIndex(EventSource eventSource) {
  return eventSource->m_id;
}

void EventListener___::OnEventSourceCreated(EventSource eventSource) {
  EventHandler<EventSourceCreatedEventArgs> eventSourceCreated = _EventSourceCreated;
  if (eventSourceCreated != nullptr) {
    EventSourceCreatedEventArgs eventSourceCreatedEventArgs = rt::newobj<EventSourceCreatedEventArgs>();
    eventSourceCreatedEventArgs->set_EventSource = eventSource;
    eventSourceCreated((EventListener)this, eventSourceCreatedEventArgs);
  }
}

void EventListener___::OnEventWritten(EventWrittenEventArgs eventData) {
}

void EventListener___::AddEventSource(EventSource newEventSource) {
}

void EventListener___::DisposeOnShutdown(Object sender, EventArgs e) {
}

void EventListener___::RemoveReferencesToListenerInEventSources(EventListener listenerToRemove) {
}

void EventListener___::CallBackForExistingEventSources(Boolean addToListenersList, EventHandler<EventSourceCreatedEventArgs> callback) {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventListenerNamespace
