#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARD(TlsOverPerCoreLockedStacksArrayPool, T)
namespace ArrayPoolNamespace {
CLASS(ArrayPool, T) : public object {
  public: static ArrayPool<T> get_Shared();
  public: static ArrayPool<T> Create();
  public: static ArrayPool<T> Create(Int32 maxArrayLength, Int32 maxArraysPerBucket);
  public: Array<T> Rent(Int32 minimumLength);
  public: void Return(Array<T> array, Boolean clearArray = false);
  public: void ctor();
  public: static void cctor();
  private: static TlsOverPerCoreLockedStacksArrayPool<T> s_shared;
};
} // namespace ArrayPoolNamespace
template <class T>
using ArrayPool = ArrayPoolNamespace::ArrayPool<T>;
} // namespace System::Private::CoreLib::System::Buffers
