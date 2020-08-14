#include "LazyInitializer-dep.h"

#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Threading::LazyInitializerNamespace {
Object LazyInitializer::EnsureLockInitialized(Object& syncLock) {
  auto default = Interlocked::CompareExchange(syncLock, rt::newobj<Object>(), nullptr);
  if (default != nullptr) default = syncLock;

  auto extern = syncLock;
  if (extern != nullptr) extern = default;

  return extern;
}

} // namespace System::Private::CoreLib::System::Threading::LazyInitializerNamespace
