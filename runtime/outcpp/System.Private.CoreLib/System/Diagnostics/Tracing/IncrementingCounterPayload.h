#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace IncrementingCounterPayloadNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
CLASS(IncrementingCounterPayload) {
  private: IEnumerable<KeyValuePair<String, Object>> get_ForEnumeration();
  public: IEnumerator<KeyValuePair<String, Object>> GetEnumerator();
  private: String Name;
  private: String DisplayName;
  private: String DisplayRateTimeScale;
  private: Double Increment;
  private: Single IntervalSec;
  private: String Metadata;
  private: String Series;
  private: String CounterType;
  private: String DisplayUnits;
};
} // namespace IncrementingCounterPayloadNamespace
using IncrementingCounterPayload = IncrementingCounterPayloadNamespace::IncrementingCounterPayload;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
