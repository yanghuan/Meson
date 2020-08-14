#include "TimeSpanTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataType.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TimeSpanTypeInfoNamespace {
void TimeSpanTypeInfo___::ctor() {
}

void TimeSpanTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->AddScalar(name, Statics::MakeDataType(TraceLoggingDataType::Int64, format));
}

void TimeSpanTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  collector->AddScalar(value.get_ScalarValue().AsTimeSpan.get_Ticks());
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TimeSpanTypeInfoNamespace
