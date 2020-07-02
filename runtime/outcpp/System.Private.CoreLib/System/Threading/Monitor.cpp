#include "Monitor-dep.h"

namespace System::Private::CoreLib::System::Threading::MonitorNamespace {
Int64 Monitor::get_LockContentionCount() {
  return Int64();
};
void Monitor::Enter(Object obj, Boolean& lockTaken) {
  return void();
};
void Monitor::ThrowLockTakenException() {
  return void();
};
Boolean Monitor::TryEnter(Object obj) {
  return Boolean();
};
void Monitor::TryEnter(Object obj, Boolean& lockTaken) {
  return void();
};
Boolean Monitor::TryEnter(Object obj, Int32 millisecondsTimeout) {
  return Boolean();
};
Int32 Monitor::MillisecondsTimeoutFromTimeSpan(TimeSpan timeout) {
  return Int32();
};
Boolean Monitor::TryEnter(Object obj, TimeSpan timeout) {
  return Boolean();
};
void Monitor::TryEnter(Object obj, Int32 millisecondsTimeout, Boolean& lockTaken) {
  return void();
};
void Monitor::TryEnter(Object obj, TimeSpan timeout, Boolean& lockTaken) {
  return void();
};
Boolean Monitor::IsEntered(Object obj) {
  return Boolean();
};
Boolean Monitor::Wait(Object obj, Int32 millisecondsTimeout, Boolean exitContext) {
  return Boolean();
};
Boolean Monitor::Wait(Object obj, TimeSpan timeout, Boolean exitContext) {
  return Boolean();
};
Boolean Monitor::Wait(Object obj, Int32 millisecondsTimeout) {
  return Boolean();
};
Boolean Monitor::Wait(Object obj, TimeSpan timeout) {
  return Boolean();
};
Boolean Monitor::Wait(Object obj) {
  return Boolean();
};
void Monitor::Pulse(Object obj) {
  return void();
};
void Monitor::PulseAll(Object obj) {
  return void();
};
} // namespace System::Private::CoreLib::System::Threading::MonitorNamespace
