#include "EventWrittenEventArgs-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventWrittenEventArgsNamespace {
String EventWrittenEventArgs___::get_EventName() {
  return nullptr;
};

void EventWrittenEventArgs___::set_EventName(String value) {
};

Guid EventWrittenEventArgs___::get_ActivityId() {
  return Guid();
};

void EventWrittenEventArgs___::set_ActivityId(Guid value) {
};

ReadOnlyCollection<String> EventWrittenEventArgs___::get_PayloadNames() {
  return nullptr;
};

void EventWrittenEventArgs___::set_PayloadNames(ReadOnlyCollection<String> value) {
};

EventSource EventWrittenEventArgs___::get_EventSource() {
  return nullptr;
};

EventKeywords EventWrittenEventArgs___::get_Keywords() {
  return EventKeywords::EventLogClassic;
};

EventOpcode EventWrittenEventArgs___::get_Opcode() {
  return EventOpcode::Receive;
};

EventTask EventWrittenEventArgs___::get_Task() {
  return EventTask::None;
};

EventTags EventWrittenEventArgs___::get_Tags() {
  return EventTags::None;
};

String EventWrittenEventArgs___::get_Message() {
  return nullptr;
};

void EventWrittenEventArgs___::set_Message(String value) {
};

EventChannel EventWrittenEventArgs___::get_Channel() {
  return EventChannel::Debug;
};

Byte EventWrittenEventArgs___::get_Version() {
  return Byte();
};

EventLevel EventWrittenEventArgs___::get_Level() {
  return EventLevel::Verbose;
};

Int64 EventWrittenEventArgs___::get_OSThreadId() {
  return Int64();
};

void EventWrittenEventArgs___::set_OSThreadId(Int64 value) {
};

void EventWrittenEventArgs___::Ctor(EventSource eventSource) {
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventWrittenEventArgsNamespace
