#pragma once

namespace System::Private::CoreLib::System {
enum class ParseFailureKind {
  None = 0,
  ArgumentNull = 1,
  Format = 2,
  FormatWithParameter = 3,
  FormatWithOriginalDateTime = 4,
  FormatWithFormatSpecifier = 5,
  FormatWithOriginalDateTimeAndParameter = 6,
  FormatBadDateTimeCalendar = 7,
};
} // namespace System::Private::CoreLib::System
