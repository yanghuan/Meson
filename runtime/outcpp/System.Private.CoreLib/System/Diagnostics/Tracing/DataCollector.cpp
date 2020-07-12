#include "DataCollector-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::DataCollectorNamespace {
void DataCollector::Enable(Byte* scratch, Int32 scratchSize, EventSource::in::EventData* datas, Int32 dataCount, GCHandle* pins, Int32 pinCount) {
};

void DataCollector::Disable() {
};

EventSource::in::EventData* DataCollector::Finish() {
  return nullptr;
};

void DataCollector::AddScalar(void* value, Int32 size) {
};

void DataCollector::AddNullTerminatedString(String value) {
};

void DataCollector::AddArray(Array<> value, Int32 length, Int32 itemSize) {
};

Int32 DataCollector::BeginBufferedArray() {
  return Int32();
};

void DataCollector::EndBufferedArray(Int32 bookmark, Int32 count) {
};

void DataCollector::BeginBuffered() {
};

void DataCollector::EndBuffered() {
};

void DataCollector::EnsureBuffer() {
};

void DataCollector::EnsureBuffer(Int32 additionalSize) {
};

void DataCollector::GrowBuffer(Int32 required) {
};

void DataCollector::PinArray(Object value, Int32 size) {
};

void DataCollector::ScalarsBegin() {
};

void DataCollector::ScalarsEnd() {
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::DataCollectorNamespace
