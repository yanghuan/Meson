#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace ConcurrentSetItemNamespace {
CLASS(ConcurrentSetItem, KeyType, ItemType) : public Object::in {
  public: Int32 Compare(ItemType other);
  public: Int32 Compare(KeyType key);
  protected: void Ctor();
};
} // namespace ConcurrentSetItemNamespace
template <class KeyType, class ItemType>
using ConcurrentSetItem = ConcurrentSetItemNamespace::ConcurrentSetItem<KeyType, ItemType>;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
