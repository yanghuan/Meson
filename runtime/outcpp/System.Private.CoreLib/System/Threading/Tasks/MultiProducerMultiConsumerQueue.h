#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace MultiProducerMultiConsumerQueueNamespace {
CLASS(MultiProducerMultiConsumerQueue, T) {
  private: Boolean get_IsEmptyOfIProducerConsumerQueueT();
  private: Int32 get_CountOfIProducerConsumerQueueT();
};
} // namespace MultiProducerMultiConsumerQueueNamespace
template <class T>
using MultiProducerMultiConsumerQueue = MultiProducerMultiConsumerQueueNamespace::MultiProducerMultiConsumerQueue<T>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
