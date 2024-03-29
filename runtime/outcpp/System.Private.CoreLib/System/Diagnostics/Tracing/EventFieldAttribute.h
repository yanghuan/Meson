#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat : int32_t;
enum class EventFieldTags : int32_t;
namespace EventFieldAttributeNamespace {
CLASS(EventFieldAttribute) : public Attribute::in {
  public: EventFieldTags get_Tags() { return Tags; }
  public: void set_Tags(EventFieldTags value) { Tags = value; }
  public: String get_Name() { return Name; }
  public: EventFieldFormat get_Format() { return Format; }
  public: void set_Format(EventFieldFormat value) { Format = value; }
  public: void ctor();
  private: EventFieldTags Tags;
  private: String Name;
  private: EventFieldFormat Format;
};
} // namespace EventFieldAttributeNamespace
using EventFieldAttribute = EventFieldAttributeNamespace::EventFieldAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
