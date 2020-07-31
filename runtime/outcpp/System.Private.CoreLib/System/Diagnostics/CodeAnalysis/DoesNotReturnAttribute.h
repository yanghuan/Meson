#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace DoesNotReturnAttributeNamespace {
CLASS(DoesNotReturnAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace DoesNotReturnAttributeNamespace
using DoesNotReturnAttribute = DoesNotReturnAttributeNamespace::DoesNotReturnAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
