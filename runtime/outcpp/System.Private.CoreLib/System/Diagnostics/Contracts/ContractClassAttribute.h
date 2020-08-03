#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractClassAttributeNamespace {
CLASS(ContractClassAttribute) : public Attribute::in {
  public: Type get_TypeContainingContracts();
  public: void Ctor(Type typeContainingContracts);
  private: Type _typeWithContracts;
};
} // namespace ContractClassAttributeNamespace
using ContractClassAttribute = ContractClassAttributeNamespace::ContractClassAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
