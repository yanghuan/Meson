#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ConditionalWeakTable, TKey, TValue)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Buffers {
namespace TlsOverPerCoreLockedStacksArrayPoolNamespace {
using namespace System::Runtime::CompilerServices;
CLASS(TlsOverPerCoreLockedStacksArrayPool, T) : public ArrayPool<T>::in {
  private: enum class MemoryPressure : int32_t {
    Low = 0,
    Medium = 1,
    High = 2,
  };
  private: CLASS(LockedStack) : public object {
    public: Boolean TryPush(Array<T> array);
    public: Array<T> TryPop();
    public: void Trim(UInt32 tickCount, Int32 id, MemoryPressure pressure, Int32 bucketSize);
    public: void ctor();
    private: Array<Array<T>> _arrays;
    private: Int32 _count;
    private: UInt32 _firstStackItemMS;
  };
  private: CLASS(PerCoreLockedStacks) : public object {
    public: void ctor();
    public: void TryPush(Array<T> array);
    public: Array<T> TryPop();
    public: void Trim(UInt32 tickCount, Int32 id, MemoryPressure pressure, Int32 bucketSize);
    private: Array<LockedStack> _perCoreStacks;
  };
  private: Int32 get_Id();
  public: void ctor();
  private: PerCoreLockedStacks CreatePerCoreLockedStacks(Int32 bucketIndex);
  public: Array<T> Rent(Int32 minimumLength);
  public: void Return(Array<T> array, Boolean clearArray = false);
  public: Boolean Trim();
  private: static Boolean Gen2GcCallbackFunc(Object target);
  private: static MemoryPressure GetMemoryPressure();
  private: static Boolean GetTrimBuffers();
  public: static void cctor();
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
