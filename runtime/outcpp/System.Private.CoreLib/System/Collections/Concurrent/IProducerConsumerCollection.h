#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Concurrent {
namespace IProducerConsumerCollectionNamespace {
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
using ICollection = Collections::ICollection;
using IEnumerator = Collections::IEnumerator;
template <class T>
using IEnumerator_ = Generic::IEnumerator<T>;
CLASS(IProducerConsumerCollection, T) : public object {
  public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable_, ICollection>;
  public: Int32 get_Count();
  public: Object get_SyncRoot();
  public: Boolean get_IsSynchronized();
  public: IEnumerator GetEnumerator();
  public: IEnumerator_<T> GetEnumerator();
  public: void CopyTo(Array<> array, Int32 index);
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
