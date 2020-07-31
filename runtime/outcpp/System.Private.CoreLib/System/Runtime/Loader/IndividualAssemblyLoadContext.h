#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Loader {
namespace IndividualAssemblyLoadContextNamespace {
CLASS(IndividualAssemblyLoadContext) : public AssemblyLoadContext::in {
  public: void Ctor(String name);
};
} // namespace IndividualAssemblyLoadContextNamespace
using IndividualAssemblyLoadContext = IndividualAssemblyLoadContextNamespace::IndividualAssemblyLoadContext;
} // namespace System::Private::CoreLib::System::Runtime::Loader
