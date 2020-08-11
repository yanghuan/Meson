#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Globalization {
enum class CalendarAlgorithmType : int32_t {
  Unknown = 0,
  SolarCalendar = 1,
  LunarCalendar = 2,
  LunisolarCalendar = 3,
};
} // namespace System::Private::CoreLib::System::Globalization
