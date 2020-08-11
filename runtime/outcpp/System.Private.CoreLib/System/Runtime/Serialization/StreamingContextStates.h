#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::Serialization {
enum class StreamingContextStates : int32_t {
  CrossProcess = 1,
  CrossMachine = 2,
  File = 4,
  Persistence = 8,
  Remoting = 16,
  Other = 32,
  Clone = 64,
  CrossAppDomain = 128,
  All = 255,
};
} // namespace System::Private::CoreLib::System::Runtime::Serialization
