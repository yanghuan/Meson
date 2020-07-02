#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(Single)
FORWARDS(Double)
FORWARD(Object)
FORWARDS(IntPtr)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace InterlockedNamespace {
class Interlocked {
  public: static Int32 Increment(Int32& location);
  public: static Int64 Increment(Int64& location);
  public: static Int32 Decrement(Int32& location);
  public: static Int64 Decrement(Int64& location);
  public: static Int32 Exchange(Int32& location1, Int32 value);
  public: static Int64 Exchange(Int64& location1, Int64 value);
  public: static Single Exchange(Single& location1, Single value);
  public: static Double Exchange(Double& location1, Double value);
  public: static Object Exchange(Object& location1, Object value);
  public: static IntPtr Exchange(IntPtr& location1, IntPtr value);
  public: static Int32 CompareExchange(Int32& location1, Int32 value, Int32 comparand);
  public: static Int64 CompareExchange(Int64& location1, Int64 value, Int64 comparand);
  public: static Single CompareExchange(Single& location1, Single value, Single comparand);
  public: static Double CompareExchange(Double& location1, Double value, Double comparand);
  public: static Object CompareExchange(Object& location1, Object value, Object comparand);
  public: static IntPtr CompareExchange(IntPtr& location1, IntPtr value, IntPtr comparand);
  public: static Int32 CompareExchange(Int32& location1, Int32 value, Int32 comparand, Boolean& succeeded);
  public: static Int32 ExchangeAdd(Int32& location1, Int32 value);
  public: static Int64 ExchangeAdd(Int64& location1, Int64 value);
  public: static Int32 Add(Int32& location1, Int32 value);
  public: static Int64 Add(Int64& location1, Int64 value);
  public: static Int64 Read(Int64& location);
  public: static void MemoryBarrier();
  private: static void _MemoryBarrierProcessWide();
  public: static void MemoryBarrierProcessWide();
};
} // namespace InterlockedNamespace
using Interlocked = InterlockedNamespace::Interlocked;
} // namespace System::Private::CoreLib::System::Threading
