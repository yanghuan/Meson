#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Char)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Loader {
FORWARD(AssemblyLoadContext)
} // namespace System::Private::CoreLib::System::Runtime::Loader
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IActivationFactory)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::Internal::Runtime::InteropServices::WindowsRuntime {
namespace ActivationFactoryLoaderNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime;
using namespace ::System::Private::CoreLib::System::Runtime::Loader;
class ActivationFactoryLoader {
  private: static AssemblyLoadContext GetALC(String assemblyPath);
  public: static Int32 GetActivationFactory(Char* componentPath, String typeName, IActivationFactory& activationFactory);
  private: static Dictionary<String, AssemblyLoadContext> s_assemblyLoadContexts;
};
} // namespace ActivationFactoryLoaderNamespace
using ActivationFactoryLoader = ActivationFactoryLoaderNamespace::ActivationFactoryLoader;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::WindowsRuntime
