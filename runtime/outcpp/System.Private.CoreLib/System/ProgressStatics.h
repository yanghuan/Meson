#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
namespace ProgressStaticsNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
class ProgressStatics {
  public: static SynchronizationContext DefaultContext;
};
} // namespace ProgressStaticsNamespace
using ProgressStatics = ProgressStaticsNamespace::ProgressStatics;
} // namespace System::Private::CoreLib::System