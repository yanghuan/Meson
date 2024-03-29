#pragma once

#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext.h>

namespace System::Private::CoreLib::System::Runtime::Loader {
namespace DefaultAssemblyLoadContextNamespace {
CLASS(DefaultAssemblyLoadContext) : public AssemblyLoadContext::in {
  public: void ctor();
  public: static void cctor();
  public: static AssemblyLoadContext s_loadContext;
};
} // namespace DefaultAssemblyLoadContextNamespace
using DefaultAssemblyLoadContext = DefaultAssemblyLoadContextNamespace::DefaultAssemblyLoadContext;
} // namespace System::Private::CoreLib::System::Runtime::Loader
