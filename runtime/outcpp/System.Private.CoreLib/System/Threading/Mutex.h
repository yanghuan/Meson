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
namespace MutexNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
CLASS(Mutex) : public WaitHandle::in {
  public: void Ctor(Boolean initiallyOwned, String name, Boolean& createdNew);
  public: void Ctor(Boolean initiallyOwned, String name);
  public: void Ctor(Boolean initiallyOwned);
  public: void Ctor();
  private: void Ctor(SafeWaitHandle handle);
  public: static Mutex OpenExisting(String name);
  public: static Boolean TryOpenExisting(String name, Mutex& result);
  private: void CreateMutexCore(Boolean initiallyOwned, String name, Boolean& createdNew);
  private: static WaitHandle::in::OpenExistingResult OpenExistingWorker(String name, Mutex& result);
  public: void ReleaseMutex();
};
} // namespace MutexNamespace
using Mutex = MutexNamespace::Mutex;
} // namespace System::Private::CoreLib::System::Threading
