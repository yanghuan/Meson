#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace ConditionalAttributeNamespace {
CLASS(ConditionalAttribute) {
  public: String get_ConditionString() { return ConditionString; }
  public: void Ctor(String conditionString);
  private: String ConditionString;
};
} // namespace ConditionalAttributeNamespace
using ConditionalAttribute = ConditionalAttributeNamespace::ConditionalAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
