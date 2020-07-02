#include "TimerQueue-dep.h"

#include <System.Private.CoreLib/System/Threading/TimerQueue-dep.h>

namespace System::Private::CoreLib::System::Threading::TimerQueueNamespace {
Boolean TimerQueue___::AppDomainTimerSafeHandle___::ReleaseHandle() {
  return Boolean();
};
Int64 TimerQueue___::get_TickCount64() {
  return Int64();
};
Boolean TimerQueue___::SetTimer(UInt32 actualDuration) {
  return Boolean();
};
void TimerQueue___::AppDomainTimerCallback(Int32 id) {
  return void();
};
Array<TimerQueue> TimerQueue___::CreateTimerQueues() {
  return Array<TimerQueue>();
};
Boolean TimerQueue___::EnsureTimerFiresBy(UInt32 requestedDuration) {
  return Boolean();
};
void TimerQueue___::FireNextTimers() {
  return void();
};
Boolean TimerQueue___::UpdateTimer(TimerQueueTimer timer, UInt32 dueTime, UInt32 period) {
  return Boolean();
};
void TimerQueue___::MoveTimerToCorrectList(TimerQueueTimer timer, Boolean shortList) {
  return void();
};
void TimerQueue___::LinkTimer(TimerQueueTimer timer) {
  return void();
};
void TimerQueue___::UnlinkTimer(TimerQueueTimer timer) {
  return void();
};
void TimerQueue___::DeleteTimer(TimerQueueTimer timer) {
  return void();
};
} // namespace System::Private::CoreLib::System::Threading::TimerQueueNamespace
