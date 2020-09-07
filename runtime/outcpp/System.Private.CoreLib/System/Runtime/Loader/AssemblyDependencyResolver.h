#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Loader {
namespace AssemblyDependencyResolverNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Text;
CLASS(AssemblyDependencyResolver) : public object {
  private: CLASS(__c__DisplayClass6_0) : public object {
    public: void ctor();
    public: void _ctor_b__0(String message);
    public: void _ctor_b__1(String assemblyPaths, String nativeSearchPaths, String resourceSearchPaths);
    public: StringBuilder errorMessage;
    public: String assemblyPathsList;
    public: String nativeSearchPathsList;
    public: String resourceSearchPathsList;
  };
  public: void ctor(String componentAssemblyPath);
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
