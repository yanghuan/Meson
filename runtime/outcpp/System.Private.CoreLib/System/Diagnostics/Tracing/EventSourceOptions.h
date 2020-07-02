#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventLevel;
enum class EventOpcode;
enum class EventKeywords : int64_t;
enum class EventTags;
enum class EventActivityOptions;
namespace EventSourceOptionsNamespace {
struct EventSourceOptions {
  public: EventLevel get_Level();
  public: void set_Level(EventLevel value);
  public: EventOpcode get_Opcode();
  public: void set_Opcode(EventOpcode value);
  public: Boolean get_IsOpcodeSet();
  public: EventKeywords get_Keywords();
  public: void set_Keywords(EventKeywords value);
  public: EventTags get_Tags();
  public: void set_Tags(EventTags value);
  public: EventActivityOptions get_ActivityOptions();
  public: void set_ActivityOptions(EventActivityOptions value);
  public: EventKeywords keywords;
  public: EventTags tags;
  public: EventActivityOptions activityOptions;
  public: Byte level;
  public: Byte opcode;
  public: Byte valuesSet;
};
} // namespace EventSourceOptionsNamespace
using EventSourceOptions = EventSourceOptionsNamespace::EventSourceOptions;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing