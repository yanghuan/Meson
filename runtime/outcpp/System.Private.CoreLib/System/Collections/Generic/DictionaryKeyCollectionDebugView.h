#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace DictionaryKeyCollectionDebugViewNamespace {
template <class T>
using ICollection = Generic::ICollection<T>;
CLASS(DictionaryKeyCollectionDebugView, TKey, TValue) : public object {
  public: Array<TKey> get_Items();
  public: void ctor(ICollection<TKey> collection);
  private: ICollection<TKey> _collection;
};
} // namespace DictionaryKeyCollectionDebugViewNamespace
template <class TKey, class TValue>
using DictionaryKeyCollectionDebugView = DictionaryKeyCollectionDebugViewNamespace::DictionaryKeyCollectionDebugView<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
