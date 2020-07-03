#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventChannelType;
namespace EventChannelAttributeNamespace {
CLASS(EventChannelAttribute) {
  private: Boolean Enabled;
  private: EventChannelType EventChannelType;
};
} // namespace EventChannelAttributeNamespace
using EventChannelAttribute = EventChannelAttributeNamespace::EventChannelAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
