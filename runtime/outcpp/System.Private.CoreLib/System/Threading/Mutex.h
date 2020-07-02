#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/WaitHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace MutexNamespace {
CLASS(Mutex) {
  public: static Mutex OpenExisting(String name);
  public: static Boolean TryOpenExisting(String name, Mutex& result);
  private: void CreateMutexCore(Boolean initiallyOwned, String name, Boolean& createdNew);
  private: static WaitHandle::in::OpenExistingResult OpenExistingWorker(String name, Mutex& result);
  public: void ReleaseMutex();
};
} // namespace MutexNamespace
using Mutex = MutexNamespace::Mutex;
} // namespace System::Private::CoreLib::System::Threading
