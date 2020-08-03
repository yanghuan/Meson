#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Loader {
namespace AssemblyDependencyResolverNamespace {
using namespace Collections::Generic;
using namespace Reflection;
CLASS(AssemblyDependencyResolver) : public Object::in {
  public: void Ctor(String componentAssemblyPath);
  public: String ResolveAssemblyToPath(AssemblyName assemblyName);
  public: String ResolveUnmanagedDllToPath(String unmanagedDllName);
  private: static Array<String> SplitPathsList(String pathsList);
  private: Dictionary<String, String> _assemblyPaths;
  private: Array<String> _nativeSearchPaths;
  private: Array<String> _resourceSearchPaths;
  private: Array<String> _assemblyDirectorySearchPaths;
};
} // namespace AssemblyDependencyResolverNamespace
using AssemblyDependencyResolver = AssemblyDependencyResolverNamespace::AssemblyDependencyResolver;
} // namespace System::Private::CoreLib::System::Runtime::Loader
