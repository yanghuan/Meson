#include "AssemblyLoadContext-dep.h"

#include <System.Private.CoreLib/Internal/IO/File-dep.h>
#include <System.Private.CoreLib/System/AppDomain-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/AssemblyLoadEventArgs-dep.h>
#include <System.Private.CoreLib/System/BadImageFormatException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Delegate-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ActivityTracker-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventActivityOptions.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NativeRuntimeEventSource-dep.h>
#include <System.Private.CoreLib/System/Func-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/IO/PathInternal-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/AssemblyBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>
#include <System.Private.CoreLib/System/ResolveEventArgs-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandleType.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/NativeLibrary-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/DefaultAssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocal-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/StackCrawlMark.h>
#include <System.Private.CoreLib/System/WeakReference-dep.h>

namespace System::Private::CoreLib::System::Runtime::Loader::AssemblyLoadContextNamespace {
using namespace Internal::IO;
using namespace System::Collections::Generic;
using namespace System::Diagnostics::Tracing;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Reflection::Emit;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

AssemblyLoadContext___::ContextualReflectionScope::ContextualReflectionScope(AssemblyLoadContext activating) {
  _predecessor = get_CurrentContextualReflectionContext();
  SetCurrentContextualReflectionContext(activating);
  _activated = activating;
  _initialized = true;
}

void AssemblyLoadContext___::ContextualReflectionScope::Dispose() {
  if (_initialized) {
    SetCurrentContextualReflectionContext(_predecessor);
  }
}

IEnumerable<Assembly> AssemblyLoadContext___::get_Assemblies() {
  Array<Assembly> loadedAssemblies = GetLoadedAssemblies();
}

AssemblyLoadContext AssemblyLoadContext___::get_Default() {
  return DefaultAssemblyLoadContext::in::s_loadContext;
}

Boolean AssemblyLoadContext___::get_IsCollectible() {
  return _isCollectible;
}

String AssemblyLoadContext___::get_Name() {
  return _name;
}

IEnumerable<AssemblyLoadContext> AssemblyLoadContext___::get_All() {
  AssemblyLoadContext default = get_Default();
  List<WeakReference<AssemblyLoadContext>> list = nullptr;
  {
    rt::lock(s_allContexts);
    list = rt::newobj<List<WeakReference<AssemblyLoadContext>>>(s_allContexts->get_Values());
  }
}

AssemblyLoadContext AssemblyLoadContext___::get_CurrentContextualReflectionContext() {
  auto& default = s_asyncLocalCurrent;
  return default == nullptr ? nullptr : default->get_Value();
}

Assembly AssemblyLoadContext___::InternalLoadFromPath(String assemblyPath, String nativeImagePath) {
  RuntimeAssembly o = nullptr;
  LoadFromPath(_nativeAssemblyLoadContext, assemblyPath, nativeImagePath, ObjectHandleOnStack::Create(o));
  return o;
}

Assembly AssemblyLoadContext___::InternalLoad(ReadOnlySpan<Byte> arrAssembly, ReadOnlySpan<Byte> arrSymbols) {
  RuntimeAssembly o = nullptr;
  {
    Byte* value = arrAssembly;
    {
      Byte* value2 = arrSymbols;
      LoadFromStream(_nativeAssemblyLoadContext, IntPtr(value), arrAssembly.get_Length(), IntPtr(value2), arrSymbols.get_Length(), ObjectHandleOnStack::Create(o));
    }
  }
  return o;
}

Assembly AssemblyLoadContext___::LoadFromInMemoryModule(IntPtr moduleHandle) {
  if (moduleHandle == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("moduleHandle");
  }
  {
    rt::lock(_unloadLock);
    VerifyIsAlive();
    RuntimeAssembly o = nullptr;
    LoadFromInMemoryModuleInternal(_nativeAssemblyLoadContext, moduleHandle, ObjectHandleOnStack::Create(o));
    return o;
  }
}

Assembly AssemblyLoadContext___::ResolveSatelliteAssembly(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName) {
  AssemblyLoadContext assemblyLoadContext = (AssemblyLoadContext)GCHandle::FromIntPtr(gchManagedAssemblyLoadContext).get_Target();
  return assemblyLoadContext->ResolveSatelliteAssembly(assemblyName);
}

IntPtr AssemblyLoadContext___::ResolveUnmanagedDll(String unmanagedDllName, IntPtr gchManagedAssemblyLoadContext) {
  AssemblyLoadContext assemblyLoadContext = (AssemblyLoadContext)GCHandle::FromIntPtr(gchManagedAssemblyLoadContext).get_Target();
  return assemblyLoadContext->LoadUnmanagedDll(unmanagedDllName);
}

IntPtr AssemblyLoadContext___::ResolveUnmanagedDllUsingEvent(String unmanagedDllName, Assembly assembly, IntPtr gchManagedAssemblyLoadContext) {
  AssemblyLoadContext assemblyLoadContext = (AssemblyLoadContext)GCHandle::FromIntPtr(gchManagedAssemblyLoadContext).get_Target();
  return assemblyLoadContext->GetResolvedUnmanagedDll(assembly, unmanagedDllName);
}

Assembly AssemblyLoadContext___::ResolveUsingResolvingEvent(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName) {
  AssemblyLoadContext assemblyLoadContext = (AssemblyLoadContext)GCHandle::FromIntPtr(gchManagedAssemblyLoadContext).get_Target();
  return assemblyLoadContext->ResolveUsingEvent(assemblyName);
}

AssemblyLoadContext AssemblyLoadContext___::GetLoadContext(Assembly assembly) {
  if (assembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
  AssemblyLoadContext result = nullptr;
  RuntimeAssembly runtimeAssembly = rt::as<RuntimeAssembly>(assembly);
  if (runtimeAssembly != nullptr) {
    RuntimeAssembly assembly2 = runtimeAssembly;
    IntPtr loadContextForAssembly = GetLoadContextForAssembly(QCallAssembly(assembly2));
    result = ((!(loadContextForAssembly == IntPtr::Zero)) ? ((AssemblyLoadContext)GCHandle::FromIntPtr(loadContextForAssembly).get_Target()) : get_Default());
  }
  return result;
}

void AssemblyLoadContext___::SetProfileOptimizationRoot(String directoryPath) {
  InternalSetProfileRoot(directoryPath);
}

void AssemblyLoadContext___::StartProfileOptimization(String profile) {
  InternalStartProfile(profile, _nativeAssemblyLoadContext);
}

RuntimeAssembly AssemblyLoadContext___::GetRuntimeAssembly(Assembly asm_) {
  if (!(asm == nullptr)) {
    RuntimeAssembly runtimeAssembly = rt::as<RuntimeAssembly>(asm);
    if ((Object)runtimeAssembly == nullptr) {
      auto& default = (rt::as<AssemblyBuilder>(asm));
      return default == nullptr ? nullptr : default->get_InternalAssembly();
    }
    return runtimeAssembly;
  }
  return nullptr;
}

void AssemblyLoadContext___::StartAssemblyLoad(Guid& activityId, Guid& relatedActivityId) {
  ActivityTracker::in::get_Instance()->Enable();
  ActivityTracker::in::get_Instance()->OnStart(NativeRuntimeEventSource::in::Log->get_Name(), "AssemblyLoad", 0, activityId, relatedActivityId, EventActivityOptions::Recursive, false);
}

void AssemblyLoadContext___::StopAssemblyLoad(Guid& activityId) {
  ActivityTracker::in::get_Instance()->OnStop(NativeRuntimeEventSource::in::Log->get_Name(), "AssemblyLoad", 0, activityId, false);
}

void AssemblyLoadContext___::InitializeDefaultContext() {
  AssemblyLoadContext default = get_Default();
}

void AssemblyLoadContext___::ctor() {
}

void AssemblyLoadContext___::ctor(Boolean isCollectible) {
}

void AssemblyLoadContext___::ctor(String name, Boolean isCollectible) {
}

void AssemblyLoadContext___::ctor(Boolean representsTPALoadContext, Boolean isCollectible, String name) {
  _isCollectible = isCollectible;
  _name = name;
  _unloadLock = rt::newobj<Object>();
  if (!isCollectible) {
    GC::SuppressFinalize((AssemblyLoadContext)this);
  }
  GCHandle value = GCHandle::Alloc((AssemblyLoadContext)this, get_IsCollectible() ? GCHandleType::WeakTrackResurrection : GCHandleType::Normal);
  IntPtr ptrAssemblyLoadContext = GCHandle::ToIntPtr(value);
  _nativeAssemblyLoadContext = InitializeAssemblyLoadContext(ptrAssemblyLoadContext, representsTPALoadContext, isCollectible);
  {
    rt::lock(s_allContexts);
    _id = s_nextId++;
    s_allContexts->Add(_id, rt::newobj<WeakReference<AssemblyLoadContext>>((AssemblyLoadContext)this, true));
  }
}

void AssemblyLoadContext___::Finalize() {
  if (_unloadLock != nullptr) {
    InitiateUnload();
  }
}

void AssemblyLoadContext___::RaiseUnloadEvent() {
}

void AssemblyLoadContext___::InitiateUnload() {
  RaiseUnloadEvent();
  {
    rt::lock(_unloadLock);
    GCHandle value = GCHandle::Alloc((AssemblyLoadContext)this, GCHandleType::Normal);
    IntPtr ptrAssemblyLoadContextStrong = GCHandle::ToIntPtr(value);
    PrepareForAssemblyLoadContextRelease(_nativeAssemblyLoadContext, ptrAssemblyLoadContextStrong);
    _state = InternalState::Unloading;
  }
  {
    rt::lock(s_allContexts);
    s_allContexts->Remove(_id);
  }
}

String AssemblyLoadContext___::ToString() {
  return """ + get_Name() + "" " + GetType()->ToString() + " #" + _id;
}

AssemblyName AssemblyLoadContext___::GetAssemblyName(String assemblyPath) {
  if (assemblyPath == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyPath");
  }
  return AssemblyName::in::GetAssemblyName(assemblyPath);
}

Assembly AssemblyLoadContext___::Load(AssemblyName assemblyName) {
  return nullptr;
}

Assembly AssemblyLoadContext___::LoadFromAssemblyName(AssemblyName assemblyName) {
  if (assemblyName == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyName");
  }
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return RuntimeAssembly::in::InternalLoad(assemblyName, stackMark, (AssemblyLoadContext)this);
}

Assembly AssemblyLoadContext___::LoadFromAssemblyPath(String assemblyPath) {
  if (assemblyPath == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyPath");
  }
  if (PathInternal::IsPartiallyQualified(assemblyPath)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_AbsolutePathRequired(), assemblyPath), "assemblyPath");
  }
  {
    rt::lock(_unloadLock);
    VerifyIsAlive();
    return InternalLoadFromPath(assemblyPath, nullptr);
  }
}

Assembly AssemblyLoadContext___::LoadFromNativeImagePath(String nativeImagePath, String assemblyPath) {
  if (nativeImagePath == nullptr) {
    rt::throw_exception<ArgumentNullException>("nativeImagePath");
  }
  if (PathInternal::IsPartiallyQualified(nativeImagePath)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_AbsolutePathRequired(), nativeImagePath), "nativeImagePath");
  }
  if (assemblyPath != nullptr && PathInternal::IsPartiallyQualified(assemblyPath)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_AbsolutePathRequired(), assemblyPath), "assemblyPath");
  }
  {
    rt::lock(_unloadLock);
    VerifyIsAlive();
    return InternalLoadFromPath(assemblyPath, nativeImagePath);
  }
}

Assembly AssemblyLoadContext___::LoadFromStream(Stream assembly) {
  return LoadFromStream(assembly, nullptr);
}

Assembly AssemblyLoadContext___::LoadFromStream(Stream assembly, Stream assemblySymbols) {
  if (assembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
  Int32 num = (Int32)assembly->get_Length();
  if (num <= 0) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_BadILFormat());
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(num);
  assembly->Read(array, 0, num);
  Array<Byte> array2 = nullptr;
  if (assemblySymbols != nullptr) {
    Int32 num2 = (Int32)assemblySymbols->get_Length();
    array2 = rt::newarr<Array<Byte>>(num2);
    assemblySymbols->Read(array2, 0, num2);
  }
  {
    rt::lock(_unloadLock);
    VerifyIsAlive();
    return InternalLoad(array, array2);
  }
}

IntPtr AssemblyLoadContext___::LoadUnmanagedDllFromPath(String unmanagedDllPath) {
  if (unmanagedDllPath == nullptr) {
    rt::throw_exception<ArgumentNullException>("unmanagedDllPath");
  }
  if (unmanagedDllPath->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyPath(), "unmanagedDllPath");
  }
  if (PathInternal::IsPartiallyQualified(unmanagedDllPath)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_AbsolutePathRequired(), unmanagedDllPath), "unmanagedDllPath");
  }
  return NativeLibrary::Load(unmanagedDllPath);
}

IntPtr AssemblyLoadContext___::LoadUnmanagedDll(String unmanagedDllName) {
  return IntPtr::Zero;
}

void AssemblyLoadContext___::Unload() {
  if (!get_IsCollectible()) {
    rt::throw_exception<InvalidOperationException>(SR::get_AssemblyLoadContext_Unload_CannotUnloadIfNotCollectible());
  }
  GC::SuppressFinalize((AssemblyLoadContext)this);
  InitiateUnload();
}

void AssemblyLoadContext___::OnProcessExit() {
  {
    rt::lock(s_allContexts);
  }
}

void AssemblyLoadContext___::VerifyIsAlive() {
  if (_state != 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_AssemblyLoadContext_Verify_NotUnloading());
  }
}

void AssemblyLoadContext___::SetCurrentContextualReflectionContext(AssemblyLoadContext value) {
  if (s_asyncLocalCurrent == nullptr) {
    Interlocked::CompareExchange(s_asyncLocalCurrent, rt::newobj<AsyncLocal<AssemblyLoadContext>>(), (AsyncLocal<AssemblyLoadContext>)nullptr);
  }
  s_asyncLocalCurrent->set_Value(value);
}

AssemblyLoadContext::in::ContextualReflectionScope AssemblyLoadContext___::EnterContextualReflection() {
  return ContextualReflectionScope((AssemblyLoadContext)this);
}

AssemblyLoadContext::in::ContextualReflectionScope AssemblyLoadContext___::EnterContextualReflection(Assembly activating) {
  if (activating == nullptr) {
    return ContextualReflectionScope(nullptr);
  }
  AssemblyLoadContext loadContext = GetLoadContext(activating);
  if (loadContext == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeRuntimeAssembly(), "activating");
  }
  return loadContext->EnterContextualReflection();
}

Assembly AssemblyLoadContext___::Resolve(IntPtr gchManagedAssemblyLoadContext, AssemblyName assemblyName) {
  AssemblyLoadContext assemblyLoadContext = (AssemblyLoadContext)GCHandle::FromIntPtr(gchManagedAssemblyLoadContext).get_Target();
  return assemblyLoadContext->ResolveUsingLoad(assemblyName);
}

Assembly AssemblyLoadContext___::GetFirstResolvedAssemblyFromResolvingEvent(AssemblyName assemblyName) {
  Assembly assembly = nullptr;
}

Assembly AssemblyLoadContext___::ValidateAssemblyNameWithSimpleName(Assembly assembly, String requestedSimpleName) {
  if (String::in::IsNullOrEmpty(requestedSimpleName)) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentNull_AssemblyNameName());
  }
  String value = nullptr;
  RuntimeAssembly runtimeAssembly = rt::as<RuntimeAssembly>(assembly);
  if (runtimeAssembly != nullptr) {
    value = runtimeAssembly->GetSimpleName();
  }
  if (String::in::IsNullOrEmpty(value) || !requestedSimpleName->Equals(value, StringComparison::InvariantCultureIgnoreCase)) {
    rt::throw_exception<InvalidOperationException>(SR::get_Argument_CustomAssemblyLoadContextRequestedNameMismatch());
  }
  return assembly;
}

Assembly AssemblyLoadContext___::ResolveUsingLoad(AssemblyName assemblyName) {
  String name = assemblyName->get_Name();
  Assembly assembly = Load(assemblyName);
  if (assembly != nullptr) {
    assembly = ValidateAssemblyNameWithSimpleName(assembly, name);
  }
  return assembly;
}

Assembly AssemblyLoadContext___::ResolveUsingEvent(AssemblyName assemblyName) {
  String name = assemblyName->get_Name();
  Assembly assembly = GetFirstResolvedAssemblyFromResolvingEvent(assemblyName);
  if (assembly != nullptr) {
    assembly = ValidateAssemblyNameWithSimpleName(assembly, name);
  }
  return assembly;
}

void AssemblyLoadContext___::OnAssemblyLoad(RuntimeAssembly assembly) {
}

RuntimeAssembly AssemblyLoadContext___::OnResourceResolve(RuntimeAssembly assembly, String resourceName) {
}

RuntimeAssembly AssemblyLoadContext___::OnTypeResolve(RuntimeAssembly assembly, String typeName) {
}

RuntimeAssembly AssemblyLoadContext___::OnAssemblyResolve(RuntimeAssembly assembly, String assemblyFullName) {
}

RuntimeAssembly AssemblyLoadContext___::InvokeResolveEvent(ResolveEventHandler eventHandler, RuntimeAssembly assembly, String name) {
  if (eventHandler == nullptr) {
    return nullptr;
  }
  ResolveEventArgs args = rt::newobj<ResolveEventArgs>(name, assembly);
  Array<Delegate> invocationList = eventHandler->GetInvocationList();
  for (Int32 i = 0; i < invocationList->get_Length(); i++) {
    ResolveEventHandler resolveEventHandler = (ResolveEventHandler)invocationList[i];
    Assembly assembly2 = resolveEventHandler(AppDomain::in::get_CurrentDomain(), args);
  }
  return nullptr;
}

Assembly AssemblyLoadContext___::ResolveSatelliteAssembly(AssemblyName assemblyName) {
  if (assemblyName->get_Name() == nullptr || !assemblyName->get_Name()->EndsWith(".resources", StringComparison::Ordinal)) {
    return nullptr;
  }
  String assemblyName2 = assemblyName->get_Name()->Substring(0, assemblyName->get_Name()->get_Length() - ".resources"->get_Length());
  Assembly assembly = LoadFromAssemblyName(rt::newobj<AssemblyName>(assemblyName2));
  AssemblyLoadContext loadContext = GetLoadContext(assembly);
  String directoryName = Path::GetDirectoryName(assembly->get_Location());
  String text = Path::Combine(directoryName, assemblyName->get_CultureName(), assemblyName->get_Name() + ".dll");
  Boolean flag = File::InternalExists(text);
  if (flag || Path::get_IsCaseSensitive()) {
  }
  Assembly result = flag ? loadContext->LoadFromAssemblyPath(text) : nullptr;
  if (IsTracingEnabled()) {
    TraceSatelliteSubdirectoryPathProbed(text, (!flag) ? (-2147024894) : 0);
  }
  return result;
}

IntPtr AssemblyLoadContext___::GetResolvedUnmanagedDll(Assembly assembly, String unmanagedDllName) {
  IntPtr zero = IntPtr::Zero;
}

void AssemblyLoadContext___::cctor() {
  s_allContexts = rt::newobj<Dictionary<Int64, WeakReference<AssemblyLoadContext>>>();
}

} // namespace System::Private::CoreLib::System::Runtime::Loader::AssemblyLoadContextNamespace
