#include "IncrementingEventCounter-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceOptions-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingCounterPayload-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingEventCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingEventCounterPayloadType-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingEventCounterNamespace {
void IncrementingEventCounter___::ctor(String name, Tracing::EventSource eventSource) {
  Publish();
}

void IncrementingEventCounter___::Increment(Double increment) {
  {
    rt::lock((IncrementingEventCounter)this);
    _increment += increment;
  }
}

String IncrementingEventCounter___::ToString() {
  return String::in::Format("IncrementingEventCounter '{0}' Increment {1}", DiagnosticCounter::get_Name(), _increment);
}

void IncrementingEventCounter___::WritePayload(Single intervalSec, Int32 pollingIntervalMillisec) {
  {
    rt::lock((IncrementingEventCounter)this);
    IncrementingCounterPayload incrementingCounterPayload = rt::newobj<IncrementingCounterPayload>();
    incrementingCounterPayload->set_Name = DiagnosticCounter::get_Name();
    incrementingCounterPayload->set_IntervalSec = intervalSec;
    auto default = DiagnosticCounter::get_DisplayName();
    if (default != nullptr) default = "";

    incrementingCounterPayload->set_DisplayName = (default);
    incrementingCounterPayload->set_DisplayRateTimeScale = ((DisplayRateTimeScale == TimeSpan::Zero) ? "" : DisplayRateTimeScale.ToString("c"));
    incrementingCounterPayload->set_Series = String::in::Format("Interval={0}", pollingIntervalMillisec);
    incrementingCounterPayload->set_CounterType = "Sum";
    incrementingCounterPayload->set_Metadata = GetMetadataString();
    incrementingCounterPayload->set_Increment = _increment - _prevIncrement;
    auto extern = DiagnosticCounter::get_DisplayUnits();
    if (extern != nullptr) extern = "";

    incrementingCounterPayload->set_DisplayUnits = (extern);
    _prevIncrement = _increment;
    DiagnosticCounter::get_EventSource()->Write("EventCounters", EventSourceOptions(), rt::newobj<IncrementingEventCounterPayloadType>(incrementingCounterPayload));
  }
}

void IncrementingEventCounter___::UpdateMetric() {
  {
    rt::lock((IncrementingEventCounter)this);
    _prevIncrement = _increment;
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::IncrementingEventCounterNamespace
