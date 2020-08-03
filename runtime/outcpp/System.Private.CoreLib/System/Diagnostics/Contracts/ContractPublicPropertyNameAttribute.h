#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractPublicPropertyNameAttributeNamespace {
CLASS(ContractPublicPropertyNameAttribute) : public Attribute::in {
  public: String get_Name();
  public: void Ctor(String name);
  private: String _publicName;
};
} // namespace ContractPublicPropertyNameAttributeNamespace
using ContractPublicPropertyNameAttribute = ContractPublicPropertyNameAttributeNamespace::ContractPublicPropertyNameAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
