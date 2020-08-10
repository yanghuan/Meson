#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadLocal, T)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
namespace LocalDataStoreSlotNamespace {
using namespace Threading;
CLASS(LocalDataStoreSlot) : public Object::in {
  public: ThreadLocal<Object> get_Data() { return Data; }
  private: void set_Data(ThreadLocal<Object> value) { Data = value; }
  public: void ctor(ThreadLocal<Object> data);
  protected: void Finalize();
  private: ThreadLocal<Object> Data;
};
} // namespace LocalDataStoreSlotNamespace
using LocalDataStoreSlot = LocalDataStoreSlotNamespace::LocalDataStoreSlot;
} // namespace System::Private::CoreLib::System
