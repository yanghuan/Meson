#include "ArrayPoolEventSource-dep.h"

#include <System.Private.CoreLib/System/Buffers/ArrayPoolEventSource-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::System::Buffers::ArrayPoolEventSourceNamespace {
void ArrayPoolEventSource___::ctor() {
}

void ArrayPoolEventSource___::BufferRented(Int32 bufferId, Int32 bufferSize, Int32 poolId, Int32 bucketId) {
  EventSource::in::EventData as[4] = {};
  EventSource::in::EventData* ptr = as;
  ptr->set_Size(4);
  ptr->set_DataPointer((IntPtr)(void*)(&bufferId));
  ptr->set_Reserved(0);
  ptr[1].set_Size(4);
  ptr[1].set_DataPointer((IntPtr)(void*)(&bufferSize));
  ptr[1].set_Reserved(0);
  ptr[2].set_Size(4);
  ptr[2].set_DataPointer((IntPtr)(void*)(&poolId));
  ptr[2].set_Reserved(0);
  ptr[3].set_Size(4);
  ptr[3].set_DataPointer((IntPtr)(void*)(&bucketId));
  ptr[3].set_Reserved(0);
  WriteEventCore(1, 4, ptr);
}

void ArrayPoolEventSource___::BufferAllocated(Int32 bufferId, Int32 bufferSize, Int32 poolId, Int32 bucketId, BufferAllocatedReason reason) {
  EventSource::in::EventData as[5] = {};
  EventSource::in::EventData* ptr = as;
  ptr->set_Size(4);
  ptr->set_DataPointer((IntPtr)(void*)(&bufferId));
  ptr->set_Reserved(0);
  ptr[1].set_Size(4);
  ptr[1].set_DataPointer((IntPtr)(void*)(&bufferSize));
  ptr[1].set_Reserved(0);
  ptr[2].set_Size(4);
  ptr[2].set_DataPointer((IntPtr)(void*)(&poolId));
  ptr[2].set_Reserved(0);
  ptr[3].set_Size(4);
  ptr[3].set_DataPointer((IntPtr)(void*)(&bucketId));
  ptr[3].set_Reserved(0);
  ptr[4].set_Size(4);
  ptr[4].set_DataPointer((IntPtr)(void*)(&reason));
  ptr[4].set_Reserved(0);
  WriteEventCore(2, 5, ptr);
}

void ArrayPoolEventSource___::BufferReturned(Int32 bufferId, Int32 bufferSize, Int32 poolId) {
  WriteEvent(3, bufferId, bufferSize, poolId);
}

void ArrayPoolEventSource___::BufferTrimmed(Int32 bufferId, Int32 bufferSize, Int32 poolId) {
  WriteEvent(4, bufferId, bufferSize, poolId);
}

void ArrayPoolEventSource___::BufferTrimPoll(Int32 milliseconds, Int32 pressure) {
  WriteEvent(5, milliseconds, pressure);
}

void ArrayPoolEventSource___::cctor() {
  Log = rt::newobj<ArrayPoolEventSource>();
}

} // namespace System::Private::CoreLib::System::Buffers::ArrayPoolEventSourceNamespace
