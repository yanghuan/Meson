#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Globalization {
enum class CalendarWeekRule : int32_t {
  FirstDay = 0,
  FirstFullWeek = 1,
  FirstFourDayWeek = 2,
};
} // namespace System::Private::CoreLib::System::Globalization
