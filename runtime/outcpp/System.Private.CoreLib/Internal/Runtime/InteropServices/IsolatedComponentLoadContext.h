#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(AssemblyName)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Loader {
FORWARD(AssemblyDependencyResolver)
} // namespace System::Private::CoreLib::System::Runtime::Loader
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace IsolatedComponentLoadContextNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::Loader;
CLASS(IsolatedComponentLoadContext) {
  protected: Assembly Load(AssemblyName assemblyName);
  protected: IntPtr LoadUnmanagedDll(String unmanagedDllName);
  private: AssemblyDependencyResolver _resolver;
};
} // namespace IsolatedComponentLoadContextNamespace
using IsolatedComponentLoadContext = IsolatedComponentLoadContextNamespace::IsolatedComponentLoadContext;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
