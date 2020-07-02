#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class IDLFLAG : int16_t {
  IDLFLAG_NONE = 0,
  IDLFLAG_FIN = 1,
  IDLFLAG_FOUT = 2,
  IDLFLAG_FLCID = 4,
  IDLFLAG_FRETVAL = 8,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
