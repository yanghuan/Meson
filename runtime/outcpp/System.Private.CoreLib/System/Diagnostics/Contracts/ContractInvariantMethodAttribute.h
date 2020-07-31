#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractInvariantMethodAttributeNamespace {
CLASS(ContractInvariantMethodAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace ContractInvariantMethodAttributeNamespace
using ContractInvariantMethodAttribute = ContractInvariantMethodAttributeNamespace::ContractInvariantMethodAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
