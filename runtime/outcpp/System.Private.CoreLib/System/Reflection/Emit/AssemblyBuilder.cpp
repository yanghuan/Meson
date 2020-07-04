#include "AssemblyBuilder-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/AssemblyBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::AssemblyBuilderNamespace {
Object AssemblyBuilder___::get_SyncRoot() {
  return nullptr;
};
InternalAssemblyBuilder AssemblyBuilder___::get_InternalAssembly() {
  return nullptr;
};
String AssemblyBuilder___::get_Location() {
  return nullptr;
};
String AssemblyBuilder___::get_ImageRuntimeVersion() {
  return nullptr;
};
String AssemblyBuilder___::get_CodeBase() {
  return nullptr;
};
MethodInfo AssemblyBuilder___::get_EntryPoint() {
  return nullptr;
};
String AssemblyBuilder___::get_FullName() {
  return nullptr;
};
Module AssemblyBuilder___::get_ManifestModule() {
  return nullptr;
};
Boolean AssemblyBuilder___::get_ReflectionOnly() {
  return Boolean();
};
Boolean AssemblyBuilder___::get_GlobalAssemblyCache() {
  return Boolean();
};
Int64 AssemblyBuilder___::get_HostContext() {
  return Int64();
};
Boolean AssemblyBuilder___::get_IsDynamic() {
  return Boolean();
};
Boolean AssemblyBuilder___::get_IsCollectible() {
  return Boolean();
};
ModuleBuilder AssemblyBuilder___::GetModuleBuilder(InternalModuleBuilder module) {
  return nullptr;
};
RuntimeAssembly AssemblyBuilder___::GetNativeHandle() {
  return nullptr;
};
void AssemblyBuilder___::InitManifestModule() {
};
AssemblyBuilder AssemblyBuilder___::DefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access) {
  return nullptr;
};
AssemblyBuilder AssemblyBuilder___::DefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access, IEnumerable<CustomAttributeBuilder> assemblyAttributes) {
  return nullptr;
};
AssemblyBuilder AssemblyBuilder___::InternalDefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access, StackCrawlMark& stackMark, IEnumerable<CustomAttributeBuilder> unsafeAssemblyAttributes) {
  return nullptr;
};
ModuleBuilder AssemblyBuilder___::DefineDynamicModule(String name) {
  return nullptr;
};
ModuleBuilder AssemblyBuilder___::DefineDynamicModule(String name, Boolean emitSymbolInfo) {
  return nullptr;
};
ModuleBuilder AssemblyBuilder___::DefineDynamicModuleInternal(String name, Boolean emitSymbolInfo) {
  return nullptr;
};
ModuleBuilder AssemblyBuilder___::DefineDynamicModuleInternalNoLock(String name, Boolean emitSymbolInfo) {
  return nullptr;
};
void AssemblyBuilder___::CheckContext(Array<Array<Type>> typess) {
};
void AssemblyBuilder___::CheckContext(Array<Type> types) {
};
Boolean AssemblyBuilder___::Equals(Object obj) {
  return Boolean();
};
Int32 AssemblyBuilder___::GetHashCode() {
  return Int32();
};
Array<Object> AssemblyBuilder___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};
Array<Object> AssemblyBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};
Boolean AssemblyBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};
IList<CustomAttributeData> AssemblyBuilder___::GetCustomAttributesData() {
  return nullptr;
};
Array<String> AssemblyBuilder___::GetManifestResourceNames() {
  return Array<String>();
};
FileStream AssemblyBuilder___::GetFile(String name) {
  return nullptr;
};
Array<FileStream> AssemblyBuilder___::GetFiles(Boolean getResourceModules) {
  return Array<FileStream>();
};
Stream AssemblyBuilder___::GetManifestResourceStream(Type type, String name) {
  return nullptr;
};
Stream AssemblyBuilder___::GetManifestResourceStream(String name) {
  return nullptr;
};
ManifestResourceInfo AssemblyBuilder___::GetManifestResourceInfo(String resourceName) {
  return nullptr;
};
Array<Type> AssemblyBuilder___::GetExportedTypes() {
  return Array<Type>();
};
AssemblyName AssemblyBuilder___::GetName(Boolean copiedName) {
  return nullptr;
};
Type AssemblyBuilder___::GetType(String name, Boolean throwOnError, Boolean ignoreCase) {
  return nullptr;
};
Module AssemblyBuilder___::GetModule(String name) {
  return nullptr;
};
Array<AssemblyName> AssemblyBuilder___::GetReferencedAssemblies() {
  return Array<AssemblyName>();
};
Array<Module> AssemblyBuilder___::GetModules(Boolean getResourceModules) {
  return Array<Module>();
};
Array<Module> AssemblyBuilder___::GetLoadedModules(Boolean getResourceModules) {
  return Array<Module>();
};
Assembly AssemblyBuilder___::GetSatelliteAssembly(CultureInfo culture) {
  return nullptr;
};
Assembly AssemblyBuilder___::GetSatelliteAssembly(CultureInfo culture, Version version) {
  return nullptr;
};
ModuleBuilder AssemblyBuilder___::GetDynamicModule(String name) {
  return nullptr;
};
ModuleBuilder AssemblyBuilder___::GetDynamicModuleNoLock(String name) {
  return nullptr;
};
void AssemblyBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
};
void AssemblyBuilder___::SetCustomAttributeNoLock(ConstructorInfo con, Array<Byte> binaryAttribute) {
};
void AssemblyBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
};
void AssemblyBuilder___::SetCustomAttributeNoLock(CustomAttributeBuilder customBuilder) {
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::AssemblyBuilderNamespace
