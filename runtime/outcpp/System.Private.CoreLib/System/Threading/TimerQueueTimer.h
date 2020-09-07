#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(ContextCallback)
FORWARD(ExecutionContext)
FORWARD(IThreadPoolWorkItem)
FORWARD(TimerCallback)
FORWARD(TimerQueue)
FORWARD(WaitHandle)
namespace TimerQueueTimerNamespace {
using namespace System::Threading::Tasks;
CLASS(TimerQueueTimer) : public object {
  public: using interface = rt::TypeList<IThreadPoolWorkItem>;
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__23_0(Object state);
    public: static __c __9;
  };
  public: void ctor(TimerCallback timerCallback, Object state, UInt32 dueTime, UInt32 period, Boolean flowExecutionContext);
  public: Boolean Change(UInt32 dueTime, UInt32 period);
  public: void Close();
  public: Boolean Close(WaitHandle toSignal);
  public: ValueTask<> CloseAsync();
  private: void ExecuteOfIThreadPoolWorkItem();
  public: void Fire(Boolean isThreadPool = false);
  public: void SignalNoCallbacksRunning();
  public: void CallCallback(Boolean isThreadPool);
  public: static void cctor();
  private: TimerQueue _associatedTimerQueue;
  public: TimerQueueTimer _next;
  public: TimerQueueTimer _prev;
  public: Boolean _short;
  public: Int64 _startTicks;
  public: UInt32 _dueTime;
  public: UInt32 _period;
  private: TimerCallback _timerCallback;
  private: Object _state;
  private: ExecutionContext _executionContext;
  private: Int32 _callbacksRunning;
  private: Boolean _canceled;
  private: Object _notifyWhenNoCallbacksRunning;
  private: static ContextCallback s_callCallbackInContext;
};
} // namespace TimerQueueTimerNamespace
using TimerQueueTimer = TimerQueueTimerNamespace::TimerQueueTimer;
} // namespace System::Private::CoreLib::System::Threading
