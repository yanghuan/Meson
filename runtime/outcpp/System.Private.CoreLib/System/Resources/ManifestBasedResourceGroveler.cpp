#include "ManifestBasedResourceGroveler-dep.h"

#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/BadImageFormatException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IO/BinaryReader-dep.h>
#include <System.Private.CoreLib/System/IO/FileLoadException-dep.h>
#include <System.Private.CoreLib/System/IO/SeekOrigin.h>
#include <System.Private.CoreLib/System/IO/Stream-dep.h>
#include <System.Private.CoreLib/System/MissingMethodException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>
#include <System.Private.CoreLib/System/Resources/FastResourceComparer-dep.h>
#include <System.Private.CoreLib/System/Resources/IResourceReader.h>
#include <System.Private.CoreLib/System/Resources/MissingManifestResourceException-dep.h>
#include <System.Private.CoreLib/System/Resources/MissingSatelliteAssemblyException-dep.h>
#include <System.Private.CoreLib/System/Resources/NeutralResourcesLanguageAttribute-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceLocator-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceReader-dep.h>
#include <System.Private.CoreLib/System/Resources/RuntimeResourceSet-dep.h>
#include <System.Private.CoreLib/System/Resources/UltimateResourceFallbackLocation.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Resources::ManifestBasedResourceGrovelerNamespace {
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Text;

Assembly ManifestBasedResourceGroveler___::InternalGetSatelliteAssembly(Assembly mainAssembly, CultureInfo culture, Version version) {
  return ((RuntimeAssembly)mainAssembly)->InternalGetSatelliteAssembly(culture, version, false);
}

void ManifestBasedResourceGroveler___::ctor(ResourceManager::in::ResourceManagerMediator mediator) {
  _mediator = mediator;
}

ResourceSet ManifestBasedResourceGroveler___::GrovelForResourceSet(CultureInfo culture, Dictionary<String, ResourceSet> localResourceSets, Boolean tryParents, Boolean createIfNotExists) {
  ResourceSet value = nullptr;
  Stream stream = nullptr;
  CultureInfo cultureInfo = UltimateFallbackFixup(culture);
  Assembly assembly;
  if (cultureInfo->get_HasInvariantCultureName() && _mediator->get_FallbackLoc() == UltimateResourceFallbackLocation::MainAssembly) {
    assembly = _mediator->get_MainAssembly();
  } else {
    assembly = GetSatelliteAssembly(cultureInfo);
    if (assembly == nullptr && culture->get_HasInvariantCultureName() && _mediator->get_FallbackLoc() == UltimateResourceFallbackLocation::Satellite) {
      HandleSatelliteMissing();
    }
  }
  String resourceFileName = _mediator->GetResourceFileName(cultureInfo);
  if (assembly != nullptr) {
    {
      rt::lock(localResourceSets);
      localResourceSets->TryGetValue(culture->get_Name(), value);
    }
    stream = GetManifestResourceStream(assembly, resourceFileName);
  }
  if (createIfNotExists && stream != nullptr && value == nullptr) {
    value = CreateResourceSet(stream, assembly);
  } else if (stream == nullptr && tryParents && culture->get_HasInvariantCultureName()) {
    HandleResourceStreamMissing(resourceFileName);
  }

  return value;
}

CultureInfo ManifestBasedResourceGroveler___::UltimateFallbackFixup(CultureInfo lookForCulture) {
  CultureInfo result = lookForCulture;
  if (lookForCulture->get_Name() == _mediator->get_NeutralResourcesCulture()->get_Name() && _mediator->get_FallbackLoc() == UltimateResourceFallbackLocation::MainAssembly) {
    result = CultureInfo::in::get_InvariantCulture();
  } else if (lookForCulture->get_HasInvariantCultureName() && _mediator->get_FallbackLoc() == UltimateResourceFallbackLocation::Satellite) {
    result = _mediator->get_NeutralResourcesCulture();
  }

  return result;
}

CultureInfo ManifestBasedResourceGroveler___::GetNeutralResourcesLanguage(Assembly a, UltimateResourceFallbackLocation& fallbackLocation) {
  NeutralResourcesLanguageAttribute customAttribute = CustomAttributeExtensions::GetCustomAttribute(a);
  if (customAttribute == nullptr) {
    fallbackLocation = UltimateResourceFallbackLocation::MainAssembly;
    return CultureInfo::in::get_InvariantCulture();
  }
  fallbackLocation = customAttribute->get_Location();
  if (fallbackLocation < UltimateResourceFallbackLocation::MainAssembly || fallbackLocation > UltimateResourceFallbackLocation::Satellite) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_InvalidNeutralResourcesLanguage_FallbackLoc(), fallbackLocation));
  }
  try {
    return CultureInfo::in::GetCultureInfo(customAttribute->get_CultureName());
  } catch (ArgumentException innerException) {
  }
}

ResourceSet ManifestBasedResourceGroveler___::CreateResourceSet(Stream store, Assembly assembly) {
  if (store->get_CanSeek() && store->get_Length() > 4) {
    Int64 position = store->get_Position();
    BinaryReader binaryReader = rt::newobj<BinaryReader>(store);
    Int32 num = binaryReader->ReadInt32();
    if (num == ResourceManager::in::MagicNumber) {
      Int32 num2 = binaryReader->ReadInt32();
      String text = nullptr;
      String text2 = nullptr;
      if (num2 == ResourceManager::in::HeaderVersionNumber) {
        binaryReader->ReadInt32();
        text = binaryReader->ReadString();
        text2 = binaryReader->ReadString();
      } else {
        if (num2 <= ResourceManager::in::HeaderVersionNumber) {
          rt::throw_exception<NotSupportedException>(SR::Format(SR::get_NotSupported_ObsoleteResourcesFile(), _mediator->get_MainAssembly()->GetName()->get_Name()));
        }
        Int32 num3 = binaryReader->ReadInt32();
        Int64 offset = binaryReader->get_BaseStream()->get_Position() + num3;
        text = binaryReader->ReadString();
        text2 = binaryReader->ReadString();
        binaryReader->get_BaseStream()->Seek(offset, SeekOrigin::Begin);
      }
      store->set_Position(position);
      if (CanUseDefaultResourceClasses(text, text2)) {
        return rt::newobj<RuntimeResourceSet>(store, true);
      }
      IResourceReader resourceReader;
      if (ResourceManager::in::IsDefaultType(text, "System.Resources.ResourceReader")) {
        resourceReader = rt::newobj<ResourceReader>(store, rt::newobj<Dictionary<String, ResourceLocator>>(FastResourceComparer::in::Default), true);
      } else {
        Type type = Type::in::GetType(text, true);
        resourceReader = (IResourceReader)Activator::CreateInstance(type, store);
      }
      Array<Object> args = rt::newarr<Array<Object>>(1);
      Type type2 = (!(_mediator->get_UserResourceSet() == nullptr)) ? _mediator->get_UserResourceSet() : Type::in::GetType(text2, true, false);
      return (ResourceSet)Activator::CreateInstance(type2, BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic | BindingFlags::CreateInstance, nullptr, args, nullptr, nullptr);
    }
    store->set_Position(position);
  }
  if (_mediator->get_UserResourceSet() == nullptr) {
    return rt::newobj<RuntimeResourceSet>(store, true);
  }
  Array<Object> args2 = rt::newarr<Array<Object>>(2);
  try {
    try {
      return (ResourceSet)Activator::CreateInstance(_mediator->get_UserResourceSet(), args2);
    } catch (MissingMethodException) {
    }
    args2 = rt::newarr<Array<Object>>(1);
    return (ResourceSet)Activator::CreateInstance(_mediator->get_UserResourceSet(), args2);
  } catch (MissingMethodException innerException) {
  }
}

Stream ManifestBasedResourceGroveler___::GetManifestResourceStream(Assembly satellite, String fileName) {
  Stream as = satellite->GetManifestResourceStream(_mediator->get_LocationInfo(), fileName);
  return as != nullptr ? as : CaseInsensitiveManifestResourceStreamLookup(satellite, fileName);
}

Stream ManifestBasedResourceGroveler___::CaseInsensitiveManifestResourceStreamLookup(Assembly satellite, String name) {
  Type locationInfo = _mediator->get_LocationInfo();
  String text = ((Object)locationInfo != nullptr) ? locationInfo->get_Namespace() : nullptr;
  Char ptr = Type::in::Delimiter;
  String text2 = (text != nullptr && name != nullptr) ? String::in::Concat(text, ReadOnlySpan<Char>(ptr, 1), name) : (text + name);
  String text3 = nullptr;
  Array<String> manifestResourceNames = satellite->GetManifestResourceNames();
}

