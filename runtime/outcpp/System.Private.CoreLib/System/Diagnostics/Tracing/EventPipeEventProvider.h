#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipeEventProviderNamespace {
CLASS(EventPipeEventProvider) : public Object::in {
  public: void Ctor();
  private: IntPtr m_provHandle;
};
} // namespace EventPipeEventProviderNamespace
using EventPipeEventProvider = EventPipeEventProviderNamespace::EventPipeEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
