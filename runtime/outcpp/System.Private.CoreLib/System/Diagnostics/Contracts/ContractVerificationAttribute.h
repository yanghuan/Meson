#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractVerificationAttributeNamespace {
CLASS(ContractVerificationAttribute) : public Attribute::in {
  public: Boolean get_Value();
  public: void Ctor(Boolean value);
  private: Boolean _value;
};
} // namespace ContractVerificationAttributeNamespace
using ContractVerificationAttribute = ContractVerificationAttributeNamespace::ContractVerificationAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
