#include "DateTimeTypeInfo-dep.h"

#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataType.h>
#include <System.Private.CoreLib/System/Int64-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::DateTimeTypeInfoNamespace {
void DateTimeTypeInfo___::ctor() {
}

void DateTimeTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->AddScalar(name, Statics::MakeDataType(TraceLoggingDataType::FileTime, format));
}

void DateTimeTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  DateTime asDateTime = value.get_ScalarValue().AsDateTime;
  Int64 value2 = 0;
  if (asDateTime.get_Ticks() > 504911232000000000) {
    value2 = asDateTime.ToFileTimeUtc();
  }
  collector->AddScalar(value2);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::DateTimeTypeInfoNamespace
