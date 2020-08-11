#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Text {
enum class TrimType : int32_t {
  Head = 1,
  Tail = 2,
  Both = 3,
};
} // namespace System::Private::CoreLib::System::Text
