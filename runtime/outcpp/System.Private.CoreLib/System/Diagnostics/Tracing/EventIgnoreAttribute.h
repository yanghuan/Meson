#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventIgnoreAttributeNamespace {
CLASS(EventIgnoreAttribute) {
  public: void Ctor();
};
} // namespace EventIgnoreAttributeNamespace
using EventIgnoreAttribute = EventIgnoreAttributeNamespace::EventIgnoreAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
