#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace FrameworkEventSourceNamespace {
CLASS(FrameworkEventSource) : public EventSource::in {
  public: class Keywords {
  };
  public: class Tasks {
  };
  private: void ctor();
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
  private: static void ctor_static();
  public: static FrameworkEventSource Log;
};
} // namespace FrameworkEventSourceNamespace
using FrameworkEventSource = FrameworkEventSourceNamespace::FrameworkEventSource;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
