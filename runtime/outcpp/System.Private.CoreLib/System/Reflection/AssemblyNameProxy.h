#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
namespace AssemblyNameProxyNamespace {
CLASS(AssemblyNameProxy) {
  public: AssemblyName GetAssemblyName(String assemblyFile);
  public: void Ctor();
};
} // namespace AssemblyNameProxyNamespace
using AssemblyNameProxy = AssemblyNameProxyNamespace::AssemblyNameProxy;
} // namespace System::Private::CoreLib::System::Reflection
