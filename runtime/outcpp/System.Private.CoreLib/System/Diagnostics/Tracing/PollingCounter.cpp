#include "PollingCounter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::PollingCounterNamespace {
void PollingCounter___::ctor(String name, Tracing::EventSource eventSource, Func<Double> metricProvider) {
  if (metricProvider == nullptr) {
    rt::throw_exception<ArgumentNullException>("metricProvider");
  }
  _metricProvider = metricProvider;
  Publish();
}

String PollingCounter___::ToString() {
}

void PollingCounter___::WritePayload(Single intervalSec, Int32 pollingIntervalMillisec) {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::PollingCounterNamespace
