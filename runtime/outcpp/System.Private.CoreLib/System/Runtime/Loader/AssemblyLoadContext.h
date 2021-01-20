#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Collections/Generic/List.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD_(Array)
FORWARD(AssemblyLoadEventHandler)
FORWARDS(Byte)
FORWARD_(Func)
FORWARDS(Guid)
FORWARD(IDisposable)
FORWARDS(ReadOnlySpan, T)
FORWARD(ResolveEventHandler)
FORWARD(String)
FORWARD_(WeakReference)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(AssemblyName)
FORWARD(RuntimeAssembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
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
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Threading;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(AssemblyLoadContext) : public object {
  private: enum class InternalState : int32_t {
    Alive = 0,
    Unloading = 1,
  };
  public: struct ContextualReflectionScope : public valueType<ContextualReflectionScope> {
    public: using interface = rt::TypeList<IDisposable>;
    public: explicit ContextualReflectionScope(AssemblyLoadContext activating);
    public: void Dispose();
    public: explicit ContextualReflectionScope() {}
    private: AssemblyLoadContext _activated;
    private: AssemblyLoadContext _predecessor;
    private: Boolean _initialized;
  };
  private: CLASS(_get_Assemblies_d__55) : public object {
    public: using interface = rt::TypeList<IEnumerable<Assembly>, IEnumerable_, IEnumerator<Assembly>, IDisposable, IEnumerator_>;
    private: Assembly get_CurrentOfAssembly();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: IEnumerator<Assembly> GetEnumeratorOfAssembly();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: Assembly __2__current;
    private: Int32 __l__initialThreadId;
    public: AssemblyLoadContext __4__this;
    private: Array<Assembly> __7__wrap1;
    private: Int32 __7__wrap2;
  };
  private: CLASS(_get_All_d__85) : public object {
    public: using interface = rt::TypeList<IEnumerable<AssemblyLoadContext>, IEnumerable_, IEnumerator<AssemblyLoadContext>, IDisposable, IEnumerator_>;
    private: AssemblyLoadContext get_CurrentOfAssemblyLoadContext();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void __m__Finally1();
    private: void ResetOfIEnumerator();
    private: IEnumerator<AssemblyLoadContext> GetEnumeratorOfAssemblyLoadContext();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: AssemblyLoadContext __2__current;
    private: Int32 __l__initialThreadId;
    private: List<WeakReference<AssemblyLoadContext>>::in::Enumerator __7__wrap1;
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
  private: static RuntimeAssembly GetRuntimeAssembly(Assembly asm一);
  private: static void StartAssemblyLoad(Guid& activityId, Guid& relatedActivityId);
  private: static void StopAssemblyLoad(Guid& activityId);
  private: static void InitializeDefaultContext();
  public: void ctor();
  public: void ctor(Boolean isCollectible);
  public: void ctor(String name, Boolean isCollectible = false);
  public: void ctor(Boolean representsTPALoadContext, Boolean isCollectible, String name);
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
  public: static void cctor();
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
