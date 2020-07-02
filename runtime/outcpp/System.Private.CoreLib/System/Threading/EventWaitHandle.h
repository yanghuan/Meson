#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/WaitHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeWaitHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Private::CoreLib::System::Threading {
enum class EventResetMode;
namespace EventWaitHandleNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
CLASS(EventWaitHandle) {
  public: static EventWaitHandle OpenExisting(String name);
  public: static Boolean TryOpenExisting(String name, EventWaitHandle& result);
  private: void CreateEventCore(Boolean initialState, EventResetMode mode, String name, Boolean& createdNew);
  private: static WaitHandle::in::OpenExistingResult OpenExistingWorker(String name, EventWaitHandle& result);
  public: Boolean Reset();
  public: Boolean Set();
  public: static Boolean Set(SafeWaitHandle waitHandle);
};
} // namespace EventWaitHandleNamespace
using EventWaitHandle = EventWaitHandleNamespace::EventWaitHandle;
} // namespace System::Private::CoreLib::System::Threading
