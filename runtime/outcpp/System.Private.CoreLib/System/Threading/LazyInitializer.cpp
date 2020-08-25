#include "LazyInitializer-dep.h"

#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Threading::LazyInitializerNamespace {
Object LazyInitializer::EnsureLockInitialized(Object& syncLock) {
  Object as = Interlocked::CompareExchange(syncLock, rt::newobj<Object>(), nullptr);
  Object is = syncLock;
  return is != nullptr ? is : as != nullptr ? as : syncLock;
}

} // namespace System::Private::CoreLib::System::Threading::LazyInitializerNamespace
