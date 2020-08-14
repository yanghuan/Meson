#include "DateTimeOffsetTypeInfo-dep.h"

#include <System.Private.CoreLib/System/DateTimeOffset-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataType.h>
#include <System.Private.CoreLib/System/Int64-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::DateTimeOffsetTypeInfoNamespace {
void DateTimeOffsetTypeInfo___::ctor() {
}

void DateTimeOffsetTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  TraceLoggingMetadataCollector traceLoggingMetadataCollector = collector->AddGroup(name);
  traceLoggingMetadataCollector->AddScalar("Ticks", Statics::MakeDataType(TraceLoggingDataType::FileTime, format));
  traceLoggingMetadataCollector->AddScalar("Offset", TraceLoggingDataType::Int64);
}

void DateTimeOffsetTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  DateTimeOffset asDateTimeOffset = value.get_ScalarValue().AsDateTimeOffset;
  Int64 ticks = asDateTimeOffset.get_Ticks();
  collector->AddScalar((ticks < 504911232000000000) ? 0 : (ticks - 504911232000000000));
  collector->AddScalar(asDateTimeOffset.get_Offset().get_Ticks());
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::DateTimeOffsetTypeInfoNamespace
