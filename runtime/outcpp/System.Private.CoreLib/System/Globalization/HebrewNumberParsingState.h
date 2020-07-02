#pragma once

namespace System::Private::CoreLib::System::Globalization {
enum class HebrewNumberParsingState {
  InvalidHebrewNumber = 0,
  NotHebrewDigit = 1,
  FoundEndOfHebrewNumber = 2,
  ContinueParsing = 3,
};
} // namespace System::Private::CoreLib::System::Globalization
