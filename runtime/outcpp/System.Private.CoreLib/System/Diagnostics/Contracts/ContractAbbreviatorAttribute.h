#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractAbbreviatorAttributeNamespace {
CLASS(ContractAbbreviatorAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace ContractAbbreviatorAttributeNamespace
using ContractAbbreviatorAttribute = ContractAbbreviatorAttributeNamespace::ContractAbbreviatorAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
