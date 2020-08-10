#include "CounterGroup-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/CounterGroup-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::CounterGroupNamespace {
void CounterGroup___::ctor(EventSource eventSource) {
}

void CounterGroup___::Add(DiagnosticCounter eventCounter) {
}

void CounterGroup___::Remove(DiagnosticCounter eventCounter) {
}

void CounterGroup___::RegisterCommandCallback() {
}

void CounterGroup___::OnEventSourceCommand(Object sender, EventCommandEventArgs e) {
}

void CounterGroup___::EnsureEventSourceIndexAvailable(Int32 eventSourceIndex) {
}

CounterGroup CounterGroup___::GetCounterGroup(EventSource eventSource) {
  return nullptr;
}

void CounterGroup___::EnableTimer(Single pollingIntervalInSeconds) {
}

void CounterGroup___::DisableTimer() {
}

void CounterGroup___::ResetCounters() {
}

void CounterGroup___::OnTimer() {
}

void CounterGroup___::PollForValues() {
}

void CounterGroup___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::CounterGroupNamespace
