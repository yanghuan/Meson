#pragma once

#include <System.Private.CoreLib/System/Object.h>

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
namespace IProducerConsumerQueueNamespace {
using namespace Collections;
using namespace Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
CLASS(IProducerConsumerQueue, T) : public Object::in {
  public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable_>;
  public: Boolean get_IsEmpty();
  public: Int32 get_Count();
  public: void Enqueue(T item);
  public: Boolean TryDequeue(T& result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IProducerConsumerQueueNamespace
template <class T>
using IProducerConsumerQueue = IProducerConsumerQueueNamespace::IProducerConsumerQueue<T>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
