#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractInvariantMethodAttributeNamespace {
CLASS(ContractInvariantMethodAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace ContractInvariantMethodAttributeNamespace
using ContractInvariantMethodAttribute = ContractInvariantMethodAttributeNamespace::ContractInvariantMethodAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
