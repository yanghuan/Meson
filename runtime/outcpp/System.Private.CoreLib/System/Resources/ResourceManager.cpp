#include "ResourceManager-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/Stream-dep.h>
#include <System.Private.CoreLib/System/IO/UnmanagedMemoryStream-dep.h>
#include <System.Private.CoreLib/System/IO/UnmanagedMemoryStreamWrapper-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyName-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeExtensions-dep.h>
#include <System.Private.CoreLib/System/Resources/FileBasedResourceGroveler-dep.h>
#include <System.Private.CoreLib/System/Resources/ManifestBasedResourceGroveler-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceFallbackManager-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceManager-dep.h>
#include <System.Private.CoreLib/System/Resources/RuntimeResourceSet-dep.h>
#include <System.Private.CoreLib/System/Resources/SatelliteContractVersionAttribute-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>

namespace System::Private::CoreLib::System::Resources::ResourceManagerNamespace {
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Reflection;

void ResourceManager___::CultureNameResourceSetPair___::ctor() {
}

String ResourceManager___::ResourceManagerMediator___::get_ModuleDir() {
  return _rm->_moduleDir;
}

Type ResourceManager___::ResourceManagerMediator___::get_LocationInfo() {
  return _rm->_locationInfo;
}

Type ResourceManager___::ResourceManagerMediator___::get_UserResourceSet() {
  return _rm->_userResourceSet;
}

String ResourceManager___::ResourceManagerMediator___::get_BaseNameField() {
  return _rm->BaseNameField;
}

CultureInfo ResourceManager___::ResourceManagerMediator___::get_NeutralResourcesCulture() {
  return _rm->_neutralResourcesCulture;
}

Boolean ResourceManager___::ResourceManagerMediator___::get_LookedForSatelliteContractVersion() {
  return _rm->_lookedForSatelliteContractVersion;
}

void ResourceManager___::ResourceManagerMediator___::set_LookedForSatelliteContractVersion(Boolean value) {
  _rm->_lookedForSatelliteContractVersion = value;
}

Version ResourceManager___::ResourceManagerMediator___::get_SatelliteContractVersion() {
  return _rm->_satelliteContractVersion;
}

void ResourceManager___::ResourceManagerMediator___::set_SatelliteContractVersion(Version value) {
  _rm->_satelliteContractVersion = value;
}

UltimateResourceFallbackLocation ResourceManager___::ResourceManagerMediator___::get_FallbackLoc() {
  return _rm->get_FallbackLocation();
}

Assembly ResourceManager___::ResourceManagerMediator___::get_MainAssembly() {
  return _rm->MainAssembly;
}

String ResourceManager___::ResourceManagerMediator___::get_BaseName() {
  return _rm->get_BaseName();
}

void ResourceManager___::ResourceManagerMediator___::ctor(ResourceManager rm) {
  if (rm == nullptr) {
    rt::throw_exception<ArgumentNullException>("rm");
  }
  _rm = rm;
}

String ResourceManager___::ResourceManagerMediator___::GetResourceFileName(CultureInfo culture) {
  return _rm->GetResourceFileName(culture);
}

Version ResourceManager___::ResourceManagerMediator___::ObtainSatelliteContractVersion(Assembly a) {
  return GetSatelliteContractVersion(a);
}

String ResourceManager___::get_BaseName() {
  return BaseNameField;
}

Boolean ResourceManager___::get_IgnoreCase() {
  return _ignoreCase;
}

void ResourceManager___::set_IgnoreCase(Boolean value) {
  _ignoreCase = value;
}

Type ResourceManager___::get_ResourceSetType() {
  Type as = _userResourceSet;
  return as != nullptr ? as : typeof<RuntimeResourceSet>();
}

UltimateResourceFallbackLocation ResourceManager___::get_FallbackLocation() {
  return _fallbackLoc;
}

void ResourceManager___::set_FallbackLocation(UltimateResourceFallbackLocation value) {
  _fallbackLoc = value;
}

void ResourceManager___::ctor() {
  _lastUsedResourceCache = rt::newobj<CultureNameResourceSetPair>();
  ResourceManagerMediator mediator = rt::newobj<ResourceManagerMediator>((ResourceManager)this);
  _resourceGroveler = rt::newobj<ManifestBasedResourceGroveler>(mediator);
  BaseNameField = String::in::Empty;
}

void ResourceManager___::ctor(String baseName, String resourceDir, Type userResourceSet) {
  if (baseName == nullptr) {
    rt::throw_exception<ArgumentNullException>("baseName");
  }
  if (resourceDir == nullptr) {
    rt::throw_exception<ArgumentNullException>("resourceDir");
  }
  BaseNameField = baseName;
  _moduleDir = resourceDir;
  _userResourceSet = userResourceSet;
  _resourceSets = rt::newobj<Dictionary<String, ResourceSet>>();
  _lastUsedResourceCache = rt::newobj<CultureNameResourceSetPair>();
  ResourceManagerMediator mediator = rt::newobj<ResourceManagerMediator>((ResourceManager)this);
  _resourceGroveler = rt::newobj<FileBasedResourceGroveler>(mediator);
}

void ResourceManager___::ctor(String baseName, Assembly assembly) {
  if (baseName == nullptr) {
    rt::throw_exception<ArgumentNullException>("baseName");
  }
  if (nullptr == assembly) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
  if (!assembly->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeAssembly());
  }
  MainAssembly = assembly;
  BaseNameField = baseName;
  CommonAssemblyInit();
}

