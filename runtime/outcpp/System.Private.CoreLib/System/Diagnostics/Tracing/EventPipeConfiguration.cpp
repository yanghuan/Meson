#include "EventPipeConfiguration-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeConfigurationNamespace {
String EventPipeConfiguration___::get_OutputFile() {
  return nullptr;
};
EventPipeSerializationFormat EventPipeConfiguration___::get_Format() {
  return EventPipeSerializationFormat();
};
UInt32 EventPipeConfiguration___::get_CircularBufferSizeInMB() {
  return UInt32();
};
Array<EventPipeProviderConfiguration> EventPipeConfiguration___::get_Providers() {
  return Array<EventPipeProviderConfiguration>();
};
void EventPipeConfiguration___::EnableProvider(String providerName, UInt64 keywords, UInt32 loggingLevel) {
  return void();
};
void EventPipeConfiguration___::EnableProviderWithFilter(String providerName, UInt64 keywords, UInt32 loggingLevel, String filterData) {
  return void();
};
void EventPipeConfiguration___::EnableProviderConfiguration(EventPipeProviderConfiguration providerConfig) {
  return void();
};
void EventPipeConfiguration___::EnableProviderRange(Array<EventPipeProviderConfiguration> providerConfigs) {
  return void();
};
void EventPipeConfiguration___::SetProfilerSamplingRate(TimeSpan minTimeBetweenSamples) {
  return void();
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeConfigurationNamespace
