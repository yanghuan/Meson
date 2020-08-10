#pragma once

#include <System.Private.CoreLib/System/MarshalByRefObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
namespace AssemblyNameProxyNamespace {
CLASS(AssemblyNameProxy) : public MarshalByRefObject::in {
  public: AssemblyName GetAssemblyName(String assemblyFile);
  public: void ctor();
};
} // namespace AssemblyNameProxyNamespace
using AssemblyNameProxy = AssemblyNameProxyNamespace::AssemblyNameProxy;
} // namespace System::Private::CoreLib::System::Reflection
