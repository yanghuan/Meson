#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
FORWARDS(Int32)
FORWARD(EventArgs)
FORWARDS(Boolean)
FORWARD_(EventHandler, T1, T2)
FORWARD_(WeakReference, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
enum class EventLevel;
enum class EventKeywords : int64_t;
FORWARD(EventWrittenEventArgs)
FORWARD(EventSourceCreatedEventArgs)
namespace EventListenerNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(EventListener) {
  public: static Object get_EventListenersLock();
  public: void Dispose();
  public: void EnableEvents(EventSource eventSource, EventLevel level);
  public: void EnableEvents(EventSource eventSource, EventLevel level, EventKeywords matchAnyKeyword);
  public: void EnableEvents(EventSource eventSource, EventLevel level, EventKeywords matchAnyKeyword, IDictionary<String, String> arguments);
  public: void DisableEvents(EventSource eventSource);
  public: static Int32 EventSourceIndex(EventSource eventSource);
  public: void OnEventSourceCreated(EventSource eventSource);
  public: void OnEventWritten(EventWrittenEventArgs eventData);
  public: static void AddEventSource(EventSource newEventSource);
  private: static void DisposeOnShutdown(Object sender, EventArgs e);
  private: static void RemoveReferencesToListenerInEventSources(EventListener listenerToRemove);
  private: void CallBackForExistingEventSources(Boolean addToListenersList, EventHandler<EventSourceCreatedEventArgs> callback);
  private: EventHandler<EventSourceCreatedEventArgs> _EventSourceCreated;
  private: EventHandler<EventWrittenEventArgs> EventWritten;
  public: EventListener m_Next;
  public: static EventListener s_Listeners;
  public: static List<WeakReference<>> s_EventSources;
  private: static Boolean s_CreatingListener;
  private: static Boolean s_EventSourceShutdownRegistered;
};
} // namespace EventListenerNamespace
using EventListener = EventListenerNamespace::EventListener;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
