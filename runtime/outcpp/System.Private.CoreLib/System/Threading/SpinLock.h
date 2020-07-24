#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS_(Nullable, T1, T2)
FORWARDS(TimeSpan)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace SpinLockNamespace {
struct SpinLock {
  friend class NAME(SystemThreading_SpinLockDebugView);
  public: Boolean get_IsHeld();
  public: Boolean get_IsHeldByCurrentThread();
  public: Boolean get_IsThreadOwnerTrackingEnabled();
  private: static Int32 CompareExchange(Int32& location, Int32 value, Int32 comparand, Boolean& success);
  public: explicit SpinLock(Boolean enableThreadOwnerTracking);
  public: void Enter(Boolean& lockTaken);
  public: void TryEnter(Boolean& lockTaken);
  public: void TryEnter(TimeSpan timeout, Boolean& lockTaken);
  public: void TryEnter(Int32 millisecondsTimeout, Boolean& lockTaken);
  private: void ContinueTryEnter(Int32 millisecondsTimeout, Boolean& lockTaken);
  private: void DecrementWaiters();
  private: void ContinueTryEnterWithThreadTracking(Int32 millisecondsTimeout, UInt32 startTime, Boolean& lockTaken);
  public: void Exit();
  public: void Exit(Boolean useMemoryBarrier);
  private: void ExitSlowPath(Boolean useMemoryBarrier);
  public: explicit SpinLock() {}
  private: Int32 _owner;
};
CLASS(SystemThreading_SpinLockDebugView) {
  public: Nullable<Boolean> get_IsHeldByCurrentThread();
  public: Nullable<Int32> get_OwnerThreadID();
  public: Boolean get_IsHeld();
  public: void Ctor(SpinLock spinLock);
  private: SpinLock _spinLock;
};
} // namespace SpinLockNamespace
using SpinLock = SpinLockNamespace::SpinLock;
} // namespace System::Private::CoreLib::System::Threading
