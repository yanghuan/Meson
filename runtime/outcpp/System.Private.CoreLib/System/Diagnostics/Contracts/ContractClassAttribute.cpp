#include "ContractClassAttribute-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractClassAttributeNamespace {
Type ContractClassAttribute___::get_TypeContainingContracts() {
  return _typeWithContracts;
}

void ContractClassAttribute___::ctor(Type typeContainingContracts) {
  _typeWithContracts = typeContainingContracts;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractClassAttributeNamespace
