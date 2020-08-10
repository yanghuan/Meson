#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARD(IReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Concurrent {
FORWARD(ConcurrentQueueSegment, T)
FORWARD(IProducerConsumerCollection, T)
namespace ConcurrentQueueNamespace {
using namespace Generic;
using Generic::IEnumerator;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(ConcurrentQueue, T) : public Object::in {
  public: using interface = rt::TypeList<IProducerConsumerCollection<T>, IEnumerable<T>, IEnumerable1, ICollection, IReadOnlyCollection<T>>;
  private: Boolean get_IsSynchronizedOfICollection();
  private: Object get_SyncRootOfICollection();
  public: Boolean get_IsEmpty();
  public: Int32 get_Count();
  public: void ctor();
  public: void ctor(IEnumerable<T> collection);
  public: Array<T> ToArray();
  private: static Int32 GetCount(ConcurrentQueueSegment<T> s, Int32 head, Int32 tail);
  private: static Int64 GetCount(ConcurrentQueueSegment<T> head, Int32 headHead, ConcurrentQueueSegment<T> tail, Int32 tailTail);
  public: void CopyTo(Array<T> array, Int32 index);
  public: IEnumerator<T> GetEnumerator();
  private: void SnapForObservation(ConcurrentQueueSegment<T>& head, Int32& headHead, ConcurrentQueueSegment<T>& tail, Int32& tailTail);
  private: static T GetItemWhenAvailable(ConcurrentQueueSegment<T> segment, Int32 i);
  private: IEnumerator<T> Enumerate(ConcurrentQueueSegment<T> head, Int32 headHead, ConcurrentQueueSegment<T> tail, Int32 tailTail);
  public: void Enqueue(T item);
  private: void EnqueueSlow(T item);
  public: Boolean TryDequeue(T& result);
  private: Boolean TryDequeueSlow(T& item);
  public: Boolean TryPeek(T& result);
  private: Boolean TryPeek(T& result, Boolean resultUsed);
  public: void Clear();
  private: Object _crossSegmentLock;
  private: ConcurrentQueueSegment<T> _tail;
  private: ConcurrentQueueSegment<T> _head;
};
} // namespace ConcurrentQueueNamespace
template <class T>
using ConcurrentQueue = ConcurrentQueueNamespace::ConcurrentQueue<T>;
} // namespace System::Private::CoreLib::System::Collections::Concurrent
