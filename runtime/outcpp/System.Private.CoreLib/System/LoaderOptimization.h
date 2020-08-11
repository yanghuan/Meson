#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class LoaderOptimization : int32_t {
  DisallowBindings = 4,
  DomainMask = 3,
  MultiDomain = 2,
  MultiDomainHost = 3,
  NotSpecified = 0,
  SingleDomain = 1,
};
} // namespace System::Private::CoreLib::System
