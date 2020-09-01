#include "Timer-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Timer-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerHolder-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueueTimer-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::TimerNamespace {
Int64 Timer___::get_ActiveCount() {
  Int64 num = 0;
  Array<TimerQueue> instances = TimerQueue::in::get_Instances();
  for (TimerQueue& timerQueue : rt::each(instances)) {
    {
      rt::lock(timerQueue);
      num += timerQueue->set_ActiveCount();
    }
  }
  return num;
}

void Timer___::ctor(TimerCallback callback, Object state, Int32 dueTime, Int32 period) {
}

void Timer___::ctor(TimerCallback callback, Object state, Int32 dueTime, Int32 period, Boolean flowExecutionContext) {
  if (dueTime < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("dueTime", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (period < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("period", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  TimerSetup(callback, state, (UInt32)dueTime, (UInt32)period, flowExecutionContext);
}

void Timer___::ctor(TimerCallback callback, Object state, TimeSpan dueTime, TimeSpan period) {
  Int64 num = (Int64)dueTime.get_TotalMilliseconds();
  if (num < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("dueTime", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (num > 4294967294u) {
    rt::throw_exception<ArgumentOutOfRangeException>("dueTime", SR::get_ArgumentOutOfRange_TimeoutTooLarge());
  }
  Int64 num2 = (Int64)period.get_TotalMilliseconds();
  if (num2 < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("period", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (num2 > 4294967294u) {
    rt::throw_exception<ArgumentOutOfRangeException>("period", SR::get_ArgumentOutOfRange_PeriodTooLarge());
  }
  TimerSetup(callback, state, (UInt32)num, (UInt32)num2);
}

void Timer___::ctor(TimerCallback callback, Object state, UInt32 dueTime, UInt32 period) {
  TimerSetup(callback, state, dueTime, period);
}

void Timer___::ctor(TimerCallback callback, Object state, Int64 dueTime, Int64 period) {
  if (dueTime < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("dueTime", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (period < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("period", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (dueTime > 4294967294u) {
    rt::throw_exception<ArgumentOutOfRangeException>("dueTime", SR::get_ArgumentOutOfRange_TimeoutTooLarge());
  }
  if (period > 4294967294u) {
    rt::throw_exception<ArgumentOutOfRangeException>("period", SR::get_ArgumentOutOfRange_PeriodTooLarge());
  }
  TimerSetup(callback, state, (UInt32)dueTime, (UInt32)period);
}

void Timer___::ctor(TimerCallback callback) {
  TimerSetup(callback, (Timer)this, UInt32::MaxValue, UInt32::MaxValue);
}

void Timer___::TimerSetup(TimerCallback callback, Object state, UInt32 dueTime, UInt32 period, Boolean flowExecutionContext) {
  if (callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
  _timer = rt::newobj<TimerHolder>(rt::newobj<TimerQueueTimer>(callback, state, dueTime, period, flowExecutionContext));
}

Boolean Timer___::Change(Int32 dueTime, Int32 period) {
  if (dueTime < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("dueTime", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (period < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("period", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  return _timer->_timer->Change((UInt32)dueTime, (UInt32)period);
}

Boolean Timer___::Change(TimeSpan dueTime, TimeSpan period) {
  return Change((Int64)dueTime.get_TotalMilliseconds(), (Int64)period.get_TotalMilliseconds());
}

Boolean Timer___::Change(UInt32 dueTime, UInt32 period) {
  return _timer->_timer->Change(dueTime, period);
}

Boolean Timer___::Change(Int64 dueTime, Int64 period) {
  if (dueTime < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("dueTime", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (period < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("period", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (dueTime > 4294967294u) {
    rt::throw_exception<ArgumentOutOfRangeException>("dueTime", SR::get_ArgumentOutOfRange_TimeoutTooLarge());
  }
  if (period > 4294967294u) {
    rt::throw_exception<ArgumentOutOfRangeException>("period", SR::get_ArgumentOutOfRange_PeriodTooLarge());
  }
  return _timer->_timer->Change((UInt32)dueTime, (UInt32)period);
}

Boolean Timer___::Dispose(WaitHandle notifyObject) {
  if (notifyObject == nullptr) {
    rt::throw_exception<ArgumentNullException>("notifyObject");
  }
  return _timer->Close(notifyObject);
}

void Timer___::Dispose() {
  _timer->Close();
}

ValueTask<> Timer___::DisposeAsync() {
  return _timer->CloseAsync();
}

} // namespace System::Private::CoreLib::System::Threading::TimerNamespace
