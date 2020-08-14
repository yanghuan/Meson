#include "LoaderAllocator-dep.h"

#include <System.Private.CoreLib/System/Reflection/LoaderAllocatorScout-dep.h>

namespace System::Private::CoreLib::System::Reflection::LoaderAllocatorNamespace {
void LoaderAllocator___::ctor() {
  m_slots = rt::newarr<Array<Object>>(5);
  m_scout = rt::newobj<LoaderAllocatorScout>();
}

} // namespace System::Private::CoreLib::System::Reflection::LoaderAllocatorNamespace
