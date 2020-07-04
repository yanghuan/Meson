#include "EventSourceOptions-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceOptionsNamespace {
EventLevel EventSourceOptions::get_Level() {
  return EventLevel::Verbose;
};
void EventSourceOptions::set_Level(EventLevel value) {
};
EventOpcode EventSourceOptions::get_Opcode() {
  return EventOpcode::Receive;
};
void EventSourceOptions::set_Opcode(EventOpcode value) {
};
Boolean EventSourceOptions::get_IsOpcodeSet() {
  return Boolean();
};
EventKeywords EventSourceOptions::get_Keywords() {
  return EventKeywords::EventLogClassic;
};
void EventSourceOptions::set_Keywords(EventKeywords value) {
};
EventTags EventSourceOptions::get_Tags() {
  return EventTags::None;
};
void EventSourceOptions::set_Tags(EventTags value) {
};
EventActivityOptions EventSourceOptions::get_ActivityOptions() {
  return EventActivityOptions::Detachable;
};
void EventSourceOptions::set_ActivityOptions(EventActivityOptions value) {
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceOptionsNamespace
