#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
enum class EventKeywords : int64_t;
enum class EventOpcode;
enum class EventTask;
enum class EventTags;
enum class EventChannel : uint8_t;
enum class EventLevel;
namespace EventWrittenEventArgsNamespace {
using namespace ::System::Private::CoreLib::System::Collections::ObjectModel;
CLASS(EventWrittenEventArgs) {
  public: String get_EventName();
  public: void set_EventName(String value);
  public: Guid get_ActivityId();
  public: void set_ActivityId(Guid value);
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
