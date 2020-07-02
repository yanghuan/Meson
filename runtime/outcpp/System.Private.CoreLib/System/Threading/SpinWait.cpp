#include "SpinWait-dep.h"

namespace System::Private::CoreLib::System::Threading::SpinWaitNamespace {
Int32 SpinWait::get_Count() {
  return Int32();
};
void SpinWait::set_Count(Int32 value) {
  return void();
};
Boolean SpinWait::get_NextSpinWillYield() {
  return Boolean();
};
void SpinWait::SpinOnce() {
  return void();
};
void SpinWait::SpinOnce(Int32 sleep1Threshold) {
  return void();
};
void SpinWait::SpinOnceCore(Int32 sleep1Threshold) {
  return void();
};
void SpinWait::Reset() {
  return void();
};
void SpinWait::SpinUntil(Func<Boolean> condition) {
  return void();
};
Boolean SpinWait::SpinUntil(Func<Boolean> condition, TimeSpan timeout) {
  return Boolean();
};
Boolean SpinWait::SpinUntil(Func<Boolean> condition, Int32 millisecondsTimeout) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Threading::SpinWaitNamespace
