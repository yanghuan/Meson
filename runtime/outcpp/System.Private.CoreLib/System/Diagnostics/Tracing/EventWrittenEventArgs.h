#pragma once

#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/EventArgs.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventChannel : uint8_t;
enum class EventKeywords : int64_t;
enum class EventLevel;
enum class EventOpcode;
enum class EventTags;
enum class EventTask;
FORWARD(EventSource)
namespace EventWrittenEventArgsNamespace {
using namespace Collections::ObjectModel;
CLASS(EventWrittenEventArgs) : public EventArgs::in {
  public: String get_EventName();
  public: void set_EventName(String value);
  public: Int32 get_EventId() { return EventId; }
  public: void set_EventId(Int32 value) { EventId = value; }
  public: Guid get_ActivityId();
  public: void set_ActivityId(Guid value);
  public: Guid get_RelatedActivityId() { return RelatedActivityId; }
  public: void set_RelatedActivityId(Guid value) { RelatedActivityId = value; }
  public: ReadOnlyCollection<Object> get_Payload() { return Payload; }
  public: void set_Payload(ReadOnlyCollection<Object> value) { Payload = value; }
  public: ReadOnlyCollection<String> get_PayloadNames();
  public: void set_PayloadNames(ReadOnlyCollection<String> value);
  public: EventSource get_EventSource();
  public: EventKeywords get_Keywords();
  public: EventOpcode get_Opcode();
  public: EventTask get_Task();
  public: EventTags get_Tags();
  public: String get_Message();
  public: void set_Message(String value);
  public: EventChannel get_Channel();
  public: Byte get_Version();
  public: EventLevel get_Level();
  public: Int64 get_OSThreadId();
  public: void set_OSThreadId(Int64 value);
  public: DateTime get_TimeStamp() { return TimeStamp; }
  public: void set_TimeStamp(DateTime value) { TimeStamp = value; }
  public: void ctor(EventSource eventSource);
  private: Int32 EventId;
  private: Guid RelatedActivityId;
  private: ReadOnlyCollection<Object> Payload;
  private: DateTime TimeStamp;
  private: String m_message;
  private: String m_eventName;
  private: EventSource m_eventSource;
  private: ReadOnlyCollection<String> m_payloadNames;
  private: Guid m_activityId;
  private: Nullable<Int64> m_osThreadId;
  public: EventTags m_tags;
  public: EventOpcode m_opcode;
  public: EventLevel m_level;
  public: EventKeywords m_keywords;
};
} // namespace EventWrittenEventArgsNamespace
using EventWrittenEventArgs = EventWrittenEventArgsNamespace::EventWrittenEventArgs;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
