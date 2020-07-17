#include "EventDescriptor-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventDescriptorNamespace {
Int32 EventDescriptor::get_EventId() {
  return Int32();
};

Byte EventDescriptor::get_Version() {
  return Byte();
};

Byte EventDescriptor::get_Channel() {
  return Byte();
};

Byte EventDescriptor::get_Level() {
  return Byte();
};

Byte EventDescriptor::get_Opcode() {
  return Byte();
};

Int32 EventDescriptor::get_Task() {
  return Int32();
};

Int64 EventDescriptor::get_Keywords() {
  return Int64();
};

void EventDescriptor::Ctor(Int32 traceloggingId, Byte level, Byte opcode, Int64 keywords) {
};

void EventDescriptor::Ctor(Int32 id, Byte version, Byte channel, Byte level, Byte opcode, Int32 task, Int64 keywords) {
};

Boolean EventDescriptor::Equals(Object obj) {
  return Boolean();
};

Int32 EventDescriptor::GetHashCode() {
  return Int32();
};

Boolean EventDescriptor::Equals(EventDescriptor other) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventDescriptorNamespace
