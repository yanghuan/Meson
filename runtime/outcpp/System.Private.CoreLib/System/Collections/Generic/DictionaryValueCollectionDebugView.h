#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace DictionaryValueCollectionDebugViewNamespace {
CLASS(DictionaryValueCollectionDebugView, TKey, TValue) {
  public: Array<TValue> get_Items();
  private: ICollection<TValue> _collection;
};
} // namespace DictionaryValueCollectionDebugViewNamespace
template <class TKey, class TValue>
using DictionaryValueCollectionDebugView = DictionaryValueCollectionDebugViewNamespace::DictionaryValueCollectionDebugView<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
