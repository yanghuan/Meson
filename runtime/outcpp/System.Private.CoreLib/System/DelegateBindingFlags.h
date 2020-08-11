#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class DelegateBindingFlags : int32_t {
  StaticMethodOnly = 1,
  InstanceMethodOnly = 2,
  OpenDelegateOnly = 4,
  ClosedDelegateOnly = 8,
  NeverCloseOverNull = 16,
  CaselessMatching = 32,
  RelaxedSignature = 64,
};
} // namespace System::Private::CoreLib::System
