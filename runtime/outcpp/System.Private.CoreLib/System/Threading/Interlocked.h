#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Double)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(Single)
FORWARDS(UInt32)
FORWARDS(UInt64)
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
  public: template <class T>
  static T Exchange(T& location1, T value);
  public: static Int32 CompareExchange(Int32& location1, Int32 value, Int32 comparand);
  public: static Int64 CompareExchange(Int64& location1, Int64 value, Int64 comparand);
  public: static Single CompareExchange(Single& location1, Single value, Single comparand);
  public: static Double CompareExchange(Double& location1, Double value, Double comparand);
  public: static Object CompareExchange(Object& location1, Object value, Object comparand);
  public: static IntPtr CompareExchange(IntPtr& location1, IntPtr value, IntPtr comparand);
  public: template <class T>
  static T CompareExchange(T& location1, T value, T comparand);
  public: static Int32 Add(Int32& location1, Int32 value);
  public: static Int64 Add(Int64& location1, Int64 value);
  private: static Int32 ExchangeAdd(Int32& location1, Int32 value);
  private: static Int64 ExchangeAdd(Int64& location1, Int64 value);
  public: static Int64 Read(Int64& location);
  public: static void MemoryBarrier();
  public: static void ReadMemoryBarrier();
  private: static void _MemoryBarrierProcessWide();
  public: static void MemoryBarrierProcessWide();
  public: static UInt32 Increment(UInt32& location);
  public: static UInt64 Increment(UInt64& location);
  public: static UInt32 Decrement(UInt32& location);
  public: static UInt64 Decrement(UInt64& location);
  public: static UInt32 Exchange(UInt32& location1, UInt32 value);
  public: static UInt64 Exchange(UInt64& location1, UInt64 value);
  public: static UInt32 CompareExchange(UInt32& location1, UInt32 value, UInt32 comparand);
  public: static UInt64 CompareExchange(UInt64& location1, UInt64 value, UInt64 comparand);
  public: static UInt32 Add(UInt32& location1, UInt32 value);
  public: static UInt64 Add(UInt64& location1, UInt64 value);
  public: static UInt64 Read(UInt64& location);
  public: static Int32 And(Int32& location1, Int32 value);
  public: static UInt32 And(UInt32& location1, UInt32 value);
  public: static Int64 And(Int64& location1, Int64 value);
  public: static UInt64 And(UInt64& location1, UInt64 value);
  public: static Int32 Or(Int32& location1, Int32 value);
  public: static UInt32 Or(UInt32& location1, UInt32 value);
  public: static Int64 Or(Int64& location1, Int64 value);
  public: static UInt64 Or(UInt64& location1, UInt64 value);
};
} // namespace InterlockedNamespace
using Interlocked = InterlockedNamespace::Interlocked;
} // namespace System::Private::CoreLib::System::Threading
