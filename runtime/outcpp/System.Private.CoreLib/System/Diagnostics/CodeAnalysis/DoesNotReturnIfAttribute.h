#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace DoesNotReturnIfAttributeNamespace {
CLASS(DoesNotReturnIfAttribute) {
  private: Boolean ParameterValue;
};
} // namespace DoesNotReturnIfAttributeNamespace
using DoesNotReturnIfAttribute = DoesNotReturnIfAttributeNamespace::DoesNotReturnIfAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
