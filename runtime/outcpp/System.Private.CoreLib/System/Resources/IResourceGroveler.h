#pragma once

#include <System.Private.CoreLib/System/Object.h>

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
FORWARD(ResourceSet)
namespace IResourceGrovelerNamespace {
using namespace Collections::Generic;
using namespace Globalization;
CLASS(IResourceGroveler) : public Object::in {
  public: ResourceSet GrovelForResourceSet(CultureInfo culture, Dictionary<String, ResourceSet> localResourceSets, Boolean tryParents, Boolean createIfNotExists);
};
} // namespace IResourceGrovelerNamespace
using IResourceGroveler = IResourceGrovelerNamespace::IResourceGroveler;
} // namespace System::Private::CoreLib::System::Resources
