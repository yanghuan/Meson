#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace ConcurrentSetNamespace {
template <class KeyType, class ItemType>
struct ConcurrentSet {
  public: ItemType TryGet(KeyType key);
  public: ItemType GetOrAdd(ItemType newItem);
  private: Array<ItemType> items;
};
} // namespace ConcurrentSetNamespace
template <class KeyType, class ItemType>
using ConcurrentSet = ConcurrentSetNamespace::ConcurrentSet<KeyType, ItemType>;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
