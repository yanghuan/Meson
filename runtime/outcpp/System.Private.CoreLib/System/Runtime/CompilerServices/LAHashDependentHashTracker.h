#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace LAHashDependentHashTrackerNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
CLASS(LAHashDependentHashTracker) {
  protected: void Finalize();
  private: GCHandle _dependentHandle;
  private: IntPtr _loaderAllocator;
};
} // namespace LAHashDependentHashTrackerNamespace
using LAHashDependentHashTracker = LAHashDependentHashTrackerNamespace::LAHashDependentHashTracker;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
