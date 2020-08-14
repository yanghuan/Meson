#include "IncrementingPollingCounter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingPollingCounterNamespace {
void IncrementingPollingCounter___::ctor(String name, Tracing::EventSource eventSource, Func<Double> totalValueProvider) {
  if (totalValueProvider == nullptr) {
    rt::throw_exception<ArgumentNullException>("totalValueProvider");
  }
  _totalValueProvider = totalValueProvider;
  Publish();
}

String IncrementingPollingCounter___::ToString() {
}

void IncrementingPollingCounter___::UpdateMetric() {
  try{
  } catch (Exception ex) {
  }
}

void IncrementingPollingCounter___::WritePayload(Single intervalSec, Int32 pollingIntervalMillisec) {
  UpdateMetric();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingPollingCounterNamespace
