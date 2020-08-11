#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Security {
enum class PartialTrustVisibilityLevel : int32_t;
namespace AllowPartiallyTrustedCallersAttributeNamespace {
CLASS(AllowPartiallyTrustedCallersAttribute) : public Attribute::in {
  public: PartialTrustVisibilityLevel get_PartialTrustVisibilityLevel() { return PartialTrustVisibilityLevel; }
  public: void set_PartialTrustVisibilityLevel(PartialTrustVisibilityLevel value) { PartialTrustVisibilityLevel = value; }
  public: void ctor();
  private: PartialTrustVisibilityLevel PartialTrustVisibilityLevel;
};
} // namespace AllowPartiallyTrustedCallersAttributeNamespace
using AllowPartiallyTrustedCallersAttribute = AllowPartiallyTrustedCallersAttributeNamespace::AllowPartiallyTrustedCallersAttribute;
} // namespace System::Private::CoreLib::System::Security
