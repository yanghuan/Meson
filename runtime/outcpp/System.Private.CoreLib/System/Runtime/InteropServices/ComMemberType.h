#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ComMemberType : int32_t {
  Method = 0,
  PropGet = 1,
  PropSet = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
