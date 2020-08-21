#include "TraceLoggingDataCollector-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DataCollector-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataCollector-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingDataCollectorNamespace {
void TraceLoggingDataCollector___::ctor() {
}

Int32 TraceLoggingDataCollector___::BeginBufferedArray() {
  return DataCollector::ThreadInstance.BeginBufferedArray();
}

void TraceLoggingDataCollector___::EndBufferedArray(Int32 bookmark, Int32 count) {
  DataCollector::ThreadInstance.EndBufferedArray(bookmark, count);
}

void TraceLoggingDataCollector___::AddScalar(PropertyValue value) {
  PropertyValue::Scalar scalarValue = value.get_ScalarValue();
  DataCollector::ThreadInstance.AddScalar(&scalarValue, value.get_ScalarLength());
}

void TraceLoggingDataCollector___::AddScalar(Int64 value) {
  DataCollector::ThreadInstance.AddScalar(&value, 8);
}

void TraceLoggingDataCollector___::AddScalar(Double value) {
  DataCollector::ThreadInstance.AddScalar(&value, 8);
}

void TraceLoggingDataCollector___::AddScalar(Boolean value) {
  DataCollector::ThreadInstance.AddScalar(&value, 1);
}

void TraceLoggingDataCollector___::AddNullTerminatedString(String value) {
  DataCollector::ThreadInstance.AddNullTerminatedString(value);
}

void TraceLoggingDataCollector___::AddArray(PropertyValue value, Int32 elementSize) {
  Array<> array = (Array<>)value.get_ReferenceValue();
  auto& as = array;
  auto& as = as == nullptr ? nullptr : as->get_Length();
  DataCollector::ThreadInstance.AddArray(array, as != nullptr ? as : 0, elementSize);
}

void TraceLoggingDataCollector___::cctor() {
  Instance = rt::newobj<TraceLoggingDataCollector>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingDataCollectorNamespace
