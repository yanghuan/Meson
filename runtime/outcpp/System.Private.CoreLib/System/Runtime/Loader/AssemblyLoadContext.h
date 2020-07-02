#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(AssemblyName)
FORWARD(RuntimeAssembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARD_(Array, T1, T2)
FORWARD(AssemblyLoadEventHandler)
FORWARDS(Byte)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARD(ResolveEventHandler)
FORWARD(String)
FORWARD(Type)
FORWARD_(WeakReference, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(QCallAssembly)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Threading {
FORWARD(AsyncLocal, T)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::Loader {
namespace AssemblyLoadContextNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(AssemblyLoadContext) {
  private: enum class InternalState {
    Alive = 0,
    Unloading = 1,
  };
  public: struct ContextualReflectionScope {
    public: void Dispose();
    private: AssemblyLoadContext _activated;
    private: AssemblyLoadContext _predecessor;
    private: Boolean _initialized;
  };
  public: IEnumerable<Assembly> get_Assemblies();
  public: static AssemblyLoadContext get_Default();
  public: Boolean get_IsCollectible();
  public: String get_Name();
  public: static IEnumerable<AssemblyLoadContext> get_All();
  public: static AssemblyLoadContext get_CurrentContextualReflectionContext();
  private: static IntPtr InitializeAssemblyLoadContext(IntPtr ptrAssemblyLoadContext, Boolean fRepresentsTPALoadContext, Boolean isCollectible);
  private: static void PrepareForAssemblyLoadContextRelease(IntPtr ptrNativeAssemblyLoadContext, IntPtr ptrAssemblyLoadContextStrong);
  private: static IntPtr LoadFromStream(IntPtr ptrNativeAssemblyLoadContext, IntPtr ptrAssemblyArray, Int32 iAssemblyArrayLen, IntPtr ptrSymbols, Int32 iSymbolArrayLen, ObjectHandleOnStack retAssembly);
  public: static void InternalSetProfileRoot(String directoryPath);
  public: static void InternalStartProfile(String profile, IntPtr ptrNativeAssemblyLoadContext);
  private: static void LoadFromPath(IntPtr ptrNativeAssemblyLoadContext, String ilPath, String niPath, ObjectHandleOnStack retAssembly);
  public: static Array<Assembly> GetLoadedAssemblies();
  private: Assembly InternalLoadFromPath(String assemblyPath, String nativeImagePath);
  public: Assembly InternalLoad(ReadOnlySpan<Byte> arrAssembly, ReadOnlySpan<Byte> arrSymbols);
  private: static IntPtr LoadFromInMemoryModuleInternal(IntPtr ptrNativeAssemblyLoadContext, IntPtr hModule, ObjectHandleOnStack retAssembly);
  public: Assembly LoadFromInMemoryModule(IntPtr moduleHandle);
  private: static Assembly Resolve(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName);
  private: static Assembly ResolveUsingResolvingEvent(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName);
  private: static Assembly ResolveSatelliteAssembly(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName);
  private: Assembly GetFirstResolvedAssembly(AssemblyName assemblyName);
  private: Assembly ValidateAssemblyNameWithSimpleName(Assembly assembly, String requestedSimpleName);
  private: Assembly ResolveUsingLoad(AssemblyName assemblyName);
  private: Assembly ResolveUsingEvent(AssemblyName assemblyName);
  private: static IntPtr InternalLoadUnmanagedDllFromPath(String unmanagedDllPath);
  private: static IntPtr ResolveUnmanagedDll(String unmanagedDllName, IntPtr gchManagedAssemblyLoadContext);
  private: static IntPtr ResolveUnmanagedDllUsingEvent(String unmanagedDllName, Assembly assembly, IntPtr gchManagedAssemblyLoadContext);
  private: IntPtr GetResolvedUnmanagedDll(Assembly assembly, String unmanagedDllName);
  private: static void LoadTypeForWinRTTypeNameInContextInternal(IntPtr ptrNativeAssemblyLoadContext, String typeName, ObjectHandleOnStack loadedType);
  public: Type LoadTypeForWinRTTypeNameInContext(String typeName);
  private: static IntPtr GetLoadContextForAssembly(QCallAssembly assembly);
  public: static AssemblyLoadContext GetLoadContext(Assembly assembly);
  public: void SetProfileOptimizationRoot(String directoryPath);
  public: void StartProfileOptimization(String profile);
  private: static void OnAssemblyLoad(RuntimeAssembly assembly);
  private: static RuntimeAssembly OnResourceResolve(RuntimeAssembly assembly, String resourceName);
  private: static RuntimeAssembly OnTypeResolve(RuntimeAssembly assembly, String typeName);
  private: static RuntimeAssembly OnAssemblyResolve(RuntimeAssembly assembly, String assemblyFullName);
  private: static RuntimeAssembly InvokeResolveEvent(ResolveEventHandler eventHandler, RuntimeAssembly assembly, String name);
  private: static RuntimeAssembly GetRuntimeAssembly(Assembly asm_);
  protected: void Finalize();
  private: void RaiseUnloadEvent();
  private: void InitiateUnload();
  public: String ToString();
  public: static AssemblyName GetAssemblyName(String assemblyPath);
  protected: Assembly Load(AssemblyName assemblyName);
  public: Assembly LoadFromAssemblyName(AssemblyName assemblyName);
  public: Assembly LoadFromAssemblyPath(String assemblyPath);
  public: Assembly LoadFromNativeImagePath(String nativeImagePath, String assemblyPath);
  public: Assembly LoadFromStream(Stream assembly);
  public: Assembly LoadFromStream(Stream assembly, Stream assemblySymbols);
  protected: IntPtr LoadUnmanagedDllFromPath(String unmanagedDllPath);
  protected: IntPtr LoadUnmanagedDll(String unmanagedDllName);
  public: void Unload();
  public: static void OnProcessExit();
  private: void VerifyIsAlive();
  private: static void SetCurrentContextualReflectionContext(AssemblyLoadContext value);
  public: ContextualReflectionScope EnterContextualReflection();
  public: static ContextualReflectionScope EnterContextualReflection(Assembly activating);
  private: Assembly ResolveSatelliteAssembly(AssemblyName assemblyName);
  private: static Dictionary<Int64, WeakReference<AssemblyLoadContext>> s_allContexts;
  private: static Int64 s_nextId;
  private: Object _unloadLock;
  private: Func<Assembly, String, IntPtr> _resolvingUnmanagedDll;
  private: Func<AssemblyLoadContext, AssemblyName, Assembly> _resolving;
  private: Action<AssemblyLoadContext> _unloading;
  private: String _name;
  private: IntPtr _nativeAssemblyLoadContext;
  private: Int64 _id;
  private: InternalState _state;
  private: Boolean _isCollectible;
  private: static AssemblyLoadEventHandler AssemblyLoad;
  private: static ResolveEventHandler TypeResolve;
  private: static ResolveEventHandler ResourceResolve;
  private: static ResolveEventHandler AssemblyResolve;
  private: static AsyncLocal<AssemblyLoadContext> s_asyncLocalCurrent;
};
} // namespace AssemblyLoadContextNamespace
using AssemblyLoadContext = AssemblyLoadContextNamespace::AssemblyLoadContext;
} // namespace System::Private::CoreLib::System::Runtime::Loader