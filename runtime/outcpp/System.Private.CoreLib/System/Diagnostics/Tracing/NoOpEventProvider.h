#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace NoOpEventProviderNamespace {
CLASS(NoOpEventProvider) : public Object::in {
  public: void Ctor();
};
} // namespace NoOpEventProviderNamespace
using NoOpEventProvider = NoOpEventProviderNamespace::NoOpEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
