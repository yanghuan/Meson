#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARD(IReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Concurrent {
FORWARD(ConcurrentQueueSegment, T)
FORWARD(IProducerConsumerCollection, T)
namespace ConcurrentQueueNamespace {
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
using ICollection = Collections::ICollection;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(ConcurrentQueue, T) : public object {
  public: using interface = rt::TypeList<IProducerConsumerCollection<T>, IEnumerable<T>, IEnumerable_, ICollection, IReadOnlyCollection<T>>;
  private: CLASS(_Enumerate_d__26) : public object {
    public: using interface = rt::TypeList<IEnumerator<T>, IDisposable, IEnumerator_>;
    private: T get_CurrentOfIEnumeratorT();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: Int32 __1__state;
    private: T __2__current;
    public: ConcurrentQueueSegment<T> head;
    public: ConcurrentQueueSegment<T> tail;
    public: Int32 tailTail;
    public: Int32 headHead;
    private: Int32 _headTail_5__2;
    private: Int32 _i_5__3;
    private: ConcurrentQueueSegment<T> _s_5__4;
    private: Int32 _i_5__5;
  };
  private: Boolean get_IsSynchronizedOfICollection();
  private: Object get_SyncRootOfICollection();
  public: Boolean get_IsEmpty();
  public: Int32 get_Count();
  public: void ctor();
  public: void ctor(IEnumerable<T> collection);
  private: void CopyToOfICollection(Array<> array, Int32 index);
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  private: Boolean TryAddOfIProducerConsumerCollectionT(T item);
  private: Boolean TryTakeOfIProducerConsumerCollectionT(T& item);
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
