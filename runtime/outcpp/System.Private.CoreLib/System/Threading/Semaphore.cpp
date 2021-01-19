#include "Semaphore-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Semaphore-dep.h>
#include <System.Private.CoreLib/System/Threading/SemaphoreFullException-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitHandleCannotBeOpenedException-dep.h>

namespace System::Private::CoreLib::System::Threading::SemaphoreNamespace {
using namespace System::IO;
using namespace System::Runtime::InteropServices;

void Semaphore___::ctor(Int32 initialCount, Int32 maximumCount) {
}

void Semaphore___::ctor(Int32 initialCount, Int32 maximumCount, String name) {
  Boolean createdNew;
  this->ctor(initialCount, maximumCount, name, createdNew);
}

void Semaphore___::ctor(Int32 initialCount, Int32 maximumCount, String name, Boolean& createdNew) {
  if (initialCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("initialCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (maximumCount < 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("maximumCount", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (initialCount > maximumCount) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_SemaphoreInitialMaximum());
  }
  CreateSemaphoreCore(initialCount, maximumCount, name, createdNew);
}

Semaphore Semaphore___::OpenExisting(String name) {
  Semaphore result;
}

Boolean Semaphore___::TryOpenExisting(String name, Semaphore& result) {
  return OpenExistingWorker(name, result) == WaitHandle::in::OpenExistingResult::Success;
}

Int32 Semaphore___::Release() {
  return ReleaseCore(1);
}

Int32 Semaphore___::Release(Int32 releaseCount) {
  if (releaseCount < 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("releaseCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return ReleaseCore(releaseCount);
}

void Semaphore___::ctor(SafeWaitHandle handle) {
  WaitHandle::in::set_SafeWaitHandle(handle);
}

void Semaphore___::CreateSemaphoreCore(Int32 initialCount, Int32 maximumCount, String name, Boolean& createdNew) {
  SafeWaitHandle safeWaitHandle = Interop::Kernel32::CreateSemaphoreEx(IntPtr::Zero, initialCount, maximumCount, name, 0u, 34603010u);
  Int32 lastWin32Error = Marshal::GetLastWin32Error();
  if (safeWaitHandle->get_IsInvalid()) {
    if (!String::in::IsNullOrEmpty(name) && lastWin32Error == 6) {
      rt::throw_exception<WaitHandleCannotBeOpenedException>(SR::Format(SR::get_Threading_WaitHandleCannotBeOpenedException_InvalidHandle(), name));
    }
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  createdNew = lastWin32Error != 183;
  WaitHandle::in::set_SafeWaitHandle(safeWaitHandle);
}

WaitHandle::in::OpenExistingResult Semaphore___::OpenExistingWorker(String name, Semaphore& result) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  SafeWaitHandle safeWaitHandle = Interop::Kernel32::OpenSemaphore(34603010u, false, name);
  if (safeWaitHandle->get_IsInvalid()) {
    result = nullptr;
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    switch (lastWin32Error.get()) {
      case 2:
      case 123:
        return WaitHandle::in::OpenExistingResult::NameNotFound;
      case 3:
        return WaitHandle::in::OpenExistingResult::PathNotFound;
      default:
        if (!String::in::IsNullOrEmpty(name) && lastWin32Error == 6) {
          return WaitHandle::in::OpenExistingResult::NameInvalid;
        }
        rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
    }
  }
  result = rt::newobj<Semaphore>(safeWaitHandle);
  return WaitHandle::in::OpenExistingResult::Success;
}

Int32 Semaphore___::ReleaseCore(Int32 releaseCount) {
  Int32 previousCount;
  if (!Interop::Kernel32::ReleaseSemaphore(WaitHandle::in::get_SafeWaitHandle(), releaseCount, previousCount)) {
    rt::throw_exception<SemaphoreFullException>();
  }
  return previousCount;
}

} // namespace System::Private::CoreLib::System::Threading::SemaphoreNamespace
