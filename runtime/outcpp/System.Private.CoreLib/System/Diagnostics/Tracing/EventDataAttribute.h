#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventLevel;
enum class EventOpcode;
namespace EventDataAttributeNamespace {
CLASS(EventDataAttribute) {
  public: EventLevel get_Level();
  public: EventOpcode get_Opcode();
  private: EventLevel level;
  private: EventOpcode opcode;
};
} // namespace EventDataAttributeNamespace
using EventDataAttribute = EventDataAttributeNamespace::EventDataAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
