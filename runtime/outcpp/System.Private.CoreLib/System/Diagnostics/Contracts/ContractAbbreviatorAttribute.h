#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractAbbreviatorAttributeNamespace {
CLASS(ContractAbbreviatorAttribute) {
  public: void Ctor();
};
} // namespace ContractAbbreviatorAttributeNamespace
using ContractAbbreviatorAttribute = ContractAbbreviatorAttributeNamespace::ContractAbbreviatorAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
