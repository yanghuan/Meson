#include "ContractClassForAttribute-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractClassForAttributeNamespace {
Type ContractClassForAttribute___::get_TypeContractsAreFor() {
  return _typeIAmAContractFor;
}

void ContractClassForAttribute___::ctor(Type typeContractsAreFor) {
  _typeIAmAContractFor = typeContractsAreFor;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractClassForAttributeNamespace
