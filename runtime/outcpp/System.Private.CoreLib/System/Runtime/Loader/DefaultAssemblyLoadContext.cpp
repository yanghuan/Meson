#include "DefaultAssemblyLoadContext-dep.h"

#include <System.Private.CoreLib/System/Runtime/Loader/DefaultAssemblyLoadContext-dep.h>

namespace System::Private::CoreLib::System::Runtime::Loader::DefaultAssemblyLoadContextNamespace {
void DefaultAssemblyLoadContext___::ctor() {
}

void DefaultAssemblyLoadContext___::cctor() {
  s_loadContext = rt::newobj<DefaultAssemblyLoadContext>();
}

} // namespace System::Private::CoreLib::System::Runtime::Loader::DefaultAssemblyLoadContextNamespace
