#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class LIBFLAGS : int16_t {
  LIBFLAG_FRESTRICTED = 1,
  LIBFLAG_FCONTROL = 2,
  LIBFLAG_FHIDDEN = 4,
  LIBFLAG_FHASDISKIMAGE = 8,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
