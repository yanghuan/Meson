#include "DecimalTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataType.h>
#include <System.Private.CoreLib/System/Double-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::DecimalTypeInfoNamespace {
void DecimalTypeInfo___::ctor() {
}

void DecimalTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->AddScalar(name, Statics::MakeDataType(TraceLoggingDataType::Double, format));
}

void DecimalTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  collector->AddScalar((Double)value.get_ScalarValue().AsDecimal);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::DecimalTypeInfoNamespace
