#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Concurrent {
FORWARD(IProducerConsumerCollection, T)
namespace IProducerConsumerCollectionDebugViewNamespace {
CLASS(IProducerConsumerCollectionDebugView, T) {
  public: Array<T> get_Items();
  private: IProducerConsumerCollection<T> _collection;
};
} // namespace IProducerConsumerCollectionDebugViewNamespace
template <class T>
using IProducerConsumerCollectionDebugView = IProducerConsumerCollectionDebugViewNamespace::IProducerConsumerCollectionDebugView<T>;
} // namespace System::Private::CoreLib::System::Collections::Concurrent