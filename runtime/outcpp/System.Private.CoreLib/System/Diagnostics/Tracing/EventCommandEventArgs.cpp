#include "EventCommandEventArgs-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommandEventArgs-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventCommandEventArgsNamespace {
Boolean EventCommandEventArgs___::EnableEvent(Int32 eventId) {
  if (Command != EventCommand::Enable && Command != EventCommand::Disable) {
    rt::throw_exception<InvalidOperationException>();
  }
  return eventSource->EnableEventForDispatcher(dispatcher, eventProviderType, eventId, true);
}

Boolean EventCommandEventArgs___::DisableEvent(Int32 eventId) {
  if (Command != EventCommand::Enable && Command != EventCommand::Disable) {
    rt::throw_exception<InvalidOperationException>();
  }
  return eventSource->EnableEventForDispatcher(dispatcher, eventProviderType, eventId, false);
}

void EventCommandEventArgs___::ctor(EventCommand command, IDictionary<String, String> arguments, EventSource eventSource, EventListener listener, EventProviderType eventProviderType, Int32 perEventSourceSessionId, Int32 etwSessionId, Boolean enable, EventLevel level, EventKeywords matchAnyKeyword) {
  Command = command;
  Arguments = arguments;
  this->eventSource = eventSource;
  this->listener = listener;
  this->eventProviderType = eventProviderType;
  this->perEventSourceSessionId = perEventSourceSessionId;
  this->etwSessionId = etwSessionId;
  this->enable = enable;
  this->level = level;
  this->matchAnyKeyword = matchAnyKeyword;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventCommandEventArgsNamespace
