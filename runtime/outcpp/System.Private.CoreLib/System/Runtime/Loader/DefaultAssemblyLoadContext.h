#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Loader {
FORWARD(AssemblyLoadContext)
namespace DefaultAssemblyLoadContextNamespace {
CLASS(DefaultAssemblyLoadContext) {
  public: void Ctor();
  private: static void SCtor();
  public: static AssemblyLoadContext s_loadContext;
};
} // namespace DefaultAssemblyLoadContextNamespace
using DefaultAssemblyLoadContext = DefaultAssemblyLoadContextNamespace::DefaultAssemblyLoadContext;
} // namespace System::Private::CoreLib::System::Runtime::Loader
