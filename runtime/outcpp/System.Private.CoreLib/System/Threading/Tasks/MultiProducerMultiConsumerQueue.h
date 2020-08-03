#pragma once

#include <System.Private.CoreLib/System/Collections/Concurrent/ConcurrentQueue.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace MultiProducerMultiConsumerQueueNamespace {
using namespace Collections::Concurrent;
CLASS(MultiProducerMultiConsumerQueue, T) : public ConcurrentQueue<T>::in {
  private: Boolean get_IsEmptyOfIProducerConsumerQueueT();
  private: Int32 get_CountOfIProducerConsumerQueueT();
  public: void Ctor();
};
} // namespace MultiProducerMultiConsumerQueueNamespace
template <class T>
using MultiProducerMultiConsumerQueue = MultiProducerMultiConsumerQueueNamespace::MultiProducerMultiConsumerQueue<T>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
