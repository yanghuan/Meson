#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
enum class UltimateResourceFallbackLocation;
namespace NeutralResourcesLanguageAttributeNamespace {
CLASS(NeutralResourcesLanguageAttribute) {
  private: String CultureName;
  private: UltimateResourceFallbackLocation Location;
};
} // namespace NeutralResourcesLanguageAttributeNamespace
using NeutralResourcesLanguageAttribute = NeutralResourcesLanguageAttributeNamespace::NeutralResourcesLanguageAttribute;
} // namespace System::Private::CoreLib::System::Resources
