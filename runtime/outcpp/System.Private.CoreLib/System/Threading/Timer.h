#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(TimeSpan)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(TimerCallback)
FORWARD(WaitHandle)
FORWARD(TimerHolder)
namespace TimerNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(Timer) {
  public: static Int64 get_ActiveCount();
  private: void TimerSetup(TimerCallback callback, Object state, UInt32 dueTime, UInt32 period, Boolean flowExecutionContext);
  public: Boolean Change(Int32 dueTime, Int32 period);
  public: Boolean Change(TimeSpan dueTime, TimeSpan period);
  public: Boolean Change(UInt32 dueTime, UInt32 period);
  public: Boolean Change(Int64 dueTime, Int64 period);
  public: Boolean Dispose(WaitHandle notifyObject);
  public: void Dispose();
  public: ValueTask<> DisposeAsync();
  private: TimerHolder _timer;
};
} // namespace TimerNamespace
using Timer = TimerNamespace::Timer;
} // namespace System::Private::CoreLib::System::Threading