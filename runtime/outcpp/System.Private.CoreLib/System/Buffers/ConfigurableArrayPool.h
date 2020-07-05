#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Threading/SpinLock.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace ConfigurableArrayPoolNamespace {
using namespace Threading;
CLASS(ConfigurableArrayPool, T) {
  private: CLASS(Bucket) {
    public: Int32 get_Id();
    public: Array<T> Rent();
    public: void Return(Array<T> array);
    public: Int32 _bufferLength;
    private: Array<Array<T>> _buffers;
    private: Int32 _poolId;
    private: SpinLock _lock;
    private: Int32 _index;
  };
  private: Int32 get_Id();
  public: Array<T> Rent(Int32 minimumLength);
  public: void Return(Array<T> array, Boolean clearArray);
  private: Array<Bucket> _buckets;
};
} // namespace ConfigurableArrayPoolNamespace
template <class T>
using ConfigurableArrayPool = ConfigurableArrayPoolNamespace::ConfigurableArrayPool<T>;
} // namespace System::Private::CoreLib::System::Buffers
