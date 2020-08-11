#pragma once

#include <System.Private.CoreLib/Internal/PaddingFor32.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(IProducerConsumerQueue, T)
namespace SingleProducerSingleConsumerQueueNamespace {
using namespace ::System::Private::CoreLib::Internal;
using namespace Collections;
using namespace Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
CLASS(SingleProducerSingleConsumerQueue, T) : public Object::in {
  public: using interface = rt::TypeList<IProducerConsumerQueue<T>, IEnumerable<T>, IEnumerable_>;
  private: struct SegmentState : public valueType<SegmentState> {
    public: PaddingFor32 m_pad0;
    public: Int32 m_first;
    public: Int32 m_lastCopy;
    public: PaddingFor32 m_pad1;
    public: Int32 m_firstCopy;
    public: Int32 m_last;
    public: PaddingFor32 m_pad2;
  };
  private: CLASS(Segment) : public Object::in {
    public: void ctor(Int32 size);
    public: Segment m_next;
    public: Array<T> m_array;
    public: SegmentState m_state;
  };
  private: CLASS(SingleProducerSingleConsumerQueue_DebugView) : public Object::in {
    public: void ctor(SingleProducerSingleConsumerQueue<T> queue);
    private: SingleProducerSingleConsumerQueue<T> m_queue;
  };
  public: Boolean get_IsEmpty();
  public: Int32 get_Count();
  public: void ctor();
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
