#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
enum class ContractFailureKind {
  Precondition = 0,
  Postcondition = 1,
  PostconditionOnException = 2,
  Invariant = 3,
  Assert = 4,
  Assume = 5,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
