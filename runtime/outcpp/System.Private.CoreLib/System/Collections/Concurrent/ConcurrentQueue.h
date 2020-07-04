#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections::Concurrent {
FORWARD(ConcurrentQueueSegment, T)
namespace ConcurrentQueueNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
CLASS(ConcurrentQueue, T) {
  private: Boolean get_IsSynchronizedOfICollection();
  private: Object get_SyncRootOfICollection();
  public: Boolean get_IsEmpty();
  public: Int32 get_Count();
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
