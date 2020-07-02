#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/WaitHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace SemaphoreNamespace {
CLASS(Semaphore) {
  public: static Semaphore OpenExisting(String name);
  public: static Boolean TryOpenExisting(String name, Semaphore& result);
  public: Int32 Release();
  public: Int32 Release(Int32 releaseCount);
  private: void CreateSemaphoreCore(Int32 initialCount, Int32 maximumCount, String name, Boolean& createdNew);
  private: static WaitHandle::in::OpenExistingResult OpenExistingWorker(String name, Semaphore& result);
  private: Int32 ReleaseCore(Int32 releaseCount);
};
} // namespace SemaphoreNamespace
using Semaphore = SemaphoreNamespace::Semaphore;
} // namespace System::Private::CoreLib::System::Threading