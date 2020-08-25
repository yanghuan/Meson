#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace TraceLoggingEventHandleTableNamespace {
CLASS(TraceLoggingEventHandleTable) : public object {
  public: IntPtr get_Item(Int32 eventID);
  public: void ctor();
  public: void SetEventHandle(Int32 eventID, IntPtr eventHandle);
  private: Array<IntPtr> m_innerTable;
};
} // namespace TraceLoggingEventHandleTableNamespace
using TraceLoggingEventHandleTable = TraceLoggingEventHandleTableNamespace::TraceLoggingEventHandleTable;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
