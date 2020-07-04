#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Security {
enum class SecurityRuleSet : uint8_t;
namespace SecurityRulesAttributeNamespace {
CLASS(SecurityRulesAttribute) {
  public: Boolean get_SkipVerificationInFullTrust() { return SkipVerificationInFullTrust; }
  public: void set_SkipVerificationInFullTrust(Boolean value) { SkipVerificationInFullTrust = value; }
  public: SecurityRuleSet get_RuleSet() { return RuleSet; }
  private: Boolean SkipVerificationInFullTrust;
  private: SecurityRuleSet RuleSet;
};
} // namespace SecurityRulesAttributeNamespace
using SecurityRulesAttribute = SecurityRulesAttributeNamespace::SecurityRulesAttribute;
} // namespace System::Private::CoreLib::System::Security
