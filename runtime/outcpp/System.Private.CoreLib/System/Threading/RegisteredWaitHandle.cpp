#include "RegisteredWaitHandle-dep.h"

#include <System.Private.CoreLib/System/Threading/RegisteredWaitHandleSafe-dep.h>

namespace System::Private::CoreLib::System::Threading::RegisteredWaitHandleNamespace {
void RegisteredWaitHandle___::ctor() {
  internalRegisteredWait = rt::newobj<RegisteredWaitHandleSafe>();
}

void RegisteredWaitHandle___::SetHandle(IntPtr handle) {
  internalRegisteredWait->SetHandle(handle);
}

void RegisteredWaitHandle___::SetWaitObject(WaitHandle waitObject) {
  internalRegisteredWait->SetWaitObject(waitObject);
}

Boolean RegisteredWaitHandle___::Unregister(WaitHandle waitObject) {
  return internalRegisteredWait->Unregister(waitObject);
}

} // namespace System::Private::CoreLib::System::Threading::RegisteredWaitHandleNamespace
