#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventSourceAttributeNamespace {
CLASS(EventSourceAttribute) {
  public: String get_Name() { return Name; }
  public: void set_Name(String value) { Name = value; }
  public: String get_Guid() { return Guid; }
  public: void set_Guid(String value) { Guid = value; }
  public: String get_LocalizationResources() { return LocalizationResources; }
  public: void set_LocalizationResources(String value) { LocalizationResources = value; }
  private: String Name;
  private: String Guid;
  private: String LocalizationResources;
};
} // namespace EventSourceAttributeNamespace
using EventSourceAttribute = EventSourceAttributeNamespace::EventSourceAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
