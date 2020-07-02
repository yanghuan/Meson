#include "EventListener-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventListenerNamespace {
Object EventListener___::get_EventListenersLock() {
  return nullptr;
};
void EventListener___::Dispose() {
  return void();
};
void EventListener___::EnableEvents(EventSource eventSource, EventLevel level) {
  return void();
};
void EventListener___::EnableEvents(EventSource eventSource, EventLevel level, EventKeywords matchAnyKeyword) {
  return void();
};
void EventListener___::EnableEvents(EventSource eventSource, EventLevel level, EventKeywords matchAnyKeyword, IDictionary<String, String> arguments) {
  return void();
};
void EventListener___::DisableEvents(EventSource eventSource) {
  return void();
};
Int32 EventListener___::EventSourceIndex(EventSource eventSource) {
  return Int32();
};
void EventListener___::OnEventSourceCreated(EventSource eventSource) {
  return void();
};
void EventListener___::OnEventWritten(EventWrittenEventArgs eventData) {
  return void();
};
void EventListener___::AddEventSource(EventSource newEventSource) {
  return void();
};
void EventListener___::DisposeOnShutdown(Object sender, EventArgs e) {
  return void();
};
void EventListener___::RemoveReferencesToListenerInEventSources(EventListener listenerToRemove) {
  return void();
};
void EventListener___::CallBackForExistingEventSources(Boolean addToListenersList, EventHandler<EventSourceCreatedEventArgs> callback) {
  return void();
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventListenerNamespace
