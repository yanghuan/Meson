#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadLocal, T)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD(Object)
namespace LocalDataStoreSlotNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(LocalDataStoreSlot) {
  protected: void Finalize();
  private: ThreadLocal<Object> Data;
};
} // namespace LocalDataStoreSlotNamespace
using LocalDataStoreSlot = LocalDataStoreSlotNamespace::LocalDataStoreSlot;
} // namespace System::Private::CoreLib::System
