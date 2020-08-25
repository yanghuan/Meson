#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IEventProvider)
namespace NoOpEventProviderNamespace {
CLASS(NoOpEventProvider) : public object {
  public: using interface = rt::TypeList<IEventProvider>;
  public: void ctor();
};
} // namespace NoOpEventProviderNamespace
using NoOpEventProvider = NoOpEventProviderNamespace::NoOpEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
