#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractPublicPropertyNameAttributeNamespace {
CLASS(ContractPublicPropertyNameAttribute) {
  public: String get_Name();
  private: String _publicName;
};
} // namespace ContractPublicPropertyNameAttributeNamespace
using ContractPublicPropertyNameAttribute = ContractPublicPropertyNameAttributeNamespace::ContractPublicPropertyNameAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
