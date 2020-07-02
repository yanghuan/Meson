#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace IProducerConsumerQueueNamespace {
CLASS(IProducerConsumerQueue, T) {
  public: Boolean get_IsEmpty();
  public: Int32 get_Count();
  public: void Enqueue(T item);
  public: Boolean TryDequeue(T& result);
};
} // namespace IProducerConsumerQueueNamespace
template <class T>
using IProducerConsumerQueue = IProducerConsumerQueueNamespace::IProducerConsumerQueue<T>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