Assembly ManifestBasedResourceGroveler___::GetSatelliteAssembly(CultureInfo lookForCulture) {
  if (!_mediator->get_LookedForSatelliteContractVersion()) {
    _mediator->set_SatelliteContractVersion(ResourceManager::in::ResourceManagerMediator::in::ObtainSatelliteContractVersion(_mediator->get_MainAssembly()));
    _mediator->set_LookedForSatelliteContractVersion(true);
  }
  Assembly result = nullptr;
  try {
    result = InternalGetSatelliteAssembly(_mediator->get_MainAssembly(), lookForCulture, _mediator->get_SatelliteContractVersion());
    return result;
  } catch (FileLoadException) {
  } catch (BadImageFormatException) {
  }
}

Boolean ManifestBasedResourceGroveler___::CanUseDefaultResourceClasses(String readerTypeName, String resSetTypeName) {
  if (_mediator->get_UserResourceSet() != nullptr) {
    return false;
  }
  if (readerTypeName != nullptr && !ResourceManager::in::IsDefaultType(readerTypeName, "System.Resources.ResourceReader")) {
    return false;
  }
  if (resSetTypeName != nullptr && !ResourceManager::in::IsDefaultType(resSetTypeName, "System.Resources.RuntimeResourceSet")) {
    return false;
  }
  return true;
}

void ManifestBasedResourceGroveler___::HandleSatelliteMissing() {
  String text = _mediator->get_MainAssembly()->GetName()->get_Name() + ".resources.dll";
  if (_mediator->get_SatelliteContractVersion() != nullptr) {
    text = text + ", Version=" + _mediator->get_SatelliteContractVersion()->ToString();
  }
  Array<Byte> publicKeyToken = _mediator->get_MainAssembly()->GetName()->GetPublicKeyToken();
  if (publicKeyToken != nullptr) {
    Int32 num = publicKeyToken->get_Length();
    StringBuilder stringBuilder = rt::newobj<StringBuilder>(num * 2);
    for (Int32 i = 0; i < num; i++) {
      stringBuilder->Append(publicKeyToken[i].ToString("x", CultureInfo::in::get_InvariantCulture()));
    }
    text = text + ", PublicKeyToken=" + ((stringBuilder != nullptr) ? stringBuilder->ToString() : nullptr);
  }
  String text2 = _mediator->get_NeutralResourcesCulture()->get_Name();
  if (text2->get_Length() == 0) {
    text2 = "<invariant>";
  }
  rt::throw_exception<MissingSatelliteAssemblyException>(SR::Format(SR::get_MissingSatelliteAssembly_Culture_Name(), _mediator->get_NeutralResourcesCulture(), text), text2);
}

String ManifestBasedResourceGroveler___::GetManifestResourceNamesList(Assembly assembly) {
  try {
    Array<String> manifestResourceNames = assembly->GetManifestResourceNames();
    Int32 num = manifestResourceNames->get_Length();
    String str = """;
    if (num > 10) {
      num = 10;
      str = "", ...";
    }
    return """ + String::in::Join("", "", manifestResourceNames, 0, num) + str;
  } catch (...) {
  }
}

void ManifestBasedResourceGroveler___::HandleResourceStreamMissing(String fileName) {
  if (_mediator->get_MainAssembly() == typeof<Object>()->get_Assembly() && _mediator->get_BaseName()->Equals("System.Private.CoreLib")) {
    Environment::FailFast("System.Private.CoreLib.resources couldn't be found!  Large parts of the BCL won't work!");
  }
  String str = String::in::Empty;
  if (_mediator->get_LocationInfo() != nullptr && _mediator->get_LocationInfo()->get_Namespace() != nullptr) {
    str = _mediator->get_LocationInfo()->get_Namespace() + Type::in::Delimiter;
  }
  str += fileName;
  rt::throw_exception<MissingManifestResourceException>(SR::Format(SR::get_MissingManifestResource_NoNeutralAsm(), str, _mediator->get_MainAssembly()->GetName()->get_Name(), GetManifestResourceNamesList(_mediator->get_MainAssembly())));
}

} // namespace System::Private::CoreLib::System::Resources::ManifestBasedResourceGrovelerNamespace
