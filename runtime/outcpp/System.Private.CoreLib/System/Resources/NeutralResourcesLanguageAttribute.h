#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
enum class UltimateResourceFallbackLocation;
namespace NeutralResourcesLanguageAttributeNamespace {
CLASS(NeutralResourcesLanguageAttribute) : public Attribute::in {
  public: String get_CultureName() { return CultureName; }
  public: UltimateResourceFallbackLocation get_Location() { return Location; }
  public: void ctor(String cultureName);
  public: void ctor(String cultureName, UltimateResourceFallbackLocation location);
  private: String CultureName;
  private: UltimateResourceFallbackLocation Location;
};
} // namespace NeutralResourcesLanguageAttributeNamespace
using NeutralResourcesLanguageAttribute = NeutralResourcesLanguageAttributeNamespace::NeutralResourcesLanguageAttribute;
} // namespace System::Private::CoreLib::System::Resources
