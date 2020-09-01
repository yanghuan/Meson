#include "SpinWait-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/TimeoutHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::SpinWaitNamespace {
Int32 SpinWait::get_Count() {
  return _count;
}

void SpinWait::set_Count(Int32 value) {
  _count = value;
}

Boolean SpinWait::get_NextSpinWillYield() {
  if (_count < 10) {
    return Environment::get_IsSingleProcessor();
  }
  return true;
}

void SpinWait::SpinOnce() {
  SpinOnceCore(20);
}

void SpinWait::SpinOnce(Int32 sleep1Threshold) {
  if (sleep1Threshold < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("sleep1Threshold", sleep1Threshold, SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (sleep1Threshold >= 0 && sleep1Threshold < 10) {
    sleep1Threshold = 10;
  }
  SpinOnceCore(sleep1Threshold);
}

void SpinWait::SpinOnceCore(Int32 sleep1Threshold) {
  if ((_count >= 10 && ((_count >= sleep1Threshold && sleep1Threshold >= 0) || (_count - 10) % 2 == 0)) || Environment::get_IsSingleProcessor()) {
    if (_count >= sleep1Threshold && sleep1Threshold >= 0) {
      Thread::in::Sleep(1);
    } else {
      Int32 num = (_count >= 10) ? ((_count - 10) / 2) : _count;
      if (num % 5 == 4) {
        Thread::in::Sleep(0);
      } else {
        Thread::in::Yield();
      }
    }
  } else {
    Int32 num2 = Thread::in::get_OptimalMaxSpinWaitsPerSpinIteration();
    if (_count <= 30 && 1 << _count < num2) {
      num2 = 1 << _count;
    }
    Thread::in::SpinWait(num2);
  }
  _count = ((_count == Int32::MaxValue) ? 10 : (_count + 1));
}

void SpinWait::Reset() {
  _count = 0;
}

void SpinWait::SpinUntil(Func<Boolean> condition) {
  SpinUntil(condition, -1);
}

Boolean SpinWait::SpinUntil(Func<Boolean> condition, TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", timeout, SR::get_SpinWait_SpinUntil_TimeoutWrong());
  }
  return SpinUntil(condition, (Int32)num);
}

Boolean SpinWait::SpinUntil(Func<Boolean> condition, Int32 millisecondsTimeout) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", millisecondsTimeout, SR::get_SpinWait_SpinUntil_TimeoutWrong());
  }
  if (condition == nullptr) {
    rt::throw_exception<ArgumentNullException>("condition", SR::get_SpinWait_SpinUntil_ArgumentNull());
  }
  UInt32 num = 0u;
  if (millisecondsTimeout != 0 && millisecondsTimeout != -1) {
    num = TimeoutHelper::GetTime();
  }
  SpinWait spinWait;
  while (!condition()) {
    if (millisecondsTimeout == 0) {
      return false;
    }
    spinWait.SpinOnce();
    if (millisecondsTimeout != -1 && spinWait.get_NextSpinWillYield() && millisecondsTimeout <= TimeoutHelper::GetTime() - num) {
      return false;
    }
  }
  return true;
}

void SpinWait::cctor() {
  SpinCountforSpinBeforeWait = (Environment::get_IsSingleProcessor() ? 1 : 35);
}

} // namespace System::Private::CoreLib::System::Threading::SpinWaitNamespace
