#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace LocalDataStoreSlotNamespace {
CLASS(LocalDataStoreSlot) {
  protected: void Finalize();
};
} // namespace LocalDataStoreSlotNamespace
using LocalDataStoreSlot = LocalDataStoreSlotNamespace::LocalDataStoreSlot;
} // namespace System::Private::CoreLib::System
