#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class VARKIND : int32_t {
  VAR_PERINSTANCE = 0,
  VAR_STATIC = 1,
  VAR_CONST = 2,
  VAR_DISPATCH = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
