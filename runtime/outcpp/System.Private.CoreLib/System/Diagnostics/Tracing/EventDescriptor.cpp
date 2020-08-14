#include "EventDescriptor-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventDescriptor-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventDescriptorNamespace {
Int32 EventDescriptor::get_EventId() {
  return m_id;
}

Byte EventDescriptor::get_Version() {
  return m_version;
}

Byte EventDescriptor::get_Channel() {
  return m_channel;
}

Byte EventDescriptor::get_Level() {
  return m_level;
}

Byte EventDescriptor::get_Opcode() {
  return m_opcode;
}

Int32 EventDescriptor::get_Task() {
  return m_task;
}

Int64 EventDescriptor::get_Keywords() {
  return m_keywords;
}

EventDescriptor::EventDescriptor(Int32 traceloggingId, Byte level, Byte opcode, Int64 keywords) {
  m_id = 0;
  m_version = 0;
  m_channel = 0;
  m_traceloggingId = traceloggingId;
  m_level = level;
  m_opcode = opcode;
  m_task = 0;
  m_keywords = keywords;
}

EventDescriptor::EventDescriptor(Int32 id, Byte version, Byte channel, Byte level, Byte opcode, Int32 task, Int64 keywords) {
  if (id < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("id", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (id > 65535) {
    rt::throw_exception<ArgumentOutOfRangeException>("id", SR::Format(SR::get_ArgumentOutOfRange_NeedValidId(), 1, UInt16::MaxValue));
  }
  m_traceloggingId = 0;
  m_id = (UInt16)id;
  m_version = version;
  m_channel = channel;
  m_level = level;
  m_opcode = opcode;
  m_keywords = keywords;
  if (task < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("task", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (task > 65535) {
    rt::throw_exception<ArgumentOutOfRangeException>("task", SR::Format(SR::get_ArgumentOutOfRange_NeedValidId(), 1, UInt16::MaxValue));
  }
  m_task = (UInt16)task;
}

Boolean EventDescriptor::Equals(Object obj) {
  if (rt::is<EventDescriptor>(obj)) {
    EventDescriptor other = (EventDescriptor)obj;
    return Equals(other);
  }
  return false;
}

Int32 EventDescriptor::GetHashCode() {
  return m_id ^ m_version ^ m_channel ^ m_level ^ m_opcode ^ m_task ^ (Int32)m_keywords;
}

Boolean EventDescriptor::Equals(EventDescriptor other) {
  if (m_id == other.m_id && m_version == other.m_version && m_channel == other.m_channel && m_level == other.m_level && m_opcode == other.m_opcode && m_task == other.m_task) {
    return m_keywords == other.m_keywords;
  }
  return false;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventDescriptorNamespace
