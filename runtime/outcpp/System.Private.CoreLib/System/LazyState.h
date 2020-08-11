#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class LazyState : int32_t {
  NoneViaConstructor = 0,
  NoneViaFactory = 1,
  NoneException = 2,
  PublicationOnlyViaConstructor = 3,
  PublicationOnlyViaFactory = 4,
  PublicationOnlyWait = 5,
  PublicationOnlyException = 6,
  ExecutionAndPublicationViaConstructor = 7,
  ExecutionAndPublicationViaFactory = 8,
  ExecutionAndPublicationException = 9,
};
} // namespace System::Private::CoreLib::System
