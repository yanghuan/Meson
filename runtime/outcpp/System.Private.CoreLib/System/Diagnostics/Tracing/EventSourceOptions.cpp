#include "EventSourceOptions-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceOptionsNamespace {
EventLevel EventSourceOptions::get_Level() {
  return (EventLevel)level;
}

void EventSourceOptions::set_Level(EventLevel value) {
  level = (Byte)value;
  valuesSet |= 4;
}

EventOpcode EventSourceOptions::get_Opcode() {
  return (EventOpcode)opcode;
}

void EventSourceOptions::set_Opcode(EventOpcode value) {
  opcode = (Byte)value;
  valuesSet |= 8;
}

Boolean EventSourceOptions::get_IsOpcodeSet() {
}

EventKeywords EventSourceOptions::get_Keywords() {
  return keywords;
}

void EventSourceOptions::set_Keywords(EventKeywords value) {
  keywords = value;
  valuesSet |= 1;
}

EventTags EventSourceOptions::get_Tags() {
  return tags;
}

void EventSourceOptions::set_Tags(EventTags value) {
  tags = value;
  valuesSet |= 2;
}

EventActivityOptions EventSourceOptions::get_ActivityOptions() {
  return activityOptions;
}

void EventSourceOptions::set_ActivityOptions(EventActivityOptions value) {
  activityOptions = value;
  valuesSet |= 16;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceOptionsNamespace
