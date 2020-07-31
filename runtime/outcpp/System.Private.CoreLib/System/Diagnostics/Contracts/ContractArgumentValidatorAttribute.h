#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractArgumentValidatorAttributeNamespace {
CLASS(ContractArgumentValidatorAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace ContractArgumentValidatorAttributeNamespace
using ContractArgumentValidatorAttribute = ContractArgumentValidatorAttributeNamespace::ContractArgumentValidatorAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
