#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
FORWARD(PermissionSet)
} // namespace System::Private::CoreLib::System::Security
namespace System::Private::CoreLib::System::Configuration::Assemblies {
enum class AssemblyHashAlgorithm;
} // namespace System::Private::CoreLib::System::Configuration::Assemblies
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(AssemblyName)
FORWARD(Binder)
enum class BindingFlags;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Security::Principal {
FORWARD(IPrincipal)
enum class PrincipalPolicy;
} // namespace System::Private::CoreLib::System::Security::Principal
namespace System::Private::CoreLib::System::Runtime::Remoting {
FORWARD(ObjectHandle)
} // namespace System::Private::CoreLib::System::Runtime::Remoting
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(AppDomainSetup)
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARDS(Int64)
FORWARDS(TimeSpan)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Object)
FORWARDS_(Nullable, T1, T2)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
FORWARD_(EventHandler, T1, T2)
FORWARD(ResolveEventHandler)
namespace AppDomainNamespace {
using namespace ::System::Private::CoreLib::System::Configuration::Assemblies;
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::Remoting;
using namespace ::System::Private::CoreLib::System::Security;
using namespace ::System::Private::CoreLib::System::Security::Principal;
CLASS(AppDomain) {
  public: static AppDomain get_CurrentDomain();
  public: String get_BaseDirectory();
  public: String get_RelativeSearchPath();
  public: AppDomainSetup get_SetupInformation();
  public: PermissionSet get_PermissionSet();
  public: String get_DynamicDirectory();
  public: String get_FriendlyName();
  public: Int32 get_Id();
  public: Boolean get_IsFullyTrusted();
  public: Boolean get_IsHomogenous();
  public: static Boolean get_MonitoringIsEnabled();
  public: static void set_MonitoringIsEnabled(Boolean value);
  public: Int64 get_MonitoringSurvivedMemorySize();
  public: static Int64 get_MonitoringSurvivedProcessMemorySize();
  public: Int64 get_MonitoringTotalAllocatedMemorySize();
  public: Boolean get_ShadowCopyFiles();
  public: TimeSpan get_MonitoringTotalProcessorTime();
  public: void SetDynamicBase(String path);
  public: String ApplyPolicy(String assemblyName);
  public: static AppDomain CreateDomain(String friendlyName);
  public: Int32 ExecuteAssembly(String assemblyFile);
  public: Int32 ExecuteAssembly(String assemblyFile, Array<String> args);
  public: Int32 ExecuteAssembly(String assemblyFile, Array<String> args, Array<Byte> hashValue, AssemblyHashAlgorithm hashAlgorithm);
  private: Int32 ExecuteAssembly(Assembly assembly, Array<String> args);
  public: Int32 ExecuteAssemblyByName(AssemblyName assemblyName, Array<String> args);
  public: Int32 ExecuteAssemblyByName(String assemblyName);
  public: Int32 ExecuteAssemblyByName(String assemblyName, Array<String> args);
  public: Object GetData(String name);
  public: void SetData(String name, Object data);
  public: Nullable<Boolean> IsCompatibilitySwitchSet(String value);
  public: Boolean IsDefaultAppDomain();
  public: Boolean IsFinalizingForUnload();
  public: String ToString();
  public: static void Unload(AppDomain domain);
  public: Assembly Load(Array<Byte> rawAssembly);
  public: Assembly Load(Array<Byte> rawAssembly, Array<Byte> rawSymbolStore);
  public: Assembly Load(AssemblyName assemblyRef);
  public: Assembly Load(String assemblyString);
  public: Array<Assembly> ReflectionOnlyGetAssemblies();
  public: static Int32 GetCurrentThreadId();
  public: void AppendPrivatePath(String path);
  public: void ClearPrivatePath();
  public: void ClearShadowCopyPath();
  public: void SetCachePath(String path);
  public: void SetShadowCopyFiles();
  public: void SetShadowCopyPath(String path);
  public: Array<Assembly> GetAssemblies();
  public: void SetPrincipalPolicy(PrincipalPolicy policy);
  public: void SetThreadPrincipal(IPrincipal principal);
  public: ObjectHandle CreateInstance(String assemblyName, String typeName);
  public: ObjectHandle CreateInstance(String assemblyName, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes);
  public: ObjectHandle CreateInstance(String assemblyName, String typeName, Array<Object> activationAttributes);
  public: Object CreateInstanceAndUnwrap(String assemblyName, String typeName);
  public: Object CreateInstanceAndUnwrap(String assemblyName, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes);
  public: Object CreateInstanceAndUnwrap(String assemblyName, String typeName, Array<Object> activationAttributes);
  public: ObjectHandle CreateInstanceFrom(String assemblyFile, String typeName);
  public: ObjectHandle CreateInstanceFrom(String assemblyFile, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes);
  public: ObjectHandle CreateInstanceFrom(String assemblyFile, String typeName, Array<Object> activationAttributes);
  public: Object CreateInstanceFromAndUnwrap(String assemblyFile, String typeName);
  public: Object CreateInstanceFromAndUnwrap(String assemblyFile, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes);
  public: Object CreateInstanceFromAndUnwrap(String assemblyFile, String typeName, Array<Object> activationAttributes);
  public: IPrincipal GetThreadPrincipal();
  private: static AppDomain s_domain;
  private: Object _forLock;
  private: IPrincipal _defaultPrincipal;
  private: PrincipalPolicy _principalPolicy;
  private: Func<IPrincipal> s_getWindowsPrincipal;
  private: Func<IPrincipal> s_getUnauthenticatedPrincipal;
  private: EventHandler<> DomainUnload;
  private: ResolveEventHandler ReflectionOnlyAssemblyResolve;
};
} // namespace AppDomainNamespace
using AppDomain = AppDomainNamespace::AppDomain;
} // namespace System::Private::CoreLib::System