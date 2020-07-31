#include "Timer-dep.h"

namespace System::Private::CoreLib::System::Threading::TimerNamespace {
Int64 Timer___::get_ActiveCount() {
  return Int64();
}

void Timer___::Ctor(TimerCallback callback, Object state, Int32 dueTime, Int32 period) {
}

void Timer___::Ctor(TimerCallback callback, Object state, Int32 dueTime, Int32 period, Boolean flowExecutionContext) {
}

void Timer___::Ctor(TimerCallback callback, Object state, TimeSpan dueTime, TimeSpan period) {
}

void Timer___::Ctor(TimerCallback callback, Object state, UInt32 dueTime, UInt32 period) {
}

void Timer___::Ctor(TimerCallback callback, Object state, Int64 dueTime, Int64 period) {
}

void Timer___::Ctor(TimerCallback callback) {
}

void Timer___::TimerSetup(TimerCallback callback, Object state, UInt32 dueTime, UInt32 period, Boolean flowExecutionContext) {
}

Boolean Timer___::Change(Int32 dueTime, Int32 period) {
  return Boolean();
}

Boolean Timer___::Change(TimeSpan dueTime, TimeSpan period) {
  return Boolean();
}

Boolean Timer___::Change(UInt32 dueTime, UInt32 period) {
  return Boolean();
}

Boolean Timer___::Change(Int64 dueTime, Int64 period) {
  return Boolean();
}

Boolean Timer___::Dispose(WaitHandle notifyObject) {
  return Boolean();
}

void Timer___::Dispose() {
}

ValueTask<> Timer___::DisposeAsync() {
  return ValueTask<>();
}

} // namespace System::Private::CoreLib::System::Threading::TimerNamespace
