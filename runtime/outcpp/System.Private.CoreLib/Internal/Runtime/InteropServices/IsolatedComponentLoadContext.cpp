#include "IsolatedComponentLoadContext-dep.h"

#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyDependencyResolver-dep.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::IsolatedComponentLoadContextNamespace {
using namespace System::Runtime::Loader;

void IsolatedComponentLoadContext___::ctor(String componentAssemblyPath) {
  _resolver = rt::newobj<AssemblyDependencyResolver>(componentAssemblyPath);
}

Assembly IsolatedComponentLoadContext___::Load(AssemblyName assemblyName) {
  String text = _resolver->ResolveAssemblyToPath(assemblyName);
  if (text != nullptr) {
    return LoadFromAssemblyPath(text);
  }
  return nullptr;
}

IntPtr IsolatedComponentLoadContext___::LoadUnmanagedDll(String unmanagedDllName) {
  String text = _resolver->ResolveUnmanagedDllToPath(unmanagedDllName);
  if (text != nullptr) {
    return LoadUnmanagedDllFromPath(text);
  }
  return IntPtr::Zero;
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::IsolatedComponentLoadContextNamespace
