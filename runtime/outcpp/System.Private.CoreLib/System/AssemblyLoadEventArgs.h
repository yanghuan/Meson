#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
namespace AssemblyLoadEventArgsNamespace {
using namespace Reflection;
CLASS(AssemblyLoadEventArgs) {
  public: Assembly get_LoadedAssembly() { return LoadedAssembly; }
  private: Assembly LoadedAssembly;
};
} // namespace AssemblyLoadEventArgsNamespace
using AssemblyLoadEventArgs = AssemblyLoadEventArgsNamespace::AssemblyLoadEventArgs;
} // namespace System::Private::CoreLib::System
