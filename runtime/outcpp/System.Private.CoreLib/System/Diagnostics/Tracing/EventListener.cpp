#include "EventListener-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventListenerNamespace {
Object EventListener___::get_EventListenersLock() {
  return nullptr;
};

void EventListener___::Dispose() {
};

void EventListener___::EnableEvents(EventSource eventSource, EventLevel level) {
};

void EventListener___::EnableEvents(EventSource eventSource, EventLevel level, EventKeywords matchAnyKeyword) {
};

void EventListener___::EnableEvents(EventSource eventSource, EventLevel level, EventKeywords matchAnyKeyword, IDictionary<String, String> arguments) {
};

void EventListener___::DisableEvents(EventSource eventSource) {
};

Int32 EventListener___::EventSourceIndex(EventSource eventSource) {
  return Int32();
};

void EventListener___::OnEventSourceCreated(EventSource eventSource) {
};

void EventListener___::OnEventWritten(EventWrittenEventArgs eventData) {
};

void EventListener___::AddEventSource(EventSource newEventSource) {
};

void EventListener___::DisposeOnShutdown(Object sender, EventArgs e) {
};

void EventListener___::RemoveReferencesToListenerInEventSources(EventListener listenerToRemove) {
};

void EventListener___::CallBackForExistingEventSources(Boolean addToListenersList, EventHandler<EventSourceCreatedEventArgs> callback) {
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventListenerNamespace
