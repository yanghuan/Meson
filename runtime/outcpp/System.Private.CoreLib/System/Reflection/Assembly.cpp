#include "Assembly-dep.h"

#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyNamespace {
IEnumerable<TypeInfo> Assembly___::get_DefinedTypes() {
  return nullptr;
};
IEnumerable<Type> Assembly___::get_ExportedTypes() {
  return nullptr;
};
String Assembly___::get_CodeBase() {
  return nullptr;
};
MethodInfo Assembly___::get_EntryPoint() {
  return nullptr;
};
String Assembly___::get_FullName() {
  return nullptr;
};
String Assembly___::get_ImageRuntimeVersion() {
  return nullptr;
};
Boolean Assembly___::get_IsDynamic() {
  return Boolean();
};
String Assembly___::get_Location() {
  return nullptr;
};
Boolean Assembly___::get_ReflectionOnly() {
  return Boolean();
};
Boolean Assembly___::get_IsCollectible() {
  return Boolean();
};
Boolean Assembly___::get_IsFullyTrusted() {
  return Boolean();
};
IEnumerable<CustomAttributeData> Assembly___::get_CustomAttributes() {
  return nullptr;
};
String Assembly___::get_EscapedCodeBase() {
  return nullptr;
};
Module Assembly___::get_ManifestModule() {
  return nullptr;
};
IEnumerable<Module> Assembly___::get_Modules() {
  return nullptr;
};
Boolean Assembly___::get_GlobalAssemblyCache() {
  return Boolean();
};
Int64 Assembly___::get_HostContext() {
  return Int64();
};
SecurityRuleSet Assembly___::get_SecurityRuleSet() {
  return SecurityRuleSet();
};
Assembly Assembly___::Load(String assemblyString) {
  return nullptr;
};
Assembly Assembly___::LoadWithPartialName(String partialName) {
  return nullptr;
};
Assembly Assembly___::Load(AssemblyName assemblyRef) {
  return nullptr;
};
Assembly Assembly___::Load(AssemblyName assemblyRef, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext) {
  return nullptr;
};
RuntimeAssembly Assembly___::GetExecutingAssembly(StackCrawlMark& stackMark) {
  return nullptr;
};
Assembly Assembly___::GetExecutingAssembly() {
  return nullptr;
};
Assembly Assembly___::GetCallingAssembly() {
  return nullptr;
};
Assembly Assembly___::GetEntryAssembly() {
  return nullptr;
};
Boolean Assembly___::IsRuntimeImplemented() {
  return Boolean();
};
Array<Type> Assembly___::GetTypes() {
  return Array<Type>();
};
Array<Type> Assembly___::GetExportedTypes() {
  return Array<Type>();
};
Array<Type> Assembly___::GetForwardedTypes() {
  return Array<Type>();
};
ManifestResourceInfo Assembly___::GetManifestResourceInfo(String resourceName) {
  return nullptr;
};
Array<String> Assembly___::GetManifestResourceNames() {
  return Array<String>();
};
Stream Assembly___::GetManifestResourceStream(String name) {
  return nullptr;
};
Stream Assembly___::GetManifestResourceStream(Type type, String name) {
  return nullptr;
};
AssemblyName Assembly___::GetName() {
  return nullptr;
};
AssemblyName Assembly___::GetName(Boolean copiedName) {
  return nullptr;
};
Type Assembly___::GetType(String name) {
  return nullptr;
};
Type Assembly___::GetType(String name, Boolean throwOnError) {
  return nullptr;
};
Type Assembly___::GetType(String name, Boolean throwOnError, Boolean ignoreCase) {
  return nullptr;
};
Boolean Assembly___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};
IList<CustomAttributeData> Assembly___::GetCustomAttributesData() {
  return nullptr;
};
Array<Object> Assembly___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};
Array<Object> Assembly___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};
Object Assembly___::CreateInstance(String typeName) {
  return nullptr;
};
Object Assembly___::CreateInstance(String typeName, Boolean ignoreCase) {
  return nullptr;
};
Object Assembly___::CreateInstance(String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  return nullptr;
};
Module Assembly___::GetModule(String name) {
  return nullptr;
};
Array<Module> Assembly___::GetModules() {
  return Array<Module>();
};
Array<Module> Assembly___::GetModules(Boolean getResourceModules) {
  return Array<Module>();
};
Array<Module> Assembly___::GetLoadedModules() {
  return Array<Module>();
};
Array<Module> Assembly___::GetLoadedModules(Boolean getResourceModules) {
  return Array<Module>();
};
Array<AssemblyName> Assembly___::GetReferencedAssemblies() {
  return Array<AssemblyName>();
};
Assembly Assembly___::GetSatelliteAssembly(CultureInfo culture) {
  return nullptr;
};
Assembly Assembly___::GetSatelliteAssembly(CultureInfo culture, Version version) {
  return nullptr;
};
FileStream Assembly___::GetFile(String name) {
  return nullptr;
};
Array<FileStream> Assembly___::GetFiles() {
  return Array<FileStream>();
};
Array<FileStream> Assembly___::GetFiles(Boolean getResourceModules) {
  return Array<FileStream>();
};
void Assembly___::GetObjectData(SerializationInfo info, StreamingContext context) {
};
String Assembly___::ToString() {
  return nullptr;
};
Boolean Assembly___::Equals(Object o) {
  return Boolean();
};
Int32 Assembly___::GetHashCode() {
  return Int32();
};
String Assembly___::CreateQualifiedName(String assemblyName, String typeName) {
  return nullptr;
};
Assembly Assembly___::GetAssembly(Type type) {
  return nullptr;
};
Assembly Assembly___::Load(Array<Byte> rawAssembly) {
  return nullptr;
};
Assembly Assembly___::Load(Array<Byte> rawAssembly, Array<Byte> rawSymbolStore) {
  return nullptr;
};
Assembly Assembly___::LoadFile(String path) {
  return nullptr;
};
Assembly Assembly___::LoadFromResolveHandler(Object sender, ResolveEventArgs args) {
  return nullptr;
};
Assembly Assembly___::LoadFrom(String assemblyFile) {
  return nullptr;
};
Assembly Assembly___::LoadFrom(String assemblyFile, Array<Byte> hashValue, AssemblyHashAlgorithm hashAlgorithm) {
  return nullptr;
};
Assembly Assembly___::UnsafeLoadFrom(String assemblyFile) {
  return nullptr;
};
Module Assembly___::LoadModule(String moduleName, Array<Byte> rawModule) {
  return nullptr;
};
Module Assembly___::LoadModule(String moduleName, Array<Byte> rawModule, Array<Byte> rawSymbolStore) {
  return nullptr;
};
Assembly Assembly___::ReflectionOnlyLoad(Array<Byte> rawAssembly) {
  return nullptr;
};
Assembly Assembly___::ReflectionOnlyLoad(String assemblyString) {
  return nullptr;
};
Assembly Assembly___::ReflectionOnlyLoadFrom(String assemblyFile) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Reflection::AssemblyNamespace
