#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace NonEventAttributeNamespace {
CLASS(NonEventAttribute) {
  public: void Ctor();
};
} // namespace NonEventAttributeNamespace
using NonEventAttribute = NonEventAttributeNamespace::NonEventAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
