#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventIgnoreAttributeNamespace {
CLASS(EventIgnoreAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace EventIgnoreAttributeNamespace
using EventIgnoreAttribute = EventIgnoreAttributeNamespace::EventIgnoreAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
