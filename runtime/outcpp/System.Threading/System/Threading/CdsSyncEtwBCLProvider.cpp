#include "CdsSyncEtwBCLProvider-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Threading/System/Threading/CdsSyncEtwBCLProvider-dep.h>

namespace System::Threading::System::Threading::CdsSyncEtwBCLProviderNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Diagnostics::Tracing;

void CdsSyncEtwBCLProvider___::ctor() {
}

void CdsSyncEtwBCLProvider___::Barrier_PhaseFinished(Boolean currentSense, Int64 phaseNum) {
  if (IsEnabled(EventLevel::Verbose, EventKeywords::All)) {
    EventSource::in::EventData default[2] = {};
    EventSource::in::EventData* ptr = default;
    Int32 num = currentSense ? 1 : 0;
    *ptr = EventSource::in::EventData();
    ptr[1] = EventSource::in::EventData();
    WriteEventCore(3, 2, ptr);
  }
}

void CdsSyncEtwBCLProvider___::cctor() {
  Log = rt::newobj<CdsSyncEtwBCLProvider>();
}

} // namespace System::Threading::System::Threading::CdsSyncEtwBCLProviderNamespace
