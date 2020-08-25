#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace DictionaryValueCollectionDebugViewNamespace {
template <class T>
using ICollection = Generic::ICollection<T>;
CLASS(DictionaryValueCollectionDebugView, TKey, TValue) : public object {
  public: Array<TValue> get_Items();
  public: void ctor(ICollection<TValue> collection);
  private: ICollection<TValue> _collection;
};
} // namespace DictionaryValueCollectionDebugViewNamespace
template <class TKey, class TValue>
using DictionaryValueCollectionDebugView = DictionaryValueCollectionDebugViewNamespace::DictionaryValueCollectionDebugView<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
