#pragma once

namespace System::Private::CoreLib::System::Security::Permissions {
enum class SecurityAction {
  Assert = 3,
  Demand = 2,
  Deny = 4,
  InheritanceDemand = 7,
  LinkDemand = 6,
  PermitOnly = 5,
  RequestMinimum = 8,
  RequestOptional = 9,
  RequestRefuse = 10,
};
} // namespace System::Private::CoreLib::System::Security::Permissions
