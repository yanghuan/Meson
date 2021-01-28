#include "Monitor-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Threading::MonitorNamespace {
Int64 Monitor::get_LockContentionCount() {
  return GetLockContentionCount();
}

void Monitor::Enter(Object obj, Boolean& lockTaken) {
  if (lockTaken) {
    ThrowLockTakenException();
  }
  ReliableEnter(obj, lockTaken);
}

void Monitor::ThrowLockTakenException() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeFalse(), "lockTaken");
}

Boolean Monitor::TryEnter(Object obj) {
  Boolean lockTaken = false;
  TryEnter(obj, 0, lockTaken);
  return lockTaken;
}

void Monitor::TryEnter(Object obj, Boolean& lockTaken) {
  if (lockTaken) {
    ThrowLockTakenException();
  }
  ReliableEnterTimeout(obj, 0, lockTaken);
}

Boolean Monitor::TryEnter(Object obj, Int32 millisecondsTimeout) {
  Boolean lockTaken = false;
  TryEnter(obj, millisecondsTimeout, lockTaken);
  return lockTaken;
}

Int32 Monitor::MillisecondsTimeoutFromTimeSpan(TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  return (Int32)num;
}

Boolean Monitor::TryEnter(Object obj, TimeSpan timeout) {
  return TryEnter(obj, MillisecondsTimeoutFromTimeSpan(timeout));
}

void Monitor::TryEnter(Object obj, Int32 millisecondsTimeout, Boolean& lockTaken) {
  if (lockTaken) {
    ThrowLockTakenException();
  }
  ReliableEnterTimeout(obj, millisecondsTimeout, lockTaken);
}

void Monitor::TryEnter(Object obj, TimeSpan timeout, Boolean& lockTaken) {
  if (lockTaken) {
    ThrowLockTakenException();
  }
  ReliableEnterTimeout(obj, MillisecondsTimeoutFromTimeSpan(timeout), lockTaken);
}

Boolean Monitor::IsEntered(Object obj) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  return IsEnteredNative(obj);
}

Boolean Monitor::Wait(Object obj, Int32 millisecondsTimeout, Boolean exitContext) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  return ObjWait(exitContext, millisecondsTimeout, obj);
}

Boolean Monitor::Wait(Object obj, TimeSpan timeout, Boolean exitContext) {
  return Wait(obj, MillisecondsTimeoutFromTimeSpan(timeout), exitContext);
}

Boolean Monitor::Wait(Object obj, Int32 millisecondsTimeout) {
  return Wait(obj, millisecondsTimeout, false);
}

Boolean Monitor::Wait(Object obj, TimeSpan timeout) {
  return Wait(obj, MillisecondsTimeoutFromTimeSpan(timeout), false);
}

Boolean Monitor::Wait(Object obj) {
  return Wait(obj, -1, false);
}

void Monitor::Pulse(Object obj) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  ObjPulse(obj);
}

void Monitor::PulseAll(Object obj) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  ObjPulseAll(obj);
}

} // namespace System::Private::CoreLib::System::Threading::MonitorNamespace
