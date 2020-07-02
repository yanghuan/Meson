#pragma once

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode {
  None = 0,
  PublicationOnly = 1,
  ExecutionAndPublication = 2,
};
} // namespace System::Private::CoreLib::System::Threading
