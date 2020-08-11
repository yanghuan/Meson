#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class IMPLTYPEFLAGS : int32_t {
  IMPLTYPEFLAG_FDEFAULT = 1,
  IMPLTYPEFLAG_FSOURCE = 2,
  IMPLTYPEFLAG_FRESTRICTED = 4,
  IMPLTYPEFLAG_FDEFAULTVTABLE = 8,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
