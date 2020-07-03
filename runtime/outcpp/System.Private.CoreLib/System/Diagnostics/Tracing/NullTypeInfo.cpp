#include "NullTypeInfo-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::NullTypeInfoNamespace {
void NullTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
};
void NullTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
};
Object NullTypeInfo___::GetData(Object value) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::NullTypeInfoNamespace
