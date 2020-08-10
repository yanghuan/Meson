#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Concurrent {
namespace IProducerConsumerCollectionNamespace {
using namespace Generic;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(IProducerConsumerCollection, T) : public Object::in {
  public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable1, ICollection>;
  public: void CopyTo(Array<T> array, Int32 index);
  public: Boolean TryAdd(T item);
  public: Boolean TryTake(T& item);
  public: Array<T> ToArray();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IProducerConsumerCollectionNamespace
template <class T>
using IProducerConsumerCollection = IProducerConsumerCollectionNamespace::IProducerConsumerCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Concurrent
