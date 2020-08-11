#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Globalization {
enum class StrongBidiCategory : int32_t {
  Other = 0,
  StrongLeftToRight = 16,
  StrongRightToLeft = 32,
};
} // namespace System::Private::CoreLib::System::Globalization
