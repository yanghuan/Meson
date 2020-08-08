#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(IEventProvider)
namespace EventPipeEventProviderNamespace {
CLASS(EventPipeEventProvider) : public Object::in {
  using interface = rt::TypeList<IEventProvider>;
  public: void Ctor();
  private: IntPtr m_provHandle;
};
} // namespace EventPipeEventProviderNamespace
using EventPipeEventProvider = EventPipeEventProviderNamespace::EventPipeEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
