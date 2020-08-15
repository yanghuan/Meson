#include "EventDataAttribute-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventDataAttributeNamespace {
EventLevel EventDataAttribute___::get_Level() {
  return level;
}

EventOpcode EventDataAttribute___::get_Opcode() {
  return opcode;
}

void EventDataAttribute___::ctor() {
  level = (EventLevel)(-1);
  opcode = (EventOpcode)(-1);
  Attribute::in::ctor();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventDataAttributeNamespace
