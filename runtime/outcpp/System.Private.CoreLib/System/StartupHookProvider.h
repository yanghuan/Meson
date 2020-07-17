#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace StartupHookProviderNamespace {
using namespace Reflection;
class StartupHookProvider {
  private: struct StartupHookNameOrPath {
    public: void Ctor();
    public: AssemblyName AssemblyName;
    public: String Path;
  };
  private: static void ProcessStartupHooks();
  private: static void CallStartupHook(StartupHookNameOrPath startupHook);
};
} // namespace StartupHookProviderNamespace
using StartupHookProvider = StartupHookProviderNamespace::StartupHookProvider;
} // namespace System::Private::CoreLib::System
