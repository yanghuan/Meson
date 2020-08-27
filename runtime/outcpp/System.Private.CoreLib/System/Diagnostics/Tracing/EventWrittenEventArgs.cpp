#include "EventWrittenEventArgs-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventWrittenEventArgsNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Threading;

String EventWrittenEventArgs___::get_EventName() {
  if (m_eventName != nullptr || EventId < 0) {
    return m_eventName;
  }
  return m_eventSource->m_eventData[EventId].Name;
}

void EventWrittenEventArgs___::set_EventName(String value) {
  m_eventName = value;
}

Guid EventWrittenEventArgs___::get_ActivityId() {
  Guid guid = m_activityId;
  if (guid == Guid::Empty) {
    guid = EventSource::in::get_CurrentThreadActivityId();
  }
  return guid;
}

void EventWrittenEventArgs___::set_ActivityId(Guid value) {
  m_activityId = value;
}

ReadOnlyCollection<String> EventWrittenEventArgs___::get_PayloadNames() {
  if (EventId >= 0 && m_payloadNames == nullptr) {
    List<String> list = rt::newobj<List<String>>();
    Array<ParameterInfo> parameters = m_eventSource->m_eventData[EventId].Parameters;
    for (ParameterInfo& parameterInfo : parameters) {
      list->Add(parameterInfo->get_Name());
    }
    m_payloadNames = rt::newobj<ReadOnlyCollection<String>>(list);
  }
  return m_payloadNames;
}

void EventWrittenEventArgs___::set_PayloadNames(ReadOnlyCollection<String> value) {
  m_payloadNames = value;
}

EventSource EventWrittenEventArgs___::get_EventSource() {
  return m_eventSource;
}

EventKeywords EventWrittenEventArgs___::get_Keywords() {
  if (EventId <= 0) {
    return m_keywords;
  }
  return (EventKeywords)m_eventSource->m_eventData[EventId].Descriptor.get_Keywords();
}

EventOpcode EventWrittenEventArgs___::get_Opcode() {
  if (EventId <= 0) {
    return m_opcode;
  }
  return (EventOpcode)m_eventSource->m_eventData[EventId].Descriptor.get_Opcode();
}

EventTask EventWrittenEventArgs___::get_Task() {
  if (EventId <= 0) {
    return EventTask::None;
  }
  return (EventTask)m_eventSource->m_eventData[EventId].Descriptor.get_Task();
}

EventTags EventWrittenEventArgs___::get_Tags() {
  if (EventId <= 0) {
    return m_tags;
  }
  return m_eventSource->m_eventData[EventId].Tags;
}

String EventWrittenEventArgs___::get_Message() {
  if (EventId <= 0) {
    return m_message;
  }
  return m_eventSource->m_eventData[EventId].Message;
}

void EventWrittenEventArgs___::set_Message(String value) {
  m_message = value;
}

EventChannel EventWrittenEventArgs___::get_Channel() {
  if (EventId <= 0) {
    return EventChannel::None;
  }
  return (EventChannel)m_eventSource->m_eventData[EventId].Descriptor.get_Channel();
}

Byte EventWrittenEventArgs___::get_Version() {
  if (EventId <= 0) {
    return 0;
  }
  return m_eventSource->m_eventData[EventId].Descriptor.get_Version();
}

EventLevel EventWrittenEventArgs___::get_Level() {
  if (EventId <= 0) {
    return m_level;
  }
  return (EventLevel)m_eventSource->m_eventData[EventId].Descriptor.get_Level();
}

Int64 EventWrittenEventArgs___::get_OSThreadId() {
  if (!m_osThreadId.get_HasValue()) {
    m_osThreadId = (Int64)Thread::in::get_CurrentOSThreadId();
  }
  return m_osThreadId.get_Value();
}

void EventWrittenEventArgs___::set_OSThreadId(Int64 value) {
  m_osThreadId = value;
}

void EventWrittenEventArgs___::ctor(EventSource eventSource) {
  m_eventSource = eventSource;
  TimeStamp = DateTime::get_UtcNow();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventWrittenEventArgsNamespace
