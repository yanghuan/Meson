#include "FileBasedResourceGroveler-dep.h"

#include <System.Private.CoreLib/Internal/IO/File-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/MissingMethodException-dep.h>
#include <System.Private.CoreLib/System/Resources/MissingManifestResourceException-dep.h>
#include <System.Private.CoreLib/System/Resources/RuntimeResourceSet-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Resources::FileBasedResourceGrovelerNamespace {
using namespace Internal::IO;
using namespace System::IO;

void FileBasedResourceGroveler___::ctor(ResourceManager::in::ResourceManagerMediator mediator) {
  _mediator = mediator;
}

ResourceSet FileBasedResourceGroveler___::GrovelForResourceSet(CultureInfo culture, Dictionary<String, ResourceSet> localResourceSets, Boolean tryParents, Boolean createIfNotExists) {
  ResourceSet result = nullptr;
  String resourceFileName = _mediator->GetResourceFileName(culture);
  String text = FindResourceFile(culture, resourceFileName);
  if (text == nullptr) {
    if (tryParents && culture->get_HasInvariantCultureName()) {
      rt::throw_exception<MissingManifestResourceException>(SR::get_MissingManifestResource_NoNeutralDisk() + "
baseName: " + _mediator->get_BaseNameField() + "  locationInfo: " + ((_mediator->get_LocationInfo() == nullptr) ? "<null>" : _mediator->get_LocationInfo()->get_FullName()) + "  fileName: " + _mediator->GetResourceFileName(culture));
    }
  } else {
    result = CreateResourceSet(text);
  }
  return result;
}

String FileBasedResourceGroveler___::FindResourceFile(CultureInfo culture, String fileName) {
  if (_mediator->get_ModuleDir() != nullptr) {
    String text = Path::Combine(_mediator->get_ModuleDir(), fileName);
    if (File::Exists(text)) {
      return text;
    }
  }
  if (File::Exists(fileName)) {
    return fileName;
  }
  return nullptr;
}

ResourceSet FileBasedResourceGroveler___::CreateResourceSet(String file) {
  if (_mediator->get_UserResourceSet() == nullptr) {
    return rt::newobj<RuntimeResourceSet>(file);
  }
  Array<Object> args = rt::newarr<Array<Object>>(1);
  try{
    return (ResourceSet)Activator::CreateInstance(_mediator->get_UserResourceSet(), rt::newarr<Array<Object>>(1, args));
  } catch (MissingMethodException innerException) {
  }
}

} // namespace System::Private::CoreLib::System::Resources::FileBasedResourceGrovelerNamespace
