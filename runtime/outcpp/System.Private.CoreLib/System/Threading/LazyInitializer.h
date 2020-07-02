#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace LazyInitializerNamespace {
class LazyInitializer {
  private: static Object EnsureLockInitialized(Object& syncLock);
};
} // namespace LazyInitializerNamespace
using LazyInitializer = LazyInitializerNamespace::LazyInitializer;
} // namespace System::Private::CoreLib::System::Threading
