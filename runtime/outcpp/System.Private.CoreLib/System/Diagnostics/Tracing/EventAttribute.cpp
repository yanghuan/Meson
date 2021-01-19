#include "EventAttribute-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventAttributeNamespace {
EventOpcode EventAttribute___::get_Opcode() {
  return m_opcode;
}

void EventAttribute___::set_Opcode(EventOpcode value) {
  m_opcode = value;
  m_opcodeSet = true;
}

Boolean EventAttribute___::get_IsOpcodeSet() {
  return m_opcodeSet;
}

void EventAttribute___::ctor(Int32 eventId) {
  EventId = eventId;
  Level = EventLevel::Informational;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventAttributeNamespace
