#include "ResourceManager-dep.h"

#include <System.Private.CoreLib/System/Resources/ResourceManager-dep.h>

namespace System::Private::CoreLib::System::Resources::ResourceManagerNamespace {
String ResourceManager___::ResourceManagerMediator___::get_ModuleDir() {
  return nullptr;
};
Type ResourceManager___::ResourceManagerMediator___::get_LocationInfo() {
  return nullptr;
};
Type ResourceManager___::ResourceManagerMediator___::get_UserResourceSet() {
  return nullptr;
};
String ResourceManager___::ResourceManagerMediator___::get_BaseNameField() {
  return nullptr;
};
CultureInfo ResourceManager___::ResourceManagerMediator___::get_NeutralResourcesCulture() {
  return nullptr;
};
Boolean ResourceManager___::ResourceManagerMediator___::get_LookedForSatelliteContractVersion() {
  return Boolean();
};
void ResourceManager___::ResourceManagerMediator___::set_LookedForSatelliteContractVersion(Boolean value) {
  return void();
};
Version ResourceManager___::ResourceManagerMediator___::get_SatelliteContractVersion() {
  return nullptr;
};
void ResourceManager___::ResourceManagerMediator___::set_SatelliteContractVersion(Version value) {
  return void();
};
UltimateResourceFallbackLocation ResourceManager___::ResourceManagerMediator___::get_FallbackLoc() {
  return UltimateResourceFallbackLocation();
};
Assembly ResourceManager___::ResourceManagerMediator___::get_MainAssembly() {
  return nullptr;
};
String ResourceManager___::ResourceManagerMediator___::get_BaseName() {
  return nullptr;
};
String ResourceManager___::ResourceManagerMediator___::GetResourceFileName(CultureInfo culture) {
  return nullptr;
};
Version ResourceManager___::ResourceManagerMediator___::ObtainSatelliteContractVersion(Assembly a) {
  return nullptr;
};
String ResourceManager___::get_BaseName() {
  return nullptr;
};
Boolean ResourceManager___::get_IgnoreCase() {
  return Boolean();
};
void ResourceManager___::set_IgnoreCase(Boolean value) {
  return void();
};
Type ResourceManager___::get_ResourceSetType() {
  return nullptr;
};
UltimateResourceFallbackLocation ResourceManager___::get_FallbackLocation() {
  return UltimateResourceFallbackLocation();
};
void ResourceManager___::set_FallbackLocation(UltimateResourceFallbackLocation value) {
  return void();
};
void ResourceManager___::CommonAssemblyInit() {
  return void();
};
void ResourceManager___::ReleaseAllResources() {
  return void();
};
ResourceManager ResourceManager___::CreateFileBasedResourceManager(String baseName, String resourceDir, Type usingResourceSet) {
  return nullptr;
};
String ResourceManager___::GetResourceFileName(CultureInfo culture) {
  return nullptr;
};
ResourceSet ResourceManager___::GetFirstResourceSet(CultureInfo culture) {
  return nullptr;
};
ResourceSet ResourceManager___::GetResourceSet(CultureInfo culture, Boolean createIfNotExists, Boolean tryParents) {
  return nullptr;
};
ResourceSet ResourceManager___::InternalGetResourceSet(CultureInfo culture, Boolean createIfNotExists, Boolean tryParents) {
  return nullptr;
};
void ResourceManager___::AddResourceSet(Dictionary<String, ResourceSet> localResourceSets, String cultureName, ResourceSet& rs) {
  return void();
};
Version ResourceManager___::GetSatelliteContractVersion(Assembly a) {
  return nullptr;
};
CultureInfo ResourceManager___::GetNeutralResourcesLanguage(Assembly a) {
  return nullptr;
};
Boolean ResourceManager___::IsDefaultType(String asmTypeName, String typeName) {
  return Boolean();
};
String ResourceManager___::GetString(String name) {
  return nullptr;
};
String ResourceManager___::GetString(String name, CultureInfo culture) {
  return nullptr;
};
Object ResourceManager___::GetObject(String name) {
  return nullptr;
};
Object ResourceManager___::GetObject(String name, CultureInfo culture) {
  return nullptr;
};
Object ResourceManager___::GetObject(String name, CultureInfo culture, Boolean wrapUnmanagedMemStream) {
  return nullptr;
};
UnmanagedMemoryStream ResourceManager___::GetStream(String name) {
  return nullptr;
};
UnmanagedMemoryStream ResourceManager___::GetStream(String name, CultureInfo culture) {
  return nullptr;
};
String ResourceManager___::GetStringFromPRI(String stringName, CultureInfo culture, String neutralResourcesCulture) {
  return nullptr;
};
WindowsRuntimeResourceManagerBase ResourceManager___::GetWinRTResourceManager() {
  return nullptr;
};
Boolean ResourceManager___::ShouldUseUapResourceManagement(Assembly resourcesAssembly) {
  return Boolean();
};
void ResourceManager___::SetUapConfiguration() {
  return void();
};
} // namespace System::Private::CoreLib::System::Resources::ResourceManagerNamespace
