#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace ExcludeFromCodeCoverageAttributeNamespace {
CLASS(ExcludeFromCodeCoverageAttribute) {
  public: void Ctor();
};
} // namespace ExcludeFromCodeCoverageAttributeNamespace
using ExcludeFromCodeCoverageAttribute = ExcludeFromCodeCoverageAttributeNamespace::ExcludeFromCodeCoverageAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
