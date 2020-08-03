#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractRuntimeIgnoredAttributeNamespace {
CLASS(ContractRuntimeIgnoredAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace ContractRuntimeIgnoredAttributeNamespace
using ContractRuntimeIgnoredAttribute = ContractRuntimeIgnoredAttributeNamespace::ContractRuntimeIgnoredAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
