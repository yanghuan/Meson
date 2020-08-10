#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace DoesNotReturnAttributeNamespace {
CLASS(DoesNotReturnAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace DoesNotReturnAttributeNamespace
using DoesNotReturnAttribute = DoesNotReturnAttributeNamespace::DoesNotReturnAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
