#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace DictionaryKeyCollectionDebugViewNamespace {
CLASS(DictionaryKeyCollectionDebugView, TKey, TValue) {
  private: ICollection<TKey> _collection;
};
} // namespace DictionaryKeyCollectionDebugViewNamespace
template <class TKey, class TValue>
using DictionaryKeyCollectionDebugView = DictionaryKeyCollectionDebugViewNamespace::DictionaryKeyCollectionDebugView<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
