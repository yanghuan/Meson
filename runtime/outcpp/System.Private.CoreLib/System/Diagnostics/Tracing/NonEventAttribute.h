#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace NonEventAttributeNamespace {
CLASS(NonEventAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace NonEventAttributeNamespace
using NonEventAttribute = NonEventAttributeNamespace::NonEventAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
