#include "EventPipeProviderConfiguration-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeProviderConfigurationNamespace {
String EventPipeProviderConfiguration::get_ProviderName() {
  return m_providerName;
}

UInt64 EventPipeProviderConfiguration::get_Keywords() {
  return m_keywords;
}

UInt32 EventPipeProviderConfiguration::get_LoggingLevel() {
  return m_loggingLevel;
}

String EventPipeProviderConfiguration::get_FilterData() {
  return m_filterData;
}

EventPipeProviderConfiguration::EventPipeProviderConfiguration(String providerName, UInt64 keywords, UInt32 loggingLevel, String filterData) {
  if (String::in::IsNullOrEmpty(providerName)) {
    rt::throw_exception<ArgumentNullException>("providerName");
  }
  if (loggingLevel > 5) {
    rt::throw_exception<ArgumentOutOfRangeException>("loggingLevel");
  }
  m_providerName = providerName;
  m_keywords = keywords;
  m_loggingLevel = loggingLevel;
  m_filterData = filterData;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeProviderConfigurationNamespace
