#include "KeepAliveCleanupWorkListElement-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::KeepAliveCleanupWorkListElementNamespace {
void KeepAliveCleanupWorkListElement___::ctor(Object obj) {
  m_obj = obj;
}

void KeepAliveCleanupWorkListElement___::DestroyCore() {
  GC::KeepAlive(m_obj);
}

} // namespace System::Private::CoreLib::System::StubHelpers::KeepAliveCleanupWorkListElementNamespace
