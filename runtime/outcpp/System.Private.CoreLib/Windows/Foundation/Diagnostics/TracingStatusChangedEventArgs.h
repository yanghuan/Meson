#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Windows::Foundation::Diagnostics {
enum class CausalityTraceLevel;
namespace TracingStatusChangedEventArgsNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(TracingStatusChangedEventArgs) {
  public: Boolean get_Enabled();
  public: CausalityTraceLevel get_TraceLevel();
};
} // namespace TracingStatusChangedEventArgsNamespace
using TracingStatusChangedEventArgs = TracingStatusChangedEventArgsNamespace::TracingStatusChangedEventArgs;
} // namespace System::Private::CoreLib::Windows::Foundation::Diagnostics
