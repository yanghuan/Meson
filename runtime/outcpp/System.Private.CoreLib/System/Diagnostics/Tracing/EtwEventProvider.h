#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EtwEventProviderNamespace {
CLASS(EtwEventProvider) : public Object::in {
  public: void Ctor();
};
} // namespace EtwEventProviderNamespace
using EtwEventProvider = EtwEventProviderNamespace::EtwEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