void ResourceManager___::ctor(String baseName, Assembly assembly, Type usingResourceSet) {
  if (baseName == nullptr) {
    rt::throw_exception<ArgumentNullException>("baseName");
  }
  if (nullptr == assembly) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
  if (!assembly->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeAssembly());
  }
  MainAssembly = assembly;
  BaseNameField = baseName;
  if (usingResourceSet != nullptr && usingResourceSet != s_minResourceSet && !usingResourceSet->IsSubclassOf(s_minResourceSet)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ResMgrNotResSet(), "usingResourceSet");
  }
  _userResourceSet = usingResourceSet;
  CommonAssemblyInit();
}

void ResourceManager___::ctor(Type resourceSource) {
  if (nullptr == resourceSource) {
    rt::throw_exception<ArgumentNullException>("resourceSource");
  }
  if (!resourceSource->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType());
  }
  _locationInfo = resourceSource;
  MainAssembly = _locationInfo->get_Assembly();
  BaseNameField = resourceSource->get_Name();
  CommonAssemblyInit();
}

void ResourceManager___::CommonAssemblyInit() {
  _useManifest = true;
  _resourceSets = rt::newobj<Dictionary<String, ResourceSet>>();
  _lastUsedResourceCache = rt::newobj<CultureNameResourceSetPair>();
  ResourceManagerMediator mediator = rt::newobj<ResourceManagerMediator>((ResourceManager)this);
  _resourceGroveler = rt::newobj<ManifestBasedResourceGroveler>(mediator);
  _neutralResourcesCulture = ManifestBasedResourceGroveler::in::GetNeutralResourcesLanguage(MainAssembly, _fallbackLoc);
}

void ResourceManager___::ReleaseAllResources() {
  Dictionary<String, ResourceSet> resourceSets = _resourceSets;
  _resourceSets = rt::newobj<Dictionary<String, ResourceSet>>();
  _lastUsedResourceCache = rt::newobj<CultureNameResourceSetPair>();
  {
    rt::lock(resourceSets);
    for (KeyValuePair<String, ResourceSet>&& item : rt::each(resourceSets)) {
      String key;
      ResourceSet value;
      item.Deconstruct(key, value);
      ResourceSet resourceSet = value;
      resourceSet->Close();
    }
  }
}

ResourceManager ResourceManager___::CreateFileBasedResourceManager(String baseName, String resourceDir, Type usingResourceSet) {
  return rt::newobj<ResourceManager>(baseName, resourceDir, usingResourceSet);
}

String ResourceManager___::GetResourceFileName(CultureInfo culture) {
  if (culture->get_HasInvariantCultureName()) {
    return BaseNameField + ".resources";
  }
  CultureInfo::in::VerifyCultureName(culture->get_Name(), true);
  return BaseNameField + "." + culture->get_Name() + ".resources";
}

ResourceSet ResourceManager___::GetFirstResourceSet(CultureInfo culture) {
  if (_neutralResourcesCulture != nullptr && culture->get_Name() == _neutralResourcesCulture->get_Name()) {
    culture = CultureInfo::in::get_InvariantCulture();
  }
  if (_lastUsedResourceCache != nullptr) {
    {
      rt::lock(_lastUsedResourceCache);
      if (culture->get_Name() == _lastUsedResourceCache->lastCultureName) {
        return _lastUsedResourceCache->lastResourceSet;
      }
    }
  }
  Dictionary<String, ResourceSet> resourceSets = _resourceSets;
  ResourceSet value = nullptr;
  if (resourceSets != nullptr) {
    {
      rt::lock(resourceSets);
      resourceSets->TryGetValue(culture->get_Name(), value);
    }
  }
  if (value != nullptr) {
    if (_lastUsedResourceCache != nullptr) {
      {
        rt::lock(_lastUsedResourceCache);
        _lastUsedResourceCache->lastCultureName = culture->get_Name();
        _lastUsedResourceCache->lastResourceSet = value;
        return value;
      }
    }
    return value;
  }
  return nullptr;
}

ResourceSet ResourceManager___::GetResourceSet(CultureInfo culture, Boolean createIfNotExists, Boolean tryParents) {
  if (culture == nullptr) {
    rt::throw_exception<ArgumentNullException>("culture");
  }
  Dictionary<String, ResourceSet> resourceSets = _resourceSets;
  if (resourceSets != nullptr) {
    {
      rt::lock(resourceSets);
      ResourceSet value;
      if (resourceSets->TryGetValue(culture->get_Name(), value)) {
        return value;
      }
    }
  }
  if (_useManifest && culture->get_HasInvariantCultureName()) {
    String resourceFileName = GetResourceFileName(culture);
    Stream manifestResourceStream = MainAssembly->GetManifestResourceStream(_locationInfo, resourceFileName);
    if (createIfNotExists && manifestResourceStream != nullptr) {
      ResourceSet value = ((ManifestBasedResourceGroveler)_resourceGroveler)->CreateResourceSet(manifestResourceStream, MainAssembly);
      AddResourceSet(resourceSets, culture->get_Name(), value);
      return value;
    }
  }
  return InternalGetResourceSet(culture, createIfNotExists, tryParents);
}

ResourceSet ResourceManager___::InternalGetResourceSet(CultureInfo culture, Boolean createIfNotExists, Boolean tryParents) {
  Dictionary<String, ResourceSet> resourceSets = _resourceSets;
  ResourceSet value = nullptr;
  CultureInfo cultureInfo = nullptr;
  {
    rt::lock(resourceSets);
    if (resourceSets->TryGetValue(culture->get_Name(), value)) {
      return value;
    }
  }
  ResourceFallbackManager resourceFallbackManager = rt::newobj<ResourceFallbackManager>(culture, _neutralResourcesCulture, tryParents);
  for (CultureInfo&& item : rt::each(resourceFallbackManager)) {
    {
      rt::lock(resourceSets);
      if (resourceSets->TryGetValue(item->get_Name(), value)) {
        if (culture != item) {
          cultureInfo = item;
        }
        goto IL_00c9;
      }
    }
    value = _resourceGroveler->GrovelForResourceSet(item, resourceSets, tryParents, createIfNotExists);
    if (value != nullptr) {
      cultureInfo = item;
      break;
    }
  }
  goto IL_00c9;

IL_00c9:
  if (value != nullptr && cultureInfo != nullptr) {
    for (CultureInfo&& item2 : rt::each(resourceFallbackManager)) {
      AddResourceSet(resourceSets, item2->get_Name(), value);
      if (item2 == cultureInfo) {
        return value;
      }
    }
    return value;
  }
  return value;
}

void ResourceManager___::AddResourceSet(Dictionary<String, ResourceSet> localResourceSets, String cultureName, ResourceSet& rs) {
  {
    rt::lock(localResourceSets);
    ResourceSet value;
    if (localResourceSets->TryGetValue(cultureName, value)) {
      if (value != rs) {
        if (!localResourceSets->ContainsValue(rs)) {
          rs->Dispose();
        }
        rs = value;
      }
    } else {
      localResourceSets->Add(cultureName, rs);
    }
  }
}

Version ResourceManager___::GetSatelliteContractVersion(Assembly a) {
  if (a == nullptr) {
    rt::throw_exception<ArgumentNullException>("a", SR::get_ArgumentNull_Assembly());
  }
  SatelliteContractVersionAttribute customAttribute = CustomAttributeExtensions::GetCustomAttribute(a);
  String text = (customAttribute != nullptr) ? customAttribute->get_Version() : nullptr;
  if (text == nullptr) {
    return nullptr;
  }
  Version result;
  if (!Version::in::TryParse(text, result)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_InvalidSatelliteContract_Asm_Ver(), a, text));
  }
  return result;
}

CultureInfo ResourceManager___::GetNeutralResourcesLanguage(Assembly a) {
  UltimateResourceFallbackLocation fallbackLocation;
  return ManifestBasedResourceGroveler::in::GetNeutralResourcesLanguage(a, fallbackLocation);
}

Boolean ResourceManager___::IsDefaultType(String asmTypeName, String typeName) {
  Int32 num = asmTypeName->IndexOf(44);
  if (((num == -1) ? asmTypeName->get_Length() : num) != typeName->get_Length()) {
    return false;
  }
  if (String::in::Compare(asmTypeName, 0, typeName, 0, typeName->get_Length(), StringComparison::Ordinal) != 0) {
    return false;
  }
  if (num == -1) {
    return true;
  }
  while (Char::IsWhiteSpace(asmTypeName[++num])) {
  }
  AssemblyName assemblyName = rt::newobj<AssemblyName>(asmTypeName->Substring(num));
  return String::in::Equals(assemblyName->get_Name(), "mscorlib", StringComparison::OrdinalIgnoreCase);
}

