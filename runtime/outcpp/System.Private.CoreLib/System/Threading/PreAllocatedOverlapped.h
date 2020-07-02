#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/DeferredDisposableLifetime.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadPoolBoundHandleOverlapped)
namespace PreAllocatedOverlappedNamespace {
CLASS(PreAllocatedOverlapped) {
  public: Boolean AddRef();
  public: void Release();
  public: void Dispose();
  protected: void Finalize();
  public: ThreadPoolBoundHandleOverlapped _overlapped;
  private: DeferredDisposableLifetime<PreAllocatedOverlapped> _lifetime;
};
} // namespace PreAllocatedOverlappedNamespace
using PreAllocatedOverlapped = PreAllocatedOverlappedNamespace::PreAllocatedOverlapped;
} // namespace System::Private::CoreLib::System::Threading
