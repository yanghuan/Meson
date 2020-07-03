#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
enum class PartialTrustVisibilityLevel;
namespace AllowPartiallyTrustedCallersAttributeNamespace {
CLASS(AllowPartiallyTrustedCallersAttribute) {
  private: PartialTrustVisibilityLevel PartialTrustVisibilityLevel;
};
} // namespace AllowPartiallyTrustedCallersAttributeNamespace
using AllowPartiallyTrustedCallersAttribute = AllowPartiallyTrustedCallersAttributeNamespace::AllowPartiallyTrustedCallersAttribute;
} // namespace System::Private::CoreLib::System::Security
