#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractClassForAttributeNamespace {
CLASS(ContractClassForAttribute) {
  public: Type get_TypeContractsAreFor();
  public: void Ctor(Type typeContractsAreFor);
  private: Type _typeIAmAContractFor;
};
} // namespace ContractClassForAttributeNamespace
using ContractClassForAttribute = ContractClassForAttributeNamespace::ContractClassForAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
