#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(AsyncCallback)
FORWARD(Object)
FORWARD(IAsyncResult)
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Loader {
namespace AssemblyDependencyResolverNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(AssemblyDependencyResolver) {
  public: CLASS(corehost_resolve_component_dependencies_result_fn) {
    public: void Invoke(String assembly_paths, String native_search_paths, String resource_search_paths);
    public: IAsyncResult BeginInvoke(String assembly_paths, String native_search_paths, String resource_search_paths, AsyncCallback callback, Object object);
    public: void EndInvoke(IAsyncResult result);
  };
  public: CLASS(corehost_error_writer_fn) {
    public: void Invoke(String message);
    public: IAsyncResult BeginInvoke(String message, AsyncCallback callback, Object object);
    public: void EndInvoke(IAsyncResult result);
  };
  public: String ResolveAssemblyToPath(AssemblyName assemblyName);
  public: String ResolveUnmanagedDllToPath(String unmanagedDllName);
  private: static Array<String> SplitPathsList(String pathsList);
  private: static Int32 corehost_resolve_component_dependencies(String component_main_assembly_path, corehost_resolve_component_dependencies_result_fn result);
  private: static IntPtr corehost_set_error_writer(IntPtr error_writer);
  private: Dictionary<String, String> _assemblyPaths;
  private: Array<String> _nativeSearchPaths;
  private: Array<String> _resourceSearchPaths;
  private: Array<String> _assemblyDirectorySearchPaths;
};
} // namespace AssemblyDependencyResolverNamespace
using AssemblyDependencyResolver = AssemblyDependencyResolverNamespace::AssemblyDependencyResolver;
} // namespace System::Private::CoreLib::System::Runtime::Loader
