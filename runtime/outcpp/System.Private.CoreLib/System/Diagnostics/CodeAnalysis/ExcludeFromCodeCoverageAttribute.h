#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace ExcludeFromCodeCoverageAttributeNamespace {
CLASS(ExcludeFromCodeCoverageAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace ExcludeFromCodeCoverageAttributeNamespace
using ExcludeFromCodeCoverageAttribute = ExcludeFromCodeCoverageAttributeNamespace::ExcludeFromCodeCoverageAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
