#include "EventCounter-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/CounterPayload-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/CounterPayloadType-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSourceOptions-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventCounterNamespace {
using namespace System::Threading;

void EventCounter___::ctor(String name, Tracing::EventSource eventSource) {
  _min = Double::PositiveInfinity();
  _max = Double::NegativeInfinity();
  Array<Double> array = rt::newarr<Array<Double>>(10);
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = Double::NegativeInfinity();
  }
  _bufferedValues = array;
  Publish();
}

void EventCounter___::WriteMetric(Single value) {
  Enqueue(value);
}

void EventCounter___::WriteMetric(Double value) {
  Enqueue(value);
}

String EventCounter___::ToString() {
  Int32 num = Volatile::Read(_count);
  if (num != 0) {
    return String::in::Format("EventCounter '{0}' Count {1} Mean {2}", DiagnosticCounter::in::get_Name(), num, (_sum / (Double)num).ToString("n3"));
  }
  return "EventCounter '" + DiagnosticCounter::in::get_Name() + "' Count 0";
}

void EventCounter___::OnMetricWritten(Double value) {
  _sum += value;
  _sumSquared += value * value;
  if (value > _max) {
    _max = value;
  }
  if (value < _min) {
    _min = value;
  }
  _count++;
}

void EventCounter___::WritePayload(Single intervalSec, Int32 pollingIntervalMillisec) {
  {
    rt::lock((EventCounter)this);
    Flush();
    CounterPayload counterPayload = rt::newobj<CounterPayload>();
    counterPayload->set_Count(_count);
    counterPayload->set_IntervalSec(intervalSec);
    if (0 < _count) {
      counterPayload->set_Mean(_sum / (Double)_count);
      counterPayload->set_StandardDeviation(Math::Sqrt(_sumSquared / (Double)_count - _sum * _sum / (Double)_count / (Double)_count));
    } else {
      counterPayload->set_Mean(0);
      counterPayload->set_StandardDeviation(0);
    }
    counterPayload->set_Min(_min);
    counterPayload->set_Max(_max);
    counterPayload->set_Series(String::in::Format("Interval={0}", pollingIntervalMillisec));
    counterPayload->set_CounterType("Mean");
    counterPayload->set_Metadata(GetMetadataString());
    String as = DiagnosticCounter::in::get_DisplayName();
    counterPayload->set_DisplayName(as != nullptr ? as : "");
    String is = DiagnosticCounter::in::get_DisplayUnits();
    counterPayload->set_DisplayUnits(is != nullptr ? is : "");
    counterPayload->set_Name(DiagnosticCounter::in::get_Name());
    ResetStatistics();
    DiagnosticCounter::in::get_EventSource()->Write("EventCounters", EventSourceOptions(), rt::newobj<CounterPayloadType>(counterPayload));
  }
}

void EventCounter___::ResetStatistics() {
  {
    rt::lock((EventCounter)this);
    _count = 0;
    _sum = 0;
    _sumSquared = 0;
    _min = Double::PositiveInfinity();
    _max = Double::NegativeInfinity();
  }
}

void EventCounter___::Enqueue(Double value) {
  Int32 num = _bufferedValuesIndex;
  Double num2;
  do {
    num2 = Interlocked::CompareExchange(_bufferedValues[num], value, Double::NegativeInfinity());
    num++;
    if (_bufferedValues->get_Length() <= num) {
      {
        rt::lock((EventCounter)this);
        Flush();
      }
      num = 0;
    }
  } while (num2 != Double::NegativeInfinity());
  _bufferedValuesIndex = num;
}

void EventCounter___::Flush() {
  for (Int32 i = 0; i < _bufferedValues->get_Length(); i++) {
    Double num = Interlocked::Exchange(_bufferedValues[i], Double::NegativeInfinity());
    if (num != Double::NegativeInfinity()) {
      OnMetricWritten(num);
    }
  }
  _bufferedValuesIndex = 0;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventCounterNamespace
