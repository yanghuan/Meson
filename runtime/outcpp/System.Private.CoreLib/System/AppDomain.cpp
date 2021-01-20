#include "AppDomain-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/AppContext-dep.h>
#include <System.Private.CoreLib/System/AppDomain-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/CannotUnloadAppDomainException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Func-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/GCMemoryInfo-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/MissingMethodException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/Security/Permissions/PermissionState.h>
#include <System.Private.CoreLib/System/Security/Principal/PrincipalPolicy.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/SystemException-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::AppDomainNamespace {
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::Loader;
using namespace System::Security::Permissions;
using namespace System::Security::Principal;
using namespace System::Threading;

AppDomain AppDomain___::get_CurrentDomain() {
  return s_domain;
}

String AppDomain___::get_BaseDirectory() {
  return AppContext::get_BaseDirectory();
}

String AppDomain___::get_RelativeSearchPath() {
  return nullptr;
}

AppDomainSetup AppDomain___::get_SetupInformation() {
  return rt::newobj<AppDomainSetup>();
}

PermissionSet AppDomain___::get_PermissionSet() {
  return rt::newobj<PermissionSet>(PermissionState::Unrestricted);
}

String AppDomain___::get_DynamicDirectory() {
  return nullptr;
}

String AppDomain___::get_FriendlyName() {
  Assembly entryAssembly = Assembly::in::GetEntryAssembly();
  if (!(entryAssembly != nullptr)) {
    return "DefaultDomain";
  }
  return entryAssembly->GetName()->get_Name();
}

Int32 AppDomain___::get_Id() {
  return 1;
}

Boolean AppDomain___::get_IsFullyTrusted() {
  return true;
}

Boolean AppDomain___::get_IsHomogenous() {
  return true;
}

Boolean AppDomain___::get_MonitoringIsEnabled() {
  return true;
}

void AppDomain___::set_MonitoringIsEnabled(Boolean value) {
  if (!value) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeTrue());
  }
}

Int64 AppDomain___::get_MonitoringSurvivedMemorySize() {
  return get_MonitoringSurvivedProcessMemorySize();
}

Int64 AppDomain___::get_MonitoringSurvivedProcessMemorySize() {
  GCMemoryInfo gCMemoryInfo = GC::GetGCMemoryInfo();
  return gCMemoryInfo.get_HeapSizeBytes() - gCMemoryInfo.get_FragmentedBytes();
}

Int64 AppDomain___::get_MonitoringTotalAllocatedMemorySize() {
  return GC::GetTotalAllocatedBytes();
}

Boolean AppDomain___::get_ShadowCopyFiles() {
  return false;
}

TimeSpan AppDomain___::get_MonitoringTotalProcessorTime() {
  Int64 creation;
  Int64 exit;
  Int64 kernel;
  Int64 user;
  if (!Interop::Kernel32::GetProcessTimes(Interop::Kernel32::GetCurrentProcess(), creation, exit, kernel, user)) {
    return TimeSpan::Zero;
  }
  return TimeSpan(user);
}

void AppDomain___::ctor() {
  _forLock = rt::newobj<Object>();
  _principalPolicy = PrincipalPolicy::NoPrincipal;
  MarshalByRefObject::in::ctor();
}

void AppDomain___::SetDynamicBase(String path) {
}

String AppDomain___::ApplyPolicy(String assemblyName) {
  if (assemblyName == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyName");
  }
  if (assemblyName->get_Length() == 0 || assemblyName[0] == u'\0') {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StringZeroLength(), "assemblyName");
  }
  return assemblyName;
}

AppDomain AppDomain___::CreateDomain(String friendlyName) {
  if (friendlyName == nullptr) {
    rt::throw_exception<ArgumentNullException>("friendlyName");
  }
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_AppDomains());
}

Int32 AppDomain___::ExecuteAssembly(String assemblyFile) {
  return ExecuteAssembly(assemblyFile, nullptr);
}

Int32 AppDomain___::ExecuteAssembly(String assemblyFile, Array<String> args) {
  if (assemblyFile == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyFile");
  }
  String fullPath = Path::GetFullPath(assemblyFile);
  Assembly assembly = Assembly::in::LoadFile(fullPath);
  return ExecuteAssembly(assembly, args);
}

Int32 AppDomain___::ExecuteAssembly(String assemblyFile, Array<String> args, Array<Byte> hashValue, AssemblyHashAlgorithm hashAlgorithm) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_CAS());
}

Int32 AppDomain___::ExecuteAssembly(Assembly assembly, Array<String> args) {
  MethodInfo entryPoint = assembly->get_EntryPoint();
  if (entryPoint == nullptr) {
    rt::throw_exception<MissingMethodException>(SR::get_Arg_EntryPointNotFoundException());
  }
  Object obj = entryPoint->Invoke(nullptr, BindingFlags::DoNotWrapExceptions, nullptr, (entryPoint->GetParameters()->get_Length() == 0) ? nullptr : rt::newarr<Array<Object>>(1), nullptr);
  if (obj == nullptr) {
    return 0;
  }
  return (Int32)obj;
}

Int32 AppDomain___::ExecuteAssemblyByName(AssemblyName assemblyName, Array<String> args) {
  return ExecuteAssembly(Assembly::in::Load(assemblyName), args);
}

Int32 AppDomain___::ExecuteAssemblyByName(String assemblyName) {
  return ExecuteAssemblyByName(assemblyName, (Array<String>)nullptr);
}

Int32 AppDomain___::ExecuteAssemblyByName(String assemblyName, Array<String> args) {
  return ExecuteAssembly(Assembly::in::Load(assemblyName), args);
}

Object AppDomain___::GetData(String name) {
  return AppContext::GetData(name);
}

void AppDomain___::SetData(String name, Object data) {
  AppContext::SetData(name, data);
}

Nullable<Boolean> AppDomain___::IsCompatibilitySwitchSet(String value) {
  Boolean isEnabled;
  if (!AppContext::TryGetSwitch(value, isEnabled)) {
    return nullptr;
  }
  return isEnabled;
}

Boolean AppDomain___::IsDefaultAppDomain() {
  return true;
}

Boolean AppDomain___::IsFinalizingForUnload() {
  return false;
}

String AppDomain___::ToString() {
  return SR::get_AppDomain_Name() + get_FriendlyName() + "\r\n" + SR::get_AppDomain_NoContextPolicies();
}

void AppDomain___::Unload(AppDomain domain) {
  if (domain == nullptr) {
    rt::throw_exception<ArgumentNullException>("domain");
  }
  rt::throw_exception<CannotUnloadAppDomainException>(SR::get_Arg_PlatformNotSupported());
}

Assembly AppDomain___::Load(Array<Byte> rawAssembly) {
  return Assembly::in::Load(rawAssembly);
}

Assembly AppDomain___::Load(Array<Byte> rawAssembly, Array<Byte> rawSymbolStore) {
  return Assembly::in::Load(rawAssembly, rawSymbolStore);
}

Assembly AppDomain___::Load(AssemblyName assemblyRef) {
  return Assembly::in::Load(assemblyRef);
}

Assembly AppDomain___::Load(String assemblyString) {
  return Assembly::in::Load(assemblyString);
}

Array<Assembly> AppDomain___::ReflectionOnlyGetAssemblies() {
  return Array<>::in::Empty<Assembly>();
}

Int32 AppDomain___::GetCurrentThreadId() {
  return Environment::get_CurrentManagedThreadId();
}

void AppDomain___::AppendPrivatePath(String path) {
}

void AppDomain___::ClearPrivatePath() {
}

void AppDomain___::ClearShadowCopyPath() {
}

void AppDomain___::SetCachePath(String path) {
}

void AppDomain___::SetShadowCopyFiles() {
}

void AppDomain___::SetShadowCopyPath(String path) {
}

Array<Assembly> AppDomain___::GetAssemblies() {
  return AssemblyLoadContext::in::GetLoadedAssemblies();
}

void AppDomain___::SetPrincipalPolicy(PrincipalPolicy policy) {
  _principalPolicy = policy;
}

void AppDomain___::SetThreadPrincipal(IPrincipal principal) {
  if (principal == nullptr) {
    rt::throw_exception<ArgumentNullException>("principal");
  }
  {
    rt::lock(_forLock);
    if (_defaultPrincipal != nullptr) {
      rt::throw_exception<SystemException>(SR::get_AppDomain_Policy_PrincipalTwice());
    }
    _defaultPrincipal = principal;
  }
}

ObjectHandle AppDomain___::CreateInstance(String assemblyName, String typeName) {
  if (assemblyName == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyName");
  }
  return Activator::CreateInstance(assemblyName, typeName);
}

ObjectHandle AppDomain___::CreateInstance(String assemblyName, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  if (assemblyName == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyName");
  }
  return Activator::CreateInstance(assemblyName, typeName, ignoreCase, bindingAttr, binder, args, culture, activationAttributes);
}

ObjectHandle AppDomain___::CreateInstance(String assemblyName, String typeName, Array<Object> activationAttributes) {
  if (assemblyName == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyName");
  }
  return Activator::CreateInstance(assemblyName, typeName, activationAttributes);
}

Object AppDomain___::CreateInstanceAndUnwrap(String assemblyName, String typeName) {
  ObjectHandle objectHandle = CreateInstance(assemblyName, typeName);
  if (objectHandle == nullptr) {
    return nullptr;
  }
  return objectHandle->Unwrap();
}

Object AppDomain___::CreateInstanceAndUnwrap(String assemblyName, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  ObjectHandle objectHandle = CreateInstance(assemblyName, typeName, ignoreCase, bindingAttr, binder, args, culture, activationAttributes);
  if (objectHandle == nullptr) {
    return nullptr;
  }
  return objectHandle->Unwrap();
}

Object AppDomain___::CreateInstanceAndUnwrap(String assemblyName, String typeName, Array<Object> activationAttributes) {
  ObjectHandle objectHandle = CreateInstance(assemblyName, typeName, activationAttributes);
  if (objectHandle == nullptr) {
    return nullptr;
  }
  return objectHandle->Unwrap();
}

ObjectHandle AppDomain___::CreateInstanceFrom(String assemblyFile, String typeName) {
  return Activator::CreateInstanceFrom(assemblyFile, typeName);
}

ObjectHandle AppDomain___::CreateInstanceFrom(String assemblyFile, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  return Activator::CreateInstanceFrom(assemblyFile, typeName, ignoreCase, bindingAttr, binder, args, culture, activationAttributes);
}

ObjectHandle AppDomain___::CreateInstanceFrom(String assemblyFile, String typeName, Array<Object> activationAttributes) {
  return Activator::CreateInstanceFrom(assemblyFile, typeName, activationAttributes);
}

Object AppDomain___::CreateInstanceFromAndUnwrap(String assemblyFile, String typeName) {
  ObjectHandle objectHandle = CreateInstanceFrom(assemblyFile, typeName);
  if (objectHandle == nullptr) {
    return nullptr;
  }
  return objectHandle->Unwrap();
}

Object AppDomain___::CreateInstanceFromAndUnwrap(String assemblyFile, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  ObjectHandle objectHandle = CreateInstanceFrom(assemblyFile, typeName, ignoreCase, bindingAttr, binder, args, culture, activationAttributes);
  if (objectHandle == nullptr) {
    return nullptr;
  }
  return objectHandle->Unwrap();
}

Object AppDomain___::CreateInstanceFromAndUnwrap(String assemblyFile, String typeName, Array<Object> activationAttributes) {
  ObjectHandle objectHandle = CreateInstanceFrom(assemblyFile, typeName, activationAttributes);
  if (objectHandle == nullptr) {
    return nullptr;
  }
  return objectHandle->Unwrap();
}

IPrincipal AppDomain___::GetThreadPrincipal() {
  IPrincipal principal = _defaultPrincipal;
  if (principal == nullptr) {
    switch (_principalPolicy) {
      case PrincipalPolicy::UnauthenticatedPrincipal:
        if (s_getUnauthenticatedPrincipal == nullptr) {
          Type type2 = Type::in::GetType("System.Security.Principal.GenericPrincipal, System.Security.Claims", true);
          MethodInfo method2 = type2->GetMethod("GetDefaultInstance", BindingFlags::Static | BindingFlags::NonPublic);
          Volatile::Write(s_getUnauthenticatedPrincipal, method2->CreateDelegate<Func<IPrincipal>>());
        }
        principal = s_getUnauthenticatedPrincipal();
        break;
      case PrincipalPolicy::WindowsPrincipal:
        if (s_getWindowsPrincipal == nullptr) {
          Type type = Type::in::GetType("System.Security.Principal.WindowsPrincipal, System.Security.Principal.Windows", true);
          MethodInfo method = type->GetMethod("GetDefaultInstance", BindingFlags::Static | BindingFlags::NonPublic);
          if (method == nullptr) {
            rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_Principal());
          }
          Volatile::Write(s_getWindowsPrincipal, method->CreateDelegate<Func<IPrincipal>>());
        }
        principal = s_getWindowsPrincipal();
        break;
    }
  }
  return principal;
}

void AppDomain___::cctor() {
  s_domain = rt::newobj<AppDomain>();
}

} // namespace System::Private::CoreLib::System::AppDomainNamespace
