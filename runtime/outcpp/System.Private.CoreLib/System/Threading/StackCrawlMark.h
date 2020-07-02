#pragma once

namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark {
  LookForMe = 0,
  LookForMyCaller = 1,
  LookForMyCallersCaller = 2,
  LookForThread = 3,
};
} // namespace System::Private::CoreLib::System::Threading
