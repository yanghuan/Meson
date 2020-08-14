#include "LAHashDependentHashTracker-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::LAHashDependentHashTrackerNamespace {
void LAHashDependentHashTracker___::Finalize() {
  if (_dependentHandle.get_IsAllocated()) {
    _dependentHandle.Free();
  }
}

void LAHashDependentHashTracker___::ctor() {
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::LAHashDependentHashTrackerNamespace
