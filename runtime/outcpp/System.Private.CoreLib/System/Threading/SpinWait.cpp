#include "SpinWait-dep.h"

namespace System::Private::CoreLib::System::Threading::SpinWaitNamespace {
Int32 SpinWait::get_Count() {
  return Int32();
}

void SpinWait::set_Count(Int32 value) {
}

Boolean SpinWait::get_NextSpinWillYield() {
  return Boolean();
}

void SpinWait::SpinOnce() {
}

void SpinWait::SpinOnce(Int32 sleep1Threshold) {
}

void SpinWait::SpinOnceCore(Int32 sleep1Threshold) {
}

void SpinWait::Reset() {
}

void SpinWait::SpinUntil(Func<Boolean> condition) {
}

Boolean SpinWait::SpinUntil(Func<Boolean> condition, TimeSpan timeout) {
  return Boolean();
}

Boolean SpinWait::SpinUntil(Func<Boolean> condition, Int32 millisecondsTimeout) {
  return Boolean();
}

void SpinWait::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Threading::SpinWaitNamespace
