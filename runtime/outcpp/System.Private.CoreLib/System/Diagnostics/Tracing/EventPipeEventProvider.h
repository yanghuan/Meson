#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipeEventProviderNamespace {
CLASS(EventPipeEventProvider) {
  private: IntPtr m_provHandle;
};
} // namespace EventPipeEventProviderNamespace
using EventPipeEventProvider = EventPipeEventProviderNamespace::EventPipeEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
