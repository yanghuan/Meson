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
using namespace System::Collections::Generic;
using namespace System::Globalization;
CLASS(IResourceGroveler) : public object {
  public: ResourceSet GrovelForResourceSet(CultureInfo culture, Dictionary<String, ResourceSet> localResourceSets, Boolean tryParents, Boolean createIfNotExists);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IResourceGrovelerNamespace
using IResourceGroveler = IResourceGrovelerNamespace::IResourceGroveler;
} // namespace System::Private::CoreLib::System::Resources
