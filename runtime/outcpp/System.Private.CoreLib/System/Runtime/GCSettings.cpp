#include "GCSettings-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/GCSettings-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::GCSettingsNamespace {
GCLatencyMode GCSettings::get_LatencyMode() {
  return GetGCLatencyMode();
}

void GCSettings::set_LatencyMode(GCLatencyMode value) {
  if (value < GCLatencyMode::Batch || value > GCLatencyMode::SustainedLowLatency) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_Enum());
  }
  SetLatencyModeStatus setLatencyModeStatus = SetGCLatencyMode(value);
  if (setLatencyModeStatus == SetLatencyModeStatus::NoGCInProgress) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_SetLatencyModeNoGC());
  }
}

GCLargeObjectHeapCompactionMode GCSettings::get_LargeObjectHeapCompactionMode() {
  return GetLOHCompactionMode();
}

void GCSettings::set_LargeObjectHeapCompactionMode(GCLargeObjectHeapCompactionMode value) {
  if (value < GCLargeObjectHeapCompactionMode::Default || value > GCLargeObjectHeapCompactionMode::CompactOnce) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_Enum());
  }
  SetLOHCompactionMode(value);
}

} // namespace System::Private::CoreLib::System::Runtime::GCSettingsNamespace
