#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Threading::System::Threading {
namespace CdsSyncEtwBCLProviderNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Diagnostics::Tracing;
CLASS(CdsSyncEtwBCLProvider) : public EventSource::in {
  private: void ctor();
  public: void Barrier_PhaseFinished(Boolean currentSense, Int64 phaseNum);
  private: static void cctor();
  public: static CdsSyncEtwBCLProvider Log;
};
} // namespace CdsSyncEtwBCLProviderNamespace
using CdsSyncEtwBCLProvider = CdsSyncEtwBCLProviderNamespace::CdsSyncEtwBCLProvider;
} // namespace System::Threading::System::Threading
