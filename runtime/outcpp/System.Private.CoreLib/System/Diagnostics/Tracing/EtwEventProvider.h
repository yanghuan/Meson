#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IEventProvider)
namespace EtwEventProviderNamespace {
CLASS(EtwEventProvider) : public object {
  public: using interface = rt::TypeList<IEventProvider>;
  public: void ctor();
};
} // namespace EtwEventProviderNamespace
using EtwEventProvider = EtwEventProviderNamespace::EtwEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
