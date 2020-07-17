#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventActivityOptions;
enum class EventChannel : uint8_t;
enum class EventKeywords : int64_t;
enum class EventLevel;
enum class EventOpcode;
enum class EventTags;
enum class EventTask;
namespace EventAttributeNamespace {
CLASS(EventAttribute) {
  public: Int32 get_EventId() { return EventId; }
  private: void set_EventId(Int32 value) { EventId = value; }
  public: EventLevel get_Level() { return Level; }
  public: void set_Level(EventLevel value) { Level = value; }
  public: EventKeywords get_Keywords() { return Keywords; }
  public: void set_Keywords(EventKeywords value) { Keywords = value; }
  public: EventOpcode get_Opcode();
  public: void set_Opcode(EventOpcode value);
  public: Boolean get_IsOpcodeSet();
  public: EventTask get_Task() { return Task; }
  public: void set_Task(EventTask value) { Task = value; }
  public: EventChannel get_Channel() { return Channel; }
  public: void set_Channel(EventChannel value) { Channel = value; }
  public: Byte get_Version() { return Version; }
  public: void set_Version(Byte value) { Version = value; }
  public: String get_Message() { return Message; }
  public: void set_Message(String value) { Message = value; }
  public: EventTags get_Tags() { return Tags; }
  public: void set_Tags(EventTags value) { Tags = value; }
  public: EventActivityOptions get_ActivityOptions() { return ActivityOptions; }
  public: void set_ActivityOptions(EventActivityOptions value) { ActivityOptions = value; }
  public: void Ctor(Int32 eventId);
  private: Int32 EventId;
  private: EventLevel Level;
  private: EventKeywords Keywords;
  private: EventTask Task;
  private: EventChannel Channel;
  private: Byte Version;
  private: String Message;
  private: EventTags Tags;
  private: EventActivityOptions ActivityOptions;
  private: EventOpcode m_opcode;
  private: Boolean m_opcodeSet;
};
} // namespace EventAttributeNamespace
using EventAttribute = EventAttributeNamespace::EventAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
