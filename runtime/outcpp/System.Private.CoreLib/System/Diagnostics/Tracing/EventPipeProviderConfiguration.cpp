#include "EventPipeProviderConfiguration-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeProviderConfigurationNamespace {
String EventPipeProviderConfiguration::get_ProviderName() {
  return nullptr;
};

UInt64 EventPipeProviderConfiguration::get_Keywords() {
  return UInt64();
};

UInt32 EventPipeProviderConfiguration::get_LoggingLevel() {
  return UInt32();
};

String EventPipeProviderConfiguration::get_FilterData() {
  return nullptr;
};

void EventPipeProviderConfiguration::Ctor(String providerName, UInt64 keywords, UInt32 loggingLevel, String filterData) {
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeProviderConfigurationNamespace
