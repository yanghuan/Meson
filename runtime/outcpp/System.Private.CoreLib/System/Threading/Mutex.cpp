#include "Mutex-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ApplicationException-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Mutex-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitHandleCannotBeOpenedException-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::MutexNamespace {
using namespace System::IO;
using namespace System::Runtime::InteropServices;

void Mutex___::ctor(Boolean initiallyOwned, String name, Boolean& createdNew) {
  CreateMutexCore(initiallyOwned, name, createdNew);
}

void Mutex___::ctor(Boolean initiallyOwned, String name) {
  Boolean createdNew;
  CreateMutexCore(initiallyOwned, name, createdNew);
}

void Mutex___::ctor(Boolean initiallyOwned) {
  Boolean createdNew;
  CreateMutexCore(initiallyOwned, nullptr, createdNew);
}

void Mutex___::ctor() {
  Boolean createdNew;
  CreateMutexCore(false, nullptr, createdNew);
}

void Mutex___::ctor(SafeWaitHandle handle) {
  WaitHandle::in::set_SafeWaitHandle(handle);
}

Mutex Mutex___::OpenExisting(String name) {
  Mutex result;
}

Boolean Mutex___::TryOpenExisting(String name, Mutex& result) {
  return OpenExistingWorker(name, result) == WaitHandle::in::OpenExistingResult::Success;
}

void Mutex___::CreateMutexCore(Boolean initiallyOwned, String name, Boolean& createdNew) {
  UInt32 flags = (initiallyOwned ? 1u : 0u);
  SafeWaitHandle safeWaitHandle = Interop::Kernel32::CreateMutexEx(IntPtr::Zero, name, flags, 34603009u);
  Int32 lastWin32Error = Marshal::GetLastWin32Error();
  if (safeWaitHandle->get_IsInvalid()) {
    safeWaitHandle->SetHandleAsInvalid();
    if (lastWin32Error == 6) {
      rt::throw_exception<WaitHandleCannotBeOpenedException>(SR::Format(SR::get_Threading_WaitHandleCannotBeOpenedException_InvalidHandle(), name));
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error, name));
  }
  createdNew = lastWin32Error != 183;
  WaitHandle::in::set_SafeWaitHandle(safeWaitHandle);
}

WaitHandle::in::OpenExistingResult Mutex___::OpenExistingWorker(String name, Mutex& result) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  result = nullptr;
  SafeWaitHandle safeWaitHandle = Interop::Kernel32::OpenMutex(34603009u, false, name);
  if (safeWaitHandle->get_IsInvalid()) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    if (2 == lastWin32Error || 123 == lastWin32Error) {
      return WaitHandle::in::OpenExistingResult::NameNotFound;
    }
    if (3 == lastWin32Error) {
      return WaitHandle::in::OpenExistingResult::PathNotFound;
    }
    if (6 == lastWin32Error) {
      return WaitHandle::in::OpenExistingResult::NameInvalid;
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error, name));
  }
  result = rt::newobj<Mutex>(safeWaitHandle);
  return WaitHandle::in::OpenExistingResult::Success;
}

void Mutex___::ReleaseMutex() {
  if (!Interop::Kernel32::ReleaseMutex(WaitHandle::in::get_SafeWaitHandle())) {
    rt::throw_exception<ApplicationException>(SR::get_Arg_SynchronizationLockException());
  }
}

} // namespace System::Private::CoreLib::System::Threading::MutexNamespace
