#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventCommand;
FORWARD(EventSource)
FORWARD(EventDispatcher)
enum class EventProviderType;
FORWARD(EventListener)
enum class EventLevel;
enum class EventKeywords : int64_t;
namespace EventCommandEventArgsNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(EventCommandEventArgs) {
  public: EventCommand get_Command() { return Command; }
  public: void set_Command(EventCommand value) { Command = value; }
  public: IDictionary<String, String> get_Arguments() { return Arguments; }
  public: void set_Arguments(IDictionary<String, String> value) { Arguments = value; }
  public: Boolean EnableEvent(Int32 eventId);
  public: Boolean DisableEvent(Int32 eventId);
  private: EventCommand Command;
  private: IDictionary<String, String> Arguments;
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
