#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/MarshalByRefObject.h>

namespace System::Private::CoreLib::System {
FORWARD(IAsyncDisposable)
FORWARD(IDisposable)
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
FORWARD(TimerHolder)
FORWARD(WaitHandle)
namespace TimerNamespace {
using namespace System::Threading::Tasks;
CLASS(Timer) : public MarshalByRefObject::in {
  public: using interface = rt::TypeList<IDisposable, IAsyncDisposable>;
  public: static Int64 get_ActiveCount();
  public: void ctor(TimerCallback callback, Object state, Int32 dueTime, Int32 period);
  public: void ctor(TimerCallback callback, Object state, Int32 dueTime, Int32 period, Boolean flowExecutionContext);
  public: void ctor(TimerCallback callback, Object state, TimeSpan dueTime, TimeSpan period);
  public: void ctor(TimerCallback callback, Object state, UInt32 dueTime, UInt32 period);
  public: void ctor(TimerCallback callback, Object state, Int64 dueTime, Int64 period);
  public: void ctor(TimerCallback callback);
  private: void TimerSetup(TimerCallback callback, Object state, UInt32 dueTime, UInt32 period, Boolean flowExecutionContext = true);
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
