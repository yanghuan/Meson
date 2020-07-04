#pragma once

namespace System::Private::CoreLib::System {
enum class LoaderOptimization {
  DisallowBindings = 4,
  DomainMask = 3,
  MultiDomain = 2,
  MultiDomainHost = 3,
  NotSpecified = 0,
  SingleDomain = 1,
};
} // namespace System::Private::CoreLib::System
