#include "ScalarArrayTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarArrayTypeInfo-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ScalarArrayTypeInfoNamespace {
void ScalarArrayTypeInfo___::ctor(Type type, Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> formatFunc, TraceLoggingDataType nativeFormat, System::Int32 elementSize) {
  this->formatFunc = formatFunc;
  this->nativeFormat = nativeFormat;
  this->elementSize = elementSize;
}

void ScalarArrayTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->AddArray(name, formatFunc(format, nativeFormat));
}

void ScalarArrayTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  collector->AddArray(value, elementSize);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Boolean() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Byte() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::SByte() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Char() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Int16() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::UInt16() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Int32() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::UInt32() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Int64() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::UInt64() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::IntPtr() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::UIntPtr() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Single() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Double() {
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Guid() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ScalarArrayTypeInfoNamespace
