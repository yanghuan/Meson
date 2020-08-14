#include "TraceLoggingEventHandleTable-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingEventHandleTableNamespace {
using namespace System::Threading;

IntPtr TraceLoggingEventHandleTable___::get_Item(Int32 eventID) {
  IntPtr result = IntPtr::Zero;
  Array<IntPtr> array = Volatile::Read(m_innerTable);
  if (eventID >= 0 && eventID < array->get_Length()) {
    result = array[eventID];
  }
  return result;
}

void TraceLoggingEventHandleTable___::ctor() {
  m_innerTable = rt::newarr<Array<IntPtr>>(10);
}

void TraceLoggingEventHandleTable___::SetEventHandle(Int32 eventID, IntPtr eventHandle) {
  if (eventID >= m_innerTable->get_Length()) {
    Int32 num = m_innerTable->get_Length() * 2;
    if (num <= eventID) {
      num = eventID + 1;
    }
    Array<IntPtr> array = rt::newarr<Array<IntPtr>>(num);
    Array<>::in::Copy(m_innerTable, array, m_innerTable->get_Length());
    Volatile::Write(m_innerTable, array);
  }
  m_innerTable[eventID] = eventHandle;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingEventHandleTableNamespace
