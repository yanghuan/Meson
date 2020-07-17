#include "TimerQueueTimer-dep.h"

namespace System::Private::CoreLib::System::Threading::TimerQueueTimerNamespace {
void TimerQueueTimer___::Ctor(TimerCallback timerCallback, Object state, UInt32 dueTime, UInt32 period, Boolean flowExecutionContext) {
};

Boolean TimerQueueTimer___::Change(UInt32 dueTime, UInt32 period) {
  return Boolean();
};

void TimerQueueTimer___::Close() {
};

Boolean TimerQueueTimer___::Close(WaitHandle toSignal) {
  return Boolean();
};

ValueTask<> TimerQueueTimer___::CloseAsync() {
  return ValueTask<>();
};

void TimerQueueTimer___::Fire(Boolean isThreadPool) {
};

void TimerQueueTimer___::SignalNoCallbacksRunning() {
};

void TimerQueueTimer___::CallCallback(Boolean isThreadPool) {
};

void TimerQueueTimer___::SCtor() {
};

} // namespace System::Private::CoreLib::System::Threading::TimerQueueTimerNamespace
