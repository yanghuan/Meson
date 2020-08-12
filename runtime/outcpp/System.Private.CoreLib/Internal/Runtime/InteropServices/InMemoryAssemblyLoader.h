#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace InMemoryAssemblyLoaderNamespace {
using namespace System;
class InMemoryAssemblyLoader {
  public: static void LoadInMemoryAssembly(IntPtr moduleHandle, IntPtr assemblyPath);
};
} // namespace InMemoryAssemblyLoaderNamespace
using InMemoryAssemblyLoader = InMemoryAssemblyLoaderNamespace::InMemoryAssemblyLoader;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
