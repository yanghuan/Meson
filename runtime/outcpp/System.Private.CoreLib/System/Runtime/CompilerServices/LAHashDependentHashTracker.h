#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace LAHashDependentHashTrackerNamespace {
using namespace System::Runtime::InteropServices;
CLASS(LAHashDependentHashTracker) : public Object::in {
  protected: void Finalize();
  public: void ctor();
  private: GCHandle _dependentHandle;
  private: IntPtr _loaderAllocator;
};
} // namespace LAHashDependentHashTrackerNamespace
using LAHashDependentHashTracker = LAHashDependentHashTrackerNamespace::LAHashDependentHashTracker;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
