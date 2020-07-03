#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Security {
enum class SecurityRuleSet : uint8_t;
namespace SecurityRulesAttributeNamespace {
CLASS(SecurityRulesAttribute) {
  private: Boolean SkipVerificationInFullTrust;
  private: SecurityRuleSet RuleSet;
};
} // namespace SecurityRulesAttributeNamespace
using SecurityRulesAttribute = SecurityRulesAttributeNamespace::SecurityRulesAttribute;
} // namespace System::Private::CoreLib::System::Security
