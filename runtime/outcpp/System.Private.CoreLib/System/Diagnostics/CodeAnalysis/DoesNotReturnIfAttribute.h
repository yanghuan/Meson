#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace DoesNotReturnIfAttributeNamespace {
CLASS(DoesNotReturnIfAttribute) {
  public: Boolean get_ParameterValue() { return ParameterValue; }
  public: void Ctor(Boolean parameterValue);
  private: Boolean ParameterValue;
};
} // namespace DoesNotReturnIfAttributeNamespace
using DoesNotReturnIfAttribute = DoesNotReturnIfAttributeNamespace::DoesNotReturnIfAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
