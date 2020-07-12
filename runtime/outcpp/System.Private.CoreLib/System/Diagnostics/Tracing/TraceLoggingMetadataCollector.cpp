#include "TraceLoggingMetadataCollector-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingMetadataCollector-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingMetadataCollectorNamespace {
void TraceLoggingMetadataCollector___::Impl___::AddScalar(Int32 size) {
};

void TraceLoggingMetadataCollector___::Impl___::AddNonscalar() {
};

void TraceLoggingMetadataCollector___::Impl___::BeginBuffered() {
};

void TraceLoggingMetadataCollector___::Impl___::EndBuffered() {
};

Int32 TraceLoggingMetadataCollector___::Impl___::Encode(Array<Byte> metadata) {
  return Int32();
};

Int32 TraceLoggingMetadataCollector___::get_ScratchSize() {
  return Int32();
};

Int32 TraceLoggingMetadataCollector___::get_DataCount() {
  return Int32();
};

Int32 TraceLoggingMetadataCollector___::get_PinCount() {
  return Int32();
};

Boolean TraceLoggingMetadataCollector___::get_BeginningBufferedArray() {
  return Boolean();
};

TraceLoggingMetadataCollector TraceLoggingMetadataCollector___::AddGroup(String name) {
  return nullptr;
};

void TraceLoggingMetadataCollector___::AddScalar(String name, TraceLoggingDataType type) {
};

void TraceLoggingMetadataCollector___::AddNullTerminatedString(String name, TraceLoggingDataType type) {
};

void TraceLoggingMetadataCollector___::AddArray(String name, TraceLoggingDataType type) {
};

void TraceLoggingMetadataCollector___::BeginBufferedArray() {
};

void TraceLoggingMetadataCollector___::EndBufferedArray() {
};

Array<Byte> TraceLoggingMetadataCollector___::GetMetadata() {
  return Array<Byte>();
};

void TraceLoggingMetadataCollector___::AddField(FieldMetadata fieldMetadata) {
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingMetadataCollectorNamespace
