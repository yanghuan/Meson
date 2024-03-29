#pragma once

#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipeProviderConfigurationNamespace {
struct EventPipeProviderConfiguration : public valueType<EventPipeProviderConfiguration> {
  public: String get_ProviderName();
  public: UInt64 get_Keywords();
  public: UInt32 get_LoggingLevel();
  public: String get_FilterData();
  public: explicit EventPipeProviderConfiguration(String providerName, UInt64 keywords, UInt32 loggingLevel, String filterData);
  public: explicit EventPipeProviderConfiguration() {}
  private: String m_providerName;
  private: UInt64 m_keywords;
  private: UInt32 m_loggingLevel;
  private: String m_filterData;
};
} // namespace EventPipeProviderConfigurationNamespace
using EventPipeProviderConfiguration = EventPipeProviderConfigurationNamespace::EventPipeProviderConfiguration;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
