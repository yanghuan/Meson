#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Collections/Concurrent/PaddedHeadAndTail.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Concurrent {
namespace ConcurrentQueueSegmentNamespace {
CLASS(ConcurrentQueueSegment, T) : public Object::in {
  public: struct Slot {
    public: T Item;
    public: Int32 SequenceNumber;
  };
  public: Int32 get_Capacity();
  public: Int32 get_FreezeOffset();
  public: void Ctor(Int32 boundedLength);
  public: static Int32 RoundUpToPowerOf2(Int32 i);
  public: void EnsureFrozenForEnqueues();
  public: Boolean TryDequeue(T& item);
  public: Boolean TryPeek(T& result, Boolean resultUsed);
  public: Boolean TryEnqueue(T item);
  public: Array<Slot> _slots;
  public: Int32 _slotsMask;
  public: PaddedHeadAndTail _headAndTail;
  public: Boolean _preservedForObservation;
  public: Boolean _frozenForEnqueues;
  public: ConcurrentQueueSegment<T> _nextSegment;
};
} // namespace ConcurrentQueueSegmentNamespace
template <class T>
using ConcurrentQueueSegment = ConcurrentQueueSegmentNamespace::ConcurrentQueueSegment<T>;
} // namespace System::Private::CoreLib::System::Collections::Concurrent
