#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EtwEventProviderNamespace {
CLASS(EtwEventProvider) {
};
} // namespace EtwEventProviderNamespace
using EtwEventProvider = EtwEventProviderNamespace::EtwEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
