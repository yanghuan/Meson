#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/TimeSpan.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventPipeSerializationFormat : int32_t;
FORWARDS(EventPipeProviderConfiguration)
namespace EventPipeConfigurationNamespace {
using namespace System::Collections::Generic;
CLASS(EventPipeConfiguration) : public Object::in {
  public: String get_OutputFile();
  public: EventPipeSerializationFormat get_Format();
  public: UInt32 get_CircularBufferSizeInMB();
  public: Array<EventPipeProviderConfiguration> get_Providers();
  public: void ctor(String outputFile, EventPipeSerializationFormat format, UInt32 circularBufferSizeInMB);
  public: void EnableProvider(String providerName, UInt64 keywords, UInt32 loggingLevel);
  public: void EnableProviderWithFilter(String providerName, UInt64 keywords, UInt32 loggingLevel, String filterData);
  private: void EnableProviderConfiguration(EventPipeProviderConfiguration providerConfig);
  public: void EnableProviderRange(Array<EventPipeProviderConfiguration> providerConfigs);
  public: void SetProfilerSamplingRate(TimeSpan minTimeBetweenSamples);
  private: String m_outputFile;
  private: EventPipeSerializationFormat m_format;
  private: UInt32 m_circularBufferSizeInMB;
  private: List<EventPipeProviderConfiguration> m_providers;
  private: TimeSpan m_minTimeBetweenSamples;
};
} // namespace EventPipeConfigurationNamespace
using EventPipeConfiguration = EventPipeConfigurationNamespace::EventPipeConfiguration;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
