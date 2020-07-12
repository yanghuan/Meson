#include "EventPipeInternal-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeInternalNamespace {
void EventPipeInternal::EventPipeProviderConfigurationNative::MarshalToNative(EventPipeProviderConfiguration managed, EventPipeProviderConfigurationNative& native) {
};

void EventPipeInternal::EventPipeProviderConfigurationNative::Release() {
};

UInt64 EventPipeInternal::Enable(String outputFile, EventPipeSerializationFormat format, UInt32 circularBufferSizeInMB, Array<EventPipeProviderConfiguration> providers) {
  return UInt64();
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeInternalNamespace
