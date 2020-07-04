#include "Mutex-dep.h"

#include <System.Private.CoreLib/System/Threading/Mutex-dep.h>

namespace System::Private::CoreLib::System::Threading::MutexNamespace {
Mutex Mutex___::OpenExisting(String name) {
  return nullptr;
};
Boolean Mutex___::TryOpenExisting(String name, Mutex& result) {
  return Boolean();
};
void Mutex___::CreateMutexCore(Boolean initiallyOwned, String name, Boolean& createdNew) {
};
WaitHandle::in::OpenExistingResult Mutex___::OpenExistingWorker(String name, Mutex& result) {
  return WaitHandle::in::OpenExistingResult::NameInvalid;
};
void Mutex___::ReleaseMutex() {
};
} // namespace System::Private::CoreLib::System::Threading::MutexNamespace
