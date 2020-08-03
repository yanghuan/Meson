#pragma once

#include <System.Private.CoreLib/System/Buffers/ArrayPool.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/SpinLock.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace ConfigurableArrayPoolNamespace {
using namespace Threading;
CLASS(ConfigurableArrayPool, T) : public ArrayPool<T>::in {
  private: CLASS(Bucket) : public Object::in {
    public: Int32 get_Id();
    public: void Ctor(Int32 bufferLength, Int32 numberOfBuffers, Int32 poolId);
    public: Array<T> Rent();
    public: void Return(Array<T> array);
    public: Int32 _bufferLength;
    private: Array<Array<T>> _buffers;
    private: Int32 _poolId;
    private: SpinLock _lock;
    private: Int32 _index;
  };
  private: Int32 get_Id();
  public: void Ctor();
  public: void Ctor(Int32 maxArrayLength, Int32 maxArraysPerBucket);
  public: Array<T> Rent(Int32 minimumLength);
  public: void Return(Array<T> array, Boolean clearArray);
  private: Array<Bucket> _buckets;
};
} // namespace ConfigurableArrayPoolNamespace
template <class T>
using ConfigurableArrayPool = ConfigurableArrayPoolNamespace::ConfigurableArrayPool<T>;
} // namespace System::Private::CoreLib::System::Buffers
