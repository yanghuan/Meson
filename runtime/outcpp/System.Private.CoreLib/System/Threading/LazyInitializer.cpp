#include "LazyInitializer-dep.h"

#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Threading::LazyInitializerNamespace {
Object LazyInitializer::EnsureLockInitialized(Object& syncLock) {
  auto& default = Interlocked::CompareExchange(syncLock, rt::newobj<Object>(), nullptr);
  auto& extern = syncLock;
  return extern != nullptr ? extern : default != nullptr ? default : syncLock;
}

} // namespace System::Private::CoreLib::System::Threading::LazyInitializerNamespace
