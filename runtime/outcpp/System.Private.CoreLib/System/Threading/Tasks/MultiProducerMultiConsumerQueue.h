#pragma once

#include <System.Private.CoreLib/System/Collections/Concurrent/ConcurrentQueue.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(IProducerConsumerQueue, T)
namespace MultiProducerMultiConsumerQueueNamespace {
using namespace Collections;
using namespace Collections::Concurrent;
using namespace Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(MultiProducerMultiConsumerQueue, T) : public ConcurrentQueue<T>::in {
  public: using interface = rt::TypeList<IProducerConsumerQueue<T>, IEnumerable<T>, IEnumerable1>;
  private: Boolean get_IsEmptyOfIProducerConsumerQueueT();
  private: Int32 get_CountOfIProducerConsumerQueueT();
  public: void Ctor();
};
} // namespace MultiProducerMultiConsumerQueueNamespace
template <class T>
using MultiProducerMultiConsumerQueue = MultiProducerMultiConsumerQueueNamespace::MultiProducerMultiConsumerQueue<T>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
