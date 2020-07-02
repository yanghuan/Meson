#pragma once

namespace System::Private::CoreLib::System {
enum class MidpointRounding {
  ToEven = 0,
  AwayFromZero = 1,
  ToZero = 2,
  ToNegativeInfinity = 3,
  ToPositiveInfinity = 4,
};
} // namespace System::Private::CoreLib::System
