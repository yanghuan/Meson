#include "StringTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataType.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::StringTypeInfoNamespace {
void StringTypeInfo___::ctor() {
}

void StringTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  if (name == nullptr) {
    name = "message";
  }
  collector->AddNullTerminatedString(name, Statics::MakeDataType(TraceLoggingDataType::Utf16String, format));
}

void StringTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  collector->AddNullTerminatedString((String)value.get_ReferenceValue());
}

Object StringTypeInfo___::GetData(Object value) {
  if (value == nullptr) {
    return "";
  }
  return value;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::StringTypeInfoNamespace
