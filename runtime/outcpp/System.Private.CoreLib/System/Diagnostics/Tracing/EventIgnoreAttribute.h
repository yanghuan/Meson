#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventIgnoreAttributeNamespace {
CLASS(EventIgnoreAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace EventIgnoreAttributeNamespace
using EventIgnoreAttribute = EventIgnoreAttributeNamespace::EventIgnoreAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
