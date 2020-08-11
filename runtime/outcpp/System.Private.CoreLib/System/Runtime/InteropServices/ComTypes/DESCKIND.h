#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class DESCKIND : int32_t {
  DESCKIND_NONE = 0,
  DESCKIND_FUNCDESC = 1,
  DESCKIND_VARDESC = 2,
  DESCKIND_TYPECOMP = 3,
  DESCKIND_IMPLICITAPPOBJ = 4,
  DESCKIND_MAX = 5,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
