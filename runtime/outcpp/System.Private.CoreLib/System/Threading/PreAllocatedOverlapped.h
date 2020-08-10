#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/DeferredDisposableLifetime.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(IDeferredDisposable)
FORWARD(IOCompletionCallback)
FORWARD(ThreadPoolBoundHandleOverlapped)
namespace PreAllocatedOverlappedNamespace {
CLASS(PreAllocatedOverlapped) : public Object::in {
  public: using interface = rt::TypeList<IDisposable, IDeferredDisposable>;
  public: void ctor(IOCompletionCallback callback, Object state, Object pinData);
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
