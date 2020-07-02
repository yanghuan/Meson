#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
FORWARD(EventDispatcher)
enum class EventProviderType;
FORWARD(EventListener)
enum class EventLevel;
enum class EventKeywords : int64_t;
namespace EventCommandEventArgsNamespace {
CLASS(EventCommandEventArgs) {
  public: Boolean EnableEvent(Int32 eventId);
  public: Boolean DisableEvent(Int32 eventId);
  public: EventSource eventSource;
  public: EventDispatcher dispatcher;
  public: EventProviderType eventProviderType;
  public: EventListener listener;
  public: Int32 perEventSourceSessionId;
  public: Int32 etwSessionId;
  public: Boolean enable;
  public: EventLevel level;
  public: EventKeywords matchAnyKeyword;
  public: EventCommandEventArgs nextCommand;
};
} // namespace EventCommandEventArgsNamespace
using EventCommandEventArgs = EventCommandEventArgsNamespace::EventCommandEventArgs;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
