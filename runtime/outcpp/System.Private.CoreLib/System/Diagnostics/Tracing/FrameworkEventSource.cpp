#include "FrameworkEventSource-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/FrameworkEventSource-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::FrameworkEventSourceNamespace {
using namespace Internal::Runtime::CompilerServices;

void FrameworkEventSource___::ctor() {
}

void FrameworkEventSource___::WriteEvent(Int32 eventId, Int64 arg1, Int32 arg2, String arg3, Boolean arg4, Int32 arg5, Int32 arg6) {
  if (IsEnabled()) {
    if (arg3 == nullptr) {
      arg3 = "";
    }
    {
      Char* ptr = arg3;
      Char* value = ptr;
      EventSource::in::EventData default[6] = {};
      EventSource::in::EventData* ptr2 = default;
      ptr2->set_DataPointer((IntPtr)(void*)(&arg1));
      ptr2->set_Size(8);
      ptr2->set_Reserved(0);
      ptr2[1].set_DataPointer((IntPtr)(void*)(&arg2));
      ptr2[1].set_Size(4);
      ptr2[1].set_Reserved(0);
      ptr2[2].set_DataPointer((IntPtr)(void*)value);
      ptr2[2].set_Size((arg3->get_Length() + 1) * 2);
      ptr2[2].set_Reserved(0);
      ptr2[3].set_DataPointer((IntPtr)(void*)(&arg4));
      ptr2[3].set_Size(4);
      ptr2[3].set_Reserved(0);
      ptr2[4].set_DataPointer((IntPtr)(void*)(&arg5));
      ptr2[4].set_Size(4);
      ptr2[4].set_Reserved(0);
      ptr2[5].set_DataPointer((IntPtr)(void*)(&arg6));
      ptr2[5].set_Size(4);
      ptr2[5].set_Reserved(0);
      WriteEventCore(eventId, 6, ptr2);
    }
  }
}

void FrameworkEventSource___::WriteEvent(Int32 eventId, Int64 arg1, Int32 arg2, String arg3) {
  if (IsEnabled()) {
    if (arg3 == nullptr) {
      arg3 = "";
    }
    {
      Char* ptr = arg3;
      Char* value = ptr;
      EventSource::in::EventData default[3] = {};
      EventSource::in::EventData* ptr2 = default;
      ptr2->set_DataPointer((IntPtr)(void*)(&arg1));
      ptr2->set_Size(8);
      ptr2->set_Reserved(0);
      ptr2[1].set_DataPointer((IntPtr)(void*)(&arg2));
      ptr2[1].set_Size(4);
      ptr2[1].set_Reserved(0);
      ptr2[2].set_DataPointer((IntPtr)(void*)value);
      ptr2[2].set_Size((arg3->get_Length() + 1) * 2);
      ptr2[2].set_Reserved(0);
      WriteEventCore(eventId, 3, ptr2);
    }
  }
}

void FrameworkEventSource___::ThreadPoolEnqueueWork(Int64 workID) {
  WriteEvent(30, workID);
}

void FrameworkEventSource___::ThreadPoolEnqueueWorkObject(Object workID) {
  ThreadPoolEnqueueWork((Int64)(UIntPtr)(IntPtr)(*(IntPtr*)Unsafe::AsPointer(workID)));
}

void FrameworkEventSource___::ThreadPoolDequeueWork(Int64 workID) {
  WriteEvent(31, workID);
}

void FrameworkEventSource___::ThreadPoolDequeueWorkObject(Object workID) {
  ThreadPoolDequeueWork((Int64)(UIntPtr)(IntPtr)(*(IntPtr*)Unsafe::AsPointer(workID)));
}

void FrameworkEventSource___::ThreadTransferSend(Int64 id, Int32 kind, String info, Boolean multiDequeues, Int32 intInfo1, Int32 intInfo2) {
  WriteEvent(150, id, kind, info, multiDequeues, intInfo1, intInfo2);
}

void FrameworkEventSource___::ThreadTransferSendObj(Object id, Int32 kind, String info, Boolean multiDequeues, Int32 intInfo1, Int32 intInfo2) {
  ThreadTransferSend((Int64)(UIntPtr)(IntPtr)(*(IntPtr*)Unsafe::AsPointer(id)), kind, info, multiDequeues, intInfo1, intInfo2);
}

void FrameworkEventSource___::ThreadTransferReceive(Int64 id, Int32 kind, String info) {
  WriteEvent(151, id, kind, info);
}

void FrameworkEventSource___::ThreadTransferReceiveObj(Object id, Int32 kind, String info) {
  ThreadTransferReceive((Int64)(UIntPtr)(IntPtr)(*(IntPtr*)Unsafe::AsPointer(id)), kind, info);
}

void FrameworkEventSource___::cctor() {
  Log = rt::newobj<FrameworkEventSource>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::FrameworkEventSourceNamespace
