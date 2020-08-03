#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARD(TlsOverPerCoreLockedStacksArrayPool, T)
namespace ArrayPoolNamespace {
CLASS(ArrayPool, T) : public Object::in {
  public: static ArrayPool<T> get_Shared();
  public: static ArrayPool<T> Create();
  public: static ArrayPool<T> Create(Int32 maxArrayLength, Int32 maxArraysPerBucket);
  public: Array<T> Rent(Int32 minimumLength);
  public: void Return(Array<T> array, Boolean clearArray);
  protected: void Ctor();
  private: static void SCtor();
  private: static TlsOverPerCoreLockedStacksArrayPool<T> s_shared;
};
} // namespace ArrayPoolNamespace
template <class T>
using ArrayPool = ArrayPoolNamespace::ArrayPool<T>;
} // namespace System::Private::CoreLib::System::Buffers
