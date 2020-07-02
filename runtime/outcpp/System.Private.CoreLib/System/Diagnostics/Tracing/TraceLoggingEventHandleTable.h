#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
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
