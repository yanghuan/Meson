#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Windows::Foundation::Diagnostics {
enum class CausalityTraceLevel;
namespace ITracingStatusChangedEventArgsNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(ITracingStatusChangedEventArgs) {
  public: Boolean get_Enabled();
  public: CausalityTraceLevel get_TraceLevel();
};
} // namespace ITracingStatusChangedEventArgsNamespace
using ITracingStatusChangedEventArgs = ITracingStatusChangedEventArgsNamespace::ITracingStatusChangedEventArgs;
} // namespace System::Private::CoreLib::Windows::Foundation::Diagnostics
