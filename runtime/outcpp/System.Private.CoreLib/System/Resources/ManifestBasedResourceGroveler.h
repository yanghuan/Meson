#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Resources/ResourceManager.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Resources {
enum class UltimateResourceFallbackLocation;
FORWARD(IResourceGroveler)
FORWARD(ResourceSet)
namespace ManifestBasedResourceGrovelerNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using namespace IO;
using namespace Reflection;
CLASS(ManifestBasedResourceGroveler) : public Object::in {
  using interface = rt::TypeList<IResourceGroveler>;
  private: static Assembly InternalGetSatelliteAssembly(Assembly mainAssembly, CultureInfo culture, Version version);
  public: void Ctor(ResourceManager::in::ResourceManagerMediator mediator);
  public: ResourceSet GrovelForResourceSet(CultureInfo culture, Dictionary<String, ResourceSet> localResourceSets, Boolean tryParents, Boolean createIfNotExists);
  private: CultureInfo UltimateFallbackFixup(CultureInfo lookForCulture);
  public: static CultureInfo GetNeutralResourcesLanguage(Assembly a, UltimateResourceFallbackLocation& fallbackLocation);
  public: ResourceSet CreateResourceSet(Stream store, Assembly assembly);
  private: Stream GetManifestResourceStream(Assembly satellite, String fileName);
  private: Stream CaseInsensitiveManifestResourceStreamLookup(Assembly satellite, String name);
  private: Assembly GetSatelliteAssembly(CultureInfo lookForCulture);
  private: Boolean CanUseDefaultResourceClasses(String readerTypeName, String resSetTypeName);
  private: void HandleSatelliteMissing();
  private: static String GetManifestResourceNamesList(Assembly assembly);
  private: void HandleResourceStreamMissing(String fileName);
  private: ResourceManager::in::ResourceManagerMediator _mediator;
};
} // namespace ManifestBasedResourceGrovelerNamespace
using ManifestBasedResourceGroveler = ManifestBasedResourceGrovelerNamespace::ManifestBasedResourceGroveler;
} // namespace System::Private::CoreLib::System::Resources