String ResourceManager___::GetString(String name) {
  return GetString(name, nullptr);
}

String ResourceManager___::GetString(String name, CultureInfo culture) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (culture == nullptr) {
    culture = CultureInfo::in::set_CurrentUICulture();
  }
  ResourceSet resourceSet = GetFirstResourceSet(culture);
  if (resourceSet != nullptr) {
    String string = resourceSet->GetString(name, _ignoreCase);
    if (string != nullptr) {
      return string;
    }
  }
  ResourceFallbackManager resourceFallbackManager = rt::newobj<ResourceFallbackManager>(culture, _neutralResourcesCulture, true);
  for (CultureInfo&& item : rt::each(resourceFallbackManager)) {
    ResourceSet resourceSet2 = InternalGetResourceSet(item, true, true);
    if (resourceSet2 == nullptr) {
      break;
    }
    if (resourceSet2 == resourceSet) {
      continue;
    }
    String string2 = resourceSet2->GetString(name, _ignoreCase);
    if (string2 != nullptr) {
      if (_lastUsedResourceCache != nullptr) {
        {
          rt::lock(_lastUsedResourceCache);
          _lastUsedResourceCache->lastCultureName = item->get_Name();
          _lastUsedResourceCache->lastResourceSet = resourceSet2;
        }
      }
      return string2;
    }
    resourceSet = resourceSet2;
  }
  return nullptr;
}

Object ResourceManager___::GetObject(String name) {
  return GetObject(name, nullptr, true);
}

Object ResourceManager___::GetObject(String name, CultureInfo culture) {
  return GetObject(name, culture, true);
}

Object ResourceManager___::GetObject(String name, CultureInfo culture, Boolean wrapUnmanagedMemStream) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (culture == nullptr) {
    culture = CultureInfo::in::set_CurrentUICulture();
  }
  ResourceSet resourceSet = GetFirstResourceSet(culture);
  if (resourceSet != nullptr) {
    Object object = resourceSet->GetObject(name, _ignoreCase);
    if (object != nullptr) {
      UnmanagedMemoryStream unmanagedMemoryStream = rt::as<UnmanagedMemoryStream>(object);
      if (unmanagedMemoryStream != nullptr && wrapUnmanagedMemStream) {
        return rt::newobj<UnmanagedMemoryStreamWrapper>(unmanagedMemoryStream);
      }
      return object;
    }
  }
  ResourceFallbackManager resourceFallbackManager = rt::newobj<ResourceFallbackManager>(culture, _neutralResourcesCulture, true);
  for (CultureInfo&& item : rt::each(resourceFallbackManager)) {
    ResourceSet resourceSet2 = InternalGetResourceSet(item, true, true);
    if (resourceSet2 == nullptr) {
      break;
    }
    if (resourceSet2 == resourceSet) {
      continue;
    }
    Object object2 = resourceSet2->GetObject(name, _ignoreCase);
    if (object2 != nullptr) {
      if (_lastUsedResourceCache != nullptr) {
        {
          rt::lock(_lastUsedResourceCache);
          _lastUsedResourceCache->lastCultureName = item->get_Name();
          _lastUsedResourceCache->lastResourceSet = resourceSet2;
        }
      }
      UnmanagedMemoryStream unmanagedMemoryStream2 = rt::as<UnmanagedMemoryStream>(object2);
      if (unmanagedMemoryStream2 != nullptr && wrapUnmanagedMemStream) {
        return rt::newobj<UnmanagedMemoryStreamWrapper>(unmanagedMemoryStream2);
      }
      return object2;
    }
    resourceSet = resourceSet2;
  }
  return nullptr;
}

UnmanagedMemoryStream ResourceManager___::GetStream(String name) {
  return GetStream(name, nullptr);
}

UnmanagedMemoryStream ResourceManager___::GetStream(String name, CultureInfo culture) {
  Object object = GetObject(name, culture, false);
  UnmanagedMemoryStream unmanagedMemoryStream = rt::as<UnmanagedMemoryStream>(object);
  if (unmanagedMemoryStream == nullptr && object != nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_InvalidOperation_ResourceNotStream_Name(), name));
  }
  return unmanagedMemoryStream;
}

void ResourceManager___::cctor() {
  MagicNumber = -1091581234;
  HeaderVersionNumber = 1;
  s_minResourceSet = typeof<ResourceSet>();
}

} // namespace System::Private::CoreLib::System::Resources::ResourceManagerNamespace
