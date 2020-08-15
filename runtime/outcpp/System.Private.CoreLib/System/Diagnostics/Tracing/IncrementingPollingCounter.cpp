#include "IncrementingPollingCounter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceOptions-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingCounterPayload-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingPollingCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingPollingCounterPayloadType-dep.h>
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
  return String::in::Format("IncrementingPollingCounter '{0}' Increment {1}", DiagnosticCounter::in::get_Name(), _increment);
}

void IncrementingPollingCounter___::UpdateMetric() {
  try{
    {
      rt::lock((IncrementingPollingCounter)this);
      _prevIncrement = _increment;
      _increment = _totalValueProvider();
    }
  } catch (Exception ex) {
  }
}

void IncrementingPollingCounter___::WritePayload(Single intervalSec, Int32 pollingIntervalMillisec) {
  UpdateMetric();
  {
    rt::lock((IncrementingPollingCounter)this);
    IncrementingCounterPayload incrementingCounterPayload = rt::newobj<IncrementingCounterPayload>();
    incrementingCounterPayload->set_Name = DiagnosticCounter::in::get_Name();
    auto& default = DiagnosticCounter::in::get_DisplayName();
    incrementingCounterPayload->set_DisplayName = (default != nullptr ? default : "");
    incrementingCounterPayload->set_DisplayRateTimeScale = ((DisplayRateTimeScale == TimeSpan::Zero) ? "" : DisplayRateTimeScale.ToString("c"));
    incrementingCounterPayload->set_IntervalSec = intervalSec;
    incrementingCounterPayload->set_Series = String::in::Format("Interval={0}", pollingIntervalMillisec);
    incrementingCounterPayload->set_CounterType = "Sum";
    incrementingCounterPayload->set_Metadata = GetMetadataString();
    incrementingCounterPayload->set_Increment = _increment - _prevIncrement;
    auto& extern = DiagnosticCounter::in::get_DisplayUnits();
    incrementingCounterPayload->set_DisplayUnits = (extern != nullptr ? extern : "");
    DiagnosticCounter::in::get_EventSource()->Write("EventCounters", EventSourceOptions(), rt::newobj<IncrementingPollingCounterPayloadType>(incrementingCounterPayload));
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingPollingCounterNamespace
