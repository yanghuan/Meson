#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Internal/PaddingFor32.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace SingleProducerSingleConsumerQueueNamespace {
using namespace ::System::Private::CoreLib::Internal;
using namespace Collections::Generic;
using Collections::Generic::IEnumerator;
CLASS(SingleProducerSingleConsumerQueue, T) {
  private: struct SegmentState {
    public: PaddingFor32 m_pad0;
    public: Int32 m_first;
    public: Int32 m_lastCopy;
    public: PaddingFor32 m_pad1;
    public: Int32 m_firstCopy;
    public: Int32 m_last;
    public: PaddingFor32 m_pad2;
  };
  private: CLASS(Segment) {
    public: void Ctor(Int32 size);
    public: Segment m_next;
    public: Array<T> m_array;
    public: SegmentState m_state;
  };
  private: CLASS(SingleProducerSingleConsumerQueue_DebugView) {
    public: void Ctor(SingleProducerSingleConsumerQueue<T> queue);
    private: SingleProducerSingleConsumerQueue<T> m_queue;
  };
  public: Boolean get_IsEmpty();
  public: Int32 get_Count();
  public: void Ctor();
  public: void Enqueue(T item);
  private: void EnqueueSlow(T item, Segment& segment);
  public: Boolean TryDequeue(T& result);
  private: Boolean TryDequeueSlow(Segment& segment, Array<T>& array, T& result);
  public: IEnumerator<T> GetEnumerator();
  private: Segment m_head;
  private: Segment m_tail;
};
} // namespace SingleProducerSingleConsumerQueueNamespace
template <class T>
using SingleProducerSingleConsumerQueue = SingleProducerSingleConsumerQueueNamespace::SingleProducerSingleConsumerQueue<T>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
