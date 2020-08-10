#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace DoesNotReturnIfAttributeNamespace {
CLASS(DoesNotReturnIfAttribute) : public Attribute::in {
  public: Boolean get_ParameterValue() { return ParameterValue; }
  public: void ctor(Boolean parameterValue);
  private: Boolean ParameterValue;
};
} // namespace DoesNotReturnIfAttributeNamespace
using DoesNotReturnIfAttribute = DoesNotReturnIfAttributeNamespace::DoesNotReturnIfAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
