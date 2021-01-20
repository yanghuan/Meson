#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace SpinWaitNamespace {
struct SpinWait : public valueType<SpinWait> {
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
  public: static void cctor();
  public: static Int32 SpinCountforSpinBeforeWait;
  private: Int32 _count;
};
} // namespace SpinWaitNamespace
using SpinWait = SpinWaitNamespace::SpinWait;
} // namespace System::Private::CoreLib::System::Threading
