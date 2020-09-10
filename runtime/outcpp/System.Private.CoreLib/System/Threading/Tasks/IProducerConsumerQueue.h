#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace IProducerConsumerQueueNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
using IEnumerator = Collections::IEnumerator;
template <class T>
using IEnumerator_ = Collections::Generic::IEnumerator<T>;
CLASS(IProducerConsumerQueue, T) : public object {
  public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable_>;
  public: Boolean get_IsEmpty();
  public: Int32 get_Count();
  public: IEnumerator GetEnumerator();
  public: IEnumerator_<T> GetEnumerator();
  public: void Enqueue(T item);
  public: Boolean TryDequeue(T& result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IProducerConsumerQueueNamespace
template <class T>
using IProducerConsumerQueue = IProducerConsumerQueueNamespace::IProducerConsumerQueue<T>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
