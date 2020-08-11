#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
enum class ContractFailureKind : int32_t {
  Precondition = 0,
  Postcondition = 1,
  PostconditionOnException = 2,
  Invariant = 3,
  Assert = 4,
  Assume = 5,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
