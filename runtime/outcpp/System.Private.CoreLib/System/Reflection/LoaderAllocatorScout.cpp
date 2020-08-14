#include "LoaderAllocatorScout-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Reflection/LoaderAllocatorScout-dep.h>

namespace System::Private::CoreLib::System::Reflection::LoaderAllocatorScoutNamespace {
void LoaderAllocatorScout___::Finalize() {
  if (!(m_nativeLoaderAllocator == IntPtr::Zero) && !Destroy(m_nativeLoaderAllocator)) {
    GC::ReRegisterForFinalize((LoaderAllocatorScout)this);
  }
}

void LoaderAllocatorScout___::ctor() {
}

} // namespace System::Private::CoreLib::System::Reflection::LoaderAllocatorScoutNamespace
