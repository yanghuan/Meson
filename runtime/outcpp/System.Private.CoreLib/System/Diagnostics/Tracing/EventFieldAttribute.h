#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldTags;
enum class EventFieldFormat;
namespace EventFieldAttributeNamespace {
CLASS(EventFieldAttribute) {
  private: EventFieldTags Tags;
  private: String Name;
  private: EventFieldFormat Format;
};
} // namespace EventFieldAttributeNamespace
using EventFieldAttribute = EventFieldAttributeNamespace::EventFieldAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
