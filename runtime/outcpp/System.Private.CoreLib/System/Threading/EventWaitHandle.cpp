#include "EventWaitHandle-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/EventWaitHandle-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitHandleCannotBeOpenedException-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::EventWaitHandleNamespace {
using namespace System::IO;
using namespace System::Runtime::InteropServices;

void EventWaitHandle___::ctor(Boolean initialState, EventResetMode mode) {
  Boolean createdNew;
  this->ctor(initialState, mode, nullptr, createdNew);
}

void EventWaitHandle___::ctor(Boolean initialState, EventResetMode mode, String name) {
  Boolean createdNew;
  this->ctor(initialState, mode, name, createdNew);
}

void EventWaitHandle___::ctor(Boolean initialState, EventResetMode mode, String name, Boolean& createdNew) {
  if (mode != 0 && mode != EventResetMode::ManualReset) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidFlag(), "mode");
  }
  CreateEventCore(initialState, mode, name, createdNew);
}

EventWaitHandle EventWaitHandle___::OpenExisting(String name) {
  EventWaitHandle result;
}

Boolean EventWaitHandle___::TryOpenExisting(String name, EventWaitHandle& result) {
  return OpenExistingWorker(name, result) == WaitHandle::in::OpenExistingResult::Success;
}

void EventWaitHandle___::ctor(SafeWaitHandle handle) {
  WaitHandle::in::set_SafeWaitHandle(handle);
}

void EventWaitHandle___::CreateEventCore(Boolean initialState, EventResetMode mode, String name, Boolean& createdNew) {
  UInt32 num = (initialState ? 2u : 0u);
  if (mode == EventResetMode::ManualReset) {
    num |= 1u;
  }
  SafeWaitHandle safeWaitHandle = Interop::Kernel32::CreateEventEx(IntPtr::Zero, name, num, 34603010u);
  Int32 lastWin32Error = Marshal::GetLastWin32Error();
  if (safeWaitHandle->get_IsInvalid()) {
    safeWaitHandle->SetHandleAsInvalid();
    if (!String::in::IsNullOrEmpty(name) && lastWin32Error == 6) {
      rt::throw_exception<WaitHandleCannotBeOpenedException>(SR::Format(SR::get_Threading_WaitHandleCannotBeOpenedException_InvalidHandle(), name));
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error, name));
  }
  createdNew = lastWin32Error != 183;
  WaitHandle::in::set_SafeWaitHandle(safeWaitHandle);
}

WaitHandle::in::OpenExistingResult EventWaitHandle___::OpenExistingWorker(String name, EventWaitHandle& result) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  result = nullptr;
  SafeWaitHandle safeWaitHandle = Interop::Kernel32::OpenEvent(34603010u, false, name);
  if (safeWaitHandle->get_IsInvalid()) {
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
        rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error, name));
    }
  }
  result = rt::newobj<EventWaitHandle>(safeWaitHandle);
  return WaitHandle::in::OpenExistingResult::Success;
}

Boolean EventWaitHandle___::Reset() {
  Boolean flag = Interop::Kernel32::ResetEvent(WaitHandle::in::get_SafeWaitHandle());
  if (!flag) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  return flag;
}

Boolean EventWaitHandle___::Set() {
  Boolean flag = Interop::Kernel32::SetEvent(WaitHandle::in::get_SafeWaitHandle());
  if (!flag) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  return flag;
}

Boolean EventWaitHandle___::Set(SafeWaitHandle waitHandle) {
  return Interop::Kernel32::SetEvent(waitHandle);
}

} // namespace System::Private::CoreLib::System::Threading::EventWaitHandleNamespace
