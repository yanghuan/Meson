#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace LoaderAllocatorScoutNamespace {
CLASS(LoaderAllocatorScout) {
  private: static Boolean Destroy(IntPtr nativeLoaderAllocator);
  protected: void Finalize();
  public: void Ctor();
  public: IntPtr m_nativeLoaderAllocator;
};
} // namespace LoaderAllocatorScoutNamespace
using LoaderAllocatorScout = LoaderAllocatorScoutNamespace::LoaderAllocatorScout;
} // namespace System::Private::CoreLib::System::Reflection
