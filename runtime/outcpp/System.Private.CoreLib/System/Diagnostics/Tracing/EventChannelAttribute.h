#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventChannelType;
namespace EventChannelAttributeNamespace {
CLASS(EventChannelAttribute) : public Attribute::in {
  public: Boolean get_Enabled() { return Enabled; }
  public: void set_Enabled(Boolean value) { Enabled = value; }
  public: EventChannelType get_EventChannelType() { return EventChannelType; }
  public: void set_EventChannelType(EventChannelType value) { EventChannelType = value; }
  public: void Ctor();
  private: Boolean Enabled;
  private: EventChannelType EventChannelType;
};
} // namespace EventChannelAttributeNamespace
using EventChannelAttribute = EventChannelAttributeNamespace::EventChannelAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
