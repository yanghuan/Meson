#include "AppDomain-dep.h"

#include <System.Private.CoreLib/System/AppDomain-dep.h>

namespace System::Private::CoreLib::System::AppDomainNamespace {
AppDomain AppDomain___::get_CurrentDomain() {
  return nullptr;
};
String AppDomain___::get_BaseDirectory() {
  return nullptr;
};
String AppDomain___::get_RelativeSearchPath() {
  return nullptr;
};
AppDomainSetup AppDomain___::get_SetupInformation() {
  return nullptr;
};
PermissionSet AppDomain___::get_PermissionSet() {
  return nullptr;
};
String AppDomain___::get_DynamicDirectory() {
  return nullptr;
};
String AppDomain___::get_FriendlyName() {
  return nullptr;
};
Int32 AppDomain___::get_Id() {
  return Int32();
};
Boolean AppDomain___::get_IsFullyTrusted() {
  return Boolean();
};
Boolean AppDomain___::get_IsHomogenous() {
  return Boolean();
};
Boolean AppDomain___::get_MonitoringIsEnabled() {
  return Boolean();
};
void AppDomain___::set_MonitoringIsEnabled(Boolean value) {
};
Int64 AppDomain___::get_MonitoringSurvivedMemorySize() {
  return Int64();
};
Int64 AppDomain___::get_MonitoringSurvivedProcessMemorySize() {
  return Int64();
};
Int64 AppDomain___::get_MonitoringTotalAllocatedMemorySize() {
  return Int64();
};
Boolean AppDomain___::get_ShadowCopyFiles() {
  return Boolean();
};
TimeSpan AppDomain___::get_MonitoringTotalProcessorTime() {
  return TimeSpan();
};
void AppDomain___::SetDynamicBase(String path) {
};
String AppDomain___::ApplyPolicy(String assemblyName) {
  return nullptr;
};
AppDomain AppDomain___::CreateDomain(String friendlyName) {
  return nullptr;
};
Int32 AppDomain___::ExecuteAssembly(String assemblyFile) {
  return Int32();
};
Int32 AppDomain___::ExecuteAssembly(String assemblyFile, Array<String> args) {
  return Int32();
};
Int32 AppDomain___::ExecuteAssembly(String assemblyFile, Array<String> args, Array<Byte> hashValue, AssemblyHashAlgorithm hashAlgorithm) {
  return Int32();
};
Int32 AppDomain___::ExecuteAssembly(Assembly assembly, Array<String> args) {
  return Int32();
};
Int32 AppDomain___::ExecuteAssemblyByName(AssemblyName assemblyName, Array<String> args) {
  return Int32();
};
Int32 AppDomain___::ExecuteAssemblyByName(String assemblyName) {
  return Int32();
};
Int32 AppDomain___::ExecuteAssemblyByName(String assemblyName, Array<String> args) {
  return Int32();
};
Object AppDomain___::GetData(String name) {
  return nullptr;
};
void AppDomain___::SetData(String name, Object data) {
};
Nullable<Boolean> AppDomain___::IsCompatibilitySwitchSet(String value) {
  return Nullable<Boolean>();
};
Boolean AppDomain___::IsDefaultAppDomain() {
  return Boolean();
};
Boolean AppDomain___::IsFinalizingForUnload() {
  return Boolean();
};
String AppDomain___::ToString() {
  return nullptr;
};
void AppDomain___::Unload(AppDomain domain) {
};
Assembly AppDomain___::Load(Array<Byte> rawAssembly) {
  return nullptr;
};
Assembly AppDomain___::Load(Array<Byte> rawAssembly, Array<Byte> rawSymbolStore) {
  return nullptr;
};
Assembly AppDomain___::Load(AssemblyName assemblyRef) {
  return nullptr;
};
Assembly AppDomain___::Load(String assemblyString) {
  return nullptr;
};
Array<Assembly> AppDomain___::ReflectionOnlyGetAssemblies() {
  return Array<Assembly>();
};
Int32 AppDomain___::GetCurrentThreadId() {
  return Int32();
};
void AppDomain___::AppendPrivatePath(String path) {
};
void AppDomain___::ClearPrivatePath() {
};
void AppDomain___::ClearShadowCopyPath() {
};
void AppDomain___::SetCachePath(String path) {
};
void AppDomain___::SetShadowCopyFiles() {
};
void AppDomain___::SetShadowCopyPath(String path) {
};
Array<Assembly> AppDomain___::GetAssemblies() {
  return Array<Assembly>();
};
void AppDomain___::SetPrincipalPolicy(PrincipalPolicy policy) {
};
void AppDomain___::SetThreadPrincipal(IPrincipal principal) {
};
ObjectHandle AppDomain___::CreateInstance(String assemblyName, String typeName) {
  return nullptr;
};
ObjectHandle AppDomain___::CreateInstance(String assemblyName, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  return nullptr;
};
ObjectHandle AppDomain___::CreateInstance(String assemblyName, String typeName, Array<Object> activationAttributes) {
  return nullptr;
};
Object AppDomain___::CreateInstanceAndUnwrap(String assemblyName, String typeName) {
  return nullptr;
};
Object AppDomain___::CreateInstanceAndUnwrap(String assemblyName, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  return nullptr;
};
Object AppDomain___::CreateInstanceAndUnwrap(String assemblyName, String typeName, Array<Object> activationAttributes) {
  return nullptr;
};
ObjectHandle AppDomain___::CreateInstanceFrom(String assemblyFile, String typeName) {
  return nullptr;
};
ObjectHandle AppDomain___::CreateInstanceFrom(String assemblyFile, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  return nullptr;
};
ObjectHandle AppDomain___::CreateInstanceFrom(String assemblyFile, String typeName, Array<Object> activationAttributes) {
  return nullptr;
};
Object AppDomain___::CreateInstanceFromAndUnwrap(String assemblyFile, String typeName) {
  return nullptr;
};
Object AppDomain___::CreateInstanceFromAndUnwrap(String assemblyFile, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  return nullptr;
};
Object AppDomain___::CreateInstanceFromAndUnwrap(String assemblyFile, String typeName, Array<Object> activationAttributes) {
  return nullptr;
};
IPrincipal AppDomain___::GetThreadPrincipal() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::AppDomainNamespace
