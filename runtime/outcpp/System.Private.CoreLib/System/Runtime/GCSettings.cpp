#include "GCSettings-dep.h"

namespace System::Private::CoreLib::System::Runtime::GCSettingsNamespace {
GCLatencyMode GCSettings::get_LatencyMode() {
  return GCLatencyMode::NoGCRegion;
};

void GCSettings::set_LatencyMode(GCLatencyMode value) {
};

GCLargeObjectHeapCompactionMode GCSettings::get_LargeObjectHeapCompactionMode() {
  return GCLargeObjectHeapCompactionMode::CompactOnce;
};

void GCSettings::set_LargeObjectHeapCompactionMode(GCLargeObjectHeapCompactionMode value) {
};

} // namespace System::Private::CoreLib::System::Runtime::GCSettingsNamespace
