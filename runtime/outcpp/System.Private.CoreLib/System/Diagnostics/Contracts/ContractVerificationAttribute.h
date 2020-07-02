#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractVerificationAttributeNamespace {
CLASS(ContractVerificationAttribute) {
  public: Boolean get_Value();
  private: Boolean _value;
};
} // namespace ContractVerificationAttributeNamespace
using ContractVerificationAttribute = ContractVerificationAttributeNamespace::ContractVerificationAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts