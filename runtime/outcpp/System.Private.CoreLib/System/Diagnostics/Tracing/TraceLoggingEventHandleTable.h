#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace TraceLoggingEventHandleTableNamespace {
CLASS(TraceLoggingEventHandleTable) {
  public: IntPtr get_Item(Int32 eventID);
  public: void SetEventHandle(Int32 eventID, IntPtr eventHandle);
  private: Array<IntPtr> m_innerTable;
};
} // namespace TraceLoggingEventHandleTableNamespace
using TraceLoggingEventHandleTable = TraceLoggingEventHandleTableNamespace::TraceLoggingEventHandleTable;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
