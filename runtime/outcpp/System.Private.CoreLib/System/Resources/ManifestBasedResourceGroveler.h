#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Resources/ResourceManager.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD(Version)
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceSet)
enum class UltimateResourceFallbackLocation;
namespace ManifestBasedResourceGrovelerNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(ManifestBasedResourceGroveler) {
  private: static Assembly InternalGetSatelliteAssembly(Assembly mainAssembly, CultureInfo culture, Version version);
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
