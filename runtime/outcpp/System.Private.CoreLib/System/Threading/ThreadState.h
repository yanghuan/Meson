#pragma once

namespace System::Private::CoreLib::System::Threading {
enum class ThreadState {
  Running = 0,
  StopRequested = 1,
  SuspendRequested = 2,
  Background = 4,
  Unstarted = 8,
  Stopped = 16,
  WaitSleepJoin = 32,
  Suspended = 64,
  AbortRequested = 128,
  Aborted = 256,
};
} // namespace System::Private::CoreLib::System::Threading
