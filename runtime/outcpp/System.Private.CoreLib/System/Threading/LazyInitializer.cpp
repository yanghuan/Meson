#include "LazyInitializer-dep.h"

#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Threading::LazyInitializerNamespace {
Object LazyInitializer::EnsureLockInitialized(Object& syncLock) {
  auto& as = Interlocked::CompareExchange(syncLock, rt::newobj<Object>(), nullptr);
  auto& as = syncLock;
  return as != nullptr ? as : as != nullptr ? as : syncLock;
}

} // namespace System::Private::CoreLib::System::Threading::LazyInitializerNamespace
