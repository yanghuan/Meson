#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace LoaderAllocatorScoutNamespace {
CLASS(LoaderAllocatorScout) : public Object::in {
  private: static Boolean Destroy(IntPtr nativeLoaderAllocator);
  protected: void Finalize();
  public: void Ctor();
  public: IntPtr m_nativeLoaderAllocator;
};
} // namespace LoaderAllocatorScoutNamespace
using LoaderAllocatorScout = LoaderAllocatorScoutNamespace::LoaderAllocatorScout;
} // namespace System::Private::CoreLib::System::Reflection
