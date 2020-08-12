#pragma once

#include <System.Private.CoreLib/System/Threading/WaitHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeWaitHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Private::CoreLib::System::Threading {
enum class EventResetMode : int32_t;
namespace EventWaitHandleNamespace {
using namespace Microsoft::Win32::SafeHandles;
CLASS(EventWaitHandle) : public WaitHandle::in {
  public: void ctor(Boolean initialState, EventResetMode mode);
  public: void ctor(Boolean initialState, EventResetMode mode, String name);
  public: void ctor(Boolean initialState, EventResetMode mode, String name, Boolean& createdNew);
  public: static EventWaitHandle OpenExisting(String name);
  public: static Boolean TryOpenExisting(String name, EventWaitHandle& result);
  private: void ctor(SafeWaitHandle handle);
  private: void CreateEventCore(Boolean initialState, EventResetMode mode, String name, Boolean& createdNew);
  private: static WaitHandle::in::OpenExistingResult OpenExistingWorker(String name, EventWaitHandle& result);
  public: Boolean Reset();
  public: Boolean Set();
  public: static Boolean Set(SafeWaitHandle waitHandle);
};
} // namespace EventWaitHandleNamespace
using EventWaitHandle = EventWaitHandleNamespace::EventWaitHandle;
} // namespace System::Private::CoreLib::System::Threading
