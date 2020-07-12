#include "RuntimeAssembly-dep.h"

#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeAssemblyNamespace {
Object RuntimeAssembly___::get_SyncRoot() {
  return nullptr;
};

String RuntimeAssembly___::get_CodeBase() {
  return nullptr;
};

String RuntimeAssembly___::get_FullName() {
  return nullptr;
};

MethodInfo RuntimeAssembly___::get_EntryPoint() {
  return nullptr;
};

IEnumerable<TypeInfo> RuntimeAssembly___::get_DefinedTypes() {
  return nullptr;
};

Boolean RuntimeAssembly___::get_IsCollectible() {
  return Boolean();
};

Module RuntimeAssembly___::get_ManifestModule() {
  return nullptr;
};

Boolean RuntimeAssembly___::get_ReflectionOnly() {
  return Boolean();
};

String RuntimeAssembly___::get_Location() {
  return nullptr;
};

String RuntimeAssembly___::get_ImageRuntimeVersion() {
  return nullptr;
};

Boolean RuntimeAssembly___::get_GlobalAssemblyCache() {
  return Boolean();
};

Int64 RuntimeAssembly___::get_HostContext() {
  return Int64();
};

Boolean RuntimeAssembly___::get_IsDynamic() {
  return Boolean();
};

IntPtr RuntimeAssembly___::GetUnderlyingNativeHandle() {
  return IntPtr();
};

String RuntimeAssembly___::GetCodeBase(Boolean copiedName) {
  return nullptr;
};

RuntimeAssembly RuntimeAssembly___::GetNativeHandle() {
  return nullptr;
};

AssemblyName RuntimeAssembly___::GetName(Boolean copiedName) {
  return nullptr;
};

Type RuntimeAssembly___::GetType(String name, Boolean throwOnError, Boolean ignoreCase) {
  return nullptr;
};

Array<Type> RuntimeAssembly___::GetExportedTypes() {
  return Array<Type>();
};

Stream RuntimeAssembly___::GetManifestResourceStream(Type type, String name) {
  return nullptr;
};

Stream RuntimeAssembly___::GetManifestResourceStream(String name) {
  return nullptr;
};

void RuntimeAssembly___::GetObjectData(SerializationInfo info, StreamingContext context) {
};

Array<Object> RuntimeAssembly___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};

Array<Object> RuntimeAssembly___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};

Boolean RuntimeAssembly___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};

IList<CustomAttributeData> RuntimeAssembly___::GetCustomAttributesData() {
  return nullptr;
};

RuntimeAssembly RuntimeAssembly___::InternalLoad(String assemblyName, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext) {
  return nullptr;
};

RuntimeAssembly RuntimeAssembly___::InternalLoad(AssemblyName assemblyName, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext) {
  return nullptr;
};

RuntimeAssembly RuntimeAssembly___::InternalLoad(AssemblyName assemblyName, RuntimeAssembly requestingAssembly, StackCrawlMark& stackMark, Boolean throwOnFileNotFound, AssemblyLoadContext assemblyLoadContext) {
  return nullptr;
};

Module RuntimeAssembly___::GetModule(String name) {
  return nullptr;
};

FileStream RuntimeAssembly___::GetFile(String name) {
  return nullptr;
};

Array<FileStream> RuntimeAssembly___::GetFiles(Boolean getResourceModules) {
  return Array<FileStream>();
};

Array<String> RuntimeAssembly___::GetManifestResourceNames() {
  return Array<String>();
};

Array<AssemblyName> RuntimeAssembly___::GetReferencedAssemblies() {
  return Array<AssemblyName>();
};

ManifestResourceInfo RuntimeAssembly___::GetManifestResourceInfo(String resourceName) {
  return nullptr;
};

Version RuntimeAssembly___::GetVersion() {
  return nullptr;
};

CultureInfo RuntimeAssembly___::GetLocale() {
  return nullptr;
};

String RuntimeAssembly___::GetSimpleName() {
  return nullptr;
};

AssemblyHashAlgorithm RuntimeAssembly___::GetHashAlgorithm() {
  return AssemblyHashAlgorithm::SHA512;
};

AssemblyNameFlags RuntimeAssembly___::GetFlags() {
  return AssemblyNameFlags::Retargetable;
};

Array<Byte> RuntimeAssembly___::GetPublicKey() {
  return Array<Byte>();
};

Assembly RuntimeAssembly___::GetSatelliteAssembly(CultureInfo culture) {
  return nullptr;
};

Assembly RuntimeAssembly___::GetSatelliteAssembly(CultureInfo culture, Version version) {
  return nullptr;
};

Assembly RuntimeAssembly___::InternalGetSatelliteAssembly(CultureInfo culture, Version version, Boolean throwOnFileNotFound) {
  return nullptr;
};

Array<RuntimeModule> RuntimeAssembly___::GetModulesInternal(Boolean loadIfNotFound, Boolean getResourceModules) {
  return Array<RuntimeModule>();
};

Array<Module> RuntimeAssembly___::GetModules(Boolean getResourceModules) {
  return Array<Module>();
};

Array<Module> RuntimeAssembly___::GetLoadedModules(Boolean getResourceModules) {
  return Array<Module>();
};

Array<Type> RuntimeAssembly___::GetForwardedTypes() {
  return Array<Type>();
};

void RuntimeAssembly___::AddPublicNestedTypes(Type type, List<Type> types, List<Exception> exceptions) {
};

} // namespace System::Private::CoreLib::System::Reflection::RuntimeAssemblyNamespace
