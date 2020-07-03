#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventLevel;
enum class EventOpcode;
enum class EventKeywords : int64_t;
enum class EventTags;
namespace EventDataAttributeNamespace {
CLASS(EventDataAttribute) {
  public: EventLevel get_Level();
  public: EventOpcode get_Opcode();
  private: EventLevel level;
  private: EventOpcode opcode;
  private: String Name;
  private: EventKeywords Keywords;
  private: EventTags Tags;
};
} // namespace EventDataAttributeNamespace
using EventDataAttribute = EventDataAttributeNamespace::EventDataAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
