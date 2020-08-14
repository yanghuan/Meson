#include "ScalarTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarTypeInfo-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ScalarTypeInfoNamespace {
void ScalarTypeInfo___::ctor(Type type, Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> formatFunc, TraceLoggingDataType nativeFormat) {
  this->formatFunc = formatFunc;
  this->nativeFormat = nativeFormat;
}

void ScalarTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->AddScalar(name, formatFunc(format, nativeFormat));
}

void ScalarTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  collector->AddScalar(value);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Boolean() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::Byte() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::SByte() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::Char() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::Int16() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::UInt16() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::Int32() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::UInt32() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::Int64() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::UInt64() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::IntPtr() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::UIntPtr() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::Single() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::Double() {
}

TraceLoggingTypeInfo ScalarTypeInfo___::Guid() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ScalarTypeInfoNamespace
