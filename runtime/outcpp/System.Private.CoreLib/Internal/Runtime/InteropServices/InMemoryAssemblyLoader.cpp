#include "InMemoryAssemblyLoader-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/InteropServices/IsolatedComponentLoadContext-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::InMemoryAssemblyLoaderNamespace {
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Loader;

void InMemoryAssemblyLoader::LoadInMemoryAssembly(IntPtr moduleHandle, IntPtr assemblyPath) {
  String text = Marshal::PtrToStringUni(assemblyPath);
  if (text == nullptr) {
    rt::throw_exception<ArgumentOutOfRangeException>("assemblyPath");
  }
  AssemblyLoadContext assemblyLoadContext = rt::newobj<IsolatedComponentLoadContext>(text);
  assemblyLoadContext->LoadFromInMemoryModule(moduleHandle);
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::InMemoryAssemblyLoaderNamespace
