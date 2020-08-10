#pragma once

#include <System.Private.CoreLib/System/EventArgs.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
namespace AssemblyLoadEventArgsNamespace {
using namespace Reflection;
CLASS(AssemblyLoadEventArgs) : public EventArgs::in {
  public: Assembly get_LoadedAssembly() { return LoadedAssembly; }
  public: void ctor(Assembly loadedAssembly);
  private: Assembly LoadedAssembly;
};
} // namespace AssemblyLoadEventArgsNamespace
using AssemblyLoadEventArgs = AssemblyLoadEventArgsNamespace::AssemblyLoadEventArgs;
} // namespace System::Private::CoreLib::System
