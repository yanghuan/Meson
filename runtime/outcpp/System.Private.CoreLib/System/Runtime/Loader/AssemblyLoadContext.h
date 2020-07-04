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
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARD(AssemblyLoadEventHandler)
FORWARDS(Byte)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARD(ResolveEventHandler)
FORWARD(String)
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
  public: static Boolean IsTracingEnabled();
  public: static Boolean TraceResolvingHandlerInvoked(String assemblyName, String handlerName, String alcName, String resultAssemblyName, String resultAssemblyPath);
  public: static Boolean TraceAssemblyResolveHandlerInvoked(String assemblyName, String handlerName, String resultAssemblyName, String resultAssemblyPath);
  public: static Boolean TraceAssemblyLoadFromResolveHandlerInvoked(String assemblyName, Boolean isTrackedAssembly, String requestingAssemblyPath, String requestedAssemblyPath);
  public: static Boolean TraceSatelliteSubdirectoryPathProbed(String filePath, Int32 hResult);
  private: Assembly InternalLoadFromPath(String assemblyPath, String nativeImagePath);
  public: Assembly InternalLoad(ReadOnlySpan<Byte> arrAssembly, ReadOnlySpan<Byte> arrSymbols);
  private: static IntPtr LoadFromInMemoryModuleInternal(IntPtr ptrNativeAssemblyLoadContext, IntPtr hModule, ObjectHandleOnStack retAssembly);
  public: Assembly LoadFromInMemoryModule(IntPtr moduleHandle);
  private: static Assembly ResolveSatelliteAssembly(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName);
  private: static IntPtr ResolveUnmanagedDll(String unmanagedDllName, IntPtr gchManagedAssemblyLoadContext);
  private: static IntPtr ResolveUnmanagedDllUsingEvent(String unmanagedDllName, Assembly assembly, IntPtr gchManagedAssemblyLoadContext);
  private: static Assembly ResolveUsingResolvingEvent(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName);
  private: static IntPtr GetLoadContextForAssembly(QCallAssembly assembly);
  public: static AssemblyLoadContext GetLoadContext(Assembly assembly);
  public: void SetProfileOptimizationRoot(String directoryPath);
  public: void StartProfileOptimization(String profile);
  private: static RuntimeAssembly GetRuntimeAssembly(Assembly asm_);
  private: static void StartAssemblyLoad(Guid& activityId, Guid& relatedActivityId);
  private: static void StopAssemblyLoad(Guid& activityId);
  private: static void InitializeDefaultContext();
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
  private: static Assembly Resolve(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName);
  private: Assembly GetFirstResolvedAssemblyFromResolvingEvent(AssemblyName assemblyName);
  private: static Assembly ValidateAssemblyNameWithSimpleName(Assembly assembly, String requestedSimpleName);
  private: Assembly ResolveUsingLoad(AssemblyName assemblyName);
  private: Assembly ResolveUsingEvent(AssemblyName assemblyName);
  private: static void OnAssemblyLoad(RuntimeAssembly assembly);
  private: static RuntimeAssembly OnResourceResolve(RuntimeAssembly assembly, String resourceName);
  private: static RuntimeAssembly OnTypeResolve(RuntimeAssembly assembly, String typeName);
  private: static RuntimeAssembly OnAssemblyResolve(RuntimeAssembly assembly, String assemblyFullName);
  private: static RuntimeAssembly InvokeResolveEvent(ResolveEventHandler eventHandler, RuntimeAssembly assembly, String name);
  private: Assembly ResolveSatelliteAssembly(AssemblyName assemblyName);
  public: IntPtr GetResolvedUnmanagedDll(Assembly assembly, String unmanagedDllName);
  private: static String AssemblyLoadName;
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
