#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
enum class EventLevel : int32_t;
enum class EventOpcode : int32_t;
enum class EventTags : int32_t;
namespace EventDataAttributeNamespace {
CLASS(EventDataAttribute) : public Attribute::in {
  public: String get_Name() { return Name; }
  public: void set_Name(String value) { Name = value; }
  public: EventLevel get_Level();
  public: EventOpcode get_Opcode();
  public: EventKeywords get_Keywords() { return Keywords; }
  public: EventTags get_Tags() { return Tags; }
  public: void ctor();
  private: EventLevel level;
  private: EventOpcode opcode;
  private: String Name;
  private: EventKeywords Keywords;
  private: EventTags Tags;
};
} // namespace EventDataAttributeNamespace
using EventDataAttribute = EventDataAttributeNamespace::EventDataAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
