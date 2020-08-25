#include "PollingCounter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/CounterPayload-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceOptions-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PollingCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PollingPayloadType-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::PollingCounterNamespace {
void PollingCounter___::ctor(String name, Tracing::EventSource eventSource, Func<Double> metricProvider) {
  if (metricProvider == nullptr) {
    rt::throw_exception<ArgumentNullException>("metricProvider");
  }
  _metricProvider = &metricProvider;
  Publish();
}

String PollingCounter___::ToString() {
  return "PollingCounter '" + DiagnosticCounter::in::get_Name() + "' Count 1 Mean " + _lastVal.ToString("n3");
}

void PollingCounter___::WritePayload(Single intervalSec, Int32 pollingIntervalMillisec) {
  {
    rt::lock((PollingCounter)this);
    Double num = 0;
    try {
      num = _metricProvider();
    } catch (Exception ex) {
    }
    CounterPayload counterPayload = rt::newobj<CounterPayload>();
    counterPayload->set_Name(DiagnosticCounter::in::get_Name());
    String as = DiagnosticCounter::in::get_DisplayName();
    counterPayload->set_DisplayName((as != nullptr ? as : ""));
    counterPayload->set_Count(1);
    counterPayload->set_IntervalSec(intervalSec);
    counterPayload->set_Series(String::in::Format("Interval={0}", pollingIntervalMillisec));
    counterPayload->set_CounterType("Mean");
    counterPayload->set_Mean(num);
    counterPayload->set_Max(num);
    counterPayload->set_Min(num);
    counterPayload->set_Metadata(GetMetadataString());
    counterPayload->set_StandardDeviation(0);
    String is = DiagnosticCounter::in::get_DisplayUnits();
    counterPayload->set_DisplayUnits((is != nullptr ? is : ""));
    _lastVal = num;
    DiagnosticCounter::in::get_EventSource()->Write("EventCounters", EventSourceOptions(), rt::newobj<PollingPayloadType>(counterPayload));
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::PollingCounterNamespace
