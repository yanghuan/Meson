#include "Semaphore-dep.h"

#include <System.Private.CoreLib/System/Threading/Semaphore-dep.h>

namespace System::Private::CoreLib::System::Threading::SemaphoreNamespace {
void Semaphore___::ctor(Int32 initialCount, Int32 maximumCount) {
}

void Semaphore___::ctor(Int32 initialCount, Int32 maximumCount, String name) {
}

void Semaphore___::ctor(Int32 initialCount, Int32 maximumCount, String name, Boolean& createdNew) {
}

Semaphore Semaphore___::OpenExisting(String name) {
  return nullptr;
}

Boolean Semaphore___::TryOpenExisting(String name, Semaphore& result) {
  return Boolean();
}

Int32 Semaphore___::Release() {
  return Int32();
}

Int32 Semaphore___::Release(Int32 releaseCount) {
  return Int32();
}

void Semaphore___::ctor(SafeWaitHandle handle) {
}

void Semaphore___::CreateSemaphoreCore(Int32 initialCount, Int32 maximumCount, String name, Boolean& createdNew) {
}

WaitHandle::in::OpenExistingResult Semaphore___::OpenExistingWorker(String name, Semaphore& result) {
  return WaitHandle::in::OpenExistingResult::NameInvalid;
}

Int32 Semaphore___::ReleaseCore(Int32 releaseCount) {
  return Int32();
}

} // namespace System::Private::CoreLib::System::Threading::SemaphoreNamespace
