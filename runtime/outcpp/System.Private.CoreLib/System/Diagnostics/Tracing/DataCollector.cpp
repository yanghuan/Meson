#include "DataCollector-dep.h"

#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DataCollector-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandleType.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::DataCollectorNamespace {
using namespace System::Runtime::InteropServices;

void DataCollector::Enable(Byte* scratch, Int32 scratchSize, EventSource::in::EventData* datas, Int32 dataCount, GCHandle* pins, Int32 pinCount) {
  datasStart = datas;
  scratchEnd = scratch + scratchSize;
  datasEnd = datas + dataCount;
  pinsEnd = pins + pinCount;
  this->scratch = scratch;
  this->datas = datas;
  this->pins = pins;
  writingScalars = false;
}

void DataCollector::Disable() {
  *this = DataCollector();
}

EventSource::in::EventData* DataCollector::Finish() {
  ScalarsEnd();
  return datas;
}

void DataCollector::AddScalar(void* value, Int32 size) {
  if (bufferNesting == 0) {
    Byte* ptr = scratch;
    Byte* ptr2 = ptr + size;
    if (scratchEnd < ptr2) {
      rt::throw_exception<IndexOutOfRangeException>(SR::get_EventSource_AddScalarOutOfRange());
    }
    ScalarsBegin();
    scratch = ptr2;
    for (Int32 i = 0; i != size; i++) {
      ptr[i] = ((Byte*)value)[i];
    }
  } else {
    Int32 num = bufferPos;
    Int32 num2;
    {
      bufferPos += size;
      EnsureBuffer();
      num2 = 0;
    }
    while (num2 != size) {
      buffer[num] = ((Byte*)value)[num2];
      num2++;
      num++;
    }
  }
}

void DataCollector::AddNullTerminatedString(String value) {
  if (value == nullptr) {
    value = String::in::Empty;
  }
  Int32 num = value->IndexOf(0);
  if (num < 0) {
    num = value->get_Length();
  }
  Int32 num2 = (num + 1) * 2;
  if (bufferNesting != 0) {
    EnsureBuffer(num2);
  }
  if (bufferNesting == 0) {
    ScalarsEnd();
    PinArray(value, num2);
    return;
  }
  Int32 startIndex = bufferPos;
  {
    bufferPos += num2;
    EnsureBuffer();
    {
      Char* ptr = value;
      void* value2 = ptr;
      Marshal::Copy((IntPtr)value2, buffer, startIndex, num2);
    }
  }
}

void DataCollector::AddArray(Array<> value, Int32 length, Int32 itemSize) {
  if (length > 65535) {
    length = 65535;
  }
  Int32 num = length * itemSize;
  if (bufferNesting != 0) {
    EnsureBuffer(num + 2);
  }
  AddScalar(&length, 2);
  {
    if (length != 0) {
      if (bufferNesting == 0) {
        ScalarsEnd();
        PinArray(value, num);
        return;
      }
      Int32 dstOffset = bufferPos;
      bufferPos += num;
      EnsureBuffer();
      Buffer::BlockCopy(value, 0, buffer, dstOffset, num);
    }
  }
}

Int32 DataCollector::BeginBufferedArray() {
  BeginBuffered();
  bufferPos += 2;
  return bufferPos;
}

void DataCollector::EndBufferedArray(Int32 bookmark, Int32 count) {
  EnsureBuffer();
  buffer[bookmark - 2] = (Byte)count;
  buffer[bookmark - 1] = (Byte)(count >> 8);
  EndBuffered();
}

void DataCollector::BeginBuffered() {
  ScalarsEnd();
  bufferNesting++;
}

void DataCollector::EndBuffered() {
  bufferNesting--;
  if (bufferNesting == 0) {
    EnsureBuffer();
    PinArray(buffer, bufferPos);
    buffer = nullptr;
    bufferPos = 0;
  }
}

void DataCollector::EnsureBuffer() {
  Int32 num = bufferPos;
  if (buffer == nullptr || buffer->get_Length() < num) {
    GrowBuffer(num);
  }
}

void DataCollector::EnsureBuffer(Int32 additionalSize) {
  Int32 num = bufferPos + additionalSize;
  if (buffer == nullptr || buffer->get_Length() < num) {
    GrowBuffer(num);
  }
}

void DataCollector::GrowBuffer(Int32 required) {
  Int32 num = (buffer == nullptr) ? 64 : buffer->get_Length();
  do {
    num *= 2;
  } while (num < required)
  Array<>::in::Resize(buffer, num);
}

void DataCollector::PinArray(Object value, Int32 size) {
  GCHandle* ptr = pins;
  if (pinsEnd <= ptr) {
    rt::throw_exception<IndexOutOfRangeException>(SR::get_EventSource_PinArrayOutOfRange());
  }
  EventSource::in::EventData* ptr2 = datas;
  if (datasEnd <= ptr2) {
    rt::throw_exception<IndexOutOfRangeException>(SR::get_EventSource_DataDescriptorsOutOfRange());
  }
  pins = ptr + 1;
  datas = ptr2 + 1;
  *ptr = GCHandle::Alloc(value, GCHandleType::Pinned);
  ptr2->set_DataPointer(ptr->AddrOfPinnedObject());
  ptr2->m_Size = size;
}

void DataCollector::ScalarsBegin() {
  if (!writingScalars) {
    EventSource::in::EventData* ptr = datas;
    if (datasEnd <= ptr) {
      rt::throw_exception<IndexOutOfRangeException>(SR::get_EventSource_DataDescriptorsOutOfRange());
    }
    ptr->set_DataPointer((IntPtr)(void*)scratch);
    writingScalars = true;
  }
}

void DataCollector::ScalarsEnd() {
  {
    if (writingScalars) {
      EventSource::in::EventData* ptr = datas;
      ptr->m_Size = (Int32)(scratch - (Byte*)(UInt64)(UIntPtr)ptr->m_Ptr);
      datas = ptr + 1;
      writingScalars = false;
    }
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::DataCollectorNamespace
