#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace SpinWaitNamespace {
struct SpinWait {
  public: Int32 get_Count();
  public: void set_Count(Int32 value);
  public: Boolean get_NextSpinWillYield();
  public: void SpinOnce();
  public: void SpinOnce(Int32 sleep1Threshold);
  private: void SpinOnceCore(Int32 sleep1Threshold);
  public: void Reset();
  public: static void SpinUntil(Func<Boolean> condition);
  public: static Boolean SpinUntil(Func<Boolean> condition, TimeSpan timeout);
  public: static Boolean SpinUntil(Func<Boolean> condition, Int32 millisecondsTimeout);
  public: static Int32 SpinCountforSpinBeforeWait;
  private: Int32 _count;
};
} // namespace SpinWaitNamespace
using SpinWait = SpinWaitNamespace::SpinWait;
} // namespace System::Private::CoreLib::System::Threading
