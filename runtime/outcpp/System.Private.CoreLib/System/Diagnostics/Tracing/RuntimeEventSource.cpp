#include "RuntimeEventSource-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IncrementingPollingCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PollingCounter-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/RuntimeEventSource-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::RuntimeEventSourceNamespace {
void RuntimeEventSource___::Initialize() {
  s_RuntimeEventSource = rt::newobj<RuntimeEventSource>();
}

void RuntimeEventSource___::ctor() {
}

void RuntimeEventSource___::OnEventCommand(EventCommandEventArgs command) {
  if (command->get_Command() != EventCommand::Enable) {
    return;
  }
  if (_cpuTimeCounter == nullptr) {
  }
  if (_workingSetCounter == nullptr) {
  }
  if (_gcHeapSizeCounter == nullptr) {
  }
  if (_gen0GCCounter == nullptr) {
  }
  if (_gen1GCCounter == nullptr) {
  }
  if (_gen2GCCounter == nullptr) {
  }
  if (_threadPoolThreadCounter == nullptr) {
  }
  if (_monitorContentionCounter == nullptr) {
  }
  if (_threadPoolQueueCounter == nullptr) {
  }
  if (_completedItemsCounter == nullptr) {
  }
  if (_allocRateCounter == nullptr) {
  }
  if (_timerCounter == nullptr) {
  }
  if (_exceptionCounter == nullptr) {
  }
  if (_gcTimeCounter == nullptr) {
  }
  if (_gen0SizeCounter == nullptr) {
  }
  if (_gen1SizeCounter == nullptr) {
  }
  if (_gen2SizeCounter == nullptr) {
  }
  if (_lohSizeCounter == nullptr) {
  }
  if (_pohSizeCounter == nullptr) {
  }
  if (_assemblyCounter == nullptr) {
  }
  if (_ilBytesJittedCounter == nullptr) {
  }
  if (_methodsJittedCounter == nullptr) {
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::RuntimeEventSourceNamespace
