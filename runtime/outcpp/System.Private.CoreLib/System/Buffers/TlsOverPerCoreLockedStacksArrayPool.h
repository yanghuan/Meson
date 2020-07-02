#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ConditionalWeakTable, TKey, TValue)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Buffers {
namespace TlsOverPerCoreLockedStacksArrayPoolNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
CLASS(TlsOverPerCoreLockedStacksArrayPool, T) {
  private: enum class MemoryPressure {
    Low = 0,
    Medium = 1,
    High = 2,
  };
  private: CLASS(LockedStack) {
    public: Boolean TryPush(Array<T> array);
    public: Array<T> TryPop();
    public: void Trim(UInt32 tickCount, Int32 id, MemoryPressure pressure, Int32 bucketSize);
    private: Array<Array<T>> _arrays;
    private: Int32 _count;
    private: UInt32 _firstStackItemMS;
  };
  private: CLASS(PerCoreLockedStacks) {
    public: void TryPush(Array<T> array);
    public: Array<T> TryPop();
    public: void Trim(UInt32 tickCount, Int32 id, MemoryPressure pressure, Int32 bucketSize);
    private: Array<LockedStack> _perCoreStacks;
  };
  private: Int32 get_Id();
  private: PerCoreLockedStacks CreatePerCoreLockedStacks(Int32 bucketIndex);
  public: Array<T> Rent(Int32 minimumLength);
  public: void Return(Array<T> array, Boolean clearArray);
  public: Boolean Trim();
  private: static Boolean Gen2GcCallbackFunc(Object target);
  private: static MemoryPressure GetMemoryPressure();
  private: static Boolean GetTrimBuffers();
  private: Array<Int32> _bucketArraySizes;
  private: Array<PerCoreLockedStacks> _buckets;
  private: static Array<Array<T>> t_tlsBuckets;
  private: Int32 _callbackCreated;
  private: static Boolean s_trimBuffers;
  private: static ConditionalWeakTable<Array<Array<T>>, Object> s_allTlsBuckets;
};
} // namespace TlsOverPerCoreLockedStacksArrayPoolNamespace
template <class T>
using TlsOverPerCoreLockedStacksArrayPool = TlsOverPerCoreLockedStacksArrayPoolNamespace::TlsOverPerCoreLockedStacksArrayPool<T>;
} // namespace System::Private::CoreLib::System::Buffers
