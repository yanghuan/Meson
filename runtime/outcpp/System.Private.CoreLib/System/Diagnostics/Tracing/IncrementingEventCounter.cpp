#include "IncrementingEventCounter-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingEventCounterNamespace {
void IncrementingEventCounter___::ctor(String name, Tracing::EventSource eventSource) {
  Publish();
}

void IncrementingEventCounter___::Increment(Double increment) {
}

String IncrementingEventCounter___::ToString() {
}

void IncrementingEventCounter___::WritePayload(Single intervalSec, Int32 pollingIntervalMillisec) {
}

void IncrementingEventCounter___::UpdateMetric() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingEventCounterNamespace
