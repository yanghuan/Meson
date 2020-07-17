#include "EventWaitHandle-dep.h"

#include <System.Private.CoreLib/System/Threading/EventWaitHandle-dep.h>

namespace System::Private::CoreLib::System::Threading::EventWaitHandleNamespace {
void EventWaitHandle___::Ctor(Boolean initialState, EventResetMode mode) {
};

void EventWaitHandle___::Ctor(Boolean initialState, EventResetMode mode, String name) {
};

void EventWaitHandle___::Ctor(Boolean initialState, EventResetMode mode, String name, Boolean& createdNew) {
};

EventWaitHandle EventWaitHandle___::OpenExisting(String name) {
  return nullptr;
};

Boolean EventWaitHandle___::TryOpenExisting(String name, EventWaitHandle& result) {
  return Boolean();
};

void EventWaitHandle___::Ctor(SafeWaitHandle handle) {
};

void EventWaitHandle___::CreateEventCore(Boolean initialState, EventResetMode mode, String name, Boolean& createdNew) {
};

WaitHandle::in::OpenExistingResult EventWaitHandle___::OpenExistingWorker(String name, EventWaitHandle& result) {
  return WaitHandle::in::OpenExistingResult::NameInvalid;
};

Boolean EventWaitHandle___::Reset() {
  return Boolean();
};

Boolean EventWaitHandle___::Set() {
  return Boolean();
};

Boolean EventWaitHandle___::Set(SafeWaitHandle waitHandle) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Threading::EventWaitHandleNamespace
