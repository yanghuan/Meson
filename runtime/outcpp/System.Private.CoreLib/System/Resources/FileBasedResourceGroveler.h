#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Resources/ResourceManager.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
FORWARD(IResourceGroveler)
FORWARD(ResourceSet)
namespace FileBasedResourceGrovelerNamespace {
using namespace Collections::Generic;
using namespace Globalization;
CLASS(FileBasedResourceGroveler) : public Object::in {
  using interface = rt::TypeList<IResourceGroveler>;
  public: void Ctor(ResourceManager::in::ResourceManagerMediator mediator);
  public: ResourceSet GrovelForResourceSet(CultureInfo culture, Dictionary<String, ResourceSet> localResourceSets, Boolean tryParents, Boolean createIfNotExists);
  private: String FindResourceFile(CultureInfo culture, String fileName);
  private: ResourceSet CreateResourceSet(String file);
  private: ResourceManager::in::ResourceManagerMediator _mediator;
};
} // namespace FileBasedResourceGrovelerNamespace
using FileBasedResourceGroveler = FileBasedResourceGrovelerNamespace::FileBasedResourceGroveler;
} // namespace System::Private::CoreLib::System::Resources
