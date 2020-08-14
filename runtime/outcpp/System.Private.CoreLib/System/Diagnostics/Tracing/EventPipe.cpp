#include "EventPipe-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeInternal-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeProviderConfiguration-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeNamespace {
void EventPipe::Enable(EventPipeConfiguration configuration) {
  if (configuration == nullptr) {
    rt::throw_exception<ArgumentNullException>("configuration");
  }
  if (configuration->get_Providers() == nullptr) {
    rt::throw_exception<ArgumentNullException>("Providers");
  }
  Array<EventPipeProviderConfiguration> providers = configuration->get_Providers();
  s_sessionID = EventPipeInternal::Enable(configuration->get_OutputFile(), configuration->get_Format(), configuration->get_CircularBufferSizeInMB(), providers);
}

void EventPipe::Disable() {
  EventPipeInternal::Disable(s_sessionID);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeNamespace
