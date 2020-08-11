#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class Base64FormattingOptions : int32_t {
  None = 0,
  InsertLineBreaks = 1,
};
} // namespace System::Private::CoreLib::System
