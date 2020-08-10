#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractReferenceAssemblyAttributeNamespace {
CLASS(ContractReferenceAssemblyAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace ContractReferenceAssemblyAttributeNamespace
using ContractReferenceAssemblyAttribute = ContractReferenceAssemblyAttributeNamespace::ContractReferenceAssemblyAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
