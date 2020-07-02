#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace NoOpEventProviderNamespace {
CLASS(NoOpEventProvider) {
};
} // namespace NoOpEventProviderNamespace
using NoOpEventProvider = NoOpEventProviderNamespace::NoOpEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
