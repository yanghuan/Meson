#pragma once

namespace System::Private::CoreLib::System::Text::Unicode {
enum class GraphemeClusterBreakType {
  Other = 0,
  CR = 1,
  LF = 2,
  Control = 3,
  Extend = 4,
  ZWJ = 5,
  Regional_Indicator = 6,
  Prepend = 7,
  SpacingMark = 8,
  L = 9,
  V = 10,
  T = 11,
  LV = 12,
  LVT = 13,
  Extended_Pictograph = 14,
};
} // namespace System::Private::CoreLib::System::Text::Unicode
