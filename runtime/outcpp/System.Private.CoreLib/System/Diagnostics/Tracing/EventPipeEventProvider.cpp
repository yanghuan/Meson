#include "EventPipeEventProvider-dep.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeEventProviderNamespace {
void EventPipeEventProvider___::ctor() {
  m_provHandle = IntPtr::Zero;
  Object::ctor();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeEventProviderNamespace
