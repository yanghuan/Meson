#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace ConditionalAttributeNamespace {
CLASS(ConditionalAttribute) : public Attribute::in {
  public: String get_ConditionString() { return ConditionString; }
  public: void Ctor(String conditionString);
  private: String ConditionString;
};
} // namespace ConditionalAttributeNamespace
using ConditionalAttribute = ConditionalAttributeNamespace::ConditionalAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
