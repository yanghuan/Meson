#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(String)
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
enum class EventTask;
namespace FrameworkEventSourceNamespace {
CLASS(FrameworkEventSource) {
  public: class Keywords {
    public: static EventKeywords ThreadPool;
    public: static EventKeywords ThreadTransfer;
  };
  public: class Tasks {
    public: static EventTask ThreadTransfer;
  };
  private: void WriteEvent(Int32 eventId, Int64 arg1, Int32 arg2, String arg3, Boolean arg4, Int32 arg5, Int32 arg6);
  private: void WriteEvent(Int32 eventId, Int64 arg1, Int32 arg2, String arg3);
  public: void ThreadPoolEnqueueWork(Int64 workID);
  public: void ThreadPoolEnqueueWorkObject(Object workID);
  public: void ThreadPoolDequeueWork(Int64 workID);
  public: void ThreadPoolDequeueWorkObject(Object workID);
  public: void ThreadTransferSend(Int64 id, Int32 kind, String info, Boolean multiDequeues, Int32 intInfo1, Int32 intInfo2);
  public: void ThreadTransferSendObj(Object id, Int32 kind, String info, Boolean multiDequeues, Int32 intInfo1, Int32 intInfo2);
  public: void ThreadTransferReceive(Int64 id, Int32 kind, String info);
  public: void ThreadTransferReceiveObj(Object id, Int32 kind, String info);
  public: static FrameworkEventSource Log;
};
} // namespace FrameworkEventSourceNamespace
using FrameworkEventSource = FrameworkEventSourceNamespace::FrameworkEventSource;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
