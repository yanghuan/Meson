#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace ConcurrentSetNamespace {
template <class KeyType, class ItemType>
struct ConcurrentSet : public valueType<ConcurrentSet<KeyType, ItemType>> {
  public: ItemType TryGet(KeyType key);
  public: ItemType GetOrAdd(ItemType newItem);
  private: Array<ItemType> items;
};
} // namespace ConcurrentSetNamespace
template <class KeyType, class ItemType>
using ConcurrentSet = ConcurrentSetNamespace::ConcurrentSet<KeyType, ItemType>;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
