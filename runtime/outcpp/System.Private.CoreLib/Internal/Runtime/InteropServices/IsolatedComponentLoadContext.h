#pragma once

#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(AssemblyName)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::Loader {
FORWARD(AssemblyDependencyResolver)
} // namespace System::Private::CoreLib::System::Runtime::Loader
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace IsolatedComponentLoadContextNamespace {
using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::Loader;
CLASS(IsolatedComponentLoadContext) : public AssemblyLoadContext::in {
  public: void ctor(String componentAssemblyPath);
  protected: Assembly Load(AssemblyName assemblyName);
  protected: IntPtr LoadUnmanagedDll(String unmanagedDllName);
  private: AssemblyDependencyResolver _resolver;
};
} // namespace IsolatedComponentLoadContextNamespace
using IsolatedComponentLoadContext = IsolatedComponentLoadContextNamespace::IsolatedComponentLoadContext;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
