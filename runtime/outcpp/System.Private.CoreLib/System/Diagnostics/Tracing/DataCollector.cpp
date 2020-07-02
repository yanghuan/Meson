#include "DataCollector-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::DataCollectorNamespace {
void DataCollector::Enable(Byte* scratch, Int32 scratchSize, EventSource::in::EventData* datas, Int32 dataCount, GCHandle* pins, Int32 pinCount) {
  return void();
};
void DataCollector::Disable() {
  return void();
};
EventSource::in::EventData* DataCollector::Finish() {
  return nullptr;
};
void DataCollector::AddScalar(void* value, Int32 size) {
  return void();
};
void DataCollector::AddNullTerminatedString(String value) {
  return void();
};
void DataCollector::AddArray(Array<> value, Int32 length, Int32 itemSize) {
  return void();
};
Int32 DataCollector::BeginBufferedArray() {
  return Int32();
};
void DataCollector::EndBufferedArray(Int32 bookmark, Int32 count) {
  return void();
};
void DataCollector::BeginBuffered() {
  return void();
};
void DataCollector::EndBuffered() {
  return void();
};
void DataCollector::EnsureBuffer() {
  return void();
};
void DataCollector::EnsureBuffer(Int32 additionalSize) {
  return void();
};
void DataCollector::GrowBuffer(Int32 required) {
  return void();
};
void DataCollector::PinArray(Object value, Int32 size) {
  return void();
};
void DataCollector::ScalarsBegin() {
  return void();
};
void DataCollector::ScalarsEnd() {
  return void();
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::DataCollectorNamespace
