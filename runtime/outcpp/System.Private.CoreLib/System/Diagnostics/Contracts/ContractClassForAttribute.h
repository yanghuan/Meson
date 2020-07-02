#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractClassForAttributeNamespace {
CLASS(ContractClassForAttribute) {
  public: Type get_TypeContractsAreFor();
  private: Type _typeIAmAContractFor;
};
} // namespace ContractClassForAttributeNamespace
using ContractClassForAttribute = ContractClassForAttributeNamespace::ContractClassForAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
