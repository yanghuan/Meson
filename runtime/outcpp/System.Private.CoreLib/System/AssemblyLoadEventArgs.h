#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
namespace AssemblyLoadEventArgsNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(AssemblyLoadEventArgs) {
  private: Assembly LoadedAssembly;
};
} // namespace AssemblyLoadEventArgsNamespace
using AssemblyLoadEventArgs = AssemblyLoadEventArgsNamespace::AssemblyLoadEventArgs;
} // namespace System::Private::CoreLib::System
