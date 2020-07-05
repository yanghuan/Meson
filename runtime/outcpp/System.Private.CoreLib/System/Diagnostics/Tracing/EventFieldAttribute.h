#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat;
enum class EventFieldTags;
namespace EventFieldAttributeNamespace {
CLASS(EventFieldAttribute) {
  public: EventFieldTags get_Tags() { return Tags; }
  public: void set_Tags(EventFieldTags value) { Tags = value; }
  public: String get_Name() { return Name; }
  public: EventFieldFormat get_Format() { return Format; }
  public: void set_Format(EventFieldFormat value) { Format = value; }
  private: EventFieldTags Tags;
  private: String Name;
  private: EventFieldFormat Format;
};
} // namespace EventFieldAttributeNamespace
using EventFieldAttribute = EventFieldAttributeNamespace::EventFieldAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
