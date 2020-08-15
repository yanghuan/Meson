#include "EventPipeConfiguration-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeConfigurationNamespace {
using namespace System::Collections::Generic;

String EventPipeConfiguration___::get_OutputFile() {
  return m_outputFile;
}

EventPipeSerializationFormat EventPipeConfiguration___::get_Format() {
  return m_format;
}

UInt32 EventPipeConfiguration___::get_CircularBufferSizeInMB() {
  return m_circularBufferSizeInMB;
}

Array<EventPipeProviderConfiguration> EventPipeConfiguration___::get_Providers() {
  return m_providers->ToArray();
}

void EventPipeConfiguration___::ctor(String outputFile, EventPipeSerializationFormat format, UInt32 circularBufferSizeInMB) {
  m_minTimeBetweenSamples = TimeSpan::FromMilliseconds(1);
  Object::in::ctor();
  if (String::in::IsNullOrEmpty(outputFile)) {
    rt::throw_exception<ArgumentNullException>("outputFile");
  }
  if (circularBufferSizeInMB == 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("circularBufferSizeInMB");
  }
  m_outputFile = outputFile;
  m_format = format;
  m_circularBufferSizeInMB = circularBufferSizeInMB;
  m_providers = rt::newobj<List<EventPipeProviderConfiguration>>();
}

void EventPipeConfiguration___::EnableProvider(String providerName, UInt64 keywords, UInt32 loggingLevel) {
  EnableProviderWithFilter(providerName, keywords, loggingLevel, nullptr);
}

void EventPipeConfiguration___::EnableProviderWithFilter(String providerName, UInt64 keywords, UInt32 loggingLevel, String filterData) {
  m_providers->Add(EventPipeProviderConfiguration(providerName, keywords, loggingLevel, filterData));
}

void EventPipeConfiguration___::EnableProviderConfiguration(EventPipeProviderConfiguration providerConfig) {
  m_providers->Add(providerConfig);
}

void EventPipeConfiguration___::EnableProviderRange(Array<EventPipeProviderConfiguration> providerConfigs) {
}

void EventPipeConfiguration___::SetProfilerSamplingRate(TimeSpan minTimeBetweenSamples) {
  if (minTimeBetweenSamples.get_Ticks() <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("minTimeBetweenSamples");
  }
  m_minTimeBetweenSamples = minTimeBetweenSamples;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeConfigurationNamespace
