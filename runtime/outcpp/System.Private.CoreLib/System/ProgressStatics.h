#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
namespace ProgressStaticsNamespace {
using namespace Threading;
class ProgressStatics : public Object::in {
  private: static void SCtor();
  public: static SynchronizationContext DefaultContext;
};
} // namespace ProgressStaticsNamespace
using ProgressStatics = ProgressStaticsNamespace::ProgressStatics;
} // namespace System::Private::CoreLib::System
