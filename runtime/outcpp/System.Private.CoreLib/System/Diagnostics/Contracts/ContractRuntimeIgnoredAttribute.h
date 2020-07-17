#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractRuntimeIgnoredAttributeNamespace {
CLASS(ContractRuntimeIgnoredAttribute) {
  public: void Ctor();
};
} // namespace ContractRuntimeIgnoredAttributeNamespace
using ContractRuntimeIgnoredAttribute = ContractRuntimeIgnoredAttributeNamespace::ContractRuntimeIgnoredAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
