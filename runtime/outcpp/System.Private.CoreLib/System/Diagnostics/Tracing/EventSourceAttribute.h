#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventSourceAttributeNamespace {
CLASS(EventSourceAttribute) {
  private: String Name;
  private: String Guid;
  private: String LocalizationResources;
};
} // namespace EventSourceAttributeNamespace
using EventSourceAttribute = EventSourceAttributeNamespace::EventSourceAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
