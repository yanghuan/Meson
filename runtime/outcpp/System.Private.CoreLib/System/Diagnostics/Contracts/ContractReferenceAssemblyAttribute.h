#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractReferenceAssemblyAttributeNamespace {
CLASS(ContractReferenceAssemblyAttribute) {
  public: void Ctor();
};
} // namespace ContractReferenceAssemblyAttributeNamespace
using ContractReferenceAssemblyAttribute = ContractReferenceAssemblyAttributeNamespace::ContractReferenceAssemblyAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
