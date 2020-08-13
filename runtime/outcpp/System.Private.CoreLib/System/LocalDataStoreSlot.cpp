#include "LocalDataStoreSlot-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/LocalDataStoreSlot-dep.h>

namespace System::Private::CoreLib::System::LocalDataStoreSlotNamespace {
void LocalDataStoreSlot___::ctor(ThreadLocal<Object> data) {
  Data = data;
  GC::SuppressFinalize((LocalDataStoreSlot)this);
}

void LocalDataStoreSlot___::Finalize() {
}

} // namespace System::Private::CoreLib::System::LocalDataStoreSlotNamespace
