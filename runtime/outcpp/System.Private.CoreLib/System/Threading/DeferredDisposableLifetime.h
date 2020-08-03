#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace DeferredDisposableLifetimeNamespace {
template <class T>
struct DeferredDisposableLifetime : public valueType<DeferredDisposableLifetime<T>> {
  public: Boolean AddRef();
  public: void Release(T obj);
  public: void Dispose(T obj);
  private: Int32 _count;
};
} // namespace DeferredDisposableLifetimeNamespace
template <class T>
using DeferredDisposableLifetime = DeferredDisposableLifetimeNamespace::DeferredDisposableLifetime<T>;
} // namespace System::Private::CoreLib::System::Threading
