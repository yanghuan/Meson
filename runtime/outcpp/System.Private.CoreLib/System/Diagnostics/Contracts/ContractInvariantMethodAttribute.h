#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractInvariantMethodAttributeNamespace {
CLASS(ContractInvariantMethodAttribute) {
  public: void Ctor();
};
} // namespace ContractInvariantMethodAttributeNamespace
using ContractInvariantMethodAttribute = ContractInvariantMethodAttributeNamespace::ContractInvariantMethodAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
