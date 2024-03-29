#include "TimerQueue-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueueTimer-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Threading::TimerQueueNamespace {
void TimerQueue___::AppDomainTimerSafeHandle___::ctor() {
}

Boolean TimerQueue___::AppDomainTimerSafeHandle___::ReleaseHandle() {
  return DeleteAppDomainTimer(handle);
}

Int64 TimerQueue___::get_TickCount64() {
  if (Environment::get_IsWindows8OrAbove()) {
    UInt64 UnbiasedTime;
    Boolean flag = Interop::Kernel32::QueryUnbiasedInterruptTime(UnbiasedTime);
    return (Int64)(UnbiasedTime / 10000);
  }
  return Environment::get_TickCount64();
}

void TimerQueue___::ctor(Int32 id) {
  _currentAbsoluteThreshold = get_TickCount64() + 333;
  Object::in::ctor();
  _id = id;
}

Boolean TimerQueue___::SetTimer(UInt32 actualDuration) {
  if (m_appDomainTimer == nullptr || m_appDomainTimer->get_IsInvalid()) {
    m_appDomainTimer = CreateAppDomainTimer(actualDuration, _id);
    return !m_appDomainTimer->get_IsInvalid();
  }
  return ChangeAppDomainTimer(m_appDomainTimer, actualDuration);
}

void TimerQueue___::AppDomainTimerCallback(Int32 id) {
  Instances[id]->FireNextTimers();
}

Array<TimerQueue> TimerQueue___::CreateTimerQueues() {
  Array<TimerQueue> array = rt::newarr<Array<TimerQueue>>(Environment::get_ProcessorCount());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = rt::newobj<TimerQueue>(i);
  }
  return array;
}

Boolean TimerQueue___::EnsureTimerFiresBy(UInt32 requestedDuration) {
  UInt32 num = Math::Min(requestedDuration, 268435455u);
  if (_isTimerScheduled) {
    Int64 num2 = get_TickCount64() - _currentTimerStartTicks;
    if (num2 >= _currentTimerDuration) {
      return true;
    }
    UInt32 num3 = _currentTimerDuration - (UInt32)(Int32)num2;
    if (num >= num3) {
      return true;
    }
  }
  if (SetTimer(num)) {
    _isTimerScheduled = true;
    _currentTimerStartTicks = get_TickCount64();
    _currentTimerDuration = num;
    return true;
  }
  return false;
}

void TimerQueue___::FireNextTimers() {
  TimerQueueTimer timerQueueTimer = nullptr;
  {
    rt::lock((TimerQueue)this);
    _isTimerScheduled = false;
    Boolean flag = false;
    UInt32 num = UInt32::MaxValue();
    Int64 tickCount = get_TickCount64();
    TimerQueueTimer timerQueueTimer2 = _shortTimers;
    for (Int32 i = 0; i < 2; i++) {
      while (timerQueueTimer2 != nullptr) {
        TimerQueueTimer next = timerQueueTimer2->_next;
        Int64 num2 = tickCount - timerQueueTimer2->_startTicks;
        Int64 num3 = timerQueueTimer2->_dueTime - num2;
        if (num3 <= 0) {
          if (timerQueueTimer2->_period != UInt32::MaxValue()) {
            timerQueueTimer2->_startTicks = tickCount;
            Int64 num4 = num2 - timerQueueTimer2->_dueTime;
            timerQueueTimer2->_dueTime = ((num4 >= timerQueueTimer2->_period) ? 1u : (timerQueueTimer2->_period - (UInt32)(Int32)num4));
            if (timerQueueTimer2->_dueTime < num) {
              flag = true;
              num = timerQueueTimer2->_dueTime;
            }
            Boolean flag2 = tickCount + timerQueueTimer2->_dueTime - _currentAbsoluteThreshold <= 0;
            if (timerQueueTimer2->_short != flag2) {
              MoveTimerToCorrectList(timerQueueTimer2, flag2);
            }
          } else {
            DeleteTimer(timerQueueTimer2);
          }
          if (timerQueueTimer == nullptr) {
            timerQueueTimer = timerQueueTimer2;
          } else {
            ThreadPool::UnsafeQueueUserWorkItemInternal(timerQueueTimer2, false);
          }
        } else {
          if (num3 < num) {
            flag = true;
            num = (UInt32)num3;
          }
          if (!timerQueueTimer2->_short && num3 <= 333) {
            MoveTimerToCorrectList(timerQueueTimer2, true);
          }
        }
        timerQueueTimer2 = next;
      }
      if (i != 0) {
        continue;
      }
      Int64 num5 = _currentAbsoluteThreshold - tickCount;
      if (num5 > 0) {
        if (_shortTimers == nullptr && _longTimers != nullptr) {
          num = (UInt32)((Int32)num5 + 1);
          flag = true;
        }
        break;
      }
      timerQueueTimer2 = _longTimers;
      _currentAbsoluteThreshold = tickCount + 333;
    }
    if (flag) {
      EnsureTimerFiresBy(num);
    }
  }
  if (timerQueueTimer != nullptr) {
    timerQueueTimer->Fire();
  }
}

Boolean TimerQueue___::UpdateTimer(TimerQueueTimer timer, UInt32 dueTime, UInt32 period) {
  Int64 tickCount = get_TickCount64();
  Int64 num = tickCount + dueTime;
  Boolean flag = _currentAbsoluteThreshold - num >= 0;
  if (timer->_dueTime == UInt32::MaxValue()) {
    timer->_short = flag;
    LinkTimer(timer);
    ActiveCount++;
  } else if (timer->_short != flag) {
    UnlinkTimer(timer);
    timer->_short = flag;
    LinkTimer(timer);
  }

  timer->_dueTime = dueTime;
  timer->_period = ((period == 0) ? UInt32::MaxValue() : period);
  timer->_startTicks = tickCount;
  return EnsureTimerFiresBy(dueTime);
}

void TimerQueue___::MoveTimerToCorrectList(TimerQueueTimer timer, Boolean shortList) {
  UnlinkTimer(timer);
  timer->_short = shortList;
  LinkTimer(timer);
}

void TimerQueue___::LinkTimer(TimerQueueTimer timer) {
  TimerQueueTimer& reference = timer->_short ? _shortTimers : _longTimers;
  timer->_next = reference;
  if (timer->_next != nullptr) {
    timer->_next->_prev = timer;
  }
  timer->_prev = nullptr;
  reference = timer;
}

void TimerQueue___::UnlinkTimer(TimerQueueTimer timer) {
  TimerQueueTimer next = timer->_next;
  if (next != nullptr) {
    next->_prev = timer->_prev;
  }
  if (_shortTimers == timer) {
    _shortTimers = next;
  } else if (_longTimers == timer) {
    _longTimers = next;
  }

  next = timer->_prev;
  if (next != nullptr) {
    next->_next = timer->_next;
  }
}

void TimerQueue___::DeleteTimer(TimerQueueTimer timer) {
  if (timer->_dueTime != UInt32::MaxValue()) {
    ActiveCount--;
    UnlinkTimer(timer);
    timer->_prev = nullptr;
    timer->_next = nullptr;
    timer->_dueTime = UInt32::MaxValue();
    timer->_period = UInt32::MaxValue();
    timer->_startTicks = 0;
    timer->_short = false;
  }
}

void TimerQueue___::cctor() {
  Instances = CreateTimerQueues();
}

} // namespace System::Private::CoreLib::System::Threading::TimerQueueNamespace
