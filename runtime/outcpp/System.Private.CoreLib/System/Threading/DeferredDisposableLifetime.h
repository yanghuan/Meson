#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace DeferredDisposableLifetimeNamespace {
template <class T>
struct DeferredDisposableLifetime {
  public: Boolean AddRef(T obj);
  public: void Release(T obj);
  public: void Dispose(T obj);
  private: Int32 _count;
};
} // namespace DeferredDisposableLifetimeNamespace
template <class T>
using DeferredDisposableLifetime = DeferredDisposableLifetimeNamespace::DeferredDisposableLifetime<T>;
} // namespace System::Private::CoreLib::System::Threading
