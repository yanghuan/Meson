#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace DoesNotReturnAttributeNamespace {
CLASS(DoesNotReturnAttribute) {
  public: void Ctor();
};
} // namespace DoesNotReturnAttributeNamespace
using DoesNotReturnAttribute = DoesNotReturnAttributeNamespace::DoesNotReturnAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
