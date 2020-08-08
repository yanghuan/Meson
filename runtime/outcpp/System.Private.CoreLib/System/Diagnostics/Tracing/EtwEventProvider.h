#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IEventProvider)
namespace EtwEventProviderNamespace {
CLASS(EtwEventProvider) : public Object::in {
  public: using interface = rt::TypeList<IEventProvider>;
  public: void Ctor();
};
} // namespace EtwEventProviderNamespace
using EtwEventProvider = EtwEventProviderNamespace::EtwEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
