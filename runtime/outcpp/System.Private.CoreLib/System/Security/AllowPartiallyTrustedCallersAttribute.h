#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
enum class PartialTrustVisibilityLevel;
namespace AllowPartiallyTrustedCallersAttributeNamespace {
CLASS(AllowPartiallyTrustedCallersAttribute) {
  public: PartialTrustVisibilityLevel get_PartialTrustVisibilityLevel() { return PartialTrustVisibilityLevel; }
  public: void set_PartialTrustVisibilityLevel(PartialTrustVisibilityLevel value) { PartialTrustVisibilityLevel = value; }
  private: PartialTrustVisibilityLevel PartialTrustVisibilityLevel;
};
} // namespace AllowPartiallyTrustedCallersAttributeNamespace
using AllowPartiallyTrustedCallersAttribute = AllowPartiallyTrustedCallersAttributeNamespace::AllowPartiallyTrustedCallersAttribute;
} // namespace System::Private::CoreLib::System::Security
