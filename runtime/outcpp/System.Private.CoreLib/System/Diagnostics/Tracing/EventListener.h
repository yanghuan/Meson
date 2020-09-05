#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(EventArgs)
FORWARD_(EventHandler, T1, T2)
FORWARD(IDisposable)
FORWARDS(Int32)
FORWARD(String)
FORWARD_(WeakReference, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
enum class EventLevel : int32_t;
FORWARD(EventSource)
FORWARD(EventSourceCreatedEventArgs)
FORWARD(EventWrittenEventArgs)
namespace EventListenerNamespace {
using namespace System::Collections::Generic;
CLASS(EventListener) : public object {
  public: using interface = rt::TypeList<IDisposable>;
  public: static Object get_EventListenersLock();
  public: static void cctor();
  public: void ctor();
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
  public: static List<WeakReference<EventSource>> s_EventSources;
  private: static Boolean s_CreatingListener;
  private: static Boolean s_EventSourceShutdownRegistered;
};
} // namespace EventListenerNamespace
using EventListener = EventListenerNamespace::EventListener;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
