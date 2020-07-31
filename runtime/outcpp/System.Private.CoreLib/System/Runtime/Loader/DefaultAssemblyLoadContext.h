#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext.h>

namespace System::Private::CoreLib::System::Runtime::Loader {
namespace DefaultAssemblyLoadContextNamespace {
CLASS(DefaultAssemblyLoadContext) : public AssemblyLoadContext::in {
  public: void Ctor();
  private: static void SCtor();
  public: static AssemblyLoadContext s_loadContext;
};
} // namespace DefaultAssemblyLoadContextNamespace
using DefaultAssemblyLoadContext = DefaultAssemblyLoadContextNamespace::DefaultAssemblyLoadContext;
} // namespace System::Private::CoreLib::System::Runtime::Loader
