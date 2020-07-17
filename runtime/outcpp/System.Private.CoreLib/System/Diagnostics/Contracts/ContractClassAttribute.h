#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractClassAttributeNamespace {
CLASS(ContractClassAttribute) {
  public: Type get_TypeContainingContracts();
  public: void Ctor(Type typeContainingContracts);
  private: Type _typeWithContracts;
};
} // namespace ContractClassAttributeNamespace
using ContractClassAttribute = ContractClassAttributeNamespace::ContractClassAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
