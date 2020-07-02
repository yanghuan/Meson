#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace ContractOptionAttributeNamespace {
CLASS(ContractOptionAttribute) {
  public: String get_Category();
  public: String get_Setting();
  public: Boolean get_Enabled();
  public: String get_Value();
  private: String _category;
  private: String _setting;
  private: Boolean _enabled;
  private: String _value;
};
} // namespace ContractOptionAttributeNamespace
using ContractOptionAttribute = ContractOptionAttributeNamespace::ContractOptionAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
