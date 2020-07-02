#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceSet)
namespace IResourceGrovelerNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(IResourceGroveler) {
  public: ResourceSet GrovelForResourceSet(CultureInfo culture, Dictionary<String, ResourceSet> localResourceSets, Boolean tryParents, Boolean createIfNotExists);
};
} // namespace IResourceGrovelerNamespace
using IResourceGroveler = IResourceGrovelerNamespace::IResourceGroveler;
} // namespace System::Private::CoreLib::System::Resources
