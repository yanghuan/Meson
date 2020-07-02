#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Concurrent {
namespace IProducerConsumerCollectionNamespace {
CLASS(IProducerConsumerCollection, T) {
  public: void CopyTo(Array<T> array, Int32 index);
  public: Boolean TryAdd(T item);
  public: Boolean TryTake(T& item);
  public: Array<T> ToArray();
};
} // namespace IProducerConsumerCollectionNamespace
template <class T>
using IProducerConsumerCollection = IProducerConsumerCollectionNamespace::IProducerConsumerCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Concurrent
