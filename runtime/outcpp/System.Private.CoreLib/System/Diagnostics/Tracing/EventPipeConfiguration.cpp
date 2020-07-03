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
};
void EventPipeConfiguration___::EnableProviderWithFilter(String providerName, UInt64 keywords, UInt32 loggingLevel, String filterData) {
};
void EventPipeConfiguration___::EnableProviderConfiguration(EventPipeProviderConfiguration providerConfig) {
};
void EventPipeConfiguration___::EnableProviderRange(Array<EventPipeProviderConfiguration> providerConfigs) {
};
void EventPipeConfiguration___::SetProfilerSamplingRate(TimeSpan minTimeBetweenSamples) {
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeConfigurationNamespace
