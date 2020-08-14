#include "HostExecutionContext-dep.h"

#include <System.Threading/System/Threading/HostExecutionContext-dep.h>

namespace System::Threading::System::Threading::HostExecutionContextNamespace {
void HostExecutionContext___::ctor() {
}

void HostExecutionContext___::ctor(Object state) {
  State = state;
}

HostExecutionContext HostExecutionContext___::CreateCopy() {
  return rt::newobj<HostExecutionContext>(State);
}

void HostExecutionContext___::Dispose() {
  Dispose(true);
}

void HostExecutionContext___::Dispose(Boolean disposing) {
}

} // namespace System::Threading::System::Threading::HostExecutionContextNamespace
