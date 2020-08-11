#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading {
enum class ApartmentState : int32_t {
  STA = 0,
  MTA = 1,
  Unknown = 2,
};
} // namespace System::Private::CoreLib::System::Threading
