#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace DictionaryKeyCollectionDebugViewNamespace {
CLASS(DictionaryKeyCollectionDebugView, TKey, TValue) {
  public: Array<TKey> get_Items();
  private: ICollection<TKey> _collection;
};
} // namespace DictionaryKeyCollectionDebugViewNamespace
template <class TKey, class TValue>
using DictionaryKeyCollectionDebugView = DictionaryKeyCollectionDebugViewNamespace::DictionaryKeyCollectionDebugView<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
