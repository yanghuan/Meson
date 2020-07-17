#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractArgumentValidatorAttributeNamespace {
CLASS(ContractArgumentValidatorAttribute) {
  public: void Ctor();
};
} // namespace ContractArgumentValidatorAttributeNamespace
using ContractArgumentValidatorAttribute = ContractArgumentValidatorAttributeNamespace::ContractArgumentValidatorAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
